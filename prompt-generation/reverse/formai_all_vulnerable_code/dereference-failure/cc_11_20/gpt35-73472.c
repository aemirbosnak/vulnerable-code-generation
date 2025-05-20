//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_DEVICES 256

int main(int argc, char *argv[])
{
    // Check for IP address or domain name argument.
    if (argc < 2) {
        printf("Usage: ./topology_mapper hostname_or_ip_address\n");
        exit(EXIT_FAILURE);
    }

    // Attempt to resolve hostname or IP address.
    struct hostent *host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        printf("Error: Could not resolve host.\n");
        exit(EXIT_FAILURE);
    }

    // Create socket for connecting to remote host.
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Error: Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize remote address structure.
    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET; 
    remote_address.sin_port = htons(80); 
    remote_address.sin_addr = *((struct in_addr *) host_info->h_addr);

    // Connect to remote host.
    if (connect(socket_fd, (struct sockaddr *) &remote_address, sizeof(remote_address)) < 0) {
        printf("Error: Could not connect to host.\n");
        exit(EXIT_FAILURE);
    }

    // Send HTTP GET request to host.
    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", host_info->h_name);
    if (send(socket_fd, request, strlen(request), 0) != strlen(request)) {
        printf("Error: Could not send request.\n");
        exit(EXIT_FAILURE);
    }

    // Receive response from host.
    char response[BUFFER_SIZE];
    int bytes_received = recv(socket_fd, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        printf("Error: Could not receive response.\n");
        exit(EXIT_FAILURE);
    }

    // Parse HTML to find links.
    char *link_start = strstr(response, "<a");
    int num_devices = 0;
    int link_count = 0;
    char links[MAX_DEVICES][BUFFER_SIZE];
    while (link_start != NULL && num_devices < MAX_DEVICES) {
        link_count++;
        char *link_url_start = strchr(link_start, '\"');
        if (link_url_start != NULL) {
            link_url_start++;
            char *link_url_end = strchr(link_url_start, '\"');
            if (link_url_end != NULL) {
                int link_url_length = link_url_end - link_url_start;
                strncpy(links[num_devices], link_url_start, link_url_length);
                links[num_devices][link_url_length] = '\0';
                num_devices++;
            }
        }
        link_start = strstr(link_start + 1, "<a");
    }

    // Close connection to remote host.
    close(socket_fd);

    // Print list of devices found.
    printf("Devices found at %s:\n", argv[1]);
    for (int i=0; i<num_devices; i++) {
        printf("  %d. %s\n", i+1, links[i]);
    }
    printf("Total devices found: %d\n", num_devices);

    // Exit program.
    exit(EXIT_SUCCESS);
}