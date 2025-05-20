//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hex_to_dec(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        return -1;
    }
}

int dec_to_hex(int dec) {
    char hex[2] = { 0 };
    int i = 0;
    if (dec == 0) {
        hex[i++] = '0';
    }
    while (dec > 0) {
        int rem = dec % 16;
        if (rem < 10) {
            hex[i++] = rem + '0';
        } else {
            hex[i++] = rem - 10 + 'A';
        }
        dec /= 16;
    }
    hex[i] = 0;
    return 0;
}

int main() {
    char color[7];
    printf("Enter a color code (e.g. #FFA500): ");
    scanf("%s", color);
    int len = strlen(color);
    if (len!= 7 || color[0]!= '#') {
        printf("Invalid color code\n");
        return 1;
    }
    int r, g, b;
    if (sscanf(color + 1, "%02X%02X%02X", &r, &g, &b)!= 3) {
        printf("Invalid color code\n");
        return 1;
    }
    printf("RGB: %02X%02X%02X\n", r, g, b);
    printf("Hex: %02X%02X%02X\n", r, g, b);
    printf("Decimal: %d\n", (r << 16) | (g << 8) | b);
    return 0;
}