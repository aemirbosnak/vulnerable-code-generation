//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char* name;
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0},
    {"White", 7},
    {"Red", 1},
    {"Green", 2},
    {"Blue", 4},
    {"Cyan", 6},
    {"Magenta", 5},
    {"Yellow", 3},
    {"Gray", 8},
    {"LightRed", 9},
    {"LightGreen", 10},
    {"LightBlue", 12},
    {"LightCyan", 14},
    {"LightMagenta", 13},
    {"LightYellow", 11},
    {"BrightWhite", 15}
};

int main() {
    int choice;
    char input[100];

    printf("Welcome to the Color Code Converter!\n\n");
    printf("Enter 'Convert' followed by a color name or code to convert it.\n");
    printf("Enter 'List' to display a list of available colors.\n");
    printf("Enter 'Exit' to quit.\n\n");

    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "Convert") == 0) {
            scanf("%s", input);

            int found = 0;
            for (int i = 0; i < MAX_COLORS; i++) {
                if (strcmp(input, colors[i].name) == 0) {
                    printf("%s: %d\n", input, colors[i].value);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Color not found.\n");
            }
        }
        else if (strcmp(input, "List") == 0) {
            printf("Available colors:\n");
            for (int i = 0; i < MAX_COLORS; i++) {
                printf("%d. %s\n", i+1, colors[i].name);
            }
        }
        else if (strcmp(input, "Exit") == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}