//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
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

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s [color_name | color_code]\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int input_length = strlen(input);

    if(input_length == MAX_CODE_LENGTH && isdigit(input[0])) {
        int code = atoi(input);
        if(code >= 0 && code <= 15) {
            printf("%s\n", color_codes[code].name);
            return 0;
        }
    }

    ColorCode *color = NULL;
    for(int i = 0; i < sizeof(color_codes)/sizeof(ColorCode); i++) {
        if(strcmp(input, color_codes[i].name) == 0) {
            color = &color_codes[i];
            break;
        }
    }

    if(color == NULL) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("%s\n", color->name);
    return 0;
}