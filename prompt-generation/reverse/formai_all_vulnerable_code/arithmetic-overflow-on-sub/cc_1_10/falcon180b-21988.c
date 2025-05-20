//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    long start_time, end_time;
    double elapsed_time;
    double speed;

    if (argc!= 2)
    {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);
    bytes_received = 0;

    while (bytes_received < BUFFER_SIZE)
    {
        bytes_received += recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
    }

    close(sock);

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    speed = (double)bytes_received / elapsed_time;

    printf("Internet speed: %.2f bytes/second\n", speed);

    return 0;
}