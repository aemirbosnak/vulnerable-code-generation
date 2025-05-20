//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTS 100
#define MAX_PINGS 10
#define PING_INTERVAL 1 // in seconds

typedef struct {
    char *hostname;
    int response_time;
} Host;

void print_usage() {
    printf("Usage:./ping_test <host1> <host2>... <hostN>\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    int num_hosts = 0;
    Host hosts[MAX_HOSTS];
    for (int i = 1; i < argc; i++) {
        if (num_hosts >= MAX_HOSTS) {
            printf("Error: Too many hosts specified.\n");
            return 1;
        }
        strncpy(hosts[num_hosts].hostname, argv[i], strlen(argv[i]));
        hosts[num_hosts].response_time = 0;
        num_hosts++;
    }

    int num_pings = 0;
    while (num_pings < MAX_PINGS) {
        for (int i = 0; i < num_hosts; i++) {
            int sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock == -1) {
                printf("Error: Failed to create socket.\n");
                return 1;
            }

            struct sockaddr_in server_addr;
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            inet_pton(AF_INET, hosts[i].hostname, &server_addr.sin_addr);
            server_addr.sin_port = htons(80);

            if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
                printf("Error: Failed to connect to %s.\n", hosts[i].hostname);
                close(sock);
                continue;
            }

            gettimeofday(&hosts[i].response_time, NULL);
            close(sock);
            num_pings++;
        }
        sleep(PING_INTERVAL);
    }

    printf("Ping results:\n");
    for (int i = 0; i < num_hosts; i++) {
        double avg_response_time = hosts[i].response_time / 1000000.0;
        printf("%s: %.2f ms\n", hosts[i].hostname, avg_response_time);
    }

    return 0;
}