//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

typedef struct message {
    char sender[50];
    char subject[100];
    char body[BUFFER_SIZE];
} Message;

/*
    Function to connect to the IMAP server and authenticate the user
*/
int connectToServer(char *server, int port, char *username, char *password) {
    int sockfd;
    struct sockaddr_in server_address;
    struct hostent *server_info;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket: ");
        exit(1);
    }

    server_info = gethostbyname(server);
    if (server_info == NULL) {
        fprintf(stderr, "Error: Unknown host '%s'\n", server);
        exit(1);
    }

    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server_info->h_addr_list[0],
          (char *)&server_address.sin_addr.s_addr,
          server_info->h_length);
    server_address.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server: ");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    bzero(buffer, BUFFER_SIZE);

    // Send LOGIN command to server to authenticate user
    char login[BUFFER_SIZE];
    sprintf(login, "LOGIN %s %s\r\n", username, password);
    send(sockfd, login, strlen(login), 0);
    bzero(login, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    return sockfd;
}

/*
    Function to fetch a list of all messages in the INBOX
*/
void listAllMessages(int sockfd) {
    char buffer[BUFFER_SIZE];
    char list_command[BUFFER_SIZE];
    sprintf(list_command, "LIST \"\" INBOX\r\n");
    send(sockfd, list_command, strlen(list_command), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
}

/*
    Function to fetch the content of a specific email
*/
Message getMessage(int sockfd, int message_num) {
    Message msg;
    char buffer[BUFFER_SIZE];
    char fetch_command[BUFFER_SIZE];
    sprintf(fetch_command, "FETCH %d BODY[]\r\n", message_num);
    send(sockfd, fetch_command, strlen(fetch_command), 0);

    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    char *token;
    token = strtok(buffer, "\n");
    while (token != NULL) {
        if (strstr(token, "From:")) {
            sscanf(token, "From: %s", msg.sender);
        } else if (strstr(token, "Subject:")) {
            sscanf(token, "Subject: %s", msg.subject);
        }
        token = strtok(NULL, "\n");
    }

    int i = 0;
    while (strstr(token, "{") == NULL) {
        token = strtok(NULL, "\n");
    }

    char *size_str = strtok(token, "{}");
    int message_size = atoi(size_str);

    bzero(msg.body, BUFFER_SIZE);
    while (i < message_size) {
        recv(sockfd, &msg.body[i], 1, 0);
        i++;
    }
    msg.body[i] = '\0';

    return msg;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: <program> <server> <port> <username> <password>\n");
        return 1;
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    int sockfd = connectToServer(server, port, username, password);

    listAllMessages(sockfd);

    int message_num;
    printf("Enter message number to view (or -1 to quit): ");
    scanf("%d", &message_num);

    while (message_num != -1) {
        if (message_num < 1) {
            printf("Invalid message number. Please try again.\n");
        } else {
            Message msg = getMessage(sockfd, message_num);
            printf("\nFrom: %s\n", msg.sender);
            printf("Subject: %s\n", msg.subject);
            printf("Message:\n%s\n", msg.body);
        }
        printf("\nEnter message number to view (or -1 to quit): ");
        scanf("%d", &message_num);
    }

    // Close connection
    char logout[BUFFER_SIZE];
    sprintf(logout, "LOGOUT\r\n");
    send(sockfd, logout, strlen(logout), 0);
    close(sockfd);
    return 0;
}