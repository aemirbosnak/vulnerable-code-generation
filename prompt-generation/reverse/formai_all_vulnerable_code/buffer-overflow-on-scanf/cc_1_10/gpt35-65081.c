//FormAI DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct Message {
    char from[50];
    char to[50];
    char subject[200];
    char body[500];
};

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: ./email [server_address] [server_port] [username]\n");
        exit(1);
    }

    char username[50];
    strcpy(username, argv[3]);

    char buffer[1024];
    struct sockaddr_in server_address;

    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("\nInvalid server address/ Address not supported \n");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("\nError : Could not create socket \n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    char login_command[100];
    sprintf(login_command, "LOGIN %s", username);
    send(sockfd, login_command, strlen(login_command), 0);

    while (1) {
        int read_bytes = recv(sockfd, buffer, 1024, 0);
        if (read_bytes <= 0) break;
        buffer[read_bytes] = '\0';

        if (strcmp(buffer, "LOGIN SUCCESS") == 0) {
            printf("Login Successful\n");
            break;
        }
        else {
            printf("%s\n", buffer);
            char password[50];
            printf("Enter Password: ");
            scanf("%s", password);
            char password_command[100];
            sprintf(password_command, "PASSWORD %s", password);
            send(sockfd, password_command, strlen(password_command), 0);
        }
    }

    char recipient[50];
    printf("Enter recipient email address: ");
    scanf("%s", recipient);

    char subject[200];
    printf("Enter email subject: ");
    scanf("%s", subject);

    char body[500];
    printf("Enter email body: ");
    scanf("%s", body);

    struct Message message;
    strcpy(message.from, username);
    strcpy(message.to, recipient);
    strcpy(message.subject, subject);
    strcpy(message.body, body);

    char send_command[1000];
    sprintf(send_command, "SEND %s %s %s %s", message.to, message.from, message.subject, message.body);
    send(sockfd, send_command, strlen(send_command), 0);

    while (1) {
        int read_bytes = recv(sockfd, buffer, 1024, 0);
        if (read_bytes <= 0) break;
        buffer[read_bytes] = '\0';
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}