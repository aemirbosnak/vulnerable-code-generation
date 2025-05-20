//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, choice, octal, binary, remainder;

    printf("Enter your choice:\n1. Convert decimal to binary\n2. Convert decimal to octal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the decimal number: ");
            scanf("%d", &num);

            binary = num;
            i = 0;

            while (binary) {
                remainder = binary % 2;
                binary /= 2;
                printf("%d ", remainder);
                i++;
            }

            printf("\nTotal number of bits: %d", i);
            break;

        case 2:
            printf("Enter the decimal number: ");
            scanf("%d", &num);

            octal = num;
            i = 0;

            while (octal) {
                remainder = octal % 8;
                octal /= 8;
                printf("%d ", remainder);
                i++;
            }

            printf("\nTotal number of bits: %d", i);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}