//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_NAME "localhost"
#define SERVER_PORT 8080
#define NUM_PINGS 5

int main() {
    int sockfd, ping_cnt, send_len, recv_len, i;
    struct sockaddr_in serv_addr;
    char send_buf[1024], recv_buf[1024];
    time_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Send and receive pings
    ping_cnt = 0;
    for (i = 0; i < NUM_PINGS; i++) {
        start_time = time(NULL);

        // Send a ping message
        snprintf(send_buf, 1024, "Ping");
        send_len = send(sockfd, send_buf, strlen(send_buf), 0);

        // Receive a ping response
        recv_len = recv(sockfd, recv_buf, 1024, 0);

        end_time = time(NULL);

        // Calculate the ping time
        int ping_time = end_time - start_time;

        // Print the ping time
        printf("Ping %d: %d ms\n", ping_cnt, ping_time);

        ping_cnt++;
    }

    // Close the socket
    close(sockfd);

    return 0;
}