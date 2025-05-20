//FormAI DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hex to decimal
int hexToDec(char hexVal[]) {
    int len = strlen(hexVal);
    int base = 1;
    int decVal = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            decVal += (hexVal[i] - 48) * base;
            base *= 16;
        }
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            decVal += (hexVal[i] - 55) * base;
            base *= 16;
        }
    }
    return decVal;
}

// Function to convert decimal to hex
void decToHex(int decVal, char* hexVal) {
    int i = 0;
    while (decVal != 0) {
        int temp = 0;
        temp = decVal % 16;

        if (temp < 10) {
            hexVal[i] = temp + 48;
            i++;
        }
        else {
            hexVal[i] = temp + 55;
            i++;
        }
        decVal /= 16;
    }

    // Adding null character at the end
    hexVal[i] = '\0';

    // Reversing the hex string
    int len = strlen(hexVal);
    for (int j = 0; j < len / 2; j++) {
        char temp = hexVal[j];
        hexVal[j] = hexVal[len - 1 - j];
        hexVal[len - 1 - j] = temp;
    }
}

int main() {
    int option;
    printf("Welcome to the Color Code Converter");
    while(1) {
        printf("\nEnter 1 to convert RGB to HEX\nEnter 2 to convert HEX to RGB\nEnter 3 to exit");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int red, green, blue;
                char hexRed[3], hexGreen[3], hexBlue[3], hexColor[7];

                printf("Enter the values for red, green, and blue (0-255):");
                scanf("%d %d %d", &red, &green, &blue);

                if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
                    printf("Invalid input. Please enter values between 0 and 255");
                    break;
                }

                decToHex(red, hexRed);
                decToHex(green, hexGreen);
                decToHex(blue, hexBlue);

                strcpy(hexColor, "");
                strcat(hexColor, hexRed);
                strcat(hexColor, hexGreen);
                strcat(hexColor, hexBlue);

                printf("The HEX color code is #%s", hexColor);
                break;
            }
            case 2: {
                char hexColor[7];
                int red, green, blue;

                printf("Enter the hex color code (ex. FF0000 for red): ");
                scanf("%s", hexColor);

                if (strlen(hexColor) != 6) {
                    printf("Invalid input. Please enter a 6 digit hex color code");
                    break;
                }

                red = hexToDec(strncpy(hexColor,hexColor+0,2));
                green = hexToDec(strncpy(hexColor,hexColor+2,2));
                blue = hexToDec(strncpy(hexColor,hexColor+4,2));

                printf("The RGB color is (%d, %d, %d)", red, green, blue);
                break;
            }
            case 3: {
                printf("Thanks for using the Color Code Converter!");
                exit(0);
                break;
            }
            default: {
                printf("Invalid option. Please enter a valid option");
                break;
            }
        }
    }
    return 0;
}