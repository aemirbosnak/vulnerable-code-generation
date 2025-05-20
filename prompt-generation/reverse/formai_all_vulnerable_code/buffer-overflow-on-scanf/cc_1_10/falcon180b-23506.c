//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 10

typedef struct {
    char *name;
    int value;
} ColorName;

ColorName colorNames[MAX_COLOR_NAMES] = {
    {"black", 0},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"white", 7},
    {"gray", 8},
    {"lightgray", 9}
};

int main() {
    int choice;
    char input[50];
    int value;

    do {
        printf("Enter your choice:\n");
        printf("1. Convert color name to value\n");
        printf("2. Convert color value to name\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter color name: ");
            scanf("%s", input);
            value = 0;
            for (int i = 0; i < MAX_COLOR_NAMES; i++) {
                if (strcmp(colorNames[i].name, input) == 0) {
                    value = colorNames[i].value;
                    break;
                }
            }
            if (value == 0) {
                printf("Color not found.\n");
            } else {
                printf("Color value: %d\n", value);
            }
            break;
        case 2:
            printf("Enter color value: ");
            scanf("%d", &value);
            for (int i = 0; i < MAX_COLOR_NAMES; i++) {
                if (colorNames[i].value == value) {
                    printf("Color name: %s\n", colorNames[i].name);
                    break;
                }
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}