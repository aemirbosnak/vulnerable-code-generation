//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 65536

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [IP Address] [Port]\n", argv[0]);
        exit(0);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    int connection = connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));
    if (connection < 0) {
        perror("Error connecting");
        exit(1);
    }

    char packet[MAX_PACKET_SIZE];
    int packet_size = 0;

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    int sent_packets = 0;
    int received_packets = 0;

    while (1) {
        memset(packet, 0, MAX_PACKET_SIZE);

        packet_size = recv(sock, packet, sizeof(packet), 0);
        if (packet_size == 0 || packet_size == -1) {
            break;
        }

        received_packets++;

        packet_size = send(sock, packet, packet_size, 0);
        if (packet_size == -1) {
            perror("Error sending packet");
            break;
        }

        sent_packets++;
    }

    gettimeofday(&end_time, NULL);

    int total_time = ((end_time.tv_sec - start_time.tv_sec) * 1000) + ((end_time.tv_usec - start_time.tv_usec) / 1000);
    int throughput = (int)(((double)sent_packets / total_time) * 1000);
    printf("Total Time: %d ms\n", total_time);
    printf("Packets Sent: %d\n", sent_packets);
    printf("Packets Received: %d\n", received_packets);
    printf("Throughput: %d bytes/second\n", throughput);

    return 0;
}