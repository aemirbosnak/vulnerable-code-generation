//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>

#define SIZE 1024
#define PORT 80

int main(int argc, char *argv[]) {

    // Check for IP address argument
    if (argc != 2) {
        printf("Please provide an IP address.\n");
        return 1;
    }

    // Create socket structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to server
    int connect_status = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_status == -1) {
        perror("connect");
        return 1;
    }

    // Send HTTP GET request
    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    int send_status = send(socket_fd, request, strlen(request), 0);
    if (send_status == -1) {
        perror("send");
        return 1;
    }

    // Receive HTTP response
    char buffer[SIZE];
    int total_received = 0;
    struct timeval start, end;
    double elapsed_time;
    gettimeofday(&start, NULL);

    while (1) {
        int received = recv(socket_fd, buffer, SIZE-1, 0);
        if (received == -1) {
            perror("recv");
            return 1;
        } else if (received == 0) {
            break;
        } else {
            total_received += received;
        }
    }

    gettimeofday(&end, NULL);
    elapsed_time = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / 1000000.0);

    // Calculate and print download speed
    double speed = (total_received / 1000000.0) / elapsed_time;
    printf("Download speed: %.2f Mbps\n", speed);

    // Close socket
    close(socket_fd);

    return 0;
}