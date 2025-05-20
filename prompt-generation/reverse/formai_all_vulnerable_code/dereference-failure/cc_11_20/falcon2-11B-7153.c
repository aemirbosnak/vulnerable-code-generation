//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, portno, new_fd, addrlen;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char *html_files[] = { "index.html", "page1.html", "page2.html", NULL };

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    for (;;) {
        new_fd = accept(sockfd, (struct sockaddr *) &serv_addr, &addrlen);
        if (new_fd < 0) {
            perror("accept");
            continue;
        }

        if (recv(new_fd, buffer, sizeof(buffer), 0) < 0) {
            perror("recv");
            close(new_fd);
            continue;
        }

        printf("Client connected\n");
        printf("Request: %s\n", buffer);

        if (strcmp(buffer, "GET / HTTP/1.0\r\n\r\n") == 0) {
            printf("GET request\n");
            for (int i = 0; html_files[i]!= NULL; i++) {
                if (strcmp(buffer, "GET /") == 0) {
                    snprintf(buffer, sizeof(buffer), "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>");
                    break;
                }
                if (strcmp(buffer, "GET /page1.html") == 0) {
                    snprintf(buffer, sizeof(buffer), "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Page 1</h1></body></html>");
                    break;
                }
                if (strcmp(buffer, "GET /page2.html") == 0) {
                    snprintf(buffer, sizeof(buffer), "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Page 2</h1></body></html>");
                    break;
                }
            }
            printf("Serving HTML file\n");
            if (write(new_fd, buffer, strlen(buffer)) < 0) {
                perror("write");
                close(new_fd);
                continue;
            }
            close(new_fd);
        }
        else {
            printf("Invalid request\n");
            snprintf(buffer, sizeof(buffer), "HTTP/1.0 400 Bad Request\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Bad Request</h1></body></html>");
            printf("Sending response\n");
            if (write(new_fd, buffer, strlen(buffer)) < 0) {
                perror("write");
                close(new_fd);
                continue;
            }
            close(new_fd);
        }
    }

    close(sockfd);

    return 0;
}