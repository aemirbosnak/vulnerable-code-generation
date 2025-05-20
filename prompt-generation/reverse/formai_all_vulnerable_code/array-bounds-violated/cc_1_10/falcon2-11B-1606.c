//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int sockfd, new_socket, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[BUF_SIZE];
    int len;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Prepare server address struct
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Simple Web Server\n");
    while(1) {
        // Accept connection
        if ((new_socket = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &len)) < 0) {
            perror("accept");
            exit(1);
        }

        // Receive data
        bzero(buf, sizeof(buf));
        n = recv(new_socket, buf, sizeof(buf) - 1, 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }
        buf[n] = '\0';

        // Process request
        if (strcmp(buf, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n") == 0) {
            printf("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
            printf("<h1>Hello World!</h1>");
        }
        else if (strcmp(buf, "GET /index.html HTTP/1.1\r\nHost: localhost\r\n\r\n") == 0) {
            printf("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
            printf("<h1>Welcome to my website!</h1>");
        }
        else if (strcmp(buf, "GET /image.jpg HTTP/1.1\r\nHost: localhost\r\n\r\n") == 0) {
            printf("HTTP/1.1 200 OK\r\nContent-Type: image/jpeg\r\n\r\n");
            printf("Hello World!");
        }
        else {
            printf("HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n");
            printf("<h1>404 Not Found</h1>");
        }

        // Close connection
        close(new_socket);
    }

    return 0;
}