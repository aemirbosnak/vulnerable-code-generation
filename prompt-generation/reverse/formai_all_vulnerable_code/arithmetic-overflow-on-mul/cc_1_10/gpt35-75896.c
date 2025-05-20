//FormAI DATASET v1.0 Category: Network Ping Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PING_TIMEOUT 2
#define PING_BUFFER_SIZE 64
#define IP_LENGTH 16

char* generate_ip_address() {
    char* ip_address = malloc(IP_LENGTH * sizeof(char));

    srand(time(0));

    sprintf(ip_address, "%d.%d.%d.%d", rand() % 254 + 1, rand() % 254 + 1, rand() % 254 + 1, rand() % 254 + 1);

    return ip_address;
}

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);

    if (sock == -1) {
        printf("ERROR: Could not create socket!");
        return -1;
    }

    char* ip_address = generate_ip_address();

    printf("Pinging %s with %d bytes of data...\n", ip_address, PING_BUFFER_SIZE);

    struct sockaddr_in dest_address;
    dest_address.sin_family = AF_INET;
    dest_address.sin_port = htons(0);
    inet_pton(AF_INET, ip_address, &dest_address.sin_addr);

    struct sockaddr_in response_address;
    socklen_t response_address_len = sizeof(response_address);

    char buffer[PING_BUFFER_SIZE];
    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT;
    timeout.tv_usec = 0;

    for (int i = 1; i <= 10; i++) {
        buffer[0] = 8;
        buffer[1] = 0;
        buffer[2] = 0;
        buffer[3] = 0;
        buffer[4] = i;
        buffer[5] = 0;
        buffer[6] = 0;
        buffer[7] = 0;

        int start_time = time(0);

        int bytes_sent = sendto(sock, buffer, PING_BUFFER_SIZE, 0, (struct sockaddr*)&dest_address, sizeof(dest_address));

        if (bytes_sent == -1) {
            printf("ERROR: Could not send ping request!");
            return -1;
        }

        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

        int bytes_received = recvfrom(sock, buffer, PING_BUFFER_SIZE, 0, (struct sockaddr*)&response_address, &response_address_len);

        int end_time = time(0);

        if (bytes_received == -1) {
            printf("Request timed out!\n");
        } else {
            printf("Reply from %s: bytes=%d time=%dms TTL=%d\n", ip_address, bytes_received, (end_time - start_time) * 1000, buffer[8]);
        }

        sleep(1);
    }

    close(sock);
    free(ip_address);

    return 0;
}