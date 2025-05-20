//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *code;
    int value;
} ColorCode;

ColorCode color_codes[] = {
    {"Black", 0},
    {"Maroon", 1},
    {"Green", 2},
    {"Olive", 3},
    {"Navy", 4},
    {"Purple", 5},
    {"Teal", 6},
    {"Silver", 7},
    {"Gray", 8},
    {"Red", 9},
    {"Lime", 10},
    {"Yellow", 11},
    {"Blue", 12},
    {"Fuchsia", 13},
    {"Aqua", 14},
    {"White", 15}
};

int main() {
    char input_code[MAX_CODE_LENGTH + 1];
    int code_value;

    printf("Enter a color code (e.g. \"Red\"): ");
    scanf("%s", input_code);

    code_value = 0;
    for (int i = 0; i < sizeof(color_codes) / sizeof(ColorCode); i++) {
        if (strcmp(input_code, color_codes[i].code) == 0) {
            code_value = color_codes[i].value;
            break;
        }
    }

    if (code_value == 0) {
        printf("Invalid color code.\n");
    } else {
        printf("Color code value: %d\n", code_value);
    }

    return 0;
}