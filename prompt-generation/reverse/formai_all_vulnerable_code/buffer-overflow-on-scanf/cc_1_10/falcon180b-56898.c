//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert hex to decimal
int hex_to_dec(char hex[]) {
    int decimal = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
    }
    return decimal;
}

// function to convert decimal to hex
void dec_to_hex(int dec, char hex[]) {
    char hex_str[10] = {0};
    int i = 0;
    while (dec > 0) {
        int rem = dec % 16;
        if (rem < 10) {
            hex_str[i] = rem + '0';
        } else {
            hex_str[i] = rem + 'A' - 10;
        }
        i++;
        dec /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        hex[j] = hex_str[j];
    }
    hex[i] = '\0';
}

int main() {
    char hex_str[100];
    char dec_str[100];
    int choice;
    printf("Enter your choice:\n1. Convert decimal to hexadecimal\n2. Convert hexadecimal to decimal\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter a decimal number: ");
        scanf("%s", dec_str);
        int dec = atoi(dec_str);
        printf("Hexadecimal representation: ");
        sprintf(hex_str, "%X", dec);
        printf("%s\n", hex_str);
    } else if (choice == 2) {
        printf("Enter a hexadecimal number: ");
        scanf("%s", hex_str);
        int dec = hex_to_dec(hex_str);
        printf("Decimal representation: %d\n", dec);
    } else {
        printf("Invalid choice\n");
        exit(1);
    }
    return 0;
}