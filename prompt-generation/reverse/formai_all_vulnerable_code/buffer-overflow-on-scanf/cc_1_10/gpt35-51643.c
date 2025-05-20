//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the C Subnet Calculator!\n");

    int num_hosts, num_subnets;
    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    int bits_needed_hosts = 1, bits_needed_subnets = 1;
    int temp_hosts = num_hosts, temp_subnets = num_subnets;

    while(temp_hosts > 2){
        bits_needed_hosts++;
        temp_hosts = temp_hosts/2;
    }

    while(temp_subnets > 2){
        bits_needed_subnets++;
        temp_subnets = temp_subnets/2;
    }

    printf("\nCalculation in progress...\n");
    printf("----------------------------------------------------\n");

    printf("Number of bits needed for hosts: %d\n", bits_needed_hosts);
    printf("Number of bits needed for subnets: %d\n", bits_needed_subnets);

    int total_bits_needed = bits_needed_hosts + bits_needed_subnets;

    printf("Total number of bits needed: %d\n", total_bits_needed);

    int num_addresses = 1;
    for(int i = 0; i < total_bits_needed-2; i++){
        num_addresses *= 2;
    }

    int usable_addresses = num_addresses - 2;

    printf("Number of addresses in total: %d\n", num_addresses);
    printf("Number of usable addresses: %d\n", usable_addresses);

    printf("----------------------------------------------------\n");
    printf("Thank you for using the C Subnet Calculator!\n");

    return 0;
}