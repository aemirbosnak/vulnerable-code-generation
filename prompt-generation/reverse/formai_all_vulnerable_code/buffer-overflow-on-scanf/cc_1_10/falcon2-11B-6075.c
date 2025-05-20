//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in server_addr;
    char buffer[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Default port for HTTP
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    printf("Enter the port number to scan (e.g. 80): ");
    scanf("%d", &portno);

    if (portno < 1 || portno > 65535) {
        printf("Invalid port number\n");
        exit(1);
    }

    n = sizeof(server_addr);
    if (getsockname(sockfd, (struct sockaddr *)&server_addr, &n) < 0) {
        perror("ERROR getting socket name");
        exit(1);
    }

    printf("Scanning port %d...\n", portno);
    send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n", 46, 0);
    if (recv(sockfd, buffer, 100, 0) > 0) {
        printf("Response: %s\n", buffer);
    } else {
        printf("Connection closed\n");
    }

    close(sockfd);

    return 0;
}