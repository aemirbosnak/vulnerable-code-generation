//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>

// Function to convert hex to decimal
int hex_to_dec(char c) {
    if(c >= '0' && c <= '9') {
        return c - '0';
    }
    else if(c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    else if(c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    else {
        return -1;
    }
}

// Function to convert decimal to hex
char dec_to_hex(int n) {
    if(n >= 0 && n <= 9) {
        return n + '0';
    }
    else if(n >= 10 && n <= 15) {
        return n - 10 + 'A';
    }
    else {
        return '\0';
    }
}

// Function to convert RGB to hex
char* rgb_to_hex(int r, int g, int b) {
    static char hex[7];
    hex[0] = '#';
    hex[1] = dec_to_hex(r / 16);
    hex[2] = dec_to_hex(r % 16);
    hex[3] = dec_to_hex(g / 16);
    hex[4] = dec_to_hex(g % 16);
    hex[5] = dec_to_hex(b / 16);
    hex[6] = dec_to_hex(b % 16);
    return hex;
}

// Function to convert hex to RGB
void hex_to_rgb(char* hex, int* r, int* g, int* b) {
    *r = 16 * hex_to_dec(hex[1]) + hex_to_dec(hex[2]);
    *g = 16 * hex_to_dec(hex[3]) + hex_to_dec(hex[4]);
    *b = 16 * hex_to_dec(hex[5]) + hex_to_dec(hex[6]);
}

// Main function
int main() {
    int r, g, b;
    char hex[7];
    printf("Enter RGB values (0-255): ");
    scanf("%d %d %d", &r, &g, &b);
    printf("Equivalent hex code: %s\n", rgb_to_hex(r, g, b));
    printf("Enter hex code: ");
    scanf("%s", hex);
    hex_to_rgb(hex, &r, &g, &b);
    printf("Equivalent RGB values: (%d,%d,%d)\n", r, g, b);
    return 0;
}