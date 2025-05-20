//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT_MAX 65535
#define BUFFER_SIZE 1024
#define THREAD_COUNT 10

int port_list[PORT_MAX];
int port_count = 0;

void *thread_func(void *arg)
{
    int port = *(int *) arg;
    int sockfd;
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int ret = connect(sockfd, (struct sockaddr *) &server, sizeof(server));
    if (ret == -1)
    {
        printf("Port %d is closed\n", port);
    }
    else
    {
        printf("Port %d is open\n", port);
    }

    close(sockfd);
    return NULL;
}

int main()
{
    printf("Enter the IP address: ");
    char ip_addr[20];
    scanf("%s", ip_addr);

    printf("Enter the port range (start-end): ");
    int start_port, end_port;
    scanf("%d-%d", &start_port, &end_port);

    int i;
    for (i = start_port; i <= end_port; i++)
    {
        port_list[port_count++] = i;
    }

    pthread_t threads[THREAD_COUNT];
    int rc;
    struct timespec ts = {0};

    for (i = 0; i < THREAD_COUNT; i++)
    {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *) &port_list[i * PORT_MAX / THREAD_COUNT]);
        if (rc)
        {
            printf("Error creating thread\n");
            exit(1);
        }
        ts.tv_sec = 0;
        ts.tv_nsec = 500000;
        nanosleep(&ts, NULL);
    }

    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}