//FormAI DATASET v1.0 Category: Firewall ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Firewall {
    char name[20];
    char ip_address[16];
    int port_number;
} Firewall;

bool is_allowed(Firewall firewalls[], int num_firewalls, char* ip_address, int port_number) {
    for (int i = 0; i < num_firewalls; i++) {
        if (strcmp(firewalls[i].ip_address, ip_address) == 0 && firewalls[i].port_number == port_number) {
            return true;
        }
    }
    return false;
}

int main() {
    int num_firewalls;
    printf("Enter the number of firewalls: ");
    scanf("%d", &num_firewalls);
    
    Firewall firewalls[num_firewalls];
    printf("Enter details of firewalls:\n");
    
    for (int i = 0; i < num_firewalls; i++) {
        printf("Enter name of firewall %d: ", i+1);
        scanf("%s", firewalls[i].name);
        printf("Enter IP address of firewall %d: ", i+1);
        scanf("%s", firewalls[i].ip_address);
        printf("Enter port number of firewall %d: ", i+1);
        scanf("%d", &firewalls[i].port_number);
    }
    
    printf("Firewalls configured successfully!\n");
    printf("---------------------------------\n");
    
    char ip_address[16];
    int port_number;
    
    while (true) {
        printf("Enter IP address to access: ");
        scanf("%s", ip_address);
        printf("Enter port number to access: ");
        scanf("%d", &port_number);
        
        if (is_allowed(firewalls, num_firewalls, ip_address, port_number)) {
            printf("Access granted!\n");
        }
        else {
            printf("Access denied! Please contact your administrator.\n");
        }
        printf("---------------------------------\n");
    }
    
    return 0;
}