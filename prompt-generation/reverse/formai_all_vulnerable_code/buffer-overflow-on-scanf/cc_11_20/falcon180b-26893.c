//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    char colorCode[7];
    int validCode = FALSE;

    printf("Welcome to the Color Code Converter 3000!\n");
    printf("Please enter a color code (e.g. #FF0000 for red): ");
    scanf("%s", colorCode);

    // Check if input is a valid hexadecimal color code
    if (strlen(colorCode)!= 7 || colorCode[0]!= '#') {
        printf("Invalid color code. Please enter a valid hexadecimal color code.\n");
    } else {
        for (int i = 1; i < strlen(colorCode); i++) {
            if (!isxdigit(colorCode[i])) {
                printf("Invalid color code. Please enter a valid hexadecimal color code.\n");
                break;
            }
        }

        if (validCode) {
            // Convert hexadecimal color code to RGB values
            int red = 0, green = 0, blue = 0;

            if (colorCode[1] == 'F' || colorCode[1] == 'f') {
                red = 255;
            } else {
                red = colorCode[1] - '0';
            }

            if (colorCode[3] == 'F' || colorCode[3] == 'f') {
                green = 255;
            } else {
                green = colorCode[3] - '0';
            }

            if (colorCode[5] == 'F' || colorCode[5] == 'f') {
                blue = 255;
            } else {
                blue = colorCode[5] - '0';
            }

            // Print RGB values
            printf("\nRGB Values:\n");
            printf("Red: %d\n", red);
            printf("Green: %d\n", green);
            printf("Blue: %d\n", blue);
        }
    }

    return 0;
}