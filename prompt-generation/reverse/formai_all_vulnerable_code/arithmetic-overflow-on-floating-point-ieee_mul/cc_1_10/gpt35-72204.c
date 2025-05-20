//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option;
    float red, green, blue, cyan, magenta, yellow, black, white;

    printf("Welcome to the C Color Code Converter!\n\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. RGB to CMYK\n");
        printf("2. CMYK to RGB\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nRGB to CMYK converter\n");
                printf("Enter the red value (0-255): ");
                scanf("%f", &red);
                printf("Enter the green value (0-255): ");
                scanf("%f", &green);
                printf("Enter the blue value (0-255): ");
                scanf("%f", &blue);

                cyan = 1 - (red/255.0);
                magenta = 1 - (green/255.0);
                yellow = 1 - (blue/255.0);

                if (cyan <= magenta && cyan <= yellow) {
                    black = cyan;
                } else if (magenta <= cyan && magenta <= yellow) {
                    black = magenta;
                } else {
                    black = yellow;
                }

                cyan = (cyan - black) / (1 - black);
                magenta = (magenta - black) / (1 - black);
                yellow = (yellow - black) / (1 - black);

                printf("The CMYK values are: C=%.2f M=%.2f Y=%.2f K=%.2f\n\n", cyan, magenta, yellow, black);
                break;
            
            case 2:
                printf("\nCMYK to RGB converter\n");
                printf("Enter the cyan value (0-1): ");
                scanf("%f", &cyan);
                printf("Enter the magenta value (0-1): ");
                scanf("%f", &magenta);
                printf("Enter the yellow value (0-1): ");
                scanf("%f", &yellow);
                printf("Enter the black value (0-1): ");
                scanf("%f", &black);

                red = 255 * (1 - cyan) * (1 - black);
                green = 255 * (1 - magenta) * (1 - black);
                blue = 255 * (1 - yellow) * (1 - black);

                printf("The RGB values are: R=%.0f G=%.0f B=%.0f\n\n", red, green, blue);
                break;

            case 3:
                printf("\nExiting the program...");
                exit(0);

            default:
                printf("\nInvalid option. Please choose again.\n\n");
                break;
        }
    }

    return 0;
}