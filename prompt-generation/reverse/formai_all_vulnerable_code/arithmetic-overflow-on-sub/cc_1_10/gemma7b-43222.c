//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 8888

int main()
{
    int sockfd, port, n, i, recv_size, send_size;
    char buffer[1024];
    struct sockaddr_in server_addr;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Server address setup
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Test speed
    clock_t start, end;
    double time_taken;
    char data[1024];

    start = clock();
    send_size = send(sockfd, data, 1024, 0);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for data transfer: %.2f seconds\n", time_taken);

    // Close socket
    close(sockfd);

    return 0;
}