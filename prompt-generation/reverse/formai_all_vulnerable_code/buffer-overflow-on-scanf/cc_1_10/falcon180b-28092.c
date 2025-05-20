//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *binary;
    char *hex;
    char *octal;
} Conversion;

void binary_to_hex(char *binary, char *hex) {
    int i;
    for (i = 0; i < strlen(binary); i++) {
        if (binary[i] == '0') {
            hex[i] = '0';
        } else if (binary[i] == '1') {
            hex[i] = '1';
        } else {
            printf("Invalid binary string!\n");
            exit(1);
        }
    }
}

void binary_to_octal(char *binary, char *octal) {
    int i;
    for (i = 0; i < strlen(binary); i++) {
        if (binary[i] == '0') {
            octal[i] = '0';
        } else if (binary[i] == '1') {
            octal[i] = '1';
        } else {
            printf("Invalid binary string!\n");
            exit(1);
        }
    }
}

int main() {
    char binary[100];
    char hex[100];
    char octal[100];
    int choice;

    printf("Enter a binary string (up to 100 characters): ");
    scanf("%s", binary);

    printf("Enter the conversion type:\n1. Binary to hexadecimal\n2. Binary to octal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            binary_to_hex(binary, hex);
            printf("Hexadecimal: %s\n", hex);
            break;
        case 2:
            binary_to_octal(binary, octal);
            printf("Octal: %s\n", octal);
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    return 0;
}