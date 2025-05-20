//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

typedef struct {
    char *name;
    char *code;
} color_t;

color_t colors[] = {
    {"red", "\033[0;31m"},
    {"green", "\033[0;32m"},
    {"yellow", "\033[0;33m"},
    {"blue", "\033[0;34m"},
    {"magenta", "\033[0;35m"},
    {"cyan", "\033[0;36m"},
    {"white", "\033[0;37m"},
    {"default", "\033[0m"}
};

int main() {
    char input[MAX_SIZE];
    char *color_name = NULL;
    int color_code = 0;
    printf("Enter text to color: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("Enter color name or code (e.g. red, \033[0;31m): ");
    scanf("%s", input);
    if (input[0] == '\033' && input[1] == '[') {
        color_code = atoi(&input[2]);
        color_name = "default";
    } else {
        for (int i = 0; i < sizeof(colors) / sizeof(color_t); i++) {
            if (strcmp(input, colors[i].name) == 0) {
                color_name = colors[i].name;
                color_code = i;
                break;
            }
        }
    }
    if (color_name == NULL) {
        printf("Invalid color\n");
        return 1;
    }
    printf("%s%s%s\033[0m\n", colors[color_code].code, input, colors[color_code].code);
    return 0;
}