//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void dec_to_hex(long long decimal_num) {
    char hexadecimal_num[100];
    int i = 0;

    while (decimal_num != 0) {
        int remainder = decimal_num % 16;

        if (remainder < 10) {
            hexadecimal_num[i] = remainder + 48;
        } else {
            hexadecimal_num[i] = remainder + 55;
        }

        i++;
        decimal_num /= 16;
    }

    printf("Hexadecimal number is: ");

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal_num[j]);
    }

    printf("\n");
}

// Function to convert hexadecimal to decimal
void hex_to_dec(char hexadecimal_num[]) {
    long long decimal_num = 0;
    int hex_len = 0;

    // Get length of hexadecimal number
    while (hexadecimal_num[hex_len] != '\0') {
        hex_len++;
    }

    // Convert each digit to decimal
    for (int i = 0; hexadecimal_num[i] != '\0'; i++) {
        int digit;

        if (hexadecimal_num[i] >= '0' && hexadecimal_num[i] <= '9') {
            digit = hexadecimal_num[i] - '0';
        } else if (hexadecimal_num[i] >= 'A' && hexadecimal_num[i] <= 'F') {
            digit = hexadecimal_num[i] - 'A' + 10;
        } else if (hexadecimal_num[i] >= 'a' && hexadecimal_num[i] <= 'f') {
            digit = hexadecimal_num[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal number\n");
            exit(0);
        }

        decimal_num += digit * pow(16, hex_len - 1);
        hex_len--;
    }

    printf("Decimal number is: %lld\n", decimal_num);
}

int main() {
    int choice;
    long long decimal_num;
    char hexadecimal_num[100];

    while (1) {
        printf("\n-------------HEXADECIMAL CONVERTER-------------\n");
        printf("1. Decimal to hexadecimal conversion\n");
        printf("2. Hexadecimal to decimal conversion\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%lld", &decimal_num);
                dec_to_hex(decimal_num);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexadecimal_num);
                hex_to_dec(hexadecimal_num);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}