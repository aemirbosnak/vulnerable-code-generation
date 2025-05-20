//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void log_event(const char *event) {
    FILE *log_file = fopen("intrusion_log.txt", "a");
    if (log_file) {
        time_t now = time(NULL);
        fprintf(log_file, "[%s] %s\n", ctime(&now), event);
        fclose(log_file);
    } else {
        perror("Unable to open log file");
    }
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nShutting down the intrusion detection system...\n");
        exit(0);
    }
}

int check_ip_address(const char *ip_address) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip_address, &(sa.sin_addr)) != 0;
}

void monitor_network_activity() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Listening for network activity on port %d\n", PORT);

    while (1) {
        ssize_t n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL,
                             (struct sockaddr *)&client_addr, &client_len);
        buffer[n] = '\0';

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);

        if (n < 0) {
            perror("Receive failed");
        } else {
            char log_msg[100];
            snprintf(log_msg, sizeof(log_msg), "Received packet from %s: %s", client_ip, buffer);
            log_event(log_msg);

            if (!check_ip_address(client_ip)) {
                log_event("Potential intrusion detected from invalid IP.");
            }
        }
    }
    close(sockfd);
}

int main() {
    signal(SIGINT, signal_handler);
    monitor_network_activity();
    return 0;
}