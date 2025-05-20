//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: inquisitive
// POP3 Client Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function prototypes
void pop3_login(int sockfd);
void pop3_list(int sockfd);
void pop3_retr(int sockfd, int msg_num);
void pop3_quit(int sockfd);

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(110),
        .sin_addr = { inet_addr("127.0.0.1") }
    };
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Login to the POP3 server
    pop3_login(sockfd);

    // List the messages on the server
    pop3_list(sockfd);

    // Retrieve the first message
    pop3_retr(sockfd, 1);

    // Quit the POP3 server
    pop3_quit(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}

void pop3_login(int sockfd) {
    // Send the USER command
    char user[] = "USER <username>";
    send(sockfd, user, strlen(user), 0);

    // Send the PASS command
    char pass[] = "PASS <password>";
    send(sockfd, pass, strlen(pass), 0);

    // Wait for the server response
    char response[1024];
    recv(sockfd, response, 1024, 0);
    printf("Response: %s\n", response);
}

void pop3_list(int sockfd) {
    // Send the LIST command
    char list[] = "LIST";
    send(sockfd, list, strlen(list), 0);

    // Wait for the server response
    char response[1024];
    recv(sockfd, response, 1024, 0);
    printf("Response: %s\n", response);
}

void pop3_retr(int sockfd, int msg_num) {
    // Send the RETR command
    char retr[] = "RETR ";
    char msg_num_str[10];
    sprintf(msg_num_str, "%d", msg_num);
    strcat(retr, msg_num_str);
    send(sockfd, retr, strlen(retr), 0);

    // Wait for the server response
    char response[1024];
    recv(sockfd, response, 1024, 0);
    printf("Response: %s\n", response);
}

void pop3_quit(int sockfd) {
    // Send the QUIT command
    char quit[] = "QUIT";
    send(sockfd, quit, strlen(quit), 0);

    // Wait for the server response
    char response[1024];
    recv(sockfd, response, 1024, 0);
    printf("Response: %s\n", response);
}