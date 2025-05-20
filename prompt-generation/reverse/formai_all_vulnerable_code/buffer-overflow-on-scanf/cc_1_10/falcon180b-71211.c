//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    char *ip_address;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int n;

    // Get user input for server IP and port number
    printf("Enter the server IP address: ");
    scanf("%s", ip_address);
    printf("Enter the port number: ");
    scanf("%d", &portno);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send commands to server
    while (1) {
        memset(send_buffer, 0, BUFFER_SIZE);
        memset(recv_buffer, 0, BUFFER_SIZE);

        printf("Enter command: ");
        scanf("%s", send_buffer);

        // Convert command to uppercase
        for (int i = 0; i < strlen(send_buffer); i++) {
            send_buffer[i] = toupper(send_buffer[i]);
        }

        // Send command to server
        n = send(sockfd, send_buffer, strlen(send_buffer), 0);
        if (n < 0) {
            printf("Error sending command\n");
            exit(1);
        }

        // Receive response from server
        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            printf("Error receiving response\n");
            exit(1);
        }

        // Print response from server
        printf("Server response: %s\n", recv_buffer);
    }

    // Close socket
    close(sockfd);
    return 0;
}