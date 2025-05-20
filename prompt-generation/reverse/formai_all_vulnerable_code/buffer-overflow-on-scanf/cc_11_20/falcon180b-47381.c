//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[]) {

    char binary[100];
    char decimal[100];
    int i, j, k, n;
    int choice;
    int flag = 0;
    int decimal_number = 0;
    int binary_number = 0;
    int octal_number = 0;
    int hexadecimal_number = 0;
    int base = 10;

    printf("Enter the number to convert: ");
    scanf("%s", decimal);

    printf("Enter the base to convert to (2 for binary, 8 for octal, 16 for hexadecimal): ");
    scanf("%d", &base);

    switch (base) {
        case 2:
            for (i = strlen(decimal) - 1; i >= 0; i--) {
                if (decimal[i] == '0' || decimal[i] == '1') {
                    binary[strlen(binary) - 1] = decimal[i];
                } else {
                    printf("Invalid input. Please enter a binary number.\n");
                    exit(1);
                }
            }
            break;
        case 8:
            for (i = strlen(decimal) - 1; i >= 0; i--) {
                if (decimal[i] >= '0' && decimal[i] <= '7') {
                    binary[strlen(binary) - 1] = decimal[i];
                } else {
                    printf("Invalid input. Please enter an octal number.\n");
                    exit(1);
                }
            }
            break;
        case 16:
            for (i = strlen(decimal) - 1; i >= 0; i--) {
                if (isdigit(decimal[i]) || (decimal[i] >= 'A' && decimal[i] <= 'F')) {
                    binary[strlen(binary) - 1] = decimal[i];
                } else {
                    printf("Invalid input. Please enter a hexadecimal number.\n");
                    exit(1);
                }
            }
            break;
        default:
            printf("Invalid base.\n");
            exit(1);
    }

    printf("Binary number: ");
    for (i = strlen(binary) - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }

    printf("\n");

    return 0;
}