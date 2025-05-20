//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void hex_to_dec(char *hex) {
    int dec = 0, i = 0;
    while (hex[i]) {
        if (isdigit(hex[i])) {
            dec = dec * 16 + hex[i] - '0';
        } else {
            dec = dec * 16 + hex[i] - 'A' + 10;
        }
        i++;
    }
    printf("%d\n", dec);
}

void dec_to_hex(int dec) {
    char hex[20];
    int i = 0;
    while (dec > 0) {
        int rem = dec % 16;
        if (rem < 10) {
            hex[i++] = rem + '0';
        } else {
            hex[i++] = rem - 10 + 'A';
        }
        dec /= 16;
    }
    printf("%s\n", hex);
}

int main() {
    char choice;
    int num;
    while (1) {
        printf("\nC Hexadecimal Converter\n");
        printf("Enter 'h' to convert from hexadecimal to decimal\n");
        printf("Enter 'd' to convert from decimal to hexadecimal\n");
        printf("Enter 'q' to quit\n");
        scanf("%c", &choice);
        if (choice == 'h' || choice == 'H') {
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex_to_dec);
        } else if (choice == 'd' || choice == 'D') {
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            dec_to_hex(num);
        } else if (choice == 'q' || choice == 'Q') {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}