#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int ip[4];
    printf("Enter IP address (4 integers separated by spaces): ");
    scanf("%d %d %d %d", &ip[0], &ip[1], &ip[2], &ip[3]);
    
    printf("Subnet mask: 255.255.255.0\n");
    printf("Network address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], 0);
    printf("Broadcast address: %d.%d.%d.255\n", ip[0], ip[1], ip[2], 255);
    
    return 0;
}
