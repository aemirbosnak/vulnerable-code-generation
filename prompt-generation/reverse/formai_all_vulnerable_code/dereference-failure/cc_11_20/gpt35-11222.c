//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 4096

int main(int argc, char* argv[]) {
    // check if user inputs hostname and port number
    if (argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    char* hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent* host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        printf("Error: no such host as %s\n", hostname);
        exit(1);
    }
    // create a socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: can't create socket");
        exit(1);
    }
    // connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr*)host_info->h_addr;
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: can't connect to server");
        exit(1);
    }
    // read response from server
    char recvline[MAX_LINE] = {0};
    if (read(sockfd, recvline, MAX_LINE) < 0) {
        perror("Error: can't read response from server");
        exit(1);
    }
    printf("%s", recvline);

    // send request to server
    char* command = "USER username\r\n";
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error: can't send request to server");
        exit(1);
    }
    memset(&recvline, 0, sizeof(recvline));
    if (read(sockfd, recvline, MAX_LINE) < 0) {
        perror("Error: can't read response from server");
        exit(1);
    }
    printf("%s", recvline);

    // send request to server
    command = "PASS password\r\n";
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error: can't send request to server");
        exit(1);
    }
    memset(&recvline, 0, sizeof(recvline));
    if (read(sockfd, recvline, MAX_LINE) < 0) {
        perror("Error: can't read response from server");
        exit(1);
    }
    printf("%s", recvline);

    // send request to server
    command = "STAT\r\n";
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error: can't send request to server");
        exit(1);
    }
    memset(&recvline, 0, sizeof(recvline));
    if (read(sockfd, recvline, MAX_LINE) < 0) {
        perror("Error: can't read response from server");
        exit(1);
    }
    printf("%s", recvline);

    // send request to server
    command = "LIST\r\n";
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error: can't send request to server");
        exit(1);
    }
    int n;
    do {
        memset(&recvline, 0, sizeof(recvline));
        if ((n = read(sockfd, recvline, MAX_LINE)) < 0) {
            perror("Error: can't read response from server");
            exit(1);
        }
        printf("%s", recvline);
    } while (n != 0 && recvline[n - 1] != '\n');

    // send request to server
    command = "QUIT\r\n";
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error: can't send request to server");
        exit(1);
    }
    memset(&recvline, 0, sizeof(recvline));
    if (read(sockfd, recvline, MAX_LINE) < 0) {
        perror("Error: can't read response from server");
        exit(1);
    }
    printf("%s", recvline);

    // close the socket
    close(sockfd);

    return 0;
}