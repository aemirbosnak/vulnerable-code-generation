//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LEN 100
#define MAX_COLOR_VALUES 3

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    int values[MAX_COLOR_VALUES];
} Color;

void print_color(Color color) {
    printf("Name: %s\n", color.name);
    printf("Values: ");
    for (int i = 0; i < MAX_COLOR_VALUES; i++) {
        printf("%d ", color.values[i]);
    }
    printf("\n");
}

int main() {
    // Initialize colors
    Color colors[] = {
        {"Red", {255, 0, 0}},
        {"Green", {0, 255, 0}},
        {"Blue", {0, 0, 255}},
        {"Yellow", {255, 255, 0}},
        {"Purple", {128, 0, 128}}
    };

    int num_colors = sizeof(colors) / sizeof(Color);

    char input[MAX_COLOR_NAME_LEN];
    int value_count;
    int values[MAX_COLOR_VALUES];

    // Loop through each color
    for (int i = 0; i < num_colors; i++) {
        // Print the current color
        print_color(colors[i]);

        // Get user input for color values
        printf("Enter values for %s (comma-separated): ", colors[i].name);
        scanf("%s", input);

        // Convert string input to integer values
        value_count = 0;
        char *token = strtok(input, ",");
        while (token!= NULL && value_count < MAX_COLOR_VALUES) {
            values[value_count++] = atoi(token);
            token = strtok(NULL, ",");
        }

        // Update the color values
        for (int j = 0; j < value_count; j++) {
            colors[i].values[j] = values[j];
        }
    }

    // Print the updated colors
    for (int i = 0; i < num_colors; i++) {
        print_color(colors[i]);
    }

    return 0;
}