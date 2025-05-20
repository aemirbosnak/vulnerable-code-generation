//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];
    char *username, *password;

    // Prompt user for POP3 server address
    printf("Enter POP3 server address: ");
    scanf("%s", &argv[1]);

    // Prompt user for username and password
    printf("Enter username: ");
    scanf("%s", &username);

    printf("Enter password: ");
    scanf("%s", &password);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send login credentials
    sprintf(send_buffer, "USER %s\r\n", username);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    sprintf(send_buffer, "PASS %s\r\n", password);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Receive server response
    memset(recv_buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = '\0';
    printf("Server response: %s\n", recv_buffer);

    // Send LIST command
    sprintf(send_buffer, "LIST\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Receive server response
    memset(recv_buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = '\0';
    printf("Server response: %s\n", recv_buffer);

    // Close socket
    close(sockfd);

    return 0;
}