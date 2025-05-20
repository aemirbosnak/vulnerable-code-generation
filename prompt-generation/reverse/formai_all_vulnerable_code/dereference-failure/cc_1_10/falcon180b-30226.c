//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 1000
#define MAX_COLOR_NAME_LENGTH 50
#define MAX_COLOR_CODE_LENGTH 10

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

int main() {
    int numColors = 0;
    Color colors[MAX_COLOR_NAMES];

    // Load color names and codes from file
    FILE *fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open colors file.\n");
        exit(1);
    }

    char line[MAX_COLOR_NAME_LENGTH + MAX_COLOR_CODE_LENGTH + 2]; // +2 for null terminator and space separator
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (numColors >= MAX_COLOR_NAMES) {
            printf("Error: Maximum number of colors exceeded.\n");
            exit(1);
        }

        char *name = strtok(line, " ");
        char *code = strtok(NULL, " ");
        if (name == NULL || code == NULL) {
            printf("Error: Invalid color format.\n");
            exit(1);
        }

        strncpy(colors[numColors].name, name, MAX_COLOR_NAME_LENGTH - 1);
        strncpy(colors[numColors].code, code, MAX_COLOR_CODE_LENGTH - 1);
        colors[numColors].name[MAX_COLOR_NAME_LENGTH - 1] = '\0';
        colors[numColors].code[MAX_COLOR_CODE_LENGTH - 1] = '\0';

        numColors++;
    }

    fclose(fp);

    // Print color table
    printf("Color Name\tColor Code\n");
    for (int i = 0; i < numColors; i++) {
        printf("%-20s\t%s\n", colors[i].name, colors[i].code);
    }

    return 0;
}