//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 4096
#define MAX_CMD_SIZE 1024

int main(int argc, char *argv[]) {

    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get host and port
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Connect to server
    struct hostent *he = gethostbyname(server);
    if (he == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", server);
        exit(EXIT_FAILURE);
    }
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Login
    char buff[MAX_BUFF_SIZE];
    ssize_t nrecv = recv(sockfd, buff, MAX_BUFF_SIZE - 1, 0);
    buff[nrecv] = '\0';
    printf("%s\n", buff);

    char username[MAX_CMD_SIZE];
    char password[MAX_CMD_SIZE];
    printf("Username: ");
    scanf("%s", username);
    send(sockfd, username, strlen(username), 0);

    nrecv = recv(sockfd, buff, MAX_BUFF_SIZE - 1, 0);
    buff[nrecv] = '\0';

    printf("%s\n", buff);
    printf("Password: ");
    scanf("%s", password);
    send(sockfd, password, strlen(password), 0);

    nrecv = recv(sockfd, buff, MAX_BUFF_SIZE - 1, 0);
    buff[nrecv] = '\0';

    if (strncmp(buff, "OK", 2) != 0) {
        printf("Login failed: %s\n", buff);
        exit(EXIT_FAILURE);
    }

    // List mailboxes
    send(sockfd, "LIST \"\" *\r\n", strlen("LIST \"\" *\r\n"), 0);
    nrecv = recv(sockfd, buff, MAX_BUFF_SIZE - 1, 0);
    buff[nrecv] = '\0';
    printf("%s\n", buff);

    // Select mailbox
    char mailbox[MAX_CMD_SIZE];
    printf("Mailbox: ");
    scanf("%s", mailbox);

    char cmd[MAX_CMD_SIZE];
    sprintf(cmd, "SELECT %s\r\n", mailbox);
    send(sockfd, cmd, strlen(cmd), 0);

    nrecv = recv(sockfd, buff, MAX_BUFF_SIZE - 1, 0);
    buff[nrecv] = '\0';
    printf("%s\n", buff);

    while (1) {
        // Prompt user for command
        char command[MAX_CMD_SIZE];
        printf("> ");
        scanf("%s", command);

        if (strncmp(command, "LIST", 4) == 0) {
            // List messages
            send(sockfd, "FETCH 1:* (FLAGS BODY.PEEK[HEADER.FIELDS (FROM SUBJECT DATE)])\r\n", strlen("FETCH 1:* (FLAGS BODY.PEEK[HEADER.FIELDS (FROM SUBJECT DATE)])\r\n"), 0);
            nrecv = recv(sockfd, buff, MAX_BUFF_SIZE - 1, 0);
            buff[nrecv] = '\0';
            printf("%s\n", buff);
        } else if (strncmp(command, "RETR", 4) == 0) {
            // Retrieve message
            char msg[MAX_CMD_SIZE];
            printf("Message ID: ");
            scanf("%s", msg);
            sprintf(cmd, "FETCH %s BODY[TEXT]\r\n", msg);
            send(sockfd, cmd, strlen(cmd), 0);
            nrecv = recv(sockfd, buff, MAX_BUFF_SIZE - 1, 0);
            buff[nrecv] = '\0';
            printf("%s\n", buff);
        } else if (strncmp(command, "QUIT", 4) == 0) {
            // Quit
            send(sockfd, "LOGOUT\r\n", strlen("LOGOUT\r\n"), 0);
            nrecv = recv(sockfd, buff, MAX_BUFF_SIZE - 1, 0);
            buff[nrecv] = '\0';
            printf("%s\n", buff);
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}