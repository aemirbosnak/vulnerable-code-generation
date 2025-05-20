//FormAI DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int decimal = 0;
    int length = strlen(hex);

    // Iterate through each character of the hexadecimal string
    for(int i=0;i<length;i++) {
        // Multiply the current digit by the corresponding power of 16
        // and add it to the decimal value
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * pow(16, length-i-1);
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * pow(16, length-i-1);
        } else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * pow(16, length-i-1);
        } else {
            // Invalid hexadecimal digit
            return -1;
        }
    }

    return decimal;
}

// Function to convert decimal to hexadecimal
char* decToHex(int decimal) {
    char hex[100];
    int i = 0;

    // Convert decimal to hexadecimal
    while(decimal > 0) {
        int remainder = decimal % 16;
        if(remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'a';
        }
        decimal /= 16;
        i++;
    }

    // Reverse the hexadecimal string
    char* result = (char*) malloc(i * sizeof(char));
    int j = 0;
    while(i--) {
        result[j++] = hex[i];
    }
    result[j] = '\0';

    return result;
}

// Function to convert RGB values to hexadecimal color code
char* rgbToHex(int red, int green, int blue) {
    char hex[7];
    sprintf(hex, "%02x%02x%02x", red, green, blue);
    char* result = (char*) malloc(7 * sizeof(char));
    strcpy(result, hex);
    return result;
}

// Function to convert hexadecimal color code to RGB values
void hexToRgb(char hex[], int* red, int* green, int* blue) {
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    *red = r;
    *green = g;
    *blue = b;
}

int main() {
    int choice;
    int red, green, blue;
    char hex[7];

    printf("Color Code Converter\n");
    printf("--------------------\n");
    printf("1. RGB to Hex\n");
    printf("2. Hex to RGB\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter RGB values (0 to 255)\n");
            printf("Red: ");
            scanf("%d", &red);
            printf("Green: ");
            scanf("%d", &green);
            printf("Blue: ");
            scanf("%d", &blue);

            if(red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
                printf("Invalid RGB values\n");
                return 0;
            }

            char* hex = rgbToHex(red, green, blue);
            printf("\nHexadecimal color code: %s\n", hex);
            free(hex);
            break;

        case 2:
            printf("\nEnter hexadecimal color code (e.g. FF0000): ");
            scanf("%s", hex);

            if(strlen(hex) != 6) {
                printf("Invalid hexadecimal color code\n");
                return 0;
            }

            int r, g, b;
            hexToRgb(hex, &r, &g, &b);
            printf("\nRGB values: (%d, %d, %d)\n", r, g, b);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}