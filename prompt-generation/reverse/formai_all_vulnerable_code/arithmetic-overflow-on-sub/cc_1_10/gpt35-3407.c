//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
// Romeo:
#include <stdio.h>

int main() {
    printf("O Juliet, my love!\n");
    printf("What brings you here today?\n");
    printf("Would you like me to calculate\n");
    printf("A subnet for you, my bae?\n");

    // Juliet:
    int subnet_bits;
    printf("Oh Romeo, my beloved!\n");
    printf("Your kindness doth amaze me.\n");
    printf("Indeed, I seek guidance\n");
    printf("In subnetting, so please be.\n");
    printf("Tell me how many bits\n");
    printf("Should I use to create\n");
    printf("A subnet mask that fits\n");
    printf("My network's every need.\n");

    // Romeo:
    scanf("%d", &subnet_bits);
    printf("Fair Juliet, your wish\n");
    printf("Is my command today.\n");
    printf("Just tell me the IP address\n");
    printf("And I'll subnet it away!\n");

    // Juliet:
    unsigned int ip;
    printf("Oh Romeo, my one true love!\n");
    printf("You fill my heart with glee.\n");
    printf("I'll give you the IP address\n");
    printf("And you can subnet it for me.\n");
    scanf("%d", &ip);

    // Romeo:
    unsigned int subnet_mask = ~0;
    subnet_mask <<= (32 - subnet_bits);
    printf("Dear Juliet, your subnet mask\n");
    printf("Is %d.%d.%d.%d\n", subnet_mask >> 24, (subnet_mask >> 16) & 255,
            (subnet_mask >> 8) & 255, subnet_mask & 255);

    // Juliet:
    unsigned int network_address = ip & subnet_mask;
    printf("Oh Romeo, my sweetest love,\n");
    printf("Your subnetting skill is divine.\n");
    printf("What is the network address\n");
    printf("Of the subnet that is now mine?\n");
    printf("Tell me, tell me quick,\n");
    printf("For patience is not my strongest trick.\n");

    // Romeo:
    printf("Dearest Juliet, your network address\n");
    printf("Is %d.%d.%d.%d\n", network_address >> 24, (network_address >> 16) & 255,
            (network_address >> 8) & 255, network_address & 255);

    return 0;
}

// Juliet:
// Oh Romeo, my gratitude 
// For your subnetting prowess 
// How fortuitous 
// To have a true love so wondrous 
// But alas, I must go 
// For there's a network to fine-tune 
// Farewell my love 
// May your subnetting skills always be in tune