//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    char *binary;
    char *decimal;
    int length;
    int choice;
    int decimal_value;
    int i;
    int j;

    printf("Welcome to the Binary Converter!\n");
    printf("Enter 1 to convert decimal to binary.\n");
    printf("Enter 2 to convert binary to decimal.\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter a decimal value: ");
        scanf("%d", &decimal_value);
        length = 0;
        i = decimal_value;
        while (i > 0) {
            length++;
            i /= 2;
        }
        binary = malloc(MAX_LENGTH);
        sprintf(binary, "%d", decimal_value);
        for (i = strlen(binary) - 1, j = 0; i >= 0; i--, j++) {
            if (binary[i] == '1') {
                length++;
            }
        }
        for (i = MAX_LENGTH - length; i > 0; i--) {
            printf("0");
        }
        printf("%s\n", binary);
        free(binary);
    } else if (choice == 2) {
        printf("Enter a binary value: ");
        scanf("%s", binary);
        length = strlen(binary);
        decimal_value = 0;
        for (i = 0; i < length; i++) {
            if (binary[i] == '1') {
                decimal_value += pow(2, length - 1 - i);
            }
        }
        printf("%d\n", decimal_value);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}