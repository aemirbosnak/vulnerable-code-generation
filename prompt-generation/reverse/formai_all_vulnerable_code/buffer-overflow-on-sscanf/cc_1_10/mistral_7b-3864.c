//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_COLOR 50
#define COLOR_SIZE 3
typedef struct {
    char name[MAX_COLOR];
    char rgb[COLOR_SIZE][3];
} Color;
Color colors[MAX_COLOR];
void convert_color(char *color_name) {
    char rgb[COLOR_SIZE][3] = {0};
    int index = -1;
    for (int i = 0; i < MAX_COLOR; i++) {
        if (strcasecmp(colors[i].name, color_name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Unknown color %s\n", color_name);
        return;
    }
    sscanf(colors[index].rgb, "%d%d%d", &rgb[0][0], &rgb[0][1], &rgb[0][2]);
    printf("RGB values for %s: %d, %d, %d\n", color_name, rgb[0][0], rgb[0][1], rgb[0][2]);
}
int main(int argc, char *argv[]) {
    FILE *file;
    char line[100];
    int count = 0;
    file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file colors.txt\n");
        return 1;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        char color_name[MAX_COLOR] = {0};
        sscanf(line, "%s", color_name);
        strcpy(colors[count].name, color_name);
        sscanf(line + strlen(color_name) + 1, "%[3][3][3]", colors[count].rgb);
        count++;
    }
    fclose(file);
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }
    convert_color(argv[1]);
    return 0;
}