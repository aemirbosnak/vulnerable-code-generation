//FormAI DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>

// Function to convert Hexadecimal to Decimal
int hexToDec(char hex[]) {
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

// Function to convert Decimal to Hexadecimal
void decToHex(int dec) {
    char hex[100];
    int i = 0;
    while (dec != 0) {
        int rem = dec % 16;
        if (rem < 10)
            hex[i++] = 48 + rem;
        else
            hex[i++] = 55 + rem;
        dec /= 16;
    }
    printf("Equivalent Hex Code: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");
}

int main() {
    char color[7];
    printf("Enter the Hex Color Code: ");
    scanf("%s", &color);
    int r = hexToDec(strncpy(r, color + 1, 2));
    int g = hexToDec(strncpy(g, color + 3, 2));
    int b = hexToDec(strncpy(b, color + 5, 2));
    printf("RGB Color Code: r=%d, g=%d, b=%d\n", r, g, b);
    decToHex(r);
    decToHex(g);
    decToHex(b);
    return 0;
}