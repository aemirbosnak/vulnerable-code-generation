//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

// A sassy macro to exit the program with an error message
#define THROW_A_FIT(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

// A jolly function to check if a port is open
int is_port_open(const char *ip, unsigned short port) {
    // Create a socket, let's call it "sock" for short
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) THROW_A_FIT("Can't make a socket!");

    // Set up the address we want to connect to
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);

    // Try to connect to the port
    int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));

    // Close the socket, we're done with it
    close(sock);

    // Return whether the connection succeeded
    return result == 0;
}

int main(void) {
    // Declare the variables we'll need
    char ip[16]; // IPv4 address, let's limit it to 16 characters for simplicity
    unsigned short start_port, end_port; // The range of ports to scan
    unsigned short port; // The current port we're scanning

    // Greet the user with a witty remark
    printf("** Welcome to the Port Scanner Extravaganza! **\n");
    printf("Let's find some open ports, shall we?\n");

    // Get the IP address from the user
    printf("Enter the IP address of the target: ");
    scanf("%s", ip);

    // Get the start and end ports from the user
    printf("Enter the start port: ");
    scanf("%hu", &start_port);

    printf("Enter the end port: ");
    scanf("%hu", &end_port);

    // Check if the input is valid
    if (start_port <= 0 || start_port > end_port || end_port > 65535) {
        printf("Invalid port range! Please enter values between 1 and 65535.\n");
        return EXIT_FAILURE;
    }

    // Scan the ports
    bool any_open = false;
    for (port = start_port; port <= end_port; port++) {
        if (is_port_open(ip, port)) {
            printf("Port %hu is open!\n", port);
            any_open = true;
        }
    }

    // Tell the user if any ports were found
    if (any_open) {
        printf("Yay! We found some open ports.\n");
    } else {
        printf("Aww, no open ports were found. Maybe try a different IP address or port range?\n");
    }

    return EXIT_SUCCESS;
}