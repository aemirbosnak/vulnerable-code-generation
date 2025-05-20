//FormAI DATASET v1.0 Category: Firewall ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>

/* This is a custom C Firewall example program that blocks incoming and outgoing connections using iptables rules. */

int main(int argc, char *argv[]) {

    // Check if the program is being run as root
    if(getuid()) {
        printf("This program must be run as root!\n");
        exit(EXIT_FAILURE);
    }

    // Define the IP address and port number to block
    char *ip_address = "192.168.1.100";
    int port_number = 80;

    // Create the iptables rules to block incoming and outgoing traffic
    char command[100];
    sprintf(command, "iptables -A INPUT -s %s -p tcp --dport %d -j DROP", ip_address, port_number);
    system(command);
    sprintf(command, "iptables -A OUTPUT -d %s -p tcp --dport %d -j DROP", ip_address, port_number);
    system(command);

    // Notify the user that the IP address and port number are being blocked
    printf("Incoming and outgoing connections to %s:%d are now blocked!\n", ip_address, port_number);

    // Keep the program running until the user decides to exit
    while (1) {

        // Wait for user input
        char input[10];
        printf("Enter exit to stop blocking traffic: ");
        scanf("%s", input);

        // Check if the user wants to exit
        if (!strcmp(input, "exit")) {

            // Remove the iptables rules that block incoming and outgoing traffic
            sprintf(command, "iptables -D INPUT -s %s -p tcp --dport %d -j DROP", ip_address, port_number);
            system(command);
            sprintf(command, "iptables -D OUTPUT -d %s -p tcp --dport %d -j DROP", ip_address, port_number);
            system(command);

            // Notify the user that the IP address and port number are no longer blocked
            printf("Incoming and outgoing connections to %s:%d are no longer blocked!\n", ip_address, port_number);

            // Exit the program
            exit(EXIT_SUCCESS);
        }
    }
}