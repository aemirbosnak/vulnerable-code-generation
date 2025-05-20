//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_ATTEMPTS 5
#define FUTURISTIC_MESSAGE_LENGTH 256

// Function to calculate checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }

    if (len == 1) {
        sum += *(unsigned char *)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to create the ICMP packet
void create_icmp_packet(char *buffer) {
    struct icmp *icmp_hdr = (struct icmp *)buffer;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = 1;
    icmp_hdr->icmp_cksum = checksum(icmp_hdr, PACKET_SIZE);
}

// Function to print current timestamp
void print_timestamp() {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline
    printf("Timestamp: %s\n", timestamp);
}

// Function to log the results
void log_result(const char *message) {
    FILE *logfile = fopen("ping_log.txt", "a");
    if (logfile != NULL) {
        fprintf(logfile, "%s\n", message);
        fclose(logfile);
    }
}

// AI feedback based on response time
void ai_feedback(float rtt) {
    if (rtt < 50.0) {
        printf("AI Status: Excellent connection!\n");
    } else if (rtt < 100.0) {
        printf("AI Status: Good connection.\n");
    } else if (rtt < 200.0) {
        printf("AI Status: Average connection.\n");
    } else {
        printf("AI Status: Poor connection! Investigate the network.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    struct sockaddr_in addr;
    struct sockaddr_in r_addr;
    char buffer[PACKET_SIZE];
    int sockfd;
    ssize_t bytes_sent, bytes_recv;
    struct timeval timeout;
    fd_set read_fds;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket Error");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    inet_pton(AF_INET, hostname, &addr.sin_addr);

    // Set socket timeout
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    
    for (int attempts = 0; attempts < MAX_ATTEMPTS; attempts++) {
        create_icmp_packet(buffer);
        print_timestamp();
        
        bytes_sent = sendto(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr));
        if (bytes_sent <= 0) {
            perror("Send Error");
            continue;
        }

        // Wait for a response
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);
        
        int ready = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
        
        if (ready > 0) {
            socklen_t len = sizeof(r_addr);
            bytes_recv = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &len);
            if (bytes_recv <= 0) {
                perror("Recv Error");
                continue;
            }
            
            struct iphdr *ip_hdr = (struct iphdr *)buffer;
            struct icmp *icmp_hdr = (struct icmp *)(buffer + (ip_hdr->ihl * 4));
            
            if (icmp_hdr->icmp_type == ICMP_ECHOREPLY) {
                printf("Received reply from %s\n", hostname);
                float rtt = (float)(TIMEOUT * 1000);  // Simulated RTT in ms
                printf("RTT: %.2f ms\n", rtt);
                char result[FUTURISTIC_MESSAGE_LENGTH];
                snprintf(result, sizeof(result), "Ping to %s successful: RTT = %.2f ms", hostname, rtt);
                log_result(result);
                ai_feedback(rtt);
            }
        } else {
            printf("Request timed out.\n");
            log_result("Ping request timed out.");
        }

        sleep(1); // Pause between pings
    }

    close(sockfd);
    return 0;
}