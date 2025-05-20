//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 100

void convert_binary_to_decimal(char *binary_num, int *decimal_num) {
    int i, j, base = 1;
    int num_length = strlen(binary_num);
    for (i = num_length - 1, j = 0; i >= 0; i--, j++) {
        *decimal_num += (binary_num[i] - '0') * base;
        base *= 2;
    }
}

void convert_decimal_to_binary(int decimal_num, char *binary_num) {
    int i, j, remainder;
    char *ptr = binary_num + strlen(binary_num) - 1;
    *ptr = '\0';
    for (i = 0; decimal_num > 0; i++) {
        remainder = decimal_num % 2;
        decimal_num /= 2;
        *ptr-- = remainder + '0';
    }
}

int main() {
    char binary_num[MAX_NUM_LENGTH];
    int decimal_num;
    int choice, num_length;

    do {
        printf("Enter 1 to convert binary to decimal or 2 to convert decimal to binary: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a binary number: ");
            scanf("%s", binary_num);
            num_length = strlen(binary_num);
            if (num_length > MAX_NUM_LENGTH) {
                printf("Error: Binary number is too long.\n");
            } else {
                convert_binary_to_decimal(binary_num, &decimal_num);
                printf("Decimal equivalent: %d\n", decimal_num);
            }
            break;

        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal_num);
            convert_decimal_to_binary(decimal_num, binary_num);
            printf("Binary equivalent: %s\n", binary_num);
            break;

        default:
            printf("Invalid choice.\n");
        }

        printf("\nDo you want to try again? (1=Yes, 0=No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}