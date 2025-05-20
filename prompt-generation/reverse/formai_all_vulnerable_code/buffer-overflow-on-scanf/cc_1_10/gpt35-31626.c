//FormAI DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

void decimal_to_binary(int decimal_num);
int binary_to_decimal(char *binary_num);

int main()
{
    int choice, decimal_num;
    char binary_num[MAX_SIZE];

    while (1) {
        printf("\n-------------------------------------------\n");
        printf("\nMenu:\n1. Decimal to Binary Conversion\n2. Binary to Decimal Conversion\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the decimal number: ");
                scanf("%d", &decimal_num);
                printf("The binary equivalent of %d is: ", decimal_num);
                decimal_to_binary(decimal_num);
                break;
            case 2:
                printf("\nEnter the binary number: ");
                scanf("%s", binary_num);
                printf("The decimal equivalent of %s is: %d", binary_num, binary_to_decimal(binary_num));
                break;
            case 3:
                printf("\nBye!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}

void decimal_to_binary(int decimal_num)
{
    int remainder, binary_array[MAX_SIZE], i = 0;

    if (decimal_num <= 1) {
        printf("%d", decimal_num);
        return;
    }

    while (decimal_num > 0) {
        remainder = decimal_num % 2;
        binary_array[i++] = remainder;
        decimal_num /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary_array[j]);
}

int binary_to_decimal(char *binary_num)
{
    int decimal_num = 0, length = strlen(binary_num);

    for (int i = 0; i < length; i++) {
        decimal_num += (binary_num[i] - '0') * pow(2, length - 1 - i);
    }

    return decimal_num;
}