//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int port = 80;
    char *host = "www.google.com";
    char *path = "/";
    char *request_method = "GET";
    char buffer[BUFFER_SIZE];

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("ERROR: Failed to create socket");
        exit(1);
    }

    // create server address struct
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_address.sin_addr);

    // connect to server
    int connected = connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));
    if (connected < 0) {
        perror("ERROR: Failed to connect to server");
        exit(1);
    }

    // create request string
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n",
             request_method, path, host);

    // send request
    int bytes_sent = send(sock, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("ERROR: Failed to send request");
        exit(1);
    }

    // read response
    int bytes_received = recv(sock, buffer, BUFFER_SIZE-1, 0);
    if (bytes_received < 0) {
        perror("ERROR: Failed to receive response");
        exit(1);
    }

    // print response
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // close socket
    close(sock);

    return 0;
}