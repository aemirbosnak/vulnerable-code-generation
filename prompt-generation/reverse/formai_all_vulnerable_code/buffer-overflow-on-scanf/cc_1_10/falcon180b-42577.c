//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char *name;
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0},
    {"White", 7},
    {"Red", 31},
    {"Green", 32},
    {"Yellow", 33},
    {"Blue", 34},
    {"Magenta", 35},
    {"Cyan", 36},
    {"Gray", 37},
    {"DarkGray", 90},
    {"LightRed", 91},
    {"LightGreen", 92},
    {"LightYellow", 93},
    {"LightBlue", 94},
    {"LightMagenta", 95},
    {"LightCyan", 96}
};

int main() {
    int choice;
    char input[100];

    printf("Welcome to the Color Code Converter 3000!\n");
    printf("Please select an option:\n");
    printf("1. Convert RGB to color code\n");
    printf("2. Convert color code to RGB\n");
    printf("3. List all available colors\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the red value (0-255): ");
            scanf("%d", &input[0]);
            printf("Enter the green value (0-255): ");
            scanf("%d", &input[1]);
            printf("Enter the blue value (0-255): ");
            scanf("%d", &input[2]);

            for (int i = 0; i < MAX_COLORS; i++) {
                if (colors[i].value == input[0] * 256 + input[1] * 16 + input[2]) {
                    printf("Color code: %s\n", colors[i].name);
                }
            }

            break;

        case 2:
            printf("Enter a color code (0-15): ");
            scanf("%d", &input[0]);

            for (int i = 0; i < MAX_COLORS; i++) {
                if (colors[i].value == input[0]) {
                    printf("RGB: %d, %d, %d\n", colors[i].value / 16, (colors[i].value / 16) % 6, colors[i].value % 6);
                }
            }

            break;

        case 3:
            printf("Available colors:\n");

            for (int i = 0; i < MAX_COLORS; i++) {
                printf("%d. %s\n", i + 1, colors[i].name);
            }

            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option\n");
    }

    return 0;
}