//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 10
#define NUM_REQUESTS 10
#define SERVER_PORT 80
#define SERVER_NAME "www.google.com"

struct hostent *server;
char *server_ip;
int server_port;

void *download_file(void *arg) {
    int sock = *(int *) arg;
    char filename[20];
    sprintf(filename, "thread_%d.txt", *(int *) arg);
    FILE *fp = fopen(filename, "w");

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    for (int i = 0; i < NUM_REQUESTS; i++) {
        send(sock, "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"), 0);
        recv(sock, buffer, BUFFER_SIZE, 0);
        fwrite(buffer, strlen(buffer), 1, fp);
    }

    fclose(fp);
    close(sock);
    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname(SERVER_NAME);
    server_ip = inet_ntoa(*(struct in_addr *) *server->h_addr_list);
    server_port = htons(SERVER_PORT);

    connect(server_sock, (struct sockaddr *) server, sizeof(struct sockaddr));

    pthread_t threads[NUM_THREADS];
    int sock[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        sock[i] = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock[i], (struct sockaddr *) server, sizeof(struct sockaddr));
        pthread_create(&threads[i], NULL, download_file, (void *) &sock[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_sock);
    return 0;
}