//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"white", 1},
    {"red", 2},
    {"green", 3},
    {"blue", 4},
    {"yellow", 5},
    {"magenta", 6},
    {"cyan", 7},
    {"gray", 8},
    {"light gray", 9},
    {"pink", 10},
    {"light pink", 11},
    {"purple", 12},
    {"light purple", 13},
    {"orange", 14},
    {"light orange", 15}
};

int main() {
    char input[100];
    int i, j;

    printf("Enter a color name or a hexadecimal color code: ");
    scanf("%s", input);

    if (input[0] == '#') {
        int hex = 0;
        for (i = 1; i < strlen(input); i++) {
            if (input[i] >= '0' && input[i] <= '9') {
                hex = hex * 16 + input[i] - '0';
            } else if (input[i] >= 'A' && input[i] <= 'F') {
                hex = hex * 16 + input[i] - 'A' + 10;
            } else {
                printf("Invalid hexadecimal color code\n");
                return 1;
            }
        }
        for (i = 0; i < MAX_COLORS; i++) {
            if (colors[i].value == hex) {
                printf("%s\n", colors[i].name);
                return 0;
            }
        }
        printf("Unknown hexadecimal color code\n");
        return 1;
    } else {
        for (i = 0; i < MAX_COLORS; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                printf("%d\n", colors[i].value);
                return 0;
            }
        }
        printf("Unknown color name\n");
        return 1;
    }
}