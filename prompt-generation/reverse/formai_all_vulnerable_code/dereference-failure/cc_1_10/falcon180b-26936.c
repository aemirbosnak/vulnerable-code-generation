//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_COLOR_NAMES 10
#define MAX_COLOR_NAME_LEN 10
#define MAX_COLOR_CODE_LEN 7
#define MAX_COLOR_NAME_CODE_LEN 17

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    char code[MAX_COLOR_CODE_LEN];
} Color;

Color color_table[MAX_COLOR_NAMES] = {
    {"black", "000000"},
    {"white", "FFFFFF"},
    {"red", "FF0000"},
    {"green", "00FF00"},
    {"blue", "0000FF"},
    {"yellow", "FFFF00"},
    {"magenta", "FF00FF"},
    {"cyan", "00FFFF"},
    {"gray", "808080"},
    {"silver", "C0C0C0"}
};

int num_colors = 10;

void print_color_table(void) {
    printf("Color Name\tCode\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s\t%s\n", color_table[i].name, color_table[i].code);
    }
}

void add_color(char *name, char *code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Color table is full.\n");
        return;
    }
    strcpy(color_table[num_colors].name, name);
    strcpy(color_table[num_colors].code, code);
    num_colors++;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }
    char *color_name = argv[1];
    int i;
    for (i = 0; i < num_colors; i++) {
        if (strcmp(color_name, color_table[i].name) == 0) {
            printf("%s\n", color_table[i].code);
            return 0;
        }
    }
    printf("Error: Color not found.\n");
    return 1;
}