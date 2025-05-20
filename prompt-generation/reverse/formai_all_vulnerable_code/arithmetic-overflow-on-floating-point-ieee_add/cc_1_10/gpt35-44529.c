//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>

// Function to calculate average round-trip time
double calculate_average_time(double arr[], int n) {
    double sum = 0.0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum/n;
}

int main() {
    int sock_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    struct timeval tv;
    fd_set rfds;
    int max_fd;
    double rtt[3];
    int seq_num = 0;

    // Creating a socket
    if((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        return EXIT_FAILURE;
    }

    // Configuring socket options for timeouts
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if(setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("Error setting timeout options");
        return EXIT_FAILURE;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    // Configuring server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int n, len;

    // Sending three packets to monitor network quality
    while(seq_num < 3) {
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "Packet %d", seq_num);
        sendto(sock_fd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&serv_addr, sizeof(serv_addr));
        printf("Packet sent: %s\n", buffer);

        // Configuring the descriptors to monitor
        FD_ZERO(&rfds);
        FD_SET(sock_fd, &rfds);

        // Finding the maximum file descriptor value
        max_fd = sock_fd + 1;

        // Waiting for response or timeout
        if(select(max_fd, &rfds, NULL, NULL, &tv) > 0) {
            n = recvfrom(sock_fd, (char *)buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *)&serv_addr, &len);
            buffer[n] = '\0';
            printf("Packet received: %s\n", buffer);
            seq_num++;
            gettimeofday(&(tv), NULL);
            rtt[seq_num-1] = ((double)tv.tv_sec * 1000.0 + (double)tv.tv_usec / 1000.0);
        } else {
            printf("Timeout: packet dropped\n");
            seq_num++;
        }
    }

    double avg_rtt = calculate_average_time(rtt, 3);
    printf("Average packet round-trip time: %lf ms\n", avg_rtt);

    close(sock_fd);

    return 0;
}