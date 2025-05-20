//Falcon-180B DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define SIZE 1024
#define PORT "110"
#define SERVER_IP "127.0.0.1"

char username[SIZE];
char password[SIZE];
char server_ip[SIZE];
int port;
int sock;
int auth_flag = 0;
int quit_flag = 0;
char buffer[SIZE];

void *receive_message(void *arg);
void send_message(char *message);

int main() {
    printf("Enter server IP: ");
    scanf("%s", server_ip);
    printf("Enter port number: ");
    scanf("%d", &port);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    pthread_t receive_thread;
    pthread_create(&receive_thread, NULL, receive_message, NULL);

    char ch;
    while (1) {
        ch = getchar();
        if (ch == '\n') {
            send_message(buffer);
            memset(buffer, 0, SIZE);
        } else {
            strncat(buffer, &ch, 1);
        }
    }

    return 0;
}

void *receive_message(void *arg) {
    char message[SIZE];

    while (1) {
        memset(message, 0, SIZE);
        if (recv(sock, message, SIZE, 0) <= 0) {
            printf("Error receiving message\n");
            exit(1);
        }
        printf("Message received: %s", message);
    }

    return 0;
}

void send_message(char *message) {
    if (send(sock, message, strlen(message), 0) <= 0) {
        printf("Error sending message\n");
        exit(1);
    }
}