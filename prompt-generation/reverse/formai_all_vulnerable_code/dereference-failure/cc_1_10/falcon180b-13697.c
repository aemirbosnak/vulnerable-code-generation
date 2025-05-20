//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024
#define DEFAULT_PORT 80 //http

struct host_info{
    char *ip;
    int port;
};

void *scan_port(void *arg){
    struct host_info *host_info = arg;
    char recv_buffer[BUFFER_SIZE];
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1){
        printf("Error creating socket\n");
        exit(0);
    }

    memset(&(host_info->ip), 0, strlen(host_info->ip));
    strcat(host_info->ip, inet_ntoa(*((struct in_addr *)host_info->ip)));

    if(connect(sock, (struct sockaddr *)host_info, sizeof(struct sockaddr)) == -1){
        printf("Port %d is closed\n", host_info->port);
        close(sock);
        return NULL;
    }

    send(sock, "GET / HTTP/1.0\r\nHost: localhost\r\n\r\n", 52, 0);

    int bytes_received = recv(sock, recv_buffer, BUFFER_SIZE, 0);

    recv_buffer[bytes_received] = '\0';

    if(strstr(recv_buffer, "200")!= NULL){
        printf("Port %d is open\n", host_info->port);
    }else{
        printf("Port %d is closed\n", host_info->port);
    }

    close(sock);
    return NULL;
}

int main(){
    int num_threads = 0;
    struct host_info *host_info = NULL;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the IP address: ");
    scanf("%s", host_info->ip);

    printf("Enter the starting port number: ");
    scanf("%d", &host_info->port);

    for(int i=0; i<num_threads; i++){
        pthread_create(&threads[i], NULL, scan_port, (void *)host_info);
        host_info->port++;
    }

    for(int i=0; i<num_threads; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}