//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: rigorous
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
    int num_codes;
    printf("Enter the number of color codes you want to convert: ");
    scanf("%d", &num_codes);

    char **input_codes = (char **)malloc(num_codes * sizeof(char *));
    for (int i = 0; i < num_codes; i++) {
        input_codes[i] = (char *)malloc(MAX_CODE_LENGTH * sizeof(char));
        printf("Enter color code %d: ", i + 1);
        scanf("%s", input_codes[i]);
    }

    int *output_values = (int *)malloc(num_codes * sizeof(int));
    for (int i = 0; i < num_codes; i++) {
        ColorCode *color = NULL;
        for (int j = 0; j < sizeof(color_codes) / sizeof(ColorCode); j++) {
            if (strcmp(input_codes[i], color_codes[j].code) == 0) {
                color = &color_codes[j];
                break;
            }
        }

        if (color == NULL) {
            printf("Invalid color code '%s'\n", input_codes[i]);
            exit(1);
        }

        output_values[i] = color->value;
    }

    for (int i = 0; i < num_codes; i++) {
        printf("Color code '%s' has a value of %d\n", input_codes[i], output_values[i]);
    }

    for (int i = 0; i < num_codes; i++) {
        free(input_codes[i]);
    }
    free(input_codes);
    free(output_values);

    return 0;
}