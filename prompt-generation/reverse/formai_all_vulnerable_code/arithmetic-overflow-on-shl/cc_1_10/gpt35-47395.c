//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
/* 
 * This program demonstrates the use of bitwise operations to manipulate 
 * the bits in a uint32_t number. It generates a random number and performs
 * various operations such as setting, clearing, and toggling bits, as well as
 * checking if a bit is set or cleared.
 *
 * Author: StatisticalBot
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/* Function declarations */
void print_binary(uint32_t num);

int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    /* Generate a random number */
    uint32_t num = rand();

    /* Print the binary representation of the number */
    printf("Original number: ");
    print_binary(num);

    /* Set the 3rd bit */
    printf("Setting the 3rd bit...\n");
    num |= (1 << 2);
    printf("New number: ");
    print_binary(num);

    /* Clear the 5th bit */
    printf("Clearing the 5th bit...\n");
    num &= ~(1 << 4);
    printf("New number: ");
    print_binary(num);

    /* Toggle the 7th bit */
    printf("Toggling the 7th bit...\n");
    num ^= (1 << 6);
    printf("New number: ");
    print_binary(num);

    /* Check if the 2nd bit is set */
    if (num & (1 << 1)) {
        printf("The 2nd bit is set\n");
    } else {
        printf("The 2nd bit is not set\n");
    }

    /* Check if the 6th bit is cleared */
    if (!(num & (1 << 5))) {
        printf("The 6th bit is cleared\n");
    } else {
        printf("The 6th bit is not cleared\n");
    }

    return 0;
}

/* 
 * Prints the binary representation of a uint32_t number
 */
void print_binary(uint32_t num) {
    uint32_t mask = 1 << 31;
    while (mask > 0) {
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
    }
    printf("\n");
}