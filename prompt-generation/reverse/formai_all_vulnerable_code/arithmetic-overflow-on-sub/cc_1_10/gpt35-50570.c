//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define BUF_SIZE 256

int sock;

void error_handling(char *message);
void handler(int signal);

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];
    int str_len;
    float packet_loss = 0;
    float delay = 0;

    if (argc != 4) {
        printf("Usage: %s <IP> <port> <timeout>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    struct sockaddr from_addr;
    socklen_t addr_sz;
    addr_sz = sizeof(from_addr);

    // Set signal handler for SIGALRM timeout
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = handler;
    sigaction(SIGALRM, &act, 0);

    // Set timeout for recvfrom() to detect packet loss
    struct timeval timeout;
    timeout.tv_sec = atoi(argv[3]);
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Send and receive packets
    for (int i = 0; i < 10; i++) {
        sprintf(message, "packet %d", i);
        sendto(sock, message, strlen(message), 0, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

        str_len = recvfrom(sock, message, BUF_SIZE - 1, 0, &from_addr, &addr_sz);
        if (str_len < 0) {
            printf("Packet %d lost\n", i);
            packet_loss += 1.0;
            continue;
        }

        // Calculate delay of received packet
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        float current_delay = (float) (current_time.tv_sec - ((uint32_t*) message)[0]) * 1000.0 + (float) (current_time.tv_usec - ((uint32_t*) message)[1]) / 1000.0;
        delay += current_delay;

        printf("Received packet %d, delay = %.3fms\n", i, current_delay);
    }

    close(sock);

    // Calculate QoS metrics
    float average_delay = delay / (10 - packet_loss);
    float average_packet_loss = packet_loss / 10.0;

    printf("\n---- Network Quality of Service ----\n");
    printf("Average delay: %.3fms\n", average_delay);
    printf("Average packet loss: %.1f%%\n", average_packet_loss * 100);

    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputs("\n", stderr);
    exit(1);
}

void handler(int signal) {
    printf("Packet lost (timeout)\n");
    close(sock);
    exit(1);
}