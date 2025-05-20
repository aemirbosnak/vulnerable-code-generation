//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_LEN 15
#define SUBNET_LEN 15

typedef struct {
    char ip[IP_LEN];
    char subnet[SUBNET_LEN];
    char broadcast[IP_LEN];
} Subnet;

void print_subnet(Subnet subnet) {
    printf("IP Address: %s\n", subnet.ip);
    printf("Subnet Mask: %s\n", subnet.subnet);
    printf("Broadcast Address: %s\n", subnet.broadcast);
    printf("\n");
}

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
    
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);
    
    for (int i = 0; i < num_subnets; i++) {
        printf("Enter IP address for subnet %d: ", i + 1);
        scanf("%s", subnets[i].ip);
        
        printf("Enter subnet mask for subnet %d: ", i + 1);
        scanf("%s", subnets[i].subnet);
        
        strcpy(subnets[i].broadcast, subnets[i].ip);
        int j = strlen(subnets[i].ip) - 1;
        while (j >= 0 && subnets[i].ip[j] == '.') {
            j--;
        }
        while (j >= 0 && subnets[i].ip[j]!= '.') {
            j--;
        }
        j++;
        while (j < strlen(subnets[i].ip)) {
            subnets[i].broadcast[j] = '255';
            j++;
        }
    }
    
    printf("Subnet Information:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }
    
    return 0;
}