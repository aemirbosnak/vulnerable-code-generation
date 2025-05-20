//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 1024
#define PORT 993 // IMAP Port

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Create Socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connect to Server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Read Welcome Response
    char buffer[BUFFSIZE];
    int numbytes = recv(sockfd, buffer, BUFFSIZE, 0);
    if (numbytes == -1) {
        perror("Error receiving message");
        return EXIT_FAILURE;
    }
    buffer[numbytes] = '\0';

    printf("%s", buffer); // Print Welcome Message

    // Login
    char login_cmd[BUFFSIZE];
    sprintf(login_cmd, "1 LOGIN %s %s\n", username, password);
    if (send(sockfd, login_cmd, strlen(login_cmd), 0) == -1) {
        perror("Error sending message");
        return EXIT_FAILURE;
    }

    numbytes = recv(sockfd, buffer, BUFFSIZE, 0);
    if (numbytes == -1) {
        perror("Error receiving message");
        return EXIT_FAILURE;
    }
    buffer[numbytes] = '\0';

    if (strstr(buffer, "OK") == NULL) { // Login Failed
        printf("Login Failed. Please check your credentials.\n");
        return EXIT_FAILURE;
    }

    // List Mailboxes
    char list_cmd[BUFFSIZE];
    sprintf(list_cmd, "2 LIST \"\" *\n");
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) == -1) {
        perror("Error sending message");
        return EXIT_FAILURE;
    }

    numbytes = recv(sockfd, buffer, BUFFSIZE, 0);
    if (numbytes == -1) {
        perror("Error receiving message");
        return EXIT_FAILURE;
    }
    buffer[numbytes] = '\0';

    if (strstr(buffer, "OK") == NULL) { // List Failed
        printf("List Failed.\n");
        return EXIT_FAILURE;
    }

    // Select Mailbox
    char select_cmd[BUFFSIZE];
    sprintf(select_cmd, "3 SELECT INBOX\n");
    if (send(sockfd, select_cmd, strlen(select_cmd), 0) == -1) {
        perror("Error sending message");
        return EXIT_FAILURE;
    }

    numbytes = recv(sockfd, buffer, BUFFSIZE, 0);
    if (numbytes == -1) {
        perror("Error receiving message");
        return EXIT_FAILURE;
    }
    buffer[numbytes] = '\0';

    if (strstr(buffer, "OK") == NULL) { // Select Failed
        printf("Select Failed.\n");
        return EXIT_FAILURE;
    }

    // Fetch Emails
    char fetch_cmd[BUFFSIZE];
    sprintf(fetch_cmd, "4 FETCH 1:* BODY[HEADER.FIELDS (FROM SUBJECT)]\n");
    if (send(sockfd, fetch_cmd, strlen(fetch_cmd), 0) == -1) {
        perror("Error sending message");
        return EXIT_FAILURE;
    }

    char email_buffer[BUFFSIZE];
    while ((numbytes = recv(sockfd, buffer, BUFFSIZE, 0)) > 0) {
        buffer[numbytes] = '\0';
        strcat(email_buffer, buffer);
    }

    printf("%s", email_buffer); // Print Emails

    // Logout
    char logout_cmd[BUFFSIZE];
    sprintf(logout_cmd, "5 LOGOUT\n");
    if (send(sockfd, logout_cmd, strlen(logout_cmd), 0) == -1) {
        perror("Error sending message");
        return EXIT_FAILURE;
    }

    numbytes = recv(sockfd, buffer, BUFFSIZE, 0);
    if (numbytes == -1) {
        perror("Error receiving message");
        return EXIT_FAILURE;
    }
    buffer[numbytes] = '\0';

    if (strstr(buffer, "OK") == NULL) { // Logout Failed
        printf("Logout Failed.\n");
        return EXIT_FAILURE;
    }

    close(sockfd); // Close Socket

    return EXIT_SUCCESS;
}