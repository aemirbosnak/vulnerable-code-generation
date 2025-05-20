//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER 1024
#define MAX_HOSTNAME 256

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: Unable to resolve hostname '%s'\n", hostname);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Unable to create socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        return 1;
    }

    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);

    printf("Enter message to send to server: ");
    fgets(buffer, MAX_BUFFER, stdin);

    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send message to server\n");
        return 1;
    }

    memset(buffer, 0, MAX_BUFFER);

    if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        printf("Error: Unable to receive message from server\n");
        return 1;
    }

    printf("Received message from server: %s\n", buffer);

    close(sock);

    return 0;
}