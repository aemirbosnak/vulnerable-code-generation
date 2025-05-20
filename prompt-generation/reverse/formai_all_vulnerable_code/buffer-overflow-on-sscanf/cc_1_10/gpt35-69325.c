//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Configurable Values
#define MAX_LEN 16
#define DELIM "."
#define MASK_LEN 32

struct in_addr gen_ip(
    const char *ip
){
    struct in_addr addr;
    if(inet_pton(AF_INET, ip, &addr) == 0){
        printf("Invalid IP Address!\n");
        exit(EXIT_FAILURE);
    }
    return addr;
}

struct in_addr gen_mask(
    unsigned int prefix_len
){
    struct in_addr mask;
    unsigned long int mask_bin = 0;
    for(unsigned int i = 0; i < prefix_len; i++){
        mask_bin |= (1UL << (MASK_LEN - 1 - i));
    }
    mask.s_addr = htonl(mask_bin);
    return mask;
}

void parse_ip(
    const char *ip,
    unsigned char *oct_1,
    unsigned char *oct_2,
    unsigned char *oct_3,
    unsigned char *oct_4
){
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", oct_1, oct_2, oct_3, oct_4);
}

void print_ip(
    const char *msg,
    struct in_addr addr
){
    printf("%s: %s\n", msg, inet_ntoa(addr));
}

void print_subnet(
    const char *ip,
    unsigned int prefix_len
){
    struct in_addr addr = gen_ip(ip);
    struct in_addr mask = gen_mask(prefix_len);

    printf("Subnet:\n");
    print_ip("IP Address", addr);
    print_ip("Subnet Mask", mask);
    
    unsigned char oct_1, oct_2, oct_3, oct_4;
    parse_ip(inet_ntoa(addr), &oct_1, &oct_2, &oct_3, &oct_4);
    
    oct_1 &= mask.s_addr >> 24;
    oct_2 &= mask.s_addr >> 16;
    oct_3 &= mask.s_addr >> 8;
    oct_4 &= mask.s_addr;

    printf("Network Address: %hhu.%hhu.%hhu.%hhu\n", oct_1, oct_2, oct_3, oct_4);
}

int main(){
    char ip[MAX_LEN], choice[MAX_LEN];
    unsigned int prefix_len;

    printf("Welcome to the Subnet Calculator!\n");

    while(1){
        printf("\nEnter the IP Address: ");
        scanf("%s", ip);
        printf("Enter the Prefix Length: ");
        scanf("%u", &prefix_len);

        print_subnet(ip, prefix_len);

        printf("\nDo you want to calculate another subnet? (y/n): ");
        scanf("%s", choice);
        if(strcmp(choice, "n") == 0 || strcmp(choice, "N") == 0){
            break;
        }
    }

    printf("Thank you for using the Subnet Calculator!\n");
    return EXIT_SUCCESS;
}