//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18
#define MAX_CHANNEL_LENGTH 4
#define MAX_FREQUENCY_LENGTH 8
#define MAX_SIGNAL_LENGTH 8
#define MAX_SECURITY_LENGTH 8
#define MAX_TIMESTAMP_LENGTH 24
#define MAX_LINE_LENGTH 1024

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    char channel[MAX_CHANNEL_LENGTH];
    char frequency[MAX_FREQUENCY_LENGTH];
    char signal[MAX_SIGNAL_LENGTH];
    char security[MAX_SECURITY_LENGTH];
    char timestamp[MAX_TIMESTAMP_LENGTH];
} access_point;

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[1024];
    time_t current_time;
    access_point ap;

    if (argc!= 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(12345);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Scanning for wireless networks on %s...\n", argv[1]);

    while (1) {
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            break;
        }
        buffer[n] = '\0';

        if (strncmp(buffer, "AP", 2) == 0) {
            sscanf(buffer, "AP %s %s %s %s %s %s", ap.ssid, ap.bssid, ap.channel, ap.frequency, ap.signal, ap.security);

            current_time = time(NULL);
            strftime(ap.timestamp, MAX_TIMESTAMP_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

            printf("Access Point: %s (%s)\n", ap.ssid, ap.bssid);
            printf("Channel: %s\n", ap.channel);
            printf("Frequency: %s MHz\n", ap.frequency);
            printf("Signal: %s dBm\n", ap.signal);
            printf("Security: %s\n", ap.security);
            printf("Timestamp: %s\n", ap.timestamp);
            printf("\n");
        }
    }

    close(sockfd);
    return 0;
}