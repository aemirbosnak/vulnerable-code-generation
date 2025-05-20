//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[MAX_COLORS];

int main() {
    int i, n;
    char input[100];

    // Initialize colors
    strcpy(colors[0].name, "black");
    colors[0].value = 0x000000;
    strcpy(colors[1].name, "white");
    colors[1].value = 0xFFFFFF;
    strcpy(colors[2].name, "red");
    colors[2].value = 0xFF0000;
    strcpy(colors[3].name, "green");
    colors[3].value = 0x00FF00;
    strcpy(colors[4].name, "blue");
    colors[4].value = 0x0000FF;

    printf("Enter the number of custom colors: ");
    scanf("%d", &n);

    for (i = 5; i < 5 + n; i++) {
        printf("Enter the name of color %d: ", i);
        scanf("%s", input);
        strcpy(colors[i].name, input);

        printf("Enter the value of color %d (in hexadecimal): ", i);
        scanf("%x", &colors[i].value);
    }

    // Test the color conversion
    printf("\nEnter a color name or value to convert:\n");
    scanf("%s", input);

    int value = 0;
    if (sscanf(input, "#%06x", &value) == 1) {
        for (i = 0; i < MAX_COLORS; i++) {
            if (colors[i].value == value) {
                printf("%s\n", colors[i].name);
                break;
            }
        }
    } else {
        for (i = 0; i < MAX_COLORS; i++) {
            if (strcmp(colors[i].name, input) == 0) {
                printf("%06x\n", colors[i].value);
                break;
            }
        }
    }

    return 0;
}