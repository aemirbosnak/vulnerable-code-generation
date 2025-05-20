//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 7

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0},
    {"White", 7},
    {"Red", 1},
    {"Green", 2},
    {"Blue", 4},
    {"Cyan", 6},
    {"Magenta", 5}
};

int main() {
    int choice, value;
    char input[50];

    printf("Welcome to the Color Code Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert color name to value\n");
    printf("2. Convert color value to name\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a color name: ");
            scanf("%s", input);

            for (int i = 0; i < MAX_COLORS; i++) {
                if (strcmp(input, colors[i].name) == 0) {
                    printf("The value for %s is %d.\n", input, colors[i].value);
                    break;
                }
            }

            break;

        case 2:
            printf("Enter a color value (0-7): ");
            scanf("%d", &value);

            for (int i = 0; i < MAX_COLORS; i++) {
                if (colors[i].value == value) {
                    printf("The name for value %d is %s.\n", value, colors[i].name);
                    break;
                }
            }

            break;

        case 3:
            printf("Thank you for using the Color Code Converter!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}