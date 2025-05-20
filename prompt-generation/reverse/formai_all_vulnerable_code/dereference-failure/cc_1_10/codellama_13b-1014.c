//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
// C Network Topology Mapper Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 256
#define MAX_BUFFER 1024
#define MAX_DEVICES 10

// Structure to represent a device
typedef struct {
    char name[MAX_LINE];
    char ip_addr[MAX_LINE];
    char mac_addr[MAX_LINE];
} device_t;

// Structure to represent a network
typedef struct {
    char name[MAX_LINE];
    device_t devices[MAX_DEVICES];
    int num_devices;
} network_t;

// Function to parse a line of text and extract the device information
device_t parse_device_line(char *line) {
    device_t device;
    char *token;

    token = strtok(line, " ");
    strcpy(device.name, token);

    token = strtok(NULL, " ");
    strcpy(device.ip_addr, token);

    token = strtok(NULL, " ");
    strcpy(device.mac_addr, token);

    return device;
}

// Function to parse a line of text and extract the network information
network_t parse_network_line(char *line) {
    network_t network;
    char *token;

    token = strtok(line, " ");
    strcpy(network.name, token);

    token = strtok(NULL, " ");
    network.num_devices = atoi(token);

    for (int i = 0; i < network.num_devices; i++) {
        token = strtok(NULL, " ");
        network.devices[i] = parse_device_line(token);
    }

    return network;
}

// Function to print the device information
void print_device(device_t device) {
    printf("%s: %s (%s)\n", device.name, device.ip_addr, device.mac_addr);
}

// Function to print the network information
void print_network(network_t network) {
    printf("%s:\n", network.name);
    for (int i = 0; i < network.num_devices; i++) {
        print_device(network.devices[i]);
    }
}

int main() {
    char buffer[MAX_BUFFER];
    char *line;
    network_t network;
    device_t device;

    // Read input from stdin
    while (fgets(buffer, MAX_BUFFER, stdin) != NULL) {
        // Parse the line of text and extract the network information
        network = parse_network_line(buffer);

        // Print the network information
        print_network(network);
    }

    return 0;
}