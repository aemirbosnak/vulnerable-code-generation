//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <poll.h>

// Define constants
#define BAUD_RATE 9600
#define STDIN_FILENO 0
#define DRONE_SOCKET_FILENO 1
#define MAX_MESSAGE_SIZE 100

// Define data structures
typedef struct {
    int x;
    int y;
    int z;
    int w;
} coordinates_t;

typedef struct {
    int x;
    int y;
    int z;
    int w;
} angles_t;

// Define functions
int open_drone_socket(char *socket_path) {
    int drone_socket_fd = open(socket_path, O_RDWR | O_NONBLOCK);
    if (drone_socket_fd < 0) {
        perror("Failed to open drone socket");
        return -1;
    }
    return drone_socket_fd;
}

int send_message(int drone_socket_fd, char *message) {
    int bytes_sent = write(drone_socket_fd, message, strlen(message));
    if (bytes_sent < 0) {
        perror("Failed to send message to drone");
        return -1;
    }
    return bytes_sent;
}

int receive_message(int drone_socket_fd, char *message, int max_size) {
    int bytes_received = read(drone_socket_fd, message, max_size);
    if (bytes_received < 0) {
        perror("Failed to receive message from drone");
        return -1;
    }
    return bytes_received;
}

void print_coordinates(coordinates_t coordinates) {
    printf("X: %d\n", coordinates.x);
    printf("Y: %d\n", coordinates.y);
    printf("Z: %d\n", coordinates.z);
    printf("W: %d\n", coordinates.w);
}

void print_angles(angles_t angles) {
    printf("X: %d\n", angles.x);
    printf("Y: %d\n", angles.y);
    printf("Z: %d\n", angles.z);
    printf("W: %d\n", angles.w);
}

int main() {
    // Open drone socket
    char drone_socket_path[100];
    sprintf(drone_socket_path, "/tmp/drone_socket");
    int drone_socket_fd = open_drone_socket(drone_socket_path);
    if (drone_socket_fd < 0) {
        printf("Failed to open drone socket\n");
        return 1;
    }

    // Send initial message to drone
    char message[MAX_MESSAGE_SIZE];
    sprintf(message, "READY");
    send_message(drone_socket_fd, message);
    printf("Sent initial message to drone\n");

    // Create data structures
    coordinates_t coordinates;
    angles_t angles;

    // Get coordinates from drone
    char coordinates_message[MAX_MESSAGE_SIZE];
    int bytes_received = receive_message(drone_socket_fd, coordinates_message, MAX_MESSAGE_SIZE);
    if (bytes_received < 0) {
        printf("Failed to receive coordinates from drone\n");
        return 1;
    }
    sscanf(coordinates_message, "%d %d %d %d", &coordinates.x, &coordinates.y, &coordinates.z, &coordinates.w);
    printf("Received coordinates from drone: %d %d %d %d\n", coordinates.x, coordinates.y, coordinates.z, coordinates.w);
    print_coordinates(coordinates);

    // Get angles from drone
    char angles_message[MAX_MESSAGE_SIZE];
    bytes_received = receive_message(drone_socket_fd, angles_message, MAX_MESSAGE_SIZE);
    if (bytes_received < 0) {
        printf("Failed to receive angles from drone\n");
        return 1;
    }
    sscanf(angles_message, "%d %d %d %d", &angles.x, &angles.y, &angles.z, &angles.w);
    printf("Received angles from drone: %d %d %d %d\n", angles.x, angles.y, angles.z, angles.w);
    print_angles(angles);

    // Close drone socket
    close(drone_socket_fd);

    return 0;
}