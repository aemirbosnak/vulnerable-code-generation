//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 4096

double calculate_time_difference(struct timeval start, struct timeval end)
{
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
}

int main()
{
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE] = {0};
    struct timeval start_time, end_time;
    double time_difference;

    // create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        printf("Failed to create socket\n");
        return -1;
    }

    // set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("8.8.8.8"); // Google DNS server IP address
    server_addr.sin_port = htons(PORT);

    // connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        return -1;
    }

    // send message to server and record start time
    gettimeofday(&start_time, NULL);
    send(sock_fd, buffer, MAX_BUFFER_SIZE, 0);

    // receive response from server and record end time
    recv(sock_fd, buffer, MAX_BUFFER_SIZE, 0);
    gettimeofday(&end_time, NULL);

    // calculate elapsed time and download speed
    time_difference = calculate_time_difference(start_time, end_time);
    double speed = ((double)MAX_BUFFER_SIZE / time_difference) / (1024.0 * 1024.0); // convert to Mbps

    printf("Download Speed: %f Mbps\n", speed);

    close(sock_fd);
    return 0;
}