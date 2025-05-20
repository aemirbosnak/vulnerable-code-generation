//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_HOSTS 10

// Data structures
typedef struct {
    char hostname[256];
    int port;
    int sockfd;
    struct sockaddr_in addr;
    int num_packets_sent;
    int num_packets_received;
    int num_packets_lost;
    double avg_rtt;
    double max_rtt;
    double min_rtt;
} Host;

typedef struct {
    Host hosts[MAX_HOSTS];
    int num_hosts;
} QoSMonitor;

// Function prototypes
int init_qos_monitor(QoSMonitor *monitor, char *hosts_file);
void send_packets(QoSMonitor *monitor);
void receive_packets(QoSMonitor *monitor);
void print_results(QoSMonitor *monitor);

// Main function
int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hosts_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize QoS monitor
    QoSMonitor monitor;
    if (init_qos_monitor(&monitor, argv[1]) == -1) {
        perror("init_qos_monitor");
        exit(EXIT_FAILURE);
    }

    // Send packets
    send_packets(&monitor);

    // Receive packets
    receive_packets(&monitor);

    // Print results
    print_results(&monitor);

    return EXIT_SUCCESS;
}

// Initialize QoS monitor
int init_qos_monitor(QoSMonitor *monitor, char *hosts_file) {
    // Open hosts file
    FILE *file = fopen(hosts_file, "r");
    if (file == NULL) {
        return -1;
    }

    // Read hosts from file
    int num_hosts = 0;
    while (fscanf(file, "%s %d", monitor->hosts[num_hosts].hostname, &monitor->hosts[num_hosts].port) != EOF) {
        num_hosts++;
    }

    // Close hosts file
    fclose(file);

    // Set number of hosts
    monitor->num_hosts = num_hosts;

    // Create sockets
    for (int i = 0; i < num_hosts; i++) {
        monitor->hosts[i].sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (monitor->hosts[i].sockfd == -1) {
            return -1;
        }

        // Set socket address
        monitor->hosts[i].addr.sin_family = AF_INET;
        monitor->hosts[i].addr.sin_port = htons(monitor->hosts[i].port);
        if (inet_pton(AF_INET, monitor->hosts[i].hostname, &monitor->hosts[i].addr.sin_addr) != 1) {
            return -1;
        }
    }

    return 0;
}

// Send packets
void send_packets(QoSMonitor *monitor) {
    // Send packets to each host
    for (int i = 0; i < monitor->num_hosts; i++) {
        char buffer[MAX_BUFFER_SIZE];
        memset(buffer, '\0', MAX_BUFFER_SIZE);
        sprintf(buffer, "Hello from QoS monitor!");

        sendto(monitor->hosts[i].sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&monitor->hosts[i].addr, sizeof(monitor->hosts[i].addr));

        monitor->hosts[i].num_packets_sent++;
    }
}

// Receive packets
void receive_packets(QoSMonitor *monitor) {
    // Receive packets from each host
    fd_set readfds;
    FD_ZERO(&readfds);

    // Add sockets to fd_set
    for (int i = 0; i < monitor->num_hosts; i++) {
        FD_SET(monitor->hosts[i].sockfd, &readfds);
    }

    // Set timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    int num_ready_sockets = select(FD_SETSIZE, &readfds, NULL, NULL, &timeout);

    while (num_ready_sockets > 0) {
        // Check which sockets are ready
        for (int i = 0; i < monitor->num_hosts; i++) {
            if (FD_ISSET(monitor->hosts[i].sockfd, &readfds)) {
                char buffer[MAX_BUFFER_SIZE];
                memset(buffer, '\0', MAX_BUFFER_SIZE);
                
                struct sockaddr_in addr;
                socklen_t addr_len = sizeof(addr);
                recvfrom(monitor->hosts[i].sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&addr, &addr_len);

                monitor->hosts[i].num_packets_received++;
                monitor->hosts[i].num_packets_lost = monitor->hosts[i].num_packets_sent - monitor->hosts[i].num_packets_received;

                // Calculate RTT
                struct timeval recv_time;
                gettimeofday(&recv_time, NULL);
                double rtt = (recv_time.tv_sec - monitor->hosts[i].addr.sin_addr.s_addr) * 1000000 + (recv_time.tv_usec - monitor->hosts[i].addr.sin_addr.s_addr) % 1000000;

                if (monitor->hosts[i].avg_rtt == 0) {
                    monitor->hosts[i].avg_rtt = rtt;
                } else {
                    monitor->hosts[i].avg_rtt = (monitor->hosts[i].avg_rtt * (monitor->hosts[i].num_packets_received - 1) + rtt) / monitor->hosts[i].num_packets_received;
                }

                if (rtt > monitor->hosts[i].max_rtt) {
                    monitor->hosts[i].max_rtt = rtt;
                }

                if (rtt < monitor->hosts[i].min_rtt) {
                    monitor->hosts[i].min_rtt = rtt;
                }
            }
        }

        // Update fd_set
        FD_ZERO(&readfds);
        for (int i = 0; i < monitor->num_hosts; i++) {
            FD_SET(monitor->hosts[i].sockfd, &readfds);
        }

        // Set timeout
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        num_ready_sockets = select(FD_SETSIZE, &readfds, NULL, NULL, &timeout);
    }
}

// Print results
void print_results(QoSMonitor *monitor) {
    // Print header
    printf("%-20s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Hostname", "Port", "Packets Sent", "Packets Received", "Packets Lost", "Avg RTT (ms)", "Max RTT (ms)");

    // Print results for each host
    for (int i = 0; i < monitor->num_hosts; i++) {
        printf("%-20s %-10d %-10d %-10d %-10d %-10.2f %-10.2f\n", monitor->hosts[i].hostname, monitor->hosts[i].port, monitor->hosts[i].num_packets_sent, monitor->hosts[i].num_packets_received, monitor->hosts[i].num_packets_lost, monitor->hosts[i].avg_rtt, monitor->hosts[i].max_rtt);
    }
}