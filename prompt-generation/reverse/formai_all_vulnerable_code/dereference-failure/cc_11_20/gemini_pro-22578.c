//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define IMAP_PORT 143 // Standard IMAP port

int main(int argc, char** argv) {
    // Check for arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <username>\n", argv[0]);
        return 1;
    }

    // Convert hostname to IP address
    struct hostent* host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: Could not connect to server\n");
        return 1;
    }

    // Read the server's greeting
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    if (recv(sock, buf, sizeof(buf) - 1, 0) == -1) {
        fprintf(stderr, "Error: Could not receive server greeting\n");
        close(sock);
        return 1;
    }
    printf("Server greeting: %s\n", buf);

    // Send the login command
    sprintf(buf, "A001 LOGIN %s %s\n", argv[2], argv[3]); // A001 is the sequence number, LOGIN is the command, %s is the username, and %s is the password
    if (send(sock, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send login command\n");
        close(sock);
        return 1;
    }

    // Read the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sock, buf, sizeof(buf) - 1, 0) == -1) {
        fprintf(stderr, "Error: Could not receive login response\n");
        close(sock);
        return 1;
    }
    printf("Login response: %s\n", buf);

    if (strcmp(buf, "+OK LOGIN successful\n") != 0) {
        fprintf(stderr, "Error: Login failed\n");
        close(sock);
        return 1;
    }

    // Send the LIST command
    sprintf(buf, "A002 LIST \"\" *\n"); // A002 is the sequence number, LIST is the command, "" is the mailbox name, and * is the wildcard for all messages
    if (send(sock, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send LIST command\n");
        close(sock);
        return 1;
    }

    // Read the server's response
    while (1) {
        memset(buf, 0, sizeof(buf));
        if (recv(sock, buf, sizeof(buf) - 1, 0) == -1) {
            fprintf(stderr, "Error: Could not receive LIST response\n");
            close(sock);
            return 1;
        }
        if (strcmp(buf, "* OK LIST completed\n") == 0) {
            break;
        }
        printf("Message: %s\n", buf);
    }

    // Close the socket
    close(sock);

    return 0;
}