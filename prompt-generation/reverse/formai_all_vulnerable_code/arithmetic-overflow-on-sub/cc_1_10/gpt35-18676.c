//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 8000
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    /* Variable declarations */
    int sockfd, bytes_sent, bytes_received;
    struct sockaddr_in server_addr;
    struct hostent* server;
    char buffer[BUFFER_SIZE];
    int interval = 5;
    int packet_size = 1024;
    int priority = 0;
    int i;
    clock_t start_time, end_time;
    double elapsed_time;

    /* Check command line arguments */
    if (argc < 2)
    {
        fprintf(stderr,"usage %s hostname\n", argv[0]);
        exit(1);
    }

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Get server IP address from hostname */
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    /* Set server address */
    bzero((char*) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    /* Prompt user for monitoring parameters */
    printf("Enter monitoring interval (in seconds): ");
    scanf("%d", &interval);
    printf("Enter packet size (in bytes): ");
    scanf("%d", &packet_size);
    printf("Enter priority (0 - low, 1 - medium, 2 - high): ");
    scanf("%d", &priority);

    /* Construct packet */
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "Interval: %d s, Packet Size: %d bytes, Priority: %d\n", interval, packet_size, priority);

    /* Send packet to server */
    bytes_sent = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*) &server_addr, sizeof(server_addr));
    if (bytes_sent < 0)
    {
        perror("ERROR sending packet");
        exit(1);
    }

    /* Receive packets from server and measure delay */
    for (i = 0; i < 10; i++)
    {
        bzero(buffer, BUFFER_SIZE);
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received < 0)
        {
            perror("ERROR receiving packet");
            exit(1);
        }
        printf("Packet received: %s\n", buffer);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
        printf("Packet delay: %f s\n", elapsed_time);
        start_time = clock();
        sleep(interval - elapsed_time);
    }

    /* Close socket */
    close(sockfd);

    return 0;
}