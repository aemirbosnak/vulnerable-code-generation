//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAMES 1000
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH + 1];
} Color;

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    char *saveptr;
    Color colors[MAX_COLOR_NAMES];
    int num_colors = 0;

    fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok_r(line, ",", &saveptr);
        if (token == NULL) {
            continue;
        }
        strcpy(colors[num_colors].name, token);
        token = strtok_r(NULL, ",", &saveptr);
        if (token == NULL) {
            printf("Invalid color definition: %s\n", line);
            continue;
        }
        strncpy(colors[num_colors].code, token, MAX_COLOR_CODE_LENGTH);
        colors[num_colors].code[MAX_COLOR_CODE_LENGTH] = '\0';
        num_colors++;
    }

    fclose(fp);

    printf("Enter a color name or code to convert:\n");
    char input[MAX_COLOR_CODE_LENGTH + 1];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    Color *color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(input, colors[i].name) == 0 || strcmp(input, colors[i].code) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color.\n");
        return 1;
    }

    printf("Color name: %s\n", color->name);
    printf("Color code: %s\n", color->code);

    return 0;
}