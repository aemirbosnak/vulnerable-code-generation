//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char *hostname = "localhost";
    int host_len;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Resolve hostname
    host_len = strlen(hostname);
    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send request
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    if (send(sock, request, strlen(request), 0) == -1) {
        printf("Error sending request\n");
        exit(1);
    }

    // Receive response
    int bytes_received = 0;
    while ((bytes_received < BUFFER_SIZE) && (recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0)!= -1)) {
        bytes_received += recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
    }
    buffer[bytes_received] = '\0';

    // Close socket
    close(sock);

    // Print response
    printf("Response:\n%s", buffer);

    return 0;
}