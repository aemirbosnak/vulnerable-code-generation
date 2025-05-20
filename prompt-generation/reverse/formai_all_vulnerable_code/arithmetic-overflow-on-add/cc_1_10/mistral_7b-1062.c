//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_IP "134.170.112.128" // Google DNS server
#define SERVER_PORT 53
#define BUFFER_SIZE 4096
#define TIMEOUT 5000
#define PACKET_SIZE 1500

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *request = "STANDARD QUERY: test.com. IN A.";
    int len, i, j, packet_num = 0;
    struct timeval start_time, end_time;
    long long start_ms, end_ms, elapsed_ms;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if ((server = gethostbyname(SERVER_IP)) == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", gai_strerror(h_errno));
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    bcopy(server->h_addr, &server_addr.sin_addr, server->h_length);

    for (i = 0; i < 5; i++) {
        gettimeofday(&start_time, NULL);
        start_ms = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;

        if (sendto(sockfd, request, strlen(request), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("sendto");
            continue;
        }

        memset(buffer, 0, BUFFER_SIZE);
        len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);

        if (len < 0) {
            perror("recvfrom");
            continue;
        }

        gettimeofday(&end_time, NULL);
        end_ms = end_time.tv_sec * 1000 + end_time.tv_usec / 1000;

        elapsed_ms = end_ms - start_ms;

        for (j = 0; j < len; j++)
            if (buffer[j] == '\r' && buffer[j + 1] == '\n') {
                printf("Reply size: %d bytes\n", j + 1);
                printf("Time taken: %lld ms\n", elapsed_ms);
                break;
            }

        packet_num++;
        printf("Packet %d sent and received\n", packet_num);

        usleep(TIMEOUT);
    }

    close(sockfd);
    return 0;
}