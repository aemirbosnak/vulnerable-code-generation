//FormAI DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <string.h>

int hex_to_decimal(char hex[]) {
    int decimal = 0, base = 1, length = strlen(hex);
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}

void rgb_to_hex(int r, int g, int b, char hex[]) {
    sprintf(hex, "%02X%02X%02X", r, g, b); //Converting RGB to hexadecimal
}

void hex_to_rgb(char hex[], int *r, int *g, int *b) {
    int decimal = hex_to_decimal(hex); //Converting hexadecimal to decimal
    *b = decimal % 256; //Extracting Blue value
    decimal /= 256;
    *g = decimal % 256; //Extracting Green value
    decimal /= 256;
    *r = decimal; //Extracting Red value
}

void print_menu() {
    printf("\nChoose an option:\n");
    printf("1. Convert RGB to Hexadecimal\n");
    printf("2. Convert Hexadecimal to RGB\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, r, g, b;
    char hex[7];

    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Red, Green and Blue values (0-255): ");
                scanf("%d %d %d", &r, &g, &b);
                rgb_to_hex(r, g, b, hex);
                printf("The hexadecimal code is #%s\n", hex);
                break;
            case 2:
                printf("Enter Hexadecimal code (without #): ");
                scanf("%s", hex);
                hex_to_rgb(hex, &r, &g, &b);
                printf("The RGB values are (%d, %d, %d)\n", r, g, b);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}