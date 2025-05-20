//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a color name: ");
    scanf("%s", str);

    // Create a map of color names to their RGB values
    char **color_map = (char**)malloc(10 * sizeof(char*));
    color_map[0] = "Red";
    color_map[1] = "Green";
    color_map[2] = "Blue";
    color_map[3] = "Yellow";
    color_map[4] = "Orange";
    color_map[5] = "Purple";
    color_map[6] = "Pink";
    color_map[7] = "Grey";
    color_map[8] = "Brown";
    color_map[9] = "Black";

    // Check if the input color name is in the map
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (strcmp(str, color_map[i]) == 0) {
            break;
        }
    }

    // If the color name is found, print its RGB values
    if (i < 10) {
        printf("RGB values for %s: ", str);
        switch (i) {
            case 0:
                printf("R: %d, G: %d, B: %d\n", 255, 0, 0);
                break;
            case 1:
                printf("R: %d, G: %d, B: %d\n", 0, 255, 0);
                break;
            case 2:
                printf("R: %d, G: %d, B: %d\n", 0, 0, 255);
                break;
            case 3:
                printf("R: %d, G: %d, B: %d\n", 255, 255, 0);
                break;
            case 4:
                printf("R: %d, G: %d, B: %d\n", 255, 165, 0);
                break;
            case 5:
                printf("R: %d, G: %d, B: %d\n", 128, 0, 128);
                break;
            case 6:
                printf("R: %d, G: %d, B: %d\n", 255, 192, 203);
                break;
            case 7:
                printf("R: %d, G: %d, B: %d\n", 128, 128, 128);
                break;
            case 8:
                printf("R: %d, G: %d, B: %d\n", 160, 120, 70);
                break;
            case 9:
                printf("R: %d, G: %d, B: %d\n", 0, 0, 0);
                break;
        }
    } else {
        // If the color name is not found, print an error message
        printf("Error: Color name not found.\n");
    }

    return 0;
}