//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *) server->h_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server.\n");

    // Receive server greeting message
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);

    if (n < 0) {
        perror("ERROR receiving from server");
        exit(EXIT_FAILURE);
    }

    printf("Server: %s", buffer);

    // Send user credentials
    char username[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE];
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n"); // Remove trailing newline
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n"); // Remove trailing newline
    char auth[MAX_BUFFER_SIZE];
    sprintf(auth, "USER %s\r\nPASS %s\r\n", username, password);
    n = send(sockfd, auth, strlen(auth), 0);

    if (n < 0) {
        perror("ERROR sending to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to USER and PASS commands
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);

    if (n < 0) {
        perror("ERROR receiving from server");
        exit(EXIT_FAILURE);
    }

    printf("Server: %s", buffer);

    // Send STAT command to get mailbox status
    char stat[MAX_BUFFER_SIZE] = "STAT\r\n";
    n = send(sockfd, stat, strlen(stat), 0);

    if (n < 0) {
        perror("ERROR sending to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to STAT command
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);

    if (n < 0) {
        perror("ERROR receiving from server");
        exit(EXIT_FAILURE);
    }

    printf("Server: %s", buffer);

    // Parse response to STAT command
    int num_messages, mailbox_size;
    sscanf(buffer, "+OK %d %d", &num_messages, &mailbox_size);
    printf("There are %d messages in the mailbox, with a total size of %d bytes.\n", num_messages, mailbox_size);

    // Send LIST command to get a list of all messages
    char list[MAX_BUFFER_SIZE] = "LIST\r\n";
    n = send(sockfd, list, strlen(list), 0);

    if (n < 0) {
        perror("ERROR sending to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to LIST command
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);

    if (n < 0) {
        perror("ERROR receiving from server");
        exit(EXIT_FAILURE);
    }

    printf("Server: %s", buffer);

    // Parse response to LIST command
    int message_num, message_size;
    char *token = strtok(buffer, "\r\n"); // Skip first line
    printf("Message List:\n");

    while ((token = strtok(NULL, "\r\n")) != NULL) {
        sscanf(token, "%d %d", &message_num, &message_size);
        printf("Message %d: %d bytes\n", message_num, message_size);
    }

    // Retrieve a message by message number
    int message_num_to_retrieve;
    printf("Enter message number to retrieve: ");
    scanf("%d", &message_num_to_retrieve);
    char retr[MAX_BUFFER_SIZE];
    sprintf(retr, "RETR %d\r\n", message_num_to_retrieve);
    n = send(sockfd, retr, strlen(retr), 0);

    if (n < 0) {
        perror("ERROR sending to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to RETR command
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);

    if (n < 0) {
        perror("ERROR receiving from server");
        exit(EXIT_FAILURE);
    }

    printf("Server: %s", buffer);

    // Parse response to RETR command
    int message_size_to_retrieve;
    sscanf(buffer, "+OK %d octets", &message_size_to_retrieve);
    printf("Retrieving message %d with size %d...\n", message_num_to_retrieve, message_size_to_retrieve);

    // Receive message body
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);

    if (n < 0) {
        perror("ERROR receiving from server");
        exit(EXIT_FAILURE);
    }

    printf("Message body:\n%s", buffer);

    // Send QUIT command to close connection
    char quit[MAX_BUFFER_SIZE] = "QUIT\r\n";
    n = send(sockfd, quit, strlen(quit), 0);

    if (n < 0) {
        perror("ERROR sending to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to QUIT command
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);

    if (n < 0) {
        perror("ERROR receiving from server");
        exit(EXIT_FAILURE);
    }

    printf("Server: %s", buffer);

    close(sockfd);
    printf("Disconnected from POP3 server.\n");

    return 0;
}