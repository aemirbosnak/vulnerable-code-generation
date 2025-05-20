//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "speedtest.net"
#define SERVER_PORT 80

int main()
{
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int bytes_sent, bytes_recv;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        close(sock);
        exit(1);
    }

    bytes_sent = send(sock, "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n"), 0);
    if (bytes_sent == -1)
    {
        printf("Error sending request\n");
        close(sock);
        exit(1);
    }

    bytes_recv = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_recv == -1)
    {
        printf("Error receiving response\n");
        close(sock);
        exit(1);
    }

    close(sock);

    start_time = clock();
    while (bytes_recv > 0)
    {
        bytes_recv -= fwrite(buffer, 1, bytes_recv, stdout);
    }
    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    speed = (double)bytes_recv / elapsed_time;

    printf("Download speed: %.2f kbps\n", speed);

    return 0;
}