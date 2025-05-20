//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

struct color {
    char name[20];
    int value;
};

int main() {
    struct color colors[MAX_COLORS];
    int num_colors = 0;
    char input[100];

    // Initialize default colors
    strcpy(colors[0].name, "black");
    colors[0].value = 0;
    num_colors++;

    strcpy(colors[1].name, "red");
    colors[1].value = 1;
    num_colors++;

    strcpy(colors[2].name, "green");
    colors[2].value = 2;
    num_colors++;

    strcpy(colors[3].name, "yellow");
    colors[3].value = 3;
    num_colors++;

    strcpy(colors[4].name, "blue");
    colors[4].value = 4;
    num_colors++;

    strcpy(colors[5].name, "magenta");
    colors[5].value = 5;
    num_colors++;

    strcpy(colors[6].name, "cyan");
    colors[6].value = 6;
    num_colors++;

    strcpy(colors[7].name, "white");
    colors[7].value = 7;
    num_colors++;

    printf("Enter a color name or value (0-7): ");
    scanf("%s", input);

    int i;
    for (i = 0; i < num_colors; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            printf("The color code for %s is %d\n", input, colors[i].value);
            return 0;
        }
    }

    for (i = 0; i < num_colors; i++) {
        if (atoi(input) == colors[i].value) {
            printf("The color name for %d is %s\n", colors[i].value, colors[i].name);
            return 0;
        }
    }

    printf("Invalid color name or value\n");
    return 0;
}