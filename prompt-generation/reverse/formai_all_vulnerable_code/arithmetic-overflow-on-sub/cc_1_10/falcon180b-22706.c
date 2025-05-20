//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 256

// Function to calculate the number of hosts in a subnet
int count_hosts(int subnet_size) {
    int hosts = 0;
    for (int i = 1; i < subnet_size; i++) {
        hosts += (subnet_size - i);
    }
    return hosts;
}

// Function to calculate the number of subnets in a given network
int count_subnets(int num_hosts, int subnet_size) {
    int subnets = 0;
    while (num_hosts > 0) {
        subnets++;
        num_hosts -= subnet_size;
    }
    return subnets;
}

// Function to print the subnet information
void print_subnet(int subnet_num, int subnet_size) {
    printf("Subnet %d: ", subnet_num);
    for (int i = 1; i <= subnet_size; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

// Function to calculate and print the subnet information
void calculate_subnets(int num_hosts, int subnet_size) {
    int subnet_num = 1;
    while (num_hosts > 0) {
        printf("Subnet %d: ", subnet_num);
        for (int i = 1; i <= subnet_size; i++) {
            printf("%d ", i);
        }
        printf("\n");
        num_hosts -= subnet_size;
        subnet_num++;
    }
}

int main() {
    int num_hosts, subnet_size;

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter the subnet size: ");
    scanf("%d", &subnet_size);

    if (num_hosts > MAX_SUBNETS || subnet_size > MAX_SUBNET_SIZE) {
        printf("Invalid input. Please enter smaller values.\n");
        return 1;
    }

    int num_subnets = count_subnets(num_hosts, subnet_size);

    printf("Number of subnets: %d\n", num_subnets);

    calculate_subnets(num_hosts, subnet_size);

    return 0;
}