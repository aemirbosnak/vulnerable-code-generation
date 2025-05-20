//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
    int value;
} color_code;

color_code color_codes[] = {
    {"black", 0},
    {"maroon", 1},
    {"green", 2},
    {"olive", 3},
    {"navy", 4},
    {"purple", 5},
    {"teal", 6},
    {"silver", 7},
    {"gray", 8},
    {"red", 9},
    {"lime", 10},
    {"yellow", 11},
    {"blue", 12},
    {"fuchsia", 13},
    {"aqua", 14},
    {"white", 15}
};

int main() {
    char input[MAX_CODE_LENGTH + 1];
    color_code *selected_color;

    printf("Enter a color code (between 0 and 15): ");
    scanf("%s", input);

    selected_color = color_codes;

    while (selected_color->value!= atoi(input)) {
        selected_color++;

        if (selected_color - color_codes == MAX_CODE_LENGTH) {
            printf("Invalid color code.\n");
            return 1;
        }
    }

    printf("Selected color: %s\n", selected_color->name);

    return 0;
}