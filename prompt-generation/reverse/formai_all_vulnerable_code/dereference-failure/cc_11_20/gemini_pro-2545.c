//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Introspective - A self-aware POP3 client that monitors its own behavior and reports on its actions.

int main(int argc, char *argv[]) {
    // Introspective - Announce the start of the program.
    printf("POP3 Client: Starting up...\n");

    // Check for the correct number of arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Introspective - Announce the server and port.
    printf("POP3 Client: Connecting to %s:%s...\n", argv[1], argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the socket creation.
    printf("POP3 Client: Socket created.\n");

    // Get the server address.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the server address.
    printf("POP3 Client: Server address: %s:%d\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));

    // Introspective - Announce the connection attempt.
    printf("POP3 Client: Attempting to connect...\n");

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the connection success.
    printf("POP3 Client: Connected.\n");

    // Introspective - Announce the reception of the welcome message.
    printf("POP3 Client: Receiving welcome message...\n");

    // Receive the welcome message.
    char buf[1024];
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the welcome message.
    printf("POP3 Client: Welcome message: %s\n", buf);

    // Introspective - Announce the sending of the USER command.
    printf("POP3 Client: Sending USER command...\n");

    // Send the USER command.
    const char *user = "username";
    if (send(sockfd, "USER ", strlen("USER ") + strlen(user), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (send(sockfd, user, strlen(user), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (send(sockfd, "\r\n", strlen("\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the reception of the USER response.
    printf("POP3 Client: Receiving USER response...\n");

    // Receive the USER response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the USER response.
    printf("POP3 Client: USER response: %s\n", buf);

    // Introspective - Announce the sending of the PASS command.
    printf("POP3 Client: Sending PASS command...\n");

    // Send the PASS command.
    const char *pass = "password";
    if (send(sockfd, "PASS ", strlen("PASS ") + strlen(pass), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (send(sockfd, pass, strlen(pass), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (send(sockfd, "\r\n", strlen("\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the reception of the PASS response.
    printf("POP3 Client: Receiving PASS response...\n");

    // Receive the PASS response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the PASS response.
    printf("POP3 Client: PASS response: %s\n", buf);

    // Introspective - Announce the sending of the LIST command.
    printf("POP3 Client: Sending LIST command...\n");

    // Send the LIST command.
    if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the reception of the LIST response.
    printf("POP3 Client: Receiving LIST response...\n");

    // Receive the LIST response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the LIST response.
    printf("POP3 Client: LIST response: %s\n", buf);

    // Introspective - Announce the sending of the RETR command.
    printf("POP3 Client: Sending RETR command...\n");

    // Send the RETR command.
    if (send(sockfd, "RETR 1\r\n", strlen("RETR 1\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the reception of the RETR response.
    printf("POP3 Client: Receiving RETR response...\n");

    // Receive the RETR response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the RETR response.
    printf("POP3 Client: RETR response: %s\n", buf);

    // Introspective - Announce the sending of the QUIT command.
    printf("POP3 Client: Sending QUIT command...\n");

    // Send the QUIT command.
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the reception of the QUIT response.
    printf("POP3 Client: Receiving QUIT response...\n");

    // Receive the QUIT response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Introspective - Announce the QUIT response.
    printf("POP3 Client: QUIT response: %s\n", buf);

    // Introspective - Announce the closing of the socket.
    printf("POP3 Client: Closing socket.\n");

    // Close the socket.
    close(sockfd);

    // Introspective - Announce the end of the program.
    printf("POP3 Client: Shutting down...\n");

    return EXIT_SUCCESS;
}