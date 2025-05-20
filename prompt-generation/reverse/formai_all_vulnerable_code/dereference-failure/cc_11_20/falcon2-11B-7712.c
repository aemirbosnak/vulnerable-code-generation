//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 12345

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_or_client>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "server") == 0) {
        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket failed");
            exit(1);
        }

        // Prepare the server socket
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(PORT);
        if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("bind failed");
            exit(1);
        }
        if (listen(sockfd, 5) < 0) {
            perror("listen failed");
            exit(1);
        }
        printf("Server is listening on port %d...\n", PORT);

        // Accept incoming connections
        int client_sockfd;
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);
        if (client_sockfd < 0) {
            perror("accept failed");
            exit(1);
        }
        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive and send data
        char buffer[1024];
        while (1) {
            int bytes_read = recv(client_sockfd, buffer, sizeof(buffer), 0);
            if (bytes_read < 0) {
                perror("recv failed");
                exit(1);
            }
            buffer[bytes_read] = '\0';
            printf("Received: %s\n", buffer);
            if (strcmp(buffer, "exit") == 0) {
                break;
            }
            send(client_sockfd, buffer, strlen(buffer), 0);
        }

        close(client_sockfd);
        exit(0);
    }

    else if (strcmp(argv[1], "client") == 0) {
        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket failed");
            exit(1);
        }

        // Prepare the client socket
        struct hostent *server = gethostbyname("localhost");
        if (server == NULL) {
            fprintf(stderr, "Host not found\n");
            exit(1);
        }
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(PORT);

        // Connect to the server
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect failed");
            exit(1);
        }
        printf("Connected to server\n");

        // Send and receive data
        char buffer[1024];
        while (1) {
            printf("Enter a message: ");
            scanf("%s", buffer);
            if (strcmp(buffer, "exit") == 0) {
                break;
            }
            printf("Sending: %s\n", buffer);
            send(sockfd, buffer, strlen(buffer), 0);
            int bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
            if (bytes_read < 0) {
                perror("recv failed");
                exit(1);
            }
            printf("Received: %s\n", buffer);
        }

        close(sockfd);
        exit(0);
    }

    else {
        fprintf(stderr, "Invalid command line argument\n");
        exit(1);
    }

    return 0;
}