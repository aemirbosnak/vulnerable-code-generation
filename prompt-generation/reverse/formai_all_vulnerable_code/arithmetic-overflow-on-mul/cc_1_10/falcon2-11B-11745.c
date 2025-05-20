//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <string.h>

// Function to convert hexadecimal to binary
void hexToBinary(char *hex, int len, int *bin) {
    int i;
    char c;

    // Convert the hexadecimal string to binary string
    for (i = 0; i < len; i++) {
        c = hex[i];
        if (c >= '0' && c <= '9') {
            *bin = (*bin) * 2 + (c - '0');
        } else if (c >= 'a' && c <= 'f') {
            *bin = (*bin) * 2 + 10 + (c - 'a');
        } else if (c >= 'A' && c <= 'F') {
            *bin = (*bin) * 2 + 10 + (c - 'A');
        }
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int bin) {
    int decimal = 0;
    while (bin) {
        decimal = decimal * 2 + bin % 2;
        bin = bin / 2;
    }
    return decimal;
}

int main() {
    char hex[16];
    int bin;
    int decimal;

    printf("Enter hexadecimal value: ");
    fgets(hex, sizeof(hex), stdin);

    // Convert the hexadecimal string to binary
    hexToBinary(hex, sizeof(hex), &bin);

    // Convert the binary string to decimal
    decimal = binaryToDecimal(bin);

    printf("Binary: %d\n", bin);
    printf("Decimal: %d\n", decimal);

    return 0;
}