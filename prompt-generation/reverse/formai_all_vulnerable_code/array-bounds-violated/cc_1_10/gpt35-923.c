//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define MAX_RESPONSE_SIZE 100000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide a URL.\n");
        exit(1);
    }

    // Parse the URL
    char *url = argv[1];
    char *hostname;
    char *path;
    if (strlen(url) > 7 && strncmp(url, "http://", 7) == 0) {
        url += 7;
    }
    hostname = strtok(url, "/");
    path = strtok(NULL, "");

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Get the server's IP address
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        perror("Could not resolve hostname");
        exit(1);
    }
    struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;
    struct in_addr ip = *addr_list[0];

    // Connect to the server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = ip.s_addr;
    server.sin_port = htons(PORT);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Send the HTTP request
    char request[1000];
    sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Send failed");
        exit(1);
    }

    // Receive the response
    char response[MAX_RESPONSE_SIZE];
    int num_received = recv(sock, response, MAX_RESPONSE_SIZE - 1, 0);
    if (num_received < 0) {
        perror("Receive failed");
        exit(1);
    }
    response[num_received] = '\0';

    // Print the response
    printf("%s", response);

    // Close the socket
    close(sock);

    return 0;
}