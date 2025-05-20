//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    struct timeval startTime, endTime;
    struct sockaddr_in server_address;
    int sock;
    char server_ip[] = "8.8.8.8";
    int server_port = 53;
    char message[] = "Q\x01\x00\x00\x01\x00\x00\x00\x00\x00\x00\x07\x65\x78\x61\x6d\x70\x6c\x65\x03\x63\x6f\x6d\x00\x00\x01\x00\x01";
    char buffer[1024];

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        printf("Failed to create socket!\n");
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    server_address.sin_addr.s_addr = inet_addr(server_ip);

    int result;
    for (int i = 0; i < 5; i++) {
        result = sendto(sock, message, strlen(message), 0, (struct sockaddr*) &server_address, sizeof(server_address));
        if (result < 0) {
            printf("Failed to send message!\n");
            close(sock);
            return 1;
        }

        gettimeofday(&startTime, NULL);

        int nBytes = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        if (nBytes < 0) {
            printf("Failed to receive response!\n");
            close(sock);
            return 1;
        }

        gettimeofday(&endTime, NULL);

        long start = (startTime.tv_sec * 1000000) + startTime.tv_usec;
        long end = (endTime.tv_sec * 1000000) + endTime.tv_usec;
        double seconds = (end - start) / 1000000.0;

        printf("Ping %d: %.3f seconds\n", i + 1, seconds);
        sleep(1);
    }

    close(sock);

    return 0;
}