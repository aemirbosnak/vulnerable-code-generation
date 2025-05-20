//FormAI DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void decimal_to_binary(int decimal_num);
void binary_to_decimal(int binary_num);

int main() {

    int choice;
    
    do {
        printf("\n-- Binary Converter --\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int decimal_num;
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimal_num);
                decimal_to_binary(decimal_num);
                break;
            }
            case 2: {
                int binary_num;
                printf("\nEnter a binary number: ");
                scanf("%d", &binary_num);
                binary_to_decimal(binary_num);
                break;
            }
            case 0: {
                printf("\nExiting program...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice, please try again.\n");
            }
        }
    } while(choice != 0);
    
    return 0;
}

/* Function to convert decimal to binary */
void decimal_to_binary(int decimal_num) {
    int binary_num = 0, i = 0;
    while(decimal_num > 0) {
        binary_num += (decimal_num % 2) * pow(10, i);
        decimal_num /= 2;
        i++;
    }
    printf("\nBinary equivalent: %d\n", binary_num);
}

/* Function to convert binary to decimal */
void binary_to_decimal(int binary_num) {
    int decimal_num = 0, i = 0;
    while(binary_num > 0) {
        decimal_num += (binary_num % 10) * pow(2, i);
        binary_num /= 10;
        i++;
    }
    printf("\nDecimal equivalent: %d\n", decimal_num);
}