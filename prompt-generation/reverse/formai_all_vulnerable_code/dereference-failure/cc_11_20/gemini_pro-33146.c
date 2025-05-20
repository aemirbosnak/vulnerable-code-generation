//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const char POP3_PORT[] = "110";

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *username = argv[2];

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(POP3_PORT));
    inet_pton(AF_INET, host, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the welcome message from the server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the USER command
    const char USER_CMD[] = "USER ";
    send(sockfd, USER_CMD, strlen(USER_CMD), 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    // Read the response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the PASS command
    const char PASS_CMD[] = "PASS ";
    char password[1024];
    memset(password, 0, sizeof(password));
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    send(sockfd, PASS_CMD, strlen(PASS_CMD), 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    // Read the response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the LIST command
    const char LIST_CMD[] = "LIST\r\n";
    send(sockfd, LIST_CMD, strlen(LIST_CMD), 0);

    // Read the response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Parse the response from the server
    int num_messages = 0;
    int message_sizes[1024];
    char *line = strtok(buffer, "\r\n");
    while (line != NULL) {
        if (strncmp(line, "+OK", 3) == 0) {
            num_messages++;
        } else if (strncmp(line, " ", 1) == 0) {
            message_sizes[num_messages - 1] = atoi(line);
        }
        line = strtok(NULL, "\r\n");
    }

    // Print the list of messages
    printf("Messages:\n");
    for (int i = 0; i < num_messages; i++) {
        printf("  %d. %d bytes\n", i + 1, message_sizes[i]);
    }

    // Send the QUIT command
    const char QUIT_CMD[] = "QUIT\r\n";
    send(sockfd, QUIT_CMD, strlen(QUIT_CMD), 0);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}