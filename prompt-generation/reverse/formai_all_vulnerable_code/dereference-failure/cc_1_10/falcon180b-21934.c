//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 64

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex_code[8];
} Color;

void add_color(Color *colors, int num_colors, char *name, char *hex_code) {
    strncpy(colors[num_colors].name, name, MAX_COLOR_NAME_LENGTH);
    strncpy(colors[num_colors].hex_code, hex_code, 8);
    num_colors++;
}

int main() {
    FILE *file;
    char line[1024];
    char *token;
    Color colors[100];
    int num_colors = 0;

    file = fopen("colors.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, 1024, file)!= NULL) {
        token = strtok(line, ",");
        add_color(colors, num_colors, token, token + 1);
    }

    fclose(file);

    printf("Enter a color name or hex code to search for:\n");
    scanf("%s", line);

    token = strtok(line, ",");
    int index = -1;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, token) == 0 || strcmp(colors[i].hex_code, token) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Color not found.\n");
    } else {
        printf("Name: %s\n", colors[index].name);
        printf("Hex Code: %s\n", colors[index].hex_code);
    }

    return 0;
}