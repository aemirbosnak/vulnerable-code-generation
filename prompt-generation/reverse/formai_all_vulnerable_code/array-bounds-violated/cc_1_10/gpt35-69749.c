//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_SIZE 1024

int connect_to_server(const char* hostname, const char* port) {
    struct addrinfo hints, *result, *rp;
    int sfd, s;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    s = getaddrinfo(hostname, port, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd == -1)
            continue;

        if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break; /* Success */

        close(sfd);
    }

    freeaddrinfo(result);

    if (rp == NULL) {
        fprintf(stderr, "Could not connect to server %s:%s.\n", hostname, port);
        return -1;
    }

    return sfd;
}

void parse_server_response(int server_fd) {
    char buffer[MAX_SIZE];
    int num_bytes;

    while ((num_bytes = recv(server_fd, buffer, MAX_SIZE - 1, 0)) > 0) {
        buffer[num_bytes] = '\0';
        printf("%s", buffer);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: %s hostname port username password\n", argv[0]);
        return -1;
    }

    char* hostname = argv[1];
    char* port = argv[2];
    char* username = argv[3];
    char* password = argv[4];

    int server_fd = connect_to_server(hostname, port);
    if (server_fd == -1)
        return -1;

    char buffer[MAX_SIZE];
    int num_bytes;

    // Wait for server greeting.
    parse_server_response(server_fd);

    // Send login information.
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    send(server_fd, buffer, strlen(buffer), 0);
    parse_server_response(server_fd);

    // Send list command to get mailbox list.
    sprintf(buffer, "LIST \"\" *\r\n");
    send(server_fd, buffer, strlen(buffer), 0);
    parse_server_response(server_fd);

    // Send select command to select inbox.
    sprintf(buffer, "SELECT INBOX\r\n");
    send(server_fd, buffer, strlen(buffer), 0);
    parse_server_response(server_fd);

    // Send search command to search for unseen messages.
    sprintf(buffer, "SEARCH UNSEEN\r\n");
    send(server_fd, buffer, strlen(buffer), 0);
    parse_server_response(server_fd);

    // Close connection to server.
    sprintf(buffer, "LOGOUT\r\n");
    send(server_fd, buffer, strlen(buffer), 0);
    close(server_fd);

    return 0;
}