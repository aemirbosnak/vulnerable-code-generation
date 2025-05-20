//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 1000
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAMES];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

void readColors(Color colors[]) {
    FILE *file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open colors.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s", colors[count].name, colors[count].code)!= EOF) {
        count++;
    }

    fclose(file);
}

void printColors(Color colors[]) {
    printf("Color Name\tColor Code\n");
    for (int i = 0; i < MAX_COLOR_NAMES; i++) {
        if (colors[i].name[0]!= '\0') {
            printf("%s\t%s\n", colors[i].name, colors[i].code);
        }
    }
}

int main() {
    Color colors[MAX_COLOR_NAMES];
    readColors(colors);

    char input[MAX_COLOR_CODE_LENGTH];
    printf("Enter a color code: ");
    scanf("%s", input);

    int index = -1;
    for (int i = 0; i < MAX_COLOR_NAMES; i++) {
        if (strcmp(colors[i].code, input) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Invalid color code\n");
    } else {
        printf("Color name: %s\n", colors[index].name);
    }

    return 0;
}