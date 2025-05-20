//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 21
#define BUF_SIZE 1024

int sock;
struct sockaddr_in server_addr;

void *thread_func(void *arg) {
    char *response = (char *) arg;
    printf("Response: %s\n", response);
    free(response);
}

void send_command(char *cmd) {
    int len = strlen(cmd);
    send(sock, cmd, len, 0);
}

void *receive_response(void *arg) {
    char buffer[BUF_SIZE];
    bzero(buffer, BUF_SIZE);
    int len = recv(sock, buffer, BUF_SIZE, 0);
    char *response = (char *) malloc(len + 1);
    strncpy(response, buffer, len);
    response[len] = '\0';
    pthread_exit((void *) response);
}

int main() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char *username = "anonymous";
    char *password = "anonymous@example.com";

    send_command("USER ");
    send_command(username);

    char *response = NULL;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, receive_response, &response);

    send_command("PASS ");
    send_command(password);

    pthread_join(thread_id, &response);
    free(response);

    send_command("LIST");

    pthread_t thread_id2;
    pthread_create(&thread_id2, NULL, receive_response, NULL);

    pthread_join(thread_id2, &response);
    printf("Response: %s\n", response);
    free(response);

    close(sock);
    return 0;
}