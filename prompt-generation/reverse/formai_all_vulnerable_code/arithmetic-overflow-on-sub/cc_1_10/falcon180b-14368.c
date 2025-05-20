//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *server_ip = "speedtest.net";
    int server_port = 80;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // Send request
    char *request = "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";
    if (send(sock, request, strlen(request), 0) == -1) {
        printf("Error sending request.\n");
        exit(1);
    }

    // Receive response
    bytes_received = 0;
    while ((bytes_received < BUFFER_SIZE) && (recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0) > 0)) {
        bytes_received += recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
    }
    buffer[bytes_received] = '\0';
    printf("Response:\n%s", buffer);

    // Close socket
    close(sock);

    return 0;
}