//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define POP3_PORT 110
#define USER "your_username"
#define PASS "your_password"

int main(int argc, char *argv[]) {
    int sock, n;
    char buf[MAX_LINE];
    struct sockaddr_in server_addr;
    char *hostname = "pop.gmail.com";
    int port = POP3_PORT;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send USER command
    send(sock, USER, strlen(USER), 0);

    // Send PASS command
    send(sock, PASS, strlen(PASS), 0);

    // Receive server response
    n = recv(sock, buf, MAX_LINE, 0);
    if (n <= 0) {
        printf("Error receiving server response\n");
        exit(1);
    }
    buf[n] = '\0';
    printf("Server response: %s\n", buf);

    // Send QUIT command
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    // Close socket
    close(sock);

    return 0;
}