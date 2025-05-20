//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 100

void convert_hex_to_decimal(char hex[], int hex_len, char dec[]) {
    int i, j = 0;
    for (i = hex_len - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            dec[j++] = hex[i];
        } else if (isupper(hex[i])) {
            dec[j++] = hex[i] - 'A' + 10;
        } else if (islower(hex[i])) {
            dec[j++] = hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
    }
    dec[j] = '\0';
}

void convert_decimal_to_hex(int dec, char hex[]) {
    if (dec == 0) {
        strcpy(hex, "0");
        return;
    }
    char hex_str[MAX_HEX_LENGTH];
    sprintf(hex_str, "%X", dec);
    strcpy(hex, hex_str);
}

int main() {
    char hex[MAX_HEX_LENGTH], dec[MAX_HEX_LENGTH];
    int choice, hex_len;

    while (1) {
        printf("\n");
        printf("1. Convert decimal to hexadecimal\n");
        printf("2. Convert hexadecimal to decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%s", dec);
            convert_decimal_to_hex(atoi(dec), hex);
            printf("Hexadecimal representation: %s\n", hex);
            break;

        case 2:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            hex_len = strlen(hex);
            if (hex_len > MAX_HEX_LENGTH) {
                printf("Hexadecimal number is too long.\n");
                break;
            }
            convert_hex_to_decimal(hex, hex_len, dec);
            printf("Decimal representation: %s\n", dec);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}