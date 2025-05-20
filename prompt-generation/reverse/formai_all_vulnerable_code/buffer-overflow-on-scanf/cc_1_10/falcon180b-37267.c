//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int value;
} ColorCode;

ColorCode color_codes[] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"blue", 2},
    {"green", 3},
    {"yellow", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_yellow", 11},
    {"light_blue", 12},
    {"light_magenta", 13},
    {"light_cyan", 14},
    {"light_gray", 15}
};

int main() {
    int n;
    scanf("%d", &n);

    char *input[n];
    for (int i = 0; i < n; i++) {
        input[i] = (char *) malloc(sizeof(char) * 50);
        scanf("%s", input[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 16; j++) {
            if (strcmp(input[i], color_codes[j].name) == 0) {
                printf("%s = %d\n", input[i], color_codes[j].value);
                break;
            }
        }
    }

    return 0;
}