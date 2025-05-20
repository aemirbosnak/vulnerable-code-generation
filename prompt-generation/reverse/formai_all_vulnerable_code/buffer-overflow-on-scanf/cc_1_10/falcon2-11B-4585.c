//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define a struct to hold information about each device on the network
struct Device {
    char name[100];
    char ip_addr[100];
};

// Function to map a device name to its IP address
char* map(char* device_name) {
    // Try to resolve the IP address of the given device
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // Use IPv4 only
    hints.ai_socktype = SOCK_STREAM; // TCP only
    hints.ai_protocol = 0; // Any protocol
    if (getaddrinfo(device_name, NULL, &hints, &res)) {
        perror("getaddrinfo() failed");
        exit(EXIT_FAILURE);
    }

    // Retrieve the IP address from the first result returned by getaddrinfo()
    struct sockaddr_in* sa = (struct sockaddr_in*) res->ai_addr;
    char ip_string[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &sa->sin_addr, ip_string, sizeof(ip_string));

    // Free resources allocated by getaddrinfo()
    freeaddrinfo(res);

    return ip_string;
}

// Main function
int main() {
    char device_name[100];
    printf("Enter a device name: ");
    scanf("%s", device_name);

    // Map the device name to its IP address
    char* ip_addr = map(device_name);
    if (ip_addr == NULL) {
        printf("Error: device not found\n");
        return 1;
    }

    // Print the IP address of the device
    printf("IP address of %s is: %s\n", device_name, ip_addr);

    // Clean up allocated memory
    free(ip_addr);

    return 0;
}