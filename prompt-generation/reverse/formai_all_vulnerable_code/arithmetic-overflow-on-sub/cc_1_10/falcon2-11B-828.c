//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <pthread.h>
#include <math.h>

void* monitor_thread(void* arg)
{
    struct timeval start_time, end_time;
    double start_time_sec, end_time_sec;
    int socket_fd, num_packets;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    char* ip_address = (char*)arg;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    num_packets = 0;
    gettimeofday(&start_time, NULL);

    while (1)
    {
        num_packets++;

        gettimeofday(&end_time, NULL);
        end_time_sec = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

        if (end_time_sec > 1)
        {
            printf("Average packet rate: %f packets/sec\n", num_packets / end_time_sec);
            fflush(stdout);
            num_packets = 0;
            gettimeofday(&start_time, NULL);
        }
    }

    close(socket_fd);
    return NULL;
}

int main()
{
    pthread_t thread;
    char* ip_address = "127.0.0.1";

    if (pthread_create(&thread, NULL, monitor_thread, (void*)ip_address)!= 0)
    {
        perror("Error creating thread");
        exit(1);
    }

    pthread_join(thread, NULL);

    return 0;
}