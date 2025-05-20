//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Structure to hold the network address information*/
typedef struct {
    unsigned char first_octet;
    unsigned char second_octet;
    unsigned char third_octet;
    unsigned char fourth_octet;
    int subnet_mask;
} IPAddress;

int main() {
    /*Array to hold user input*/
    char input[20];
    /*Structure to hold user input after parsing*/
    IPAddress ip_address;
    printf("Welcome to the Sherlock Holmes Subnet Calculator.\n");

    /*Get user input*/
    printf("Please enter an IP address and subnet mask in the format X.X.X.X/Y:\n");
    fgets(input,sizeof(input),stdin);

    /*Parse the IP address and subnet mask*/
    char* token = strtok(input,"./");
    int count = 0;
    while( token != NULL ) {
        count++;
        switch(count) {
            case 1:
                ip_address.first_octet = atoi(token);
                break;
            case 2:
                ip_address.second_octet = atoi(token);
                break;
            case 3:
                ip_address.third_octet = atoi(token);
                break;
            case 4:
                ip_address.fourth_octet = atoi(token);
                break;
            case 5:
                ip_address.subnet_mask = atoi(token);
                break;
        }
        token = strtok(NULL, "./");
    }

    /*Calculate the subnet mask*/
    unsigned long mask = 0xffffffff << (32 - ip_address.subnet_mask);

    /*Print out the network address*/
    printf("The network address is %d.%d.%d.%d/%d\n", ip_address.first_octet & (mask >> 24), ip_address.second_octet & (mask >> 16),
           ip_address.third_octet & (mask >> 8), ip_address.fourth_octet & mask, ip_address.subnet_mask);

    /*Print out the broadcast address*/
    printf("The broadcast address is %d.%d.%d.%d/%d\n", ip_address.first_octet | (~mask >> 24) & 0xff, ip_address.second_octet | (~mask >> 16) & 0xff,
           ip_address.third_octet | (~mask >> 8) & 0xff, ip_address.fourth_octet | ~mask & 0xff, ip_address.subnet_mask);

    /*Print out the number of hosts*/
    printf("The number of hosts on the network is %lu\n", ((~mask & 0xffffffff) - 1));

    return 0;
}