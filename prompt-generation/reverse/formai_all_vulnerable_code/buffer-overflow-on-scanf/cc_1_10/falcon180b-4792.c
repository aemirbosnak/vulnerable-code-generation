//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME 64

// Struct to hold subnet information
typedef struct {
    char name[MAX_SUBNET_NAME];
    int size;
} Subnet;

// Function to initialize a subnet with default values
void init_subnet(Subnet* subnet) {
    strcpy(subnet->name, "Unnamed");
    subnet->size = 0;
}

// Function to print a subnet's information
void print_subnet(Subnet* subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("Subnet Size: %d\n\n", subnet->size);
}

// Function to calculate the number of hosts in a subnet
int calculate_hosts(int size) {
    return (int)pow(2, size) - 2;
}

// Function to calculate the number of subnets in a network
int calculate_subnets(int size) {
    return (int)pow(2, size) - 1;
}

// Function to calculate the broadcast address of a subnet
void calculate_broadcast(char* ip, int size, char* broadcast) {
    int i;
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            broadcast[i] = '.';
        } else {
            broadcast[i] = ip[i];
        }
    }
    broadcast[strlen(ip)] = '\0';
    broadcast[strlen(broadcast) - 1] = '255';
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet subnets[MAX_SUBNETS];
    int i;
    for (i = 0; i < num_subnets; i++) {
        init_subnet(&subnets[i]);
        printf("Enter subnet %d information:\n", i+1);
        printf("Subnet Name: ");
        scanf("%s", subnets[i].name);
        printf("Subnet Size: ");
        scanf("%d", &subnets[i].size);
    }

    printf("\nSubnet Information:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}