//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char code[MAX_CODE_LENGTH];
    int value;
} ColorCode;

ColorCode color_codes[] = {
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
    int num_codes = sizeof(color_codes) / sizeof(ColorCode);
    char input[MAX_CODE_LENGTH];

    printf("Enter a color code (or type 'list' for a list of available codes): ");
    scanf("%s", input);

    if (strcmp(input, "list") == 0) {
        printf("Available color codes:\n");
        for (int i = 0; i < num_codes; i++) {
            printf("%s (%d)\n", color_codes[i].code, color_codes[i].value);
        }
        return 0;
    }

    int code_value = -1;
    for (int i = 0; i < num_codes; i++) {
        if (strcmp(input, color_codes[i].code) == 0) {
            code_value = color_codes[i].value;
            break;
        }
    }

    if (code_value == -1) {
        printf("Invalid color code.\n");
    } else {
        printf("Color code value: %d\n", code_value);
    }

    return 0;
}