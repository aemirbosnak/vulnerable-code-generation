//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    int i = 31;
    while (num!= 0) {
        printf("%d", num & 1);
        num >>= 1;
        i--;
    }
    while (i >= 0) {
        printf("0");
        i--;
    }
    printf("\n");
}

// Function to count number of set bits in a number
int countSetBits(unsigned int num) {
    int count = 0;
    while (num!= 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}

int main() {
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Print binary representation of a number\n");
        printf("2. Count number of set bits in a number\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                unsigned int num;
                scanf("%u", &num);
                printBinary(num);
                break;
            case 2:
                printf("Enter a number: ");
                unsigned int num2;
                scanf("%u", &num2);
                printf("Number of set bits: %d\n", countSetBits(num2));
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}