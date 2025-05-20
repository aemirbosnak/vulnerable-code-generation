//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 12345
#define BUF_SIZE 1024
#define NUM_OF_THREADS 4
#define NUM_OF_SAMPLES 10
#define SEND_DELAY 1000000 // 1 second
#define RECV_DELAY 1000000 // 1 second

struct sockaddr_in server_addr;
int sock;

double speed_test(int thread_id) {
    int bytes_sent = 0;
    int bytes_recv = 0;
    int i;
    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];

    memset(send_buf, 'a', BUF_SIZE);
    memset(recv_buf, 0, BUF_SIZE);

    for (i = 0; i < NUM_OF_SAMPLES; i++) {
        send(sock, send_buf, BUF_SIZE, 0);
        usleep(SEND_DELAY);
        bytes_sent += BUF_SIZE;

        usleep(RECV_DELAY);
        int bytes_recvd = recv(sock, recv_buf, BUF_SIZE, 0);
        bytes_recv += bytes_recvd;
    }

    double speed = (double)bytes_sent / (double)bytes_recv;
    printf("Thread %d: Speed = %.2f bytes/sec\n", thread_id, speed);

    return speed;
}

int main() {
    int i;
    pthread_t threads[NUM_OF_THREADS];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    for (i = 0; i < NUM_OF_THREADS; i++) {
        pthread_create(&threads[i], NULL, speed_test, (void*)i);
    }

    for (i = 0; i < NUM_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);
    return 0;
}