//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 64
#define MAX_COLOR_CODE_LENGTH 7

struct Color {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
};

int main() {
    int num_colors = 0;
    struct Color colors[100]; // Maximum of 100 colors

    // Read in color names and codes from a file
    FILE *fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open colors.txt\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_colors >= 100) {
            printf("Error: Too many colors (maximum 100)\n");
            exit(1);
        }

        char *name_start = line;
        char *name_end = strchr(line, ',');
        if (name_end == NULL) {
            printf("Error: Invalid color format\n");
            exit(1);
        }
        *name_end = '\0';
        strncpy(colors[num_colors].name, name_start, MAX_COLOR_NAME_LENGTH - 1);
        colors[num_colors].name[MAX_COLOR_NAME_LENGTH - 1] = '\0';

        char *code_start = name_end + 1;
        char *code_end = strchr(code_start, '\n');
        if (code_end == NULL) {
            printf("Error: Invalid color format\n");
            exit(1);
        }
        *code_end = '\0';
        strncpy(colors[num_colors].code, code_start, MAX_COLOR_CODE_LENGTH - 1);
        colors[num_colors].code[MAX_COLOR_CODE_LENGTH - 1] = '\0';

        num_colors++;
    }

    fclose(fp);

    // Convert RGB color code to hexadecimal
    char hex_code[MAX_COLOR_CODE_LENGTH];
    for (int i = 0; i < num_colors; i++) {
        sprintf(hex_code, "#%02x%02x%02x",
            atoi(colors[i].code),
            atoi(colors[i].code + 3),
            atoi(colors[i].code + 6));

        printf("%s -> %s\n", colors[i].name, hex_code);
    }

    return 0;
}