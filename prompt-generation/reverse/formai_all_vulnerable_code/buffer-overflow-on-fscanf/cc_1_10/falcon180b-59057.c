//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256
#define MAX_COLOR_NAME_LEN 32
#define MAX_COLOR_CODE_LEN 8

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    char code[MAX_COLOR_CODE_LEN];
} Color;

int main() {
    Color colors[MAX_COLORS];
    int numColors = 0;
    char input[MAX_COLOR_NAME_LEN];
    char code[MAX_COLOR_CODE_LEN];
    int len;

    // read in the color names and codes from a file
    FILE *fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open colors.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", input, code) == 2) {
        strcpy(colors[numColors].name, input);
        strcpy(colors[numColors].code, code);
        numColors++;
    }

    fclose(fp);

    // prompt the user for a color name
    printf("Enter a color name: ");
    fgets(input, MAX_COLOR_NAME_LEN, stdin);
    len = strlen(input);

    // remove the newline character from the input
    input[len - 1] = '\0';

    // find the color code for the input color name
    for (int i = 0; i < numColors; i++) {
        if (strcmp(colors[i].name, input) == 0) {
            printf("The color code for %s is: %s\n", input, colors[i].code);
            exit(0);
        }
    }

    // if the color name is not found, print an error message
    printf("Error: color '%s' not found\n", input);
    exit(1);
}