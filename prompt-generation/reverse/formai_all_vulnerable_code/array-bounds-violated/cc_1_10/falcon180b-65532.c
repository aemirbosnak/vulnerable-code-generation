//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

struct sockaddr_in server_addr;
int sockfd = -1;
char recv_buffer[MAX_DATA_SIZE];

void *thread_func(void *arg) {
    int bytes_received;
    while(1) {
        bytes_received = recv(sockfd, recv_buffer, MAX_DATA_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        recv_buffer[bytes_received] = '\0';
        printf("Received data: %s\n", recv_buffer);
    }
    return NULL;
}

int main() {
    int port = 8080;
    char *ip_address = "192.168.1.1";
    struct hostent *host_info;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func, NULL);

    while(1) {
        char input[MAX_DATA_SIZE];
        fgets(input, MAX_DATA_SIZE, stdin);
        if(strcmp(input, "exit") == 0) {
            break;
        }
        send(sockfd, input, strlen(input), 0);
    }

    close(sockfd);
    return 0;
}