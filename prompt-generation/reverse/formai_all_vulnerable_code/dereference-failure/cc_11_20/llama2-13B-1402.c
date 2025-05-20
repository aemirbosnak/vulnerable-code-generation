//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE_MIN 1024
#define PORT_RANGE_MAX 65535
#define IP_ADDRESS_MAX 4

struct port_scan_params {
    int port_range_min;
    int port_range_max;
    char *ip_address;
    char *output_format;
};

struct port_scan_result {
    int port;
    char *hostname;
    char *service_name;
};

int main(int argc, char *argv[]) {
    struct port_scan_params params;

    // Parse command line arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <IP address> <port range> <output format>\n", argv[0]);
        return 1;
    }

    params.port_range_min = atoi(argv[2]);
    params.port_range_max = atoi(argv[3]);
    params.ip_address = argv[1];
    params.output_format = argv[4];

    // Sanity checks
    if (params.port_range_min > params.port_range_max) {
        fprintf(stderr, "Invalid port range: %d - %d\n", params.port_range_min, params.port_range_max);
        return 2;
    }

    if (params.ip_address == NULL || strlen(params.ip_address) > IP_ADDRESS_MAX) {
        fprintf(stderr, "Invalid IP address: %s\n", params.ip_address);
        return 3;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 4;
    }

    // Set up the socket address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(params.port_range_min);
    inet_pton(AF_INET, params.ip_address, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(sock);
        return 5;
    }

    // Scan the ports
    for (int port = params.port_range_min; port <= params.port_range_max; port++) {
        struct port_scan_result result;
        result.port = port;

        // Send a SYN packet to the port
        int packet_len = sizeof(struct sockaddr_in);
        struct sockaddr_in client_addr;
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);

        sendto(sock, &client_addr, packet_len, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // Wait for a response
        int wait_status = wait(NULL);
        if (wait_status == 0) {
            // Received a response, extract the hostname and service name
            char buffer[1024];
            recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
            result.hostname = strtok(buffer, "\n");
            result.service_name = strtok(NULL, "\n");
        } else {
            // Timed out or error
            result.hostname = NULL;
            result.service_name = NULL;
        }

        // Print the result
        if (result.hostname != NULL && result.service_name != NULL) {
            printf("%d %s %s\n", port, result.hostname, result.service_name);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}