//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define MAX_RESPONSE_SIZE 1024
#define MAX_COMMAND_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <user>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        printf("Invalid host\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(he->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the username and password
    char command[MAX_COMMAND_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", argv[2]);
    if (send(sock, command, strlen(command), 0) == -1) {
        perror("send");
        return 1;
    }

    char response[MAX_RESPONSE_SIZE];
    if (recv(sock, response, sizeof(response), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("Response: %s\n", response);

    // Close the socket
    close(sock);

    return 0;
}