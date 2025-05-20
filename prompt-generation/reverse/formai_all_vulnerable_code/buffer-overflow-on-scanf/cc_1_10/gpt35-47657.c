//FormAI DATASET v1.0 Category: Firewall ; Style: curious
// Welcome to the curious C Firewall example program!
// This program is designed to block certain IP addresses from accessing our network.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_IPS 100
#define BUFFER_SIZE 1024

int main() {
    int i, j, num_ips;
    char ip_str[INET_ADDRSTRLEN];
    char buffer[BUFFER_SIZE];
    struct in_addr ips[MAX_IPS];
    struct in_addr user_ip;
    struct sockaddr_in serv_addr;

    // Ask the user for the number of IPs they want to block
    printf("Welcome to our curious C Firewall program! How many IPs would you like to block? ");
    scanf("%d", &num_ips);

    // Ask the user to enter the IPs they want to block
    printf("Please enter the %d IP addresses you would like to block, one per line: \n", num_ips);
    for (i = 0; i < num_ips; i++) {
        scanf("%s", ip_str);
        inet_pton(AF_INET, ip_str, &ips[i]);
    }

    // Create a socket for the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Could not create socket!");
        return -1;
    }

    // Bind the socket to a port and IP address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Could not bind socket!");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        printf("Could not listen on socket!");
        return -1;
    }

    // Receive incoming connections and check their IP addresses against the blocked list
    while (1) {
        int client_fd = accept(server_fd, (struct sockaddr*)NULL, NULL);
        if (client_fd < 0) {
            printf("Could not accept connection!");
            return -1;
        }

        // Get the IP address of the client
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        getpeername(client_fd, (struct sockaddr*)&addr, &addr_len);
        user_ip = addr.sin_addr;

        // Check if the client's IP address matches one of the blocked IPs
        for (j = 0; j < num_ips; j++) {
            if (ips[j].s_addr == user_ip.s_addr) {
                printf("Connection from blocked IP address %s\n", inet_ntop(AF_INET, &user_ip, buffer, INET_ADDRSTRLEN));
                close(client_fd);
                break;
            }
        }

        // If the IP address was not blocked, allow the connection
        if (j == num_ips) {
            printf("Connection received from IP address %s\n", inet_ntop(AF_INET, &user_ip, buffer, INET_ADDRSTRLEN));
            char message[] = "Welcome to our server!";
            write(client_fd, message, sizeof(message));
            close(client_fd);
        }
    }

    return 0;
}