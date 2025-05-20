//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 64
#define BASE 10

void binary_to_decimal(char binary[], int decimal[]) {
    int i = 0, j = 0, k = 0;
    while (binary[i]!= '\0') {
        if (isdigit(binary[i])) {
            decimal[j] = binary[i] - '0';
            i++;
            j++;
        } else {
            i++;
        }
    }
    while (j < MAX_NUM_LENGTH) {
        decimal[j] = 0;
        j++;
    }
    for (i = 0, j = MAX_NUM_LENGTH - 1; i < j; i++, j--) {
        k = decimal[i];
        decimal[i] = decimal[j];
        decimal[j] = k;
    }
}

void decimal_to_binary(int decimal, char binary[]) {
    int i = 0;
    while (decimal!= 0) {
        binary[i] = decimal % BASE + '0';
        decimal /= BASE;
        i++;
    }
    binary[i] = '\0';
    for (int j = i - 1; j >= 0; j--) {
        if (binary[j] == '0' && binary[j - 1] == '0') {
            binary[j] = '\0';
        }
    }
}

int main() {
    char binary[MAX_NUM_LENGTH];
    int decimal[MAX_NUM_LENGTH];
    int choice, length;
    do {
        printf("Enter your choice:\n1. Binary to Decimal\n2. Decimal to Binary\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter binary number: ");
                scanf("%s", binary);
                binary_to_decimal(binary, decimal);
                printf("Decimal number: %d\n", decimal[0]);
                break;
            case 2:
                printf("Enter decimal number: ");
                scanf("%d", &decimal[0]);
                decimal_to_binary(decimal[0], binary);
                printf("Binary number: %s\n", binary);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}