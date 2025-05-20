//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAME_LENGTH 7
#define MAX_COLOR_VALUE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char value[MAX_COLOR_VALUE_LENGTH];
} Color;

Color colors[] = {
    {"BLACK", "\033[30m"},
    {"RED", "\033[31m"},
    {"GREEN", "\033[32m"},
    {"YELLOW", "\033[33m"},
    {"BLUE", "\033[34m"},
    {"MAGENTA", "\033[35m"},
    {"CYAN", "\033[36m"},
    {"WHITE", "\033[37m"},
    {"RESET", "\033[0m"}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [text]\n", argv[0]);
        return 1;
    }

    int text_length = strlen(argv[1]);
    char *output = malloc(text_length + 1);

    int output_length = 0;
    for (int i = 0; i < text_length; i++) {
        if (isalpha(argv[1][i])) {
            for (int j = 0; j < sizeof(colors) / sizeof(Color); j++) {
                if (strcasecmp(argv[1] + i, colors[j].name) == 0) {
                    strcat(output, colors[j].value);
                    i += strlen(colors[j].name) - 1;
                    break;
                }
            }
        } else {
            output[output_length++] = argv[1][i];
        }
    }

    output[output_length] = '\0';
    printf("%s\n", output);

    free(output);
    return 0;
}