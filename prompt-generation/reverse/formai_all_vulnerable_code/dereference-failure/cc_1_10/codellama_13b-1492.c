//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: shape shifting
// Email Client in Shape Shifting Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFSIZE 1024
#define MAX_LINE 256
#define MAX_HEADERS 10

typedef struct {
    char name[MAX_LINE];
    char value[MAX_LINE];
} Header;

typedef struct {
    Header headers[MAX_HEADERS];
    char body[BUFSIZE];
} Email;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        return 1;
    }

    // Receive the email
    Email email;
    memset(&email, 0, sizeof(email));
    int bytes_read = recv(sock, &email, sizeof(email), 0);
    if (bytes_read < 0) {
        perror("recv()");
        return 1;
    }

    // Print the email headers
    for (int i = 0; i < MAX_HEADERS; i++) {
        if (strlen(email.headers[i].name) == 0) {
            break;
        }
        printf("%s: %s\n", email.headers[i].name, email.headers[i].value);
    }

    // Print the email body
    printf("%s\n", email.body);

    // Close the socket
    close(sock);

    return 0;
}