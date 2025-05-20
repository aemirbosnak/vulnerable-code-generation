//FormAI DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main(){
    const char *COLOR_CODES[] = {"#FF0000", "#00FF00", "#0000FF", "#FFFF00", "#00FFFF", "#FF00FF", "#000000", "#FFFFFF"};
    const char *COLOR_NAMES[] = {"red", "green", "blue", "yellow", "cyan", "magenta", "black", "white"};

    // Display menu
    printf("Color Code Converter\n");
    printf("--------------------\n");
    printf("Select option\n");
    printf("1. Convert color code to color name\n");
    printf("2. Convert color name to color code\n");

    int option;
    scanf("%d", &option);

    if (option == 1) {
        // Convert color code to color name
        printf("Enter color code (in format #RRGGBB): ");
        char color_code[7];
        scanf("%s", color_code);

        // Find color name corresponding to the entered color code
        int i;
        for (i = 0; i < 8; i++) {
            if (strcmp(COLOR_CODES[i], color_code) == 0) {
                printf("The color name is: %s\n", COLOR_NAMES[i]);
                break;
            }
        }

        if (i == 8) {
            printf("Invalid color code. Try again.\n");
        }

    } else if(option == 2) {
        // Convert color name to color code
        printf("Enter color name: ");
        char color_name[10];
        scanf("%s", color_name);

        // Find color code corresponding to the entered color name
        int i;
        for (i = 0; i < 8; i++) {
            if (strcmp(COLOR_NAMES[i], color_name) == 0) {
                printf("The color code is: %s\n", COLOR_CODES[i]);
                break;
            }
        }

        if(i == 8) {
            printf("Invalid color name. Try again.\n");
        }

    } else {
        printf("Invalid option. Try again.\n");
    }

    return 0;
}