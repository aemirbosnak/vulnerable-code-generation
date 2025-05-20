//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char username[100];
    char password[100];
    int n, i;
    char *ptr;

    if (argc!= 6) {
        printf("Usage:./pop3 <server_ip> <server_port> <username> <password> <command>\n");
        exit(1);
    }

    // Convert server IP and port to network byte order
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    // Connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    // Send username and password
    strcpy(buffer, "USER ");
    strcat(buffer, argv[3]);
    strcat(buffer, "\r\n");
    write(sockfd, buffer, strlen(buffer));

    strcpy(buffer, "PASS ");
    strcat(buffer, argv[4]);
    strcat(buffer, "\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Send command
    strcpy(buffer, argv[5]);
    strcat(buffer, "\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Receive response
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        printf("Error: Failed to read response\n");
        exit(1);
    }
    printf("Response: %s", buffer);

    close(sockfd);
    exit(0);
}