//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for color codes
typedef struct {
    char name[20];
    int code;
} ColorCode;

int main() {
    int choice, i = 0;
    char input[20];
    ColorCode colors[] = {{"Black", 0}, {"White", 1}, {"Red", 2}, {"Green", 3}, {"Blue", 4}, {"Yellow", 5}, {"Magenta", 6}, {"Cyan", 7}, {"Gray", 8}, {"Light Red", 9}, {"Light Green", 10}, {"Light Blue", 11}, {"Light Yellow", 12}, {"Light Magenta", 13}, {"Light Cyan", 14}, {"Light Gray", 15}};

    // Display menu
    printf("Color Code Converter\n");
    printf("Enter your choice:\n");
    printf("1. Convert from color name to code\n");
    printf("2. Convert from code to color name\n");
    scanf("%d", &choice);

    // Convert from color name to code
    if (choice == 1) {
        printf("Enter color name: ");
        scanf("%s", input);
        for (i = 0; i < 16; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                printf("Code: %d\n", colors[i].code);
                break;
            }
        }
    }

    // Convert from code to color name
    else if (choice == 2) {
        printf("Enter code: ");
        scanf("%d", &i);
        for (int j = 0; j < 16; j++) {
            if (i == colors[j].code) {
                printf("Color name: %s\n", colors[j].name);
                break;
            }
        }
    }

    // Invalid choice
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}