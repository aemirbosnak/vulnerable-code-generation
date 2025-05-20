//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

// function to convert hexadecimal to decimal 
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
            base = base * 16;
        }
    }
    return dec;
}

// function to convert decimal to hexadecimal
void decToHex(int dec) {
    char hex[100];
    int i = 0;
    while (dec != 0) {
        int rem = dec % 16;
        if (rem < 10) {
            hex[i] = rem + 48;
        }
        else {
            hex[i] = rem + 55;
        }
        i++;
        dec /= 16;
    }
    printf("Hexadecimal equivalent is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int dec = hexToDec(hex);
    printf("Decimal equivalent is: %d\n", dec);

    printf("Would you like to convert back? (y/n) ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        decToHex(dec);
    }

    return 0;
}