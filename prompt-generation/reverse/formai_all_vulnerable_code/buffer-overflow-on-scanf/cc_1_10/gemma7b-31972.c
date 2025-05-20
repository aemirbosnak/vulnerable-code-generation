//Gemma-7B DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

int main() {
    int sockfd, port, len, n, i, buflen = 1024;
    char buf[buflen], msg[buflen], server_ip[buflen];
    struct sockaddr_in serv_addr;

    // Get server IP and port
    printf("Enter server IP: ");
    scanf("%s", server_ip);
    printf("Enter port: ");
    scanf("%d", &port);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send message
    printf("Enter your message: ");
    scanf("%s", msg);

    n = write(sockfd, msg, strlen(msg) + 1);
    if (n < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Receive response
    len = read(sockfd, buf, buflen);
    if (len < 0) {
        perror("Error receiving response");
        exit(1);
    }

    // Print response
    printf("Server's response: %s\n", buf);

    // Close socket
    close(sockfd);

    return 0;
}