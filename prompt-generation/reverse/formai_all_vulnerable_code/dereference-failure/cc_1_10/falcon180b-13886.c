//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024
#define USERNAME "username"
#define PASSWORD "password"

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int n;

    // Resolve the server hostname or IP address
    host = gethostbyname("pop.gmail.com");
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname\n");
        return 1;
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: could not create socket\n");
        return 1;
    }

    // Connect to the server
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "Error: could not connect to server\n");
        close(sock);
        return 1;
    }

    // Send the USER command
    sprintf(buffer, "USER %s\r\n", USERNAME);
    send(sock, buffer, strlen(buffer), 0);

    // Send the PASS command
    sprintf(buffer, "PASS %s\r\n", PASSWORD);
    send(sock, buffer, strlen(buffer), 0);

    // Receive the server response
    memset(response, 0, BUFFER_SIZE);
    n = recv(sock, response, BUFFER_SIZE, 0);
    if (n <= 0) {
        fprintf(stderr, "Error: could not receive response\n");
        close(sock);
        return 1;
    }

    // Print the server response
    printf("Server response: %s", response);

    // Close the socket
    close(sock);
    return 0;
}