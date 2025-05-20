//FormAI DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Let's start by defining our firewall rules

#define ALLOWED_IPS {"127.0.0.1", "10.0.0.1", "192.168.1.1"}
#define BLOCKED_PORTS {80, 443, 666}

// Now, let's create a function that will check if an IP is allowed

int check_ip(char *ip) {
    char *allowed_ips[] = ALLOWED_IPS;

    for (int i = 0; i < sizeof(allowed_ips) / sizeof(allowed_ips[0]); i++) {
        if (strcmp(ip, allowed_ips[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// And a function that will check if a port is blocked

int check_port(int port) {
    int blocked_ports[] = BLOCKED_PORTS;

    for (int i = 0; i < sizeof(blocked_ports) / sizeof(blocked_ports[0]); i++) {
        if (port == blocked_ports[i]) {
            return 1;
        }
    }

    return 0;
}

// Finally, let's put it all together in our main function

int main() {
    char ip[16];
    int port;

    printf("Welcome to the funniest firewall you'll ever see!\n\n");

    while (1) {
        printf("Enter an IP address (or 'exit' to quit): ");
        scanf("%s", ip);

        if (strcmp(ip, "exit") == 0) {
            printf("Thanks for using our firewall! Goodbye!\n");
            exit(0);
        }

        printf("Enter a port number: ");
        scanf("%d", &port);

        if (check_ip(ip) && !check_port(port)) {
            printf("Access granted! Welcome to the internet!\n\n");
        } else {
            printf("Access denied! You shall not pass!\n\n");
        }
    }

    return 0;
}