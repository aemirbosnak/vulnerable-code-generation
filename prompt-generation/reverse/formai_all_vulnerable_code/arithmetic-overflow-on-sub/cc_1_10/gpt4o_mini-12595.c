//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <pthread.h>

#define PORT 8080
#define PACKET_SIZE 64
#define NUM_PACKETS 10
#define TIME_FORMAT_LENGTH 26
#define MONITORING_INTERVAL 2

typedef struct {
    struct sockaddr_in server_addr;
    int packet_count;
    int packet_loss;
} QoS_Data;

void *ping_server(void *data) {
    QoS_Data *qos_data = (QoS_Data *)data;
    char packet[PACKET_SIZE];
    struct timeval start, end;
    int sockfd, i;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    for (i = 0; i < NUM_PACKETS; i++) {
        gettimeofday(&start, NULL);
        int sent = sendto(sockfd, packet, sizeof(packet), 0,
                          (struct sockaddr *)&(qos_data->server_addr), sizeof(qos_data->server_addr));
        if (sent < 0) {
            qos_data->packet_loss++;
            printf("Packet %d lost\n", i + 1);
        } else {
            char time_string[TIME_FORMAT_LENGTH];
            gettimeofday(&end, NULL);
            double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
            printf("Packet %d sent, RTT: %.2f ms\n", i + 1, elapsed_time);
            qos_data->packet_count++;
        }
        sleep(MONITORING_INTERVAL);
    }

    close(sockfd);
    return NULL;
}

int main() {
    QoS_Data qos_data;
    pthread_t ping_thread;

    memset(&qos_data, 0, sizeof(QoS_Data));
    qos_data.packet_loss = 0;
    qos_data.packet_count = 0;

    memset(&(qos_data.server_addr), 0, sizeof(qos_data.server_addr));
    qos_data.server_addr.sin_family = AF_INET;
    qos_data.server_addr.sin_port = htons(PORT);
    qos_data.server_addr.sin_addr.s_addr = inet_addr("8.8.8.8"); // Using Google's public DNS

    if (pthread_create(&ping_thread, NULL, ping_server, (void *)&qos_data) != 0) {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }

    pthread_join(ping_thread, NULL);
    
    printf("Monitoring complete. Total packets sent: %d, Total packets lost: %d\n",
           qos_data.packet_count, qos_data.packet_loss);
    return EXIT_SUCCESS;
}