//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    int value;
} ColorName;

ColorName colorNames[MAX_COLOR_NAMES];
int numColorNames = 0;

int main() {
    int i, j, k;
    char line[1024];
    char *token;
    ColorName *color;

    // Initialize color names
    colorNames[0].name = "black";
    colorNames[0].value = 0;
    numColorNames = 1;

    // Read color names from file
    FILE *fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open colors.txt\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }
        color = &colorNames[numColorNames];
        strcpy(color->name, token);
        color->value = numColorNames;
        numColorNames++;
    }
    fclose(fp);

    // Print color names
    printf("Color names:\n");
    for (i = 0; i < numColorNames; i++) {
        printf("%s (%d)\n", colorNames[i].name, colorNames[i].value);
    }

    // Convert color names to values
    while (1) {
        printf("Enter a color name or value (0-%d): ", numColorNames - 1);
        if (scanf("%d", &k) == 1) {
            if (k >= 0 && k < numColorNames) {
                printf("Value: %d\n", k);
                break;
            } else {
                printf("Invalid value\n");
            }
        } else if (fgets(line, sizeof(line), stdin)!= NULL) {
            token = strtok(line, "\n");
            for (i = 0; i < numColorNames; i++) {
                if (strcmp(token, colorNames[i].name) == 0) {
                    printf("Value: %d\n", colorNames[i].value);
                    break;
                }
            }
            if (i == numColorNames) {
                printf("Color not found\n");
            }
        } else {
            printf("Error reading input\n");
            exit(1);
        }
    }

    return 0;
}