//FormAI DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define RGB structure */
typedef struct {
    int r;
    int g;
    int b;
} RGB;

/* Define HEX structure */
typedef struct {
    char hex[7];
} HEX;

/* Function to convert RGB to HEX */
HEX rgb_to_hex(RGB rgb) {
    HEX hex;
    sprintf(hex.hex, "%02X%02X%02X", rgb.r, rgb.g, rgb.b);
    return hex;
}

/* Function to convert HEX to RGB */
RGB hex_to_rgb(HEX hex) {
    RGB rgb;
    sscanf(hex.hex, "%02X%02X%02X", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

/* Main function */
int main() {
    char choice[10];
    printf("C Color Code Converter\n");
    printf("----------------------\n");
    printf("Enter '1' to convert RGB to HEX\n");
    printf("Enter '2' to convert HEX to RGB\n");
    printf("Enter '0' to exit\n");
    printf("----------------------\n");

    while(1) {
        printf("Enter your choice: ");
        fgets(choice, sizeof(choice), stdin);

        /* Convert RGB to HEX */
        if(strcmp(choice, "1\n") == 0) {
            RGB rgb;
            printf("Enter values for R, G, B (0-255):\n");
            printf("R: ");
            scanf("%d", &rgb.r);
            printf("G: ");
            scanf("%d", &rgb.g);
            printf("B: ");
            scanf("%d", &rgb.b);
            HEX hex = rgb_to_hex(rgb);
            printf("The HEX code is #%s\n", hex.hex);
            getchar();
        }

        /* Convert HEX to RGB */
        else if(strcmp(choice, "2\n") == 0) {
            HEX hex;
            printf("Enter a HEX code (without the # symbol):\n");
            printf("HEX: ");
            scanf("%s", hex.hex);
            RGB rgb = hex_to_rgb(hex);
            printf("The RGB values are R:%d, G:%d, B:%d\n", rgb.r, rgb.g, rgb.b);
            getchar();
        }

        /* Exit program */
        else if(strcmp(choice, "0\n") == 0) {
            printf("Exiting program.\n");
            exit(0);
        }

        /* Invalid choice */
        else {
            printf("Invalid choice. Please try again.\n");
            getchar();
        }
    }

    return 0;
}