//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40
#define MAX_PATTERNS 10

typedef struct {
    char *name;
    int width;
    int height;
    char *pattern;
} Pattern;

Pattern patterns[MAX_PATTERNS] = {
    {"Checkerboard", 8, 8, "ABCDEFGH"},
    {"Sine Wave", 16, 4, "AABBCC"},
    {"Random Dots", 12, 6, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"Diagonal Lines", 20, 2, "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"Triangles", 10, 10, "ABCDEFGHIJ"},
    {"Hexagons", 12, 8, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"Chevron", 16, 4, "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"Stars", 12, 6, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"Circles", 14, 5, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"Spiral", 18, 2, "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"}
};

void print_pattern(Pattern *pattern) {
    int i, j, k;
    for (i = 0; i < pattern->height; i++) {
        for (j = 0; j < pattern->width; j++) {
            printf("%c", pattern->pattern[k]);
            k++;
            if (k >= strlen(pattern->pattern)) {
                k = 0;
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int pattern_index = rand() % MAX_PATTERNS;
    Pattern *pattern = &patterns[pattern_index];
    printf("Pattern Name: %s\n", pattern->name);
    printf("Width: %d\n", pattern->width);
    printf("Height: %d\n", pattern->height);
    printf("Pattern: %s\n", pattern->pattern);
    print_pattern(pattern);
    return 0;
}