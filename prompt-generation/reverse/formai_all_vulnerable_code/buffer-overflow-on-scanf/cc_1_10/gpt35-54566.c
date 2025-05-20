//FormAI DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

/* Function to convert a hexadecimal number to decimal */
int hexToDecimal(char hex[]) {
    int decimal = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal = decimal * 16 + (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal = decimal * 16 + (hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal = decimal * 16 + (hex[i] - 'a' + 10);
        }
    }

    return decimal;
}

/* Function to convert a decimal number to hexadecimal */
void decimalToHex(int decimal, char hex[]) {
    int rem, i = 0;

    while (decimal != 0) {
        rem = decimal % 16;
        if (rem < 10) {
            hex[i++] = rem + 48;
        } else {
            hex[i++] = rem + 55;
        }
        decimal /= 16;
    }

    hex[i] = '\0';

    /* Reverse the hex string */
    for (int j = 0, k = i-1; j < k; j++, k--) {
        char temp = hex[j];
        hex[j] = hex[k];
        hex[k] = temp;
    }
}

int main() {
    char input[30];
    char output[30];
    int decimal;
    int choice;

    printf("*** C Color Code Converter ***\n");
    printf("Enter 1 to convert Hexadecimal to Decimal\n");
    printf("Enter 2 to convert Decimal to Hexadecimal\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Hexadecimal code: ");
            scanf("%s", input);

            decimal = hexToDecimal(input);

            printf("Decimal Code: %d\n", decimal);

            break;

        case 2:
            printf("Enter Decimal code: ");
            scanf("%d", &decimal);

            decimalToHex(decimal, output);

            printf("Hexadecimal Code: #%s\n", output);

            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}