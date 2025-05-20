//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 32 // Maximum length of a binary number
#define MAX_DEC_LENGTH 10 // Maximum length of a decimal number

int main() {
    int choice;
    char input[MAX_NUM_LENGTH];
    char output[MAX_NUM_LENGTH];
    int decimal[MAX_DEC_LENGTH];
    int i;

    do {
        printf("\nBinary to Decimal Converter\n");
        printf("1. Convert binary to decimal\n");
        printf("2. Convert decimal to binary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%s", input);
                decimal[0] = 0;
                for(i = strlen(input) - 1; i >= 0; i--) {
                    if(input[i] == '1') {
                        decimal[0] += pow(2, strlen(input) - 1 - i);
                    }
                }
                printf("The decimal representation of %s is: %d\n", input, decimal[0]);
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal[0]);
                sprintf(output, "%b", decimal[0]);
                printf("The binary representation of %d is: %s\n", decimal[0], output);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 3);

    return 0;
}