//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_BUFF_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, bytes;
    char *domain, *username, *password, userpass[MAX_BUFF_SIZE], buffer[MAX_BUFF_SIZE], command[MAX_BUFF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 4) {
        printf("Usage: %s <mail_domain> <username> <password>\n", argv[0]);
        exit(1);
    }

    domain = argv[1];
    username = argv[2];
    password = argv[3];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(2);
    }

    // Get server IP address
    server = gethostbyname(domain);
    if (server == NULL) {
        perror("Error getting host");
        exit(3);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    serv_addr.sin_port = htons(110); // POP3 default port

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(4);
    }

    // Authenticate with userpass
    snprintf(userpass, MAX_BUFF_SIZE, "USER %s\r\n", username);
    send(sockfd, userpass, strlen(userpass), 0);
    bytes = recv(sockfd, buffer, MAX_BUFF_SIZE - 1, 0);
    buffer[bytes] = '\0';
    printf("%s", buffer);
    snprintf(userpass, MAX_BUFF_SIZE, "PASS %s\r\n", password);
    send(sockfd, userpass, strlen(userpass), 0);
    bytes = recv(sockfd, buffer, MAX_BUFF_SIZE - 1, 0);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // List all emails
    snprintf(command, MAX_BUFF_SIZE, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);
    bytes = recv(sockfd, buffer, MAX_BUFF_SIZE - 1, 0);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    close(sockfd);
    return 0;
}