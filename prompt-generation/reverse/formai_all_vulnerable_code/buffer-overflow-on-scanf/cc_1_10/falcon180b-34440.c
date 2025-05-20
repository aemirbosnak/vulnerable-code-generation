//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char color_name[MAX_COLOR_NAME_LENGTH];
    char color_code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[MAX_COLORS] = {
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"},
    {"black", "\033[30m"},
    {"light_red", "\033[91m"},
    {"light_green", "\033[92m"}
};

int main() {
    int num_colors;
    char input_buffer[100];
    char color_name[MAX_COLOR_NAME_LENGTH];
    char color_code[MAX_COLOR_CODE_LENGTH];

    printf("Enter the number of colors you want to use (1-10): ");
    scanf("%d", &num_colors);

    if (num_colors < 1 || num_colors > MAX_COLORS) {
        printf("Invalid number of colors. Please enter a number between 1 and 10.\n");
        return 1;
    }

    printf("Enter the colors you want to use (separated by spaces): ");
    scanf("%s", input_buffer);

    char* token = strtok(input_buffer, " ");
    int i = 0;

    while (token!= NULL && i < num_colors) {
        strcpy(color_name, token);
        strcpy(color_code, colors[i].color_code);

        printf("Color %d: %s (%s)\n", i + 1, color_name, color_code);
        i++;

        token = strtok(NULL, " ");
    }

    if (i < num_colors) {
        printf("Not enough colors entered.\n");
        return 1;
    }

    return 0;
}