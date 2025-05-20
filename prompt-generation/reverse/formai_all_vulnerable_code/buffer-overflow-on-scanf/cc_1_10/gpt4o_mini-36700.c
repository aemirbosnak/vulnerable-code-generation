//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void print_triangle(int depth, int level, char **triangle, int height) {
    if (level == depth) {
        return;
    }

    int width = height * 2 - 1;
    for (int i = 0; i < (1 << level); i++) {
        int row = (1 << level) - 1 + (i << (depth - level));
        for (int j = height - 1 - (i + 1); j < height + i; j++) {
            if (j >= 0 && j < height) {
                triangle[row][j] = '#';
            }
        }
        print_triangle(depth, level + 1, triangle, height);
    }
}

void initialize_triangle(char **triangle, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height * 2 - 1; j++) {
            triangle[i][j] = ' ';
        }
        triangle[i][height * 2 - 1] = '\0'; // Null-terminate the string
    }
}

void display_triangle(char **triangle, int height) {
    for (int i = 0; i < height; i++) {
        printf("%s\n", triangle[i]);
    }
}

void free_triangle(char **triangle, int height) {
    for (int i = 0; i < height; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

int main() {
    int depth;

    printf("Enter the depth of the Sierpinski triangle (0-7): ");
    scanf("%d", &depth);

    if (depth < 0 || depth > 7) {
        printf("Depth must be between 0 and 7.\n");
        return 1;
    }

    int height = (1 << depth); // Calculate height based on the depth
    char **triangle = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        triangle[i] = malloc((height * 2 - 1) * sizeof(char));
    }

    initialize_triangle(triangle, height);
    print_triangle(depth, 0, triangle, height);
    display_triangle(triangle, height);

    free_triangle(triangle, height);
    return 0;
}