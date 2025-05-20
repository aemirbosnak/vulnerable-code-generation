//FormAI DATASET v1.0 Category: Audio processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <math.h>

#define PORT 8080
#define SAMPLE_RATE 44100

void playback(int socketfd, int *samples, int sample_count) {
    int bytes_sent = 0;
    int total_bytes_sent = 0;
    while (total_bytes_sent < sample_count * sizeof(int)) {
        bytes_sent = send(socketfd, samples + (total_bytes_sent/sizeof(int)), sample_count * sizeof(int) - total_bytes_sent, 0);
        
        if (bytes_sent == -1) {
            perror("Failed to send data.\n");
            exit(1);
        }

        total_bytes_sent += bytes_sent;
    }
}

void capture(int socketfd, int *samples, int sample_count) {
    int bytes_received = 0;
    int total_bytes_received = 0;
    while (total_bytes_received < sample_count * sizeof(int)) {
        bytes_received = recv(socketfd, samples + (total_bytes_received/sizeof(int)), sample_count * sizeof(int) - total_bytes_received, 0);
        
        if (bytes_received == -1) {
            perror("Failed to receive data.\n");
            exit(1);
        }

        total_bytes_received += bytes_received;
    }
}

void *audio_processing(void *args) {
    int socketfd = *(int *)args;

    int buffer[SAMPLE_RATE];
    int samples_read = 0;

    while ((samples_read = recv(socketfd, buffer, SAMPLE_RATE * sizeof(int), 0)) > 0) {

        // Audio processing code goes here
        // In this example, we'll just apply an amplitude multiplier
        double amplitude_multiplier = 0.5;
        for (int i = 0; i < SAMPLE_RATE; i++) {
            buffer[i] = (int)floor(buffer[i] * amplitude_multiplier);
        }

        playback(socketfd, buffer, SAMPLE_RATE);
    }

    pthread_exit(NULL);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    int buffersize = SAMPLE_RATE * sizeof(int);
    int buffer[SAMPLE_RATE];

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    pthread_t processing_thread;
    if (pthread_create(&processing_thread, NULL, audio_processing, &new_socket) != 0) {
        perror("Failed to create processing thread.");
        exit(1);
    }

    // Now start recording and sending to the processing thread
    while(1) {
        // Record audio
        capture(new_socket, buffer, SAMPLE_RATE);

        // Send audio to processing thread
        if (send(new_socket, buffer, buffersize, 0) == -1) {
            perror("Failed to send data.\n");
            exit(1);
        }
    }

    close(new_socket);
    close(server_fd);

    return 0;
}