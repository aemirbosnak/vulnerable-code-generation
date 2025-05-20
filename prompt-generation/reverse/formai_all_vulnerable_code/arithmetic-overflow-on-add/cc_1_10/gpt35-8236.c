//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 5000

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    int socket_fd, server_response;
    char buffer[BUFFER_SIZE];
    double download_speed, upload_speed;
    time_t start_time, end_time;
    ssize_t bytes_sent, bytes_received;
    long total_bytes_sent = 0, total_bytes_received = 0;

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socket_fd < 0) {
        perror("Could not create a socket");
        exit(EXIT_FAILURE);
    }

    // Configure the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if(connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Could not connect to server");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // Start the download speed test
    printf("Downloading data...\n");
    start_time = time(NULL);
    while(total_bytes_received < BUFFER_SIZE * 10) {
        bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if(bytes_received < 0) {
            perror("Error receiving data");
            close(socket_fd);
            exit(EXIT_FAILURE);
        }
        total_bytes_received += bytes_received;
    }
    end_time = time(NULL);

    // Calculate the download speed
    download_speed = (double) (total_bytes_received / 1024) / difftime(end_time, start_time);
    printf("Download speed: %.2f KB/s\n", download_speed);

    // Start the upload speed test
    printf("Uploading data...\n");
    start_time = time(NULL);
    while(total_bytes_sent < BUFFER_SIZE * 10) {
        bytes_sent = send(socket_fd, buffer, BUFFER_SIZE, 0);
        if(bytes_sent < 0) {
            perror("Error sending data");
            close(socket_fd);
            exit(EXIT_FAILURE);
        }
        total_bytes_sent += bytes_sent;
    }
    end_time = time(NULL);

    // Calculate the upload speed
    upload_speed = (double) (total_bytes_sent / 1024) / difftime(end_time, start_time);
    printf("Upload speed: %.2f KB/s\n", upload_speed);

    // Close the socket and exit
    close(socket_fd);
    return 0;
}