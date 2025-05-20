//Falcon-180B DATASET v1.0 Category: Chat server ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#define MAX 100

int sock;
int newsock;
int portno;
int addrlen;
struct sockaddr_in serv_addr;
struct sockaddr_in cli_addr;
pthread_t thread_id;
int thread_count = 0;

void *thread_handler(void *arg) {
    char *message = (char *) arg;
    send(newsock, message, strlen(message), 0);
    close(newsock);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    int opt;
    int res;
    char buffer[MAX];
    pthread_attr_t attr;

    if(argc!= 3) {
        printf("Usage :./server <port_number> <message>\n");
        return -1;
    }

    portno = atoi(argv[1]);
    strcpy(buffer, argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == 0) {
        printf("socket creation failed\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind failed\n");
        return -1;
    }

    if(listen(sock, 3) < 0) {
        printf("listen failed\n");
        return -1;
    }

    addrlen = sizeof(cli_addr);

    while(1) {
        newsock = accept(sock, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen);

        if(newsock < 0) {
            printf("accept failed\n");
            return -1;
        }

        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

        res = pthread_create(&thread_id, &attr, thread_handler, (void*)buffer);
        if(res!= 0) {
            printf("thread creation failed\n");
            return -1;
        }

        thread_count++;
    }

    return 0;
}