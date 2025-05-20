//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
    unsigned int code;
} color_t;

color_t colors[] = {
    {"black", 0},
    {"white", 16777215},
    {"red", 16711680},
    {"green", 65280},
    {"blue", 255},
    {"yellow", 16776960},
    {"magenta", 16711935},
    {"cyan", 65535},
    {"gray", 8421504}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name|color_code>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int input_len = strlen(input);

    if (input_len == MAX_CODE_LENGTH && input[0] == '#') {
        // Input is a hexadecimal color code
        unsigned int code = 0;
        for (int i = 1; i < input_len; i++) {
            if (input[i] >= '0' && input[i] <= '9') {
                code = (code << 4) + (input[i] - '0');
            } else if (input[i] >= 'A' && input[i] <= 'F') {
                code = (code << 4) + (input[i] - 'A' + 10);
            } else {
                // Invalid character in color code
                printf("Invalid color code\n");
                return 1;
            }
        }

        color_t *color = NULL;
        for (int i = 0; i < sizeof(colors) / sizeof(color_t); i++) {
            if (colors[i].code == code) {
                color = &colors[i];
                break;
            }
        }

        if (color == NULL) {
            printf("Unknown color code\n");
            return 1;
        }

        printf("%s\n", color->name);
    } else {
        // Input is a color name
        color_t *color = NULL;
        for (int i = 0; i < sizeof(colors) / sizeof(color_t); i++) {
            if (strcmp(input, colors[i].name) == 0) {
                color = &colors[i];
                break;
            }
        }

        if (color == NULL) {
            printf("Unknown color name\n");
            return 1;
        }

        printf("#%06X\n", color->code);
    }

    return 0;
}