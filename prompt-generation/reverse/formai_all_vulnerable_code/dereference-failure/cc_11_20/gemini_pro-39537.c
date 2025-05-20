//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define IMAP_PORT 143
#define BUF_SIZE 1024

// Error handling macro
#define DIE(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[])
{
    // Check for proper usage
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server> <port> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the server address and port
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Get the username and password
    char *username = argv[3];
    char *password = argv[4];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        DIE("socket");

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(server);
    if (host == NULL)
        DIE("gethostbyname");
    memcpy(&serv_addr.sin_addr, host->h_addr_list[0], host->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        DIE("connect");

    // Send the username
    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
        DIE("send");

    // Receive the response
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0)
        DIE("recv");

    // Check for success
    if (strncmp(buf, "+OK", 3) != 0)
        DIE("Authentication failed");

    // Send the password
    snprintf(buf, BUF_SIZE, "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
        DIE("send");

    // Receive the response
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0)
        DIE("recv");

    // Check for success
    if (strncmp(buf, "+OK", 3) != 0)
        DIE("Authentication failed");

    // Send the command to list the mailboxes
    snprintf(buf, BUF_SIZE, "LIST \"\" *\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
        DIE("send");

    // Receive the response
    while (1) {
        if (recv(sockfd, buf, BUF_SIZE, 0) < 0)
            DIE("recv");

        // Check for the end of the response
        if (strncmp(buf, "* OK", 3) == 0)
            break;

        // Print the mailbox name
        printf("%s", buf);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}