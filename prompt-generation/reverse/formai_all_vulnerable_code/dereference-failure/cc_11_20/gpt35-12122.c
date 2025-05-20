//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sock_fd, ret_val;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) { 
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported\n"); 
        exit(EXIT_FAILURE); 
    }

    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    // Receive greeting message from the server
    memset(&buffer, 0, BUF_SIZE);
    if ((ret_val = recv(sock_fd, buffer, BUF_SIZE, 0)) < 0) {
        fprintf(stderr, "Error receiving message from server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send username
    printf("Username: ");
    fgets(buffer, BUF_SIZE, stdin);
    if ((ret_val = send(sock_fd, buffer, strlen(buffer), 0)) < 0) {
        fprintf(stderr, "Error sending username to server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive password prompt from the server
    memset(&buffer, 0, BUF_SIZE);
    if ((ret_val = recv(sock_fd, buffer, BUF_SIZE, 0)) < 0) {
        fprintf(stderr, "Error receiving message from server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send password
    printf("Password: ");
    fgets(buffer, BUF_SIZE, stdin);
    if ((ret_val = send(sock_fd, buffer, strlen(buffer), 0)) < 0) {
        fprintf(stderr, "Error sending password to server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive authentication result from the server
    memset(&buffer, 0, BUF_SIZE);
    if ((ret_val = recv(sock_fd, buffer, BUF_SIZE, 0)) < 0) {
        fprintf(stderr, "Error receiving message from server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Enter main loop
    while(1) {
        printf("> ");
        memset(&buffer, 0, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);
        strtok(buffer, "\n"); // remove newline character
        if ((ret_val = send(sock_fd, buffer, strlen(buffer), 0)) < 0) {
            fprintf(stderr, "Error sending command to server: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        if (strncmp(buffer, "quit", 4) == 0) {
            printf("Goodbye!\n");
            break;
        }
        memset(&buffer, 0, BUF_SIZE);
        if ((ret_val = recv(sock_fd, buffer, BUF_SIZE, 0)) < 0) {
            fprintf(stderr, "Error receiving message from server: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        printf("%s", buffer);
    }

    // Close socket
    close(sock_fd);

    return 0;
}