//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_MAIL_SIZE 1024
#define MAX_CLIENT_NAME 16

void send_email(char* email, char* subject, char* message);
void receive_email(char* email);

int main() {
    char email[MAX_CLIENT_NAME + 1] = "";
    char subject[MAX_EMAIL_SIZE + 1] = "";
    char message[MAX_MAIL_SIZE + 1] = "";

    printf("Enter your email address: ");
    fgets(email, MAX_CLIENT_NAME, stdin);
    email[strlen(email) - 1] = '\0'; // Remove trailing newline

    printf("Enter the subject of your email: ");
    fgets(subject, MAX_EMAIL_SIZE, stdin);
    subject[strlen(subject) - 1] = '\0'; // Remove trailing newline

    printf("Enter the message of your email: ");
    fgets(message, MAX_MAIL_SIZE, stdin);
    message[strlen(message) - 1] = '\0'; // Remove trailing newline

    send_email(email, subject, message);
    receive_email(email);

    return 0;
}

void send_email(char* email, char* subject, char* message) {
    char hostname[MAX_EMAIL_SIZE + 1];
    char command[MAX_EMAIL_SIZE + 1];
    char reply[MAX_EMAIL_SIZE + 1];

    printf("Enter the hostname of the email server: ");
    fgets(hostname, MAX_EMAIL_SIZE, stdin);
    hostname[strlen(hostname) - 1] = '\0'; // Remove trailing newline

    strcpy(command, "SEND ");
    strcat(command, email);
    strcat(command, " ");
    strcat(command, subject);
    strcat(command, " ");
    strcat(command, message);
    strcat(command, "\n");

    printf("Sending email...\n");
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25);
    server_address.sin_addr.s_addr = inet_addr(hostname);
    connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
    write(socket_fd, command, strlen(command));
    close(socket_fd);
}

void receive_email(char* email) {
    char hostname[MAX_EMAIL_SIZE + 1];
    char command[MAX_EMAIL_SIZE + 1];
    char reply[MAX_EMAIL_SIZE + 1];

    printf("Enter the hostname of the email server: ");
    fgets(hostname, MAX_EMAIL_SIZE, stdin);
    hostname[strlen(hostname) - 1] = '\0'; // Remove trailing newline

    strcpy(command, "RECEIVE ");
    strcat(command, email);
    strcat(command, "\n");

    printf("Receiving email...\n");
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25);
    server_address.sin_addr.s_addr = inet_addr(hostname);
    connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
    write(socket_fd, command, strlen(command));
    close(socket_fd);
}