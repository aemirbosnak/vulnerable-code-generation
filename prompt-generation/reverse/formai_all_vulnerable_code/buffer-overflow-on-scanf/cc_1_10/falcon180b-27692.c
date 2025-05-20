//Falcon-180B DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 1000

int sock;
struct sockaddr_in server;
int port = 8080;
char ip[16];

void *thread(void *arg) {
    char message[MAX];
    int bytes_read;

    while (1) {
        bytes_read = recv(sock, message, MAX, 0);
        if (bytes_read <= 0) {
            printf("Connection closed by server\n");
            close(sock);
            exit(0);
        }

        message[bytes_read] = '\0';
        printf("%s", message);
    }
}

int main() {
    int i;
    char hostname[16];

    printf("Enter IP address of the server: ");
    scanf("%s", ip);

    printf("Enter hostname: ");
    scanf("%s", hostname);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket failed");
        exit(0);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed");
        exit(0);
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread, NULL);

    while (1) {
        char message[MAX];
        fgets(message, MAX, stdin);

        int bytes_sent = send(sock, message, strlen(message), 0);
        if (bytes_sent <= 0) {
            printf("Connection closed by server\n");
            close(sock);
            exit(0);
        }
    }

    return 0;
}