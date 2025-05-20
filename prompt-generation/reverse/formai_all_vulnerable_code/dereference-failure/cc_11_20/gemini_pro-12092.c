//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Cyberpunk
// Welcome to the Neon City, runner!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

// Our cyberpunk IMAP client. Ready to hack into the megacorps!
int main(int argc, char** argv) {
    // Let's get into the shadows first...
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Establish a connection to the server. Better use a secure protocol!
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct hostent* host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Time to exchange some data. Let's initiate the IMAP session!
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int n;

    // We are ready for the server's greeting.
    if ((n = recv(sock, buffer, sizeof(buffer) - 1, 0)) == -1) {
        perror("recv");
        return 1;
    }

    // And we say hello back.
    snprintf(buffer, sizeof(buffer), "A C H E L L O %s\n", argv[1]);
    if ((n = send(sock, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return 1;
    }

    // Now we're ready to send commands.
    memset(buffer, 0, sizeof(buffer));
    printf("> ");
    while (fgets(buffer, sizeof(buffer) - 1, stdin) != NULL) {
        // First remove the newline character.
        buffer[strlen(buffer) - 1] = '\0';

        // And send the command to the server.
        if ((n = send(sock, buffer, strlen(buffer), 0)) == -1) {
            perror("send");
            return 1;
        }

        // Wait for the server's response.
        memset(buffer, 0, sizeof(buffer));
        if ((n = recv(sock, buffer, sizeof(buffer) - 1, 0)) == -1) {
            perror("recv");
            return 1;
        }

        // Let's decode the response.
        char* command = strtok(buffer, " ");
        if (strcmp(command, "OK") == 0) {
            printf("%s\n", buffer);
        } else if (strcmp(command, "NO") == 0) {
            printf("Error: %s\n", buffer);
        } else {
            printf("Unknown response: %s\n", buffer);
        }

        // And we're ready for the next command.
        memset(buffer, 0, sizeof(buffer));
        printf("> ");
    }

    // Closing the connection. We're done here.
    close(sock);

    return 0;
}