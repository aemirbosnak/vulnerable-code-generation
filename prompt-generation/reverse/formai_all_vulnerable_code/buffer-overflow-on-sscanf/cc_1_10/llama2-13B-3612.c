//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345

// Structure to store rover information
struct rover_info {
    float latitude;
    float longitude;
    float temperature;
};

// Function to create a new rover
struct rover_info create_rover(float lat, float lon, float temp) {
    struct rover_info ri;
    ri.latitude = lat;
    ri.longitude = lon;
    ri.temperature = temp;
    return ri;
}

// Function to send rover information to the base station
void send_rover_info(struct rover_info ri) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    memset(buffer, 0, 1024);
    sprintf(buffer, "%f %f %f", ri.latitude, ri.longitude, ri.temperature);
    send(sock, buffer, strlen(buffer), 0);
    close(sock);
}

// Function to receive rover information from the base station
struct rover_info receive_rover_info() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    struct rover_info ri;
    sscanf(buffer, "%f %f %f", &ri.latitude, &ri.longitude, &ri.temperature);
    close(sock);
    return ri;
}

int main() {
    // Create a new rover
    struct rover_info ri = create_rover(39.7833, -104.9999, 20.0);

    // Send rover information to the base station
    send_rover_info(ri);

    // Receive rover information from the base station
    struct rover_info ri2 = receive_rover_info();

    // Print the received rover information
    printf("Received rover information: %f %f %f\n", ri2.latitude, ri2.longitude, ri2.temperature);

    return 0;
}