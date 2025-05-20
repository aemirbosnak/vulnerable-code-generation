//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define BUF_SIZE 1024

int threads[MAX_THREADS];
int thread_count = 0;

void *scan(void *arg)
{
    int port = *(int *) arg;
    char host[16] = {0};
    sprintf(host, "127.0.0.1");

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1)
    {
        if (errno == ECONNREFUSED)
        {
            printf("Port %d is closed\n", port);
        }
        else
        {
            printf("Error connecting to port %d\n", port);
        }
        close(sock);
        return NULL;
    }

    close(sock);
    printf("Port %d is open\n", port);
    return NULL;
}

int main()
{
    printf("Enter number of threads: ");
    scanf("%d", &thread_count);

    if (thread_count > MAX_THREADS)
    {
        printf("Maximum thread count is %d\n", MAX_THREADS);
        exit(1);
    }

    printf("Enter ports to scan:\n");
    char ports[100][6] = {0};
    int i = 0;
    while (i < thread_count)
    {
        scanf("%s", ports[i]);
        i++;
    }

    for (int j = 0; j < thread_count; j++)
    {
        int port = atoi(ports[j]);
        threads[j] = malloc(sizeof(pthread_t));
        pthread_create(threads[j], NULL, scan, (void *) &port);
    }

    for (int k = 0; k < thread_count; k++)
    {
        pthread_join(threads[k], NULL);
    }

    return 0;
}