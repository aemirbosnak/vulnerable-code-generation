//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *hex_code;
    char *rgb_code;
} ColorCode;

typedef struct {
    char *name;
    ColorCode *color_code;
} Color;

Color *get_color_by_name(char *name) {
    Color *color = NULL;
    FILE *file = fopen("colors.txt", "r");
    char line[MAX_LINE_LENGTH];

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ":");
        if (strcmp(token, name) == 0) {
            color = (Color *)malloc(sizeof(Color));
            color->name = strdup(name);

            token = strtok(NULL, ":");
            color->color_code = (ColorCode *)malloc(sizeof(ColorCode));
            color->color_code->hex_code = strdup(token);

            token = strtok(NULL, ":");
            int len = strlen(token);
            color->color_code->rgb_code = (char *)malloc(len + 1);
            strcpy(color->color_code->rgb_code, token);

            break;
        }
    }

    fclose(file);
    return color;
}

void print_color_codes(Color *color) {
    printf("Name: %s\n", color->name);
    printf("Hex Code: %s\n", color->color_code->hex_code);
    printf("RGB Code: %s\n", color->color_code->rgb_code);
}

int main() {
    char name[100];
    printf("Enter a color name: ");
    scanf("%s", name);

    Color *color = get_color_by_name(name);

    if (color!= NULL) {
        print_color_codes(color);
    } else {
        printf("Color not found.\n");
    }

    free(color->name);
    free(color->color_code->hex_code);
    free(color->color_code->rgb_code);
    free(color);

    return 0;
}