//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_COLOR_CODE_LENGTH 7
#define MAX_COLOR_NAME_LENGTH 10

struct Color {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
};

void load_colors(struct Color *colors) {
    FILE *file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error loading colors.\n");
        exit(1);
    }
    
    int count = 0;
    while (fscanf(file, "%s %s", colors[count].name, colors[count].code) == 2 && count < MAX_COLORS) {
        count++;
    }
    
    fclose(file);
}

int main() {
    struct Color colors[MAX_COLORS];
    load_colors(colors);
    
    char input[MAX_COLOR_CODE_LENGTH];
    printf("Enter a color code: ");
    scanf("%s", input);
    
    int found = 0;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(input, colors[i].code) == 0) {
            printf("Color: %s\n", colors[i].name);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Color not found.\n");
    }
    
    return 0;
}