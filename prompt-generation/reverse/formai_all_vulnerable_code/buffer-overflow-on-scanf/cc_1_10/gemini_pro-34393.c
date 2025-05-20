//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFF_SIZE];

    printf("Enter the IP address of the server: ");
    scanf("%s", buffer);

    printf("Enter the port number of the server: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(buffer);
    if (server == NULL)
    {
        perror("ERROR, no such host");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to server. Starting speed test...\n");

    clock_t start = clock();
    int bytes_received = 0;
    int bytes_sent = 0;
    int num_packets = 0;

    while (1)
    {
        // Send a packet to the server
        memset(buffer, 'a', BUFF_SIZE);
        n = send(sockfd, buffer, BUFF_SIZE, 0);
        if (n < 0)
        {
            perror("ERROR writing to socket");
            break;
        }
        bytes_sent += n;
        num_packets++;

        // Receive a packet from the server
        memset(buffer, 0, BUFF_SIZE);
        n = recv(sockfd, buffer, BUFF_SIZE, 0);
        if (n < 0)
        {
            perror("ERROR reading from socket");
            break;
        }
        bytes_received += n;
    }

    clock_t end = clock();
    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Speed test completed.\n");
    printf("Bytes sent: %d\n", bytes_sent);
    printf("Bytes received: %d\n", bytes_received);
    printf("Number of packets: %d\n", num_packets);
    printf("Time elapsed: %f seconds\n", time_elapsed);

    double throughput = (double)(bytes_sent + bytes_received) / time_elapsed;
    printf("Throughput: %f bytes/second\n", throughput);

    close(sockfd);
    return 0;
}