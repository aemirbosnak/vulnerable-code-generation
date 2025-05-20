//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 16

struct color {
    char name[20];
    int value;
};

static struct color colors[] = {
    {"black", 0},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"white", 7},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_yellow", 11},
    {"light_blue", 12},
    {"light_magenta", 13},
    {"light_cyan", 14},
    {"light_white", 15}
};

int main(int argc, char *argv[]) {
    int color_index = 0;
    char input[80];
    char *token;

    printf("Enter a color name or a hexadecimal value:\n");
    scanf("%s", input);

    token = strtok(input, ",");
    while (token!= NULL) {
        for (int i = 0; i < MAX_COLORS; i++) {
            if (strcmp(token, colors[i].name) == 0) {
                printf("%s = %d\n", token, colors[i].value);
                return 0;
            }
        }
        if (isdigit(token[0])) {
            int hex_value = strtol(token, NULL, 16);
            for (int i = 0; i < MAX_COLORS; i++) {
                if (hex_value == colors[i].value) {
                    printf("%s = %d\n", token, hex_value);
                    return 0;
                }
            }
        }
        token = strtok(NULL, ",");
    }

    printf("Invalid color name or value.\n");
    return 1;
}