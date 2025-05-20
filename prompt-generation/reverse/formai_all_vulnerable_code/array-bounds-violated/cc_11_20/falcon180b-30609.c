//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define MAX_URL_SIZE 2048

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    int opt = 1;
    char *url = NULL;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    // Allocate memory for the URL
    url = (char *)malloc(MAX_URL_SIZE * sizeof(char));
    if (url == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Copy the URL into the allocated memory
    strcpy(url, argv[1]);

    // Sanitize the URL
    int i = 0;
    while (url[i]!= '\0') {
        // Check if the character is valid
        if (isalnum(url[i]) || url[i] == '-') {
            i++;
        } else if (url[i] == '.' && (i == 0 || url[i-1] == '.')) {
            i++;
        } else if (url[i] == ':' && (i == 7 || url[i-1] == ':' || url[i-1] == ']')) {
            i++;
        } else if (url[i] == '[' || url[i] == ']') {
            i++;
        } else {
            // Replace invalid characters with underscores
            url[i] = '_';
        }
    }

    // Connect to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed!\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(8080);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection failed!\n");
        exit(1);
    }

    // Send the sanitized URL to the server
    send(sockfd, url, strlen(url), 0);

    // Receive the response from the server
    char response[MAX_LINE_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, MAX_LINE_SIZE, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    // Close the socket
    close(sockfd);

    return 0;
}