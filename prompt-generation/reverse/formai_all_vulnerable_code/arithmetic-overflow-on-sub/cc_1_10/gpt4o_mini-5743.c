//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define TARGET_IP "192.168.1.1" // Change this for the target you want to monitor
#define TARGET_PORT 80           // Change this for a different service port
#define LOG_FILE "QoS_monitor.log"

void write_log(const char *message) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile != NULL) {
        fprintf(logfile, "%s\n", message);
        fclose(logfile);
    } else {
        perror("Could not open log file");
    }
}

// Function to check connectivity
int check_connectivity() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 0; // Connection failed
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(TARGET_PORT);
    inet_pton(AF_INET, TARGET_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        return 0; // Connection failed
    }

    close(sockfd);
    return 1; // Connection succeeded
}

// Function to measure round-trip time (RTT)
double measure_rtt() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    struct timeval start, end;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(TARGET_PORT);
    inet_pton(AF_INET, TARGET_IP, &server_addr.sin_addr);

    gettimeofday(&start, NULL); // Start the timer
    if (sendto(sockfd, "Ping", strlen("Ping"), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Send failed");
        close(sockfd);
        return -1;
    }

    socklen_t addr_len = sizeof(server_addr);
    if (recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len) < 0) {
        perror("Receive failed");
        close(sockfd);
        return -1;
    }

    gettimeofday(&end, NULL); // Stop the timer
    close(sockfd);

    double rtt = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
    return rtt; // Return Round-Trip Time
}

// Function to evaluate and log the quality of service
void evaluate_qos() {
    int connectivity = check_connectivity();
    double rtt = measure_rtt();

    if (connectivity) {
        write_log("Connectivity: OK");
    } else {
        write_log("Connectivity: FAIL");
    }

    if (rtt >= 0) {
        char log_string[100];
        snprintf(log_string, sizeof(log_string), "RTT: %.2f ms", rtt);
        write_log(log_string);
    } else {
        write_log("RTT measurement: FAIL");
    }
}

int main() {
    while (1) {
        evaluate_qos();
        sleep(5); // Monitor every 5 seconds
    }
    return 0;
}