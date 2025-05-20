//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PACKET_SIZE 4096
#define LOG_FILE "intrusion.log"

void log_intrusion(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Unable to open log file");
        return;
    }
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

void process_packet(char *buffer, struct sockaddr_in *addr) {
    // For demonstration, we will consider any packet from a suspicious IP as an intrusion
    const char *suspicious_ip = "192.168.1.10";
    char packet_source[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(addr->sin_addr), packet_source, INET_ADDRSTRLEN);

    if (strcmp(packet_source, suspicious_ip) == 0) {
        char log_message[256];
        snprintf(log_message, sizeof(log_message), "Intrusion detected from IP: %s", packet_source);
        log_intrusion(log_message);
        printf("%s\n", log_message);
    } else {
        printf("Packet from %s processed normally.\n", packet_source);
    }
}

int main() {
    int sockfd;
    char buffer[PACKET_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888); // Listening on port 8888

    // Bind the socket to the port
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    printf("Listening for UDP packets on port 8888...\n");

    // Listen for incoming packets
    while (1) {
        ssize_t n = recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        if (n < 0) {
            perror("Receive failed");
            close(sockfd);
            return EXIT_FAILURE;
        }
        buffer[n] = '\0'; // Null-terminate the buffer

        // Process the incoming packet
        process_packet(buffer, &client_addr);
    }

    // Close the socket (unreachable in this loop)
    close(sockfd);
    return EXIT_SUCCESS;
}