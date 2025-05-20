//Gemma-7B DATASET v1.0 Category: Building a HTTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char url[256];
    char method[64];
    char body[1024];
    int port = 8080;

    printf("Enter the URL: ");
    scanf("%s", url);

    printf("Enter the method (GET/POST/PUT/DELETE): ");
    scanf("%s", method);

    printf("Enter the body (optional): ");
    scanf("%s", body);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(url);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Send the request
    write(sockfd, method, strlen(method));
    write(sockfd, "\n", 1);

    if (body) {
        write(sockfd, body, strlen(body));
        write(sockfd, "\n", 1);
    }

    // Receive the response
    read(sockfd, buffer, 1024);

    // Print the response
    printf("Response: \n");
    printf("%s", buffer);

    close(sockfd);

    return 0;
}