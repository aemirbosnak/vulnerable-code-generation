//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hex_to_dec(char hex_num[]) {
    int decimal_num = 0, base = 1, len = strlen(hex_num);
    for (int i = len - 1; i >= 0; i--) {
        if (hex_num[i] >= '0' && hex_num[i] <= '9') {
            decimal_num += (hex_num[i] - '0') * base;
            base *= 16;
        }
        else if (hex_num[i] >= 'A' && hex_num[i] <= 'F') {
            decimal_num += (hex_num[i] - 55) * base;
            base *= 16;
        }
        else if (hex_num[i] >= 'a' && hex_num[i] <= 'f') {
            decimal_num += (hex_num[i] - 87) * base;
            base *= 16;
        }
        else {
            printf("Invalid input!\n");
            return;
        }
    }
    printf("The decimal equivalent of %s is %d\n", hex_num, decimal_num);
}

void dec_to_hex(int decimal_num) {
    char hex_num[100];
    int rem, i = 0;
    while(decimal_num != 0) {
        rem = decimal_num % 16;
        if (rem < 10)
            hex_num[i] = rem + 48;
        else
            hex_num[i] = rem + 55;
        i++;
        decimal_num /= 16;
    }
    printf("The hexadecimal equivalent of %d is 0x", decimal_num);
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex_num[j]);
    printf("\n");
}

int main() {
    int input, decimal_num;
    char hex_num[100];
    while (1) {
        printf("Choose an option:\n");
        printf("1. Convert hexadecimal to decimal\n");
        printf("2. Convert decimal to hexadecimal\n");
        printf("3. Exit\n");
        scanf("%d", &input);
        switch(input) {
            case 1:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex_num);
                hex_to_dec(hex_num);
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal_num);
                dec_to_hex(decimal_num);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}