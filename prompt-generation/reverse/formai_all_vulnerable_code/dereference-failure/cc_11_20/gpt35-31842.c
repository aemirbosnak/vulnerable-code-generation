//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF_SIZE 4096
#define MAX_PENDING 5

int main(int argc, char *argv[])
{
    int proxySocket, clientSocket;
    struct sockaddr_in proxyAddr, clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    char buffer[MAX_BUF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    proxySocket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxySocket < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    memset(&proxyAddr, 0, sizeof(proxyAddr));
    proxyAddr.sin_family = AF_INET;
    proxyAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxyAddr.sin_port = htons(atoi(argv[1]));

    if (bind(proxySocket, (struct sockaddr *) &proxyAddr, sizeof(proxyAddr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    if (listen(proxySocket, MAX_PENDING) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %s\n", argv[1]);

    while (1) {
        clientSocket = accept(proxySocket, (struct sockaddr *) &clientAddr, &clientLen);
        if (clientSocket < 0) {
            perror("accept() failed");
            exit(EXIT_FAILURE);
        }

        printf("Accepted connection from %s\n", inet_ntoa(clientAddr.sin_addr));

        int pid = fork();
        if (pid == -1) {
            perror("fork() failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // In child process, handle client request
            close(proxySocket);

            // Read client request
            memset(buffer, 0, MAX_BUF_SIZE);
            int numBytes = read(clientSocket, buffer, MAX_BUF_SIZE);
            if (numBytes < 0) {
                perror("read() failed");
                exit(EXIT_FAILURE);
            }

            printf("Received %d bytes from client:\n%s\n", numBytes, buffer);

            // Extract host and port from client request
            char host[MAX_BUF_SIZE], port[MAX_BUF_SIZE];
            int found = sscanf(buffer, "GET http://%[^:/]:%[^/\r\n]", host, port);
            if (found != 2) {
                printf("Invalid GET request\n");
                exit(EXIT_FAILURE);
            }

            printf("Proxying to host %s:%s\n", host, port);

            // Resolve host name to IP address
            struct hostent *hostInfo = gethostbyname(host);
            if (hostInfo == NULL) {
                printf("gethostbyname() failed for host %s: %s\n", host, hstrerror(h_errno));
                exit(EXIT_FAILURE);
            }

            // Open connection to server
            struct sockaddr_in serverAddr;
            int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
            if (serverSocket < 0) {
                perror("socket() failed");
                exit(EXIT_FAILURE);
            }

            memset(&serverAddr, 0, sizeof(serverAddr));
            serverAddr.sin_family = AF_INET;
            serverAddr.sin_addr = *((struct in_addr *) hostInfo->h_addr_list[0]);
            serverAddr.sin_port = htons(atoi(port));

            if (connect(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
                perror("connect() failed");
                exit(EXIT_FAILURE);
            }

            // Send client request to server
            if (write(serverSocket, buffer, numBytes) < 0) {
                perror("write() failed");
                exit(EXIT_FAILURE);
            }

            // Forward server response to client
            memset(buffer, 0, MAX_BUF_SIZE);
            while ((numBytes = read(serverSocket, buffer, MAX_BUF_SIZE)) > 0) {
                if (write(clientSocket, buffer, numBytes) < 0) {
                    perror("write() failed");
                    exit(EXIT_FAILURE);
                }
                memset(buffer, 0, MAX_BUF_SIZE);
            }

            if (numBytes < 0) {
                perror("read() failed");
                exit(EXIT_FAILURE);
            }

            // Close sockets and exit child process
            close(serverSocket);
            close(clientSocket);
            exit(EXIT_SUCCESS);
        } else {
            close(clientSocket);
        }
    }

    close(proxySocket);
    return 0;
}