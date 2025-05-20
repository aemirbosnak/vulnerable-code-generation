//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFSIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    // Get the server address and port
    struct sockaddr_in server_addr;
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
        return 1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Create a socket and connect to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: could not create socket\n");
        return 1;
    }
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: could not connect to server\n");
        return 1;
    }

    // Read the welcome message from the server
    char buf[BUFSIZE];
    int bytes_read = recv(sock, buf, BUFSIZE, 0);
    if (bytes_read == -1) {
        fprintf(stderr, "Error: could not read welcome message from server\n");
        return 1;
    }
    printf("%s", buf);

    // Send the username and password to the server
    char username[BUFSIZE];
    char password[BUFSIZE];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(buf, "USER %s\r\n", username);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: could not send username to server\n");
        return 1;
    }
    bytes_read = recv(sock, buf, BUFSIZE, 0);
    if (bytes_read == -1) {
        fprintf(stderr, "Error: could not receive response from server after sending username\n");
        return 1;
    }
    printf("%s", buf);
    sprintf(buf, "PASS %s\r\n", password);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: could not send password to server\n");
        return 1;
    }
    bytes_read = recv(sock, buf, BUFSIZE, 0);
    if (bytes_read == -1) {
        fprintf(stderr, "Error: could not receive response from server after sending password\n");
        return 1;
    }
    printf("%s", buf);

    // List the emails on the server
    if (send(sock, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        fprintf(stderr, "Error: could not send LIST command to server\n");
        return 1;
    }
    bytes_read = recv(sock, buf, BUFSIZE, 0);
    if (bytes_read == -1) {
        fprintf(stderr, "Error: could not receive response from server after sending LIST command\n");
        return 1;
    }
    printf("%s", buf);

    // Retrieve the first email
    if (send(sock, "RETR 1\r\n", strlen("RETR 1\r\n"), 0) == -1) {
        fprintf(stderr, "Error: could not send RETR command to server\n");
        return 1;
    }
    bytes_read = recv(sock, buf, BUFSIZE, 0);
    if (bytes_read == -1) {
        fprintf(stderr, "Error: could not receive response from server after sending RETR command\n");
        return 1;
    }
    printf("%s", buf);

    // Close the socket and exit
    close(sock);
    return 0;
}