//Falcon-180B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define EMAIL_SERVER "localhost"
#define EMAIL_PORT 25
#define EMAIL_USER "email@example.com"
#define EMAIL_PASSWORD "password"

int email_socket;
struct sockaddr_in email_server;

void email_connect() {
    email_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(email_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    email_server.sin_family = AF_INET;
    email_server.sin_port = htons(EMAIL_PORT);
    inet_pton(AF_INET, EMAIL_SERVER, &email_server.sin_addr);

    if(connect(email_socket, (struct sockaddr *)&email_server, sizeof(email_server)) == -1) {
        printf("Error connecting to email server\n");
        exit(1);
    }
}

void email_login() {
    char login_command[100];
    sprintf(login_command, "USER %s\r\n", EMAIL_USER);
    send(email_socket, login_command, strlen(login_command), 0);

    char password_command[100];
    sprintf(password_command, "PASS %s\r\n", EMAIL_PASSWORD);
    send(email_socket, password_command, strlen(password_command), 0);
}

void email_send(char *to, char *subject, char *message) {
    char send_command[200];
    sprintf(send_command, "MAIL FROM: %s\r\n", EMAIL_USER);
    send(email_socket, send_command, strlen(send_command), 0);

    sprintf(send_command, "RCPT TO: %s\r\n", to);
    send(email_socket, send_command, strlen(send_command), 0);

    sprintf(send_command, "DATA\r\n");
    send(email_socket, send_command, strlen(send_command), 0);

    sprintf(send_command, "Subject: %s\r\n\r\n", subject);
    send(email_socket, send_command, strlen(send_command), 0);

    sprintf(send_command, "%s\r\n.\r\n", message);
    send(email_socket, send_command, strlen(send_command), 0);
}

void email_disconnect() {
    char disconnect_command[50];
    sprintf(disconnect_command, "QUIT\r\n");
    send(email_socket, disconnect_command, strlen(disconnect_command), 0);
    close(email_socket);
}

void *email_thread(void *arg) {
    char *to = arg;
    email_connect();
    email_login();
    email_send(to, "Email Subject", "Email Message");
    email_disconnect();
    pthread_exit(NULL);
}

int main() {
    char to[100];
    printf("Enter recipient email address: ");
    scanf("%s", to);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, email_thread, to);
    pthread_join(thread_id, NULL);

    return 0;
}