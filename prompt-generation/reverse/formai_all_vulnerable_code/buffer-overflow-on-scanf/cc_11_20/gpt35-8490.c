//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
/* Welcome to this C Hexadecimal Converter! */

#include <stdio.h>

int main() {

    int input, choice;

    printf("Welcome to the C Hexadecimal Converter!\n");

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &input);

    // Prompt the user to choose an option
    printf("Choose an option:\n");
    printf("1. Convert to Hexadecimal\n");
    printf("2. Convert from Hexadecimal\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            // Convert from decimal to hexadecimal
            char hex[100];
            int i = 0;

            while(input != 0) {
                int temp = 0;
                temp = input % 16;

                if(temp < 10) {
                    hex[i] = temp + 48;
                    i++;
                } else {
                    hex[i] = temp + 55;
                    i++;
                }

                input /= 16;
            }

            printf("Hexadecimal equivalent: ");

            for(int j = i-1; j >= 0; j--) {
                printf("%c", hex[j]);
            }

            break;
        }
        case 2: {
            // Convert from hexadecimal to decimal
            int decimal = 0, base = 1;

            // Prompt the user to enter a hexadecimal number
            char hex[100];

            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);

            int length = strlen(hex);

            for(int i = length - 1; i >= 0; i--) {
                if(hex[i] >= '0' && hex[i] <= '9') {
                    decimal += (hex[i] - 48) * base;
                    base *= 16;
                } else if(hex[i] >= 'A' && hex[i] <= 'F') {
                    decimal += (hex[i] - 55) * base;
                    base *= 16;
                } else if(hex[i] >= 'a' && hex[i] <= 'f') {
                    decimal += (hex[i] - 87) * base;
                    base *= 16;
                }
            }

            printf("Decimal equivalent: %d\n", decimal);

            break;
        }
        default: {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}