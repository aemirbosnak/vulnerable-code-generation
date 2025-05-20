//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

#define MAX_BUFFER 1024
#define DEFAULT_PORT 8080
#define TIME_DELAY 2

volatile sig_atomic_t stop_program = 0;

void handle_signal(int sig) {
    stop_program = 1;
}

void print_network_metrics(float latency, float jitter, int packet_loss) {
    printf("\nNetwork Quality of Service Metrics:\n");
    printf("Latency: %.2f ms\n", latency);
    printf("Jitter: %.2f ms\n", jitter);
    printf("Packet Loss: %d%%\n", packet_loss);
}

void calculate_metrics(int count, float *latency_avg, float *jitter_avg, int *packet_loss_count) {
    *latency_avg /= count;
    *jitter_avg /= count;
    *packet_loss_count = (*packet_loss_count * 100) / count;
}

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_signal);

    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[MAX_BUFFER], recv_buffer[MAX_BUFFER];
    int port = (argc > 1) ? atoi(argv[1]) : DEFAULT_PORT;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    float total_latency = 0.0f, total_jitter = 0.0f;
    int total_packet_loss = 0, packet_loss_count = 0, count = 0;

    while (!stop_program) {
        snprintf(send_buffer, sizeof(send_buffer), "Ping %d", count + 1);
        
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);
        
        if (sendto(sockfd, send_buffer, strlen(send_buffer), 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) <= 0) {
            perror("Send failed");
            break;
        }

        socklen_t addr_len = sizeof(server_addr);
        int recv_len = recvfrom(sockfd, recv_buffer, MAX_BUFFER, 0, (struct sockaddr*)&server_addr, &addr_len);
        
        gettimeofday(&end_time, NULL);
        
        if (recv_len < 0) {
            perror("Receive failed");
            total_packet_loss++;
            packet_loss_count++;
        } else {
            recv_buffer[recv_len] = '\0';
            long latency = (end_time.tv_sec - start_time.tv_sec) * 1000 + 
                           (end_time.tv_usec - start_time.tv_usec) / 1000;
            total_latency += latency;
            count++;

            if (count > 1) {
                float jitter = (latency - (total_latency / count));
                total_jitter += (jitter < 0) ? -jitter : jitter;
            }
        }
        
        sleep(TIME_DELAY);
    }

    calculate_metrics(count, &total_latency, &total_jitter, &packet_loss_count);
    print_network_metrics(total_latency, total_jitter, packet_loss_count);
    
    close(sockfd);
    return EXIT_SUCCESS;
}