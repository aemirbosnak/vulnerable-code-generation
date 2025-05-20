//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 8080

void speed_test(int sockfd)
{
    char buff[1024];
    clock_t start, end;
    double time_taken;
    int bytes_sent = 0, bytes_received = 0;

    start = clock();
    while (bytes_received < 1024 * 10)
    {
        send(sockfd, buff, 1024, 0);
        bytes_received = recv(sockfd, buff, 1024, 0);
    }
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Speed test results:\n");
    printf("   - Total bytes sent: %d\n", bytes_sent);
    printf("   - Total bytes received: %d\n", bytes_received);
    printf("   - Time taken: %.2f seconds\n", time_taken);
    printf("   - Speed: %.2f Mbps\n", (double) (bytes_sent * 8) / time_taken);
}

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char hostname[256];

    printf("Enter the hostname of the server: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    speed_test(sockfd);

    close(sockfd);

    return 0;
}