//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_imap(const char *server) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Unable to create socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if(inet_pton(AF_INET, server, &serv_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection to server failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    
    while ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0'; 
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break; // End condition on response
        }
    }
}

void authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, BUFFER_SIZE, "A1 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A2 LIST \"\" \"*\"");
    receive_response(sockfd);
}

void fetch_email(int sockfd, const char *mailbox) {
    char command[BUFFER_SIZE];
    
    snprintf(command, BUFFER_SIZE, "A3 SELECT \"%s\"", mailbox);
    send_command(sockfd, command);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_imap(server);

    receive_response(sockfd); 

    authenticate(sockfd, username, password);
    
    list_mailboxes(sockfd); 
    
    fetch_email(sockfd, "INBOX");
    
    close(sockfd);
    return EXIT_SUCCESS;
}