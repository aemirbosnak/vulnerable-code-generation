//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>

#define BUF_SIZE 1024

struct sockaddr_in server_addr;
int sockfd;
char username[20];
char password[20];
char buffer[BUF_SIZE];

void *thread_func(void *arg) {
    char *response = (char *) arg;
    printf("%s\n", response);
}

void send_command(char *command) {
    send(sockfd, command, strlen(command), 0);
}

void receive_response() {
    memset(buffer, 0, BUF_SIZE);
    int bytes_received = recv(sockfd, buffer, BUF_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func, buffer);
}

int main() {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *login_command = "USER ";
    strcat(login_command, username);
    strcat(login_command, "\r\n");
    send_command(login_command);
    receive_response();

    char *pass_command = "PASS ";
    strcat(pass_command, password);
    strcat(pass_command, "\r\n");
    send_command(pass_command);
    receive_response();

    char *stat_command = "STAT\r\n";
    send_command(stat_command);
    receive_response();

    close(sockfd);
    return 0;
}