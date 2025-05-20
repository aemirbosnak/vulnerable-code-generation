//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 100

typedef struct {
    char *name;
    char *hex_code;
} Color;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    Color colors[MAX_COLOR_NAMES];
    int num_colors = 0;

    file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open colors.txt\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (num_colors >= MAX_COLOR_NAMES) {
                printf("Error: Too many color names\n");
                return 1;
            }
            colors[num_colors].name = strdup(token);
            token = strtok(NULL, ",");
            if (token == NULL) {
                printf("Error: Invalid color format\n");
                return 1;
            }
            colors[num_colors].hex_code = strdup(token);
            num_colors++;
            token = strtok(NULL, ",");
        }
    }

    fclose(file);

    printf("Enter a color name or hex code to convert:\n");
    char input[MAX_LINE_LENGTH];
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    token = strtok(input, ",");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_colors; i++) {
            if (strcmp(token, colors[i].name) == 0) {
                printf("%.6s\n", colors[i].hex_code);
                break;
            } else if (strcmp(token, colors[i].hex_code) == 0) {
                printf("%s\n", colors[i].name);
                break;
            }
        }
        if (i == num_colors) {
            printf("Error: Invalid color name or hex code\n");
        }
        token = strtok(NULL, ",");
    }

    return 0;
}