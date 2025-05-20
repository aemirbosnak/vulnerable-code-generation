//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_REQUEST_SIZE 10240 // maximum size of a HTTP request
#define MAX_RESPONSE_SIZE 102400 // maximum size for a HTTP response

int main() {
    char request[MAX_REQUEST_SIZE]; // request buffer
    char response[MAX_RESPONSE_SIZE]; // response buffer
    char host[256]; // domain name
    char path[256]; // path to resource
    int port = 80; // default HTTP port
    int sock; // socket file descriptor
    struct sockaddr_in server; // server address struct

    printf("Welcome to HTTP Client!\n");

    // get user input
    printf("Enter the domain name: ");
    fgets(host, sizeof(host), stdin);
    host[strcspn(host, "\n")] = 0; // remove newline character
    printf("Enter the path to the resource: ");
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = 0; // remove newline character
    printf("Enter the port number (default is 80): ");
    scanf("%d", &port);
    getchar(); // remove trailing newline

    // create the request
    sprintf(request, "GET %s HTTP/1.1\r\n"
                      "Host: %s\r\n"
                      "Connection: close\r\n"
                      "\r\n", path, host);

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        return -1;
    }

    // set server address
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    // send request to server
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        return -1;
    }

    // receive response from server
    if (recv(sock, response, MAX_RESPONSE_SIZE, 0) < 0) {
        perror("Error receiving response");
        return -1;
    }

    // print the response
    printf("Response:\n%s", response);

    // close socket
    close(sock);

    return 0;
}