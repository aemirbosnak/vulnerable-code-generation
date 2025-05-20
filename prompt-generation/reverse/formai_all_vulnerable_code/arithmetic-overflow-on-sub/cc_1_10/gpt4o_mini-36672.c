//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netdb.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024
#define PING_COUNT 4
#define TIMEOUT 2

void log_result(const char* hostname, const char* result) {
    FILE *log_file = fopen("network_qos_log.txt", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    fprintf(log_file, "Hostname: %s, Result: %s\n", hostname, result);
    fclose(log_file);
}

void ping_host(const char* hostname) {
    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        log_result(hostname, "Socket creation failed");
        return;
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        perror("No such host");
        log_result(hostname, "No such host");
        close(sockfd);
        return;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    for (int i = 0; i < PING_COUNT; i++) {
        struct timeval start, end;
        gettimeofday(&start, NULL);
        
        if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("Connection failed");
            log_result(hostname, "Connection failed");
            close(sockfd);
            return;
        }
        
        gettimeofday(&end, NULL);
        close(sockfd);

        long elapsed_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
        
        char log_message[100];
        snprintf(log_message, sizeof(log_message), "Ping %d to %s succeeded. Time: %ld ms", i + 1, hostname, elapsed_time);
        log_result(hostname, log_message);
        sleep(1); // Delay between pings
    }
}

void display_log() {
    FILE *log_file = fopen("network_qos_log.txt", "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    char line[MAX_BUFFER_SIZE];
    printf("Network Quality of Service Log:\n");
    while (fgets(line, sizeof(line), log_file)) {
        printf("%s", line);
    }

    fclose(log_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];

    // Clear the log file at the start
    FILE *log_file = fopen("network_qos_log.txt", "w");
    if (log_file != NULL) {
        fclose(log_file);
    } else {
        perror("Error initializing log file");
    }

    printf("Monitoring QoS for host: %s\n", hostname);
    ping_host(hostname);
    display_log();

    return EXIT_SUCCESS;
}