//FormAI DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_LENGTH 7
#define RGB_VALUES 3

int hex_to_decimal(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9') {
        return hex_digit - '0';
    } else if (hex_digit >= 'A' && hex_digit <= 'F') {
        return hex_digit - 'A' + 10;
    } else if (hex_digit >= 'a' && hex_digit <= 'f') {
        return hex_digit - 'a' + 10;
    }
    return -1;
}

void convert_hex_to_rgb(char* hex_color, int* rgb_color) {
    if (strlen(hex_color) != HEX_LENGTH) {
        printf("Error: invalid hex color format!\n");
        return;
    }
    for (int i = 1; i < HEX_LENGTH; i += 2) {
        int high = hex_to_decimal(hex_color[i]);
        int low = hex_to_decimal(hex_color[i+1]);
        if (high == -1 || low == -1) {
            printf("Error: invalid hex color format!\n");
            return;
        }
        rgb_color[(i-1)/2] = high*16 + low;
    }
}

void convert_rgb_to_hex(int* rgb_color, char* hex_color) {
    sprintf(hex_color, "#%02X%02X%02X", rgb_color[0], rgb_color[1], rgb_color[2]);
}

int main() {
    int* rgb_color = malloc(RGB_VALUES * sizeof(int));
    char hex_color[HEX_LENGTH];
    char choice;
    
    printf("Welcome to the Color Code Converter!\n");
    do {
        printf("\nEnter option:\n H: Convert hex to RGB\n R: Convert RGB to hex\n Q: Quit program\n");
        scanf(" %c", &choice);
        switch(choice) {
            case 'H': 
                printf("Enter hex color code: ");
                scanf("%s", hex_color);
                convert_hex_to_rgb(hex_color, rgb_color);
                printf("RGB color code: %d, %d, %d\n", rgb_color[0], rgb_color[1], rgb_color[2]);
                break;
            case 'R':
                printf("Enter RGB color code separated by commas: ");
                scanf("%d,%d,%d", &rgb_color[0], &rgb_color[1], &rgb_color[2]);
                convert_rgb_to_hex(rgb_color, hex_color);
                printf("Hex color code: %s\n", hex_color);
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
                break;
        }
    } while (choice != 'Q');
    
    free(rgb_color);
    return 0;
}