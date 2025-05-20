//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[MAX_COLORS] = {{"Black", 0}, {"White", 7}, {"Red", 1}, {"Green", 2}, {"Blue", 4}, {"Yellow", 6}, {"Magenta", 5}, {"Cyan", 3}, {"Gray", 8}, {"LightRed", 9}, {"LightGreen", 10}, {"LightBlue", 11}, {"LightYellow", 13}, {"LightMagenta", 12}, {"LightCyan", 14}, {"LightGray", 7}};

int main() {
    int choice;
    char input[100];

    printf("Welcome to the Color Code Converter!\n");
    printf("Enter 1 to convert from name to value.\n");
    printf("Enter 2 to convert from value to name.\n");
    printf("Enter 3 to exit.\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the name of the color: ");
            scanf("%s", input);

            for (int i = 0; i < MAX_COLORS; i++) {
                if (strcmp(colors[i].name, input) == 0) {
                    printf("The value of %s is %d.\n", input, colors[i].value);
                    break;
                }
            }

            break;

        case 2:
            printf("Enter the value of the color: ");
            scanf("%d", &input);

            for (int i = 0; i < MAX_COLORS; i++) {
                if (colors[i].value == input) {
                    printf("The name of %d is %s.\n", input, colors[i].name);
                    break;
                }
            }

            break;

        case 3:
            printf("Thank you for using the Color Code Converter!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}