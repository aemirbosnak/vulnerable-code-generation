//FormAI DATASET v1.0 Category: Firewall ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define firewall rules
const char *ALLOWED_IPS[] = {"192.168.1.1", "10.0.0.1", "127.0.0.1"};
const int ALLOWED_PORTS[] = {80, 443, 22};

// Check if IP address is allowed
int is_ip_allowed(const char *ip) {
    int i;
    for (i = 0; i < sizeof(ALLOWED_IPS) / sizeof(ALLOWED_IPS[0]); i++) {
        if (strcmp(ip, ALLOWED_IPS[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Check if port is allowed
int is_port_allowed(int port) {
    int i;
    for (i = 0; i < sizeof(ALLOWED_PORTS) / sizeof(ALLOWED_PORTS[0]); i++) {
        if (port == ALLOWED_PORTS[i]) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    char ip[16];
    int port;

    // Get IP address and port
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter port number: ");
    scanf("%d", &port);

    // Check if IP and port are allowed
    if (is_ip_allowed(ip) && is_port_allowed(port)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}