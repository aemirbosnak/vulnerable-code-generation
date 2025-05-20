//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    char *color_code;
} ColorCode;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    ColorCode *color_codes = NULL;
    int num_color_codes = 0;

    file = fopen("color_codes.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *color_name, *color_code_str;
        ColorCode *new_color_code;

        color_name = strtok(line, ",");
        color_code_str = strtok(NULL, ",");

        new_color_code = (ColorCode *) malloc(sizeof(ColorCode));
        new_color_code->name = strdup(color_name);
        new_color_code->color_code = strdup(color_code_str);

        color_codes = realloc(color_codes, sizeof(ColorCode) * (num_color_codes + 1));
        color_codes[num_color_codes] = *new_color_code;
        num_color_codes++;
    }

    fclose(file);

    // Convert a color name to its color code
    char *color_name;
    printf("Enter a color name: ");
    scanf("%s", color_name);

    ColorCode *color_code = NULL;
    for (int i = 0; i < num_color_codes; i++) {
        if (strcmp(color_name, color_codes[i].name) == 0) {
            color_code = &color_codes[i];
            break;
        }
    }

    if (color_code == NULL) {
        printf("Error: color not found.\n");
        exit(1);
    }

    printf("Color code: %s\n", color_code->color_code);

    return 0;
}