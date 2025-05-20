//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

// Function to print usage instructions
void print_usage() {
    printf("Usage:./ping <host> <port>\n");
}

// Function to perform a ping test
int ping_test(char *host, int port) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket.\n");
        return -1;
    }

    // Get host information
    host_info = gethostbyname(host);
    if (host_info == NULL) {
        printf("Failed to resolve host name.\n");
        close(sockfd);
        return -1;
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to server
    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Failed to connect to server.\n");
        close(sockfd);
        return -1;
    }

    // Ping test successful
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage();
        return -1;
    }

    int retval = ping_test(argv[1], atoi(argv[2]));
    if (retval == 0) {
        printf("Ping test successful.\n");
    } else {
        printf("Ping test failed.\n");
    }

    return 0;
}