//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_RESPONSE_SIZE 4096
#define SERVER_PORT 80
#define SERVER_IP "93.184.216.34" // Example.com IP for demonstration

void checkResponse(const char *response) {
    if (strstr(response, "200 OK")) {
        printf("Response received: Success - 200 OK\n");
    } else {
        printf("Unexpected response: %s\n", response);
    }
}

void futuristicHttpClient(const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    char request[256];
    char response[MAX_RESPONSE_SIZE];
    NULL;

    // Creating the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Constructing the HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", path, SERVER_IP);

    // Sending the request
    send(sock, request, strlen(request), 0);

    // Receiving the response
    int bytes_received = recv(sock, response, MAX_RESPONSE_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Response not received");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Null-terminate the received data
    response[bytes_received] = '\0';

    // Displaying the response
    printf("Response:\n%s\n", response);
    checkResponse(response);

    // Closing the socket
    close(sock);
}

void runFuturisticClient() {
    printf("=====================================================\n");
    printf("  Welcome to the Futuristic HTTP Client Program!    \n");
    printf("=====================================================\n");
    printf("This client connects to a distant server and fetches \n");
    printf("resources from the vast ocean of the intergalactic web.\n\n");

    // Simulation of various resource paths to fetch
    const char *paths[] = {
        "/index.html",
        "/about.html",
        "/contact.html",
        "/nonexistent.html" // This path is deliberately wrong
    };

    // Fetching resources sequentially
    for (int i = 0; i < sizeof(paths) / sizeof(paths[0]); i++) {
        printf("Fetching resource at: %s\n", paths[i]);
        futuristicHttpClient(paths[i]);
        printf("-----------------------------------------------------\n");
    }
    printf("=====================================================\n");
    printf("Thank you for using this futuristic HTTP Client!\n");
    printf("=====================================================\n");
}

int main() {
    runFuturisticClient();
    return 0;
}