//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 1000
#define MAX_COLOR_VALUES 100000

typedef struct {
    char color_name[50];
    int color_value;
} Color;

Color color_table[MAX_COLOR_NAMES];
int color_table_size = 0;

void load_color_table(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open color table file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* color_name = strtok(line, ",");
        int color_value = strtol(strtok(NULL, ","), NULL, 16);

        if (color_table_size >= MAX_COLOR_NAMES) {
            printf("Error: Color table is full.\n");
            exit(1);
        }

        strncpy(color_table[color_table_size].color_name, color_name, sizeof(color_table[color_table_size].color_name));
        color_table[color_table_size].color_value = color_value;
        color_table_size++;
    }

    fclose(file);
}

int main() {
    load_color_table("colors.txt");

    char input[50];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char* color_name = strtok(input, " ");
        int color_value = strtol(strtok(NULL, " "), NULL, 16);

        if (color_value == 0) {
            printf("Error: Invalid color value.\n");
            continue;
        }

        int i;
        for (i = 0; i < color_table_size; i++) {
            if (color_table[i].color_value == color_value) {
                printf("%s\n", color_table[i].color_name);
                break;
            }
        }

        if (i == color_table_size) {
            printf("Error: Color not found.\n");
        }
    }

    return 0;
}