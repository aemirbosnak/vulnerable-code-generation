//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 100

typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLOR_NAMES];
int numColors = 0;

void loadColors() {
    FILE *fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open colors.txt\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *name = strtok(line, " ");
        int red = atoi(strtok(NULL, " "));
        int green = atoi(strtok(NULL, " "));
        int blue = atoi(strtok(NULL, " "));

        if (numColors >= MAX_COLOR_NAMES) {
            printf("Error: Too many colors\n");
            exit(1);
        }

        colors[numColors].name = strdup(name);
        colors[numColors].red = red;
        colors[numColors].green = green;
        colors[numColors].blue = blue;

        numColors++;
    }

    fclose(fp);
}

int main() {
    loadColors();

    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *token = strtok(input, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < numColors; i++) {
                if (strcmp(token, colors[i].name) == 0) {
                    printf("%s", colors[i].name);
                    break;
                }
            }

            if (i == numColors) {
                printf("%s", token);
            }

            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}