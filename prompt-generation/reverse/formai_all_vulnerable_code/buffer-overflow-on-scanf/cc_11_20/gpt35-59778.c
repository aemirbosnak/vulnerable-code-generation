//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Invalid Arguments\n");
        printf("Usage: ./pop3client <server> <port>\n");
        return 1;
    }

    char* server = argv[1];
    int port = atoi(argv[2]);

    // Connect to the server
    struct hostent *he;
    struct sockaddr_in server_address;
    int socket_fd;

    if ((he = gethostbyname(server)) == NULL) {
        printf("Could not resolve server address\n");
        return 1;
    }

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Could not connect to server\n");
        return 1;
    }

    // Read the welcome message
    char buffer[BUFFER_SIZE];
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive data\n");
        return 1;
    }
    printf("%s", buffer);

    // Login
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    char login[BUFFER_SIZE];
    sprintf(login, "USER %s\r\n", username);
    if (send(socket_fd, login, strlen(login), 0) == -1) {
        printf("Could not send data\n");
        return 1;
    }

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive data\n");
        return 1;
    }
    printf("%s", buffer);

    sprintf(login, "PASS %s\r\n", password);
    if (send(socket_fd, login, strlen(login), 0) == -1) {
        printf("Could not send data\n");
        return 1;
    }

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive data\n");
        return 1;
    }
    printf("%s", buffer);

    // List emails
    char list_command[] = "LIST\r\n";
    if (send(socket_fd, list_command, strlen(list_command), 0) == -1) {
        printf("Could not send data\n");
        return 1;
    }

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive data\n");
        return 1;
    }
    printf("%s", buffer);

    // Retrieve an email
    int email_number;
    printf("Enter email number to retrieve: ");
    scanf("%d", &email_number);

    char retr_command[BUFFER_SIZE];
    sprintf(retr_command, "RETR %d\r\n", email_number);
    if (send(socket_fd, retr_command, strlen(retr_command), 0) == -1) {
        printf("Could not send data\n");
        return 1;
    }

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive data\n");
        return 1;
    }
    printf("%s", buffer);

    // Quit
    char quit_command[] = "QUIT\r\n";
    if (send(socket_fd, quit_command, strlen(quit_command), 0) == -1) {
        printf("Could not send data\n");
        return 1;
    }

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Could not receive data\n");
        return 1;
    }
    printf("%s", buffer);

    close(socket_fd);

    return 0;
}