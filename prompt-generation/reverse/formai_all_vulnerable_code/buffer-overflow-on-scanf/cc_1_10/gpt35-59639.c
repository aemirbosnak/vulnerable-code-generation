//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert decimal to hexadecimal */
char* dec_to_hex(int num)
{
    char* hex = (char*)malloc(20 * sizeof(char));
    int i = 0;
    while (num) {
        int rem = num % 16;
        if (rem < 10) {
            hex[i++] = rem + 48;
        } else {
            hex[i++] = rem + 55;
        }
        num /= 16;
    }
    hex[i] = '\0';
    /* Reverse the string */
    int len = strlen(hex);
    for (int i = 0; i < len / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[len - i - 1];
        hex[len - i - 1] = temp;
    }
    return hex;
}

/* Function to convert hexadecimal to decimal */
int hex_to_dec(char hex[])
{
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
            base *= 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return dec;
}

int main()
{
    /* Display Menu */
    printf("Hexadecimal Converter Menu\n");
    printf("1. Decimal to Hexadecimal Conversion\n");
    printf("2. Hexadecimal to Decimal Conversion\n");
    printf("Enter your choice (1 or 2): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        /* Decimal to Hexadecimal Conversion */
        printf("Enter a decimal number: ");
        int num;
        scanf("%d", &num);
        char* hex = dec_to_hex(num);
        printf("Hexadecimal Conversion: %s\n", hex);
        free(hex); // Free the dynamically allocated memory
    } else if (choice == 2) {
        /* Hexadecimal to Decimal Conversion */
        printf("Enter a hexadecimal number: ");
        char hex[20];
        scanf("%s", hex);
        int dec = hex_to_dec(hex);
        printf("Decimal Conversion: %d\n", dec);
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}