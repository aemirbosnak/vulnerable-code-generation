//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
    int x;
    int y;
} Point;

void print_pattern(char pattern[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }
}

void set_pattern(char pattern[SIZE][SIZE], char c, Point start) {
    for (int i = start.y; i < start.y + 2; i++) {
        for (int j = start.x; j < start.x + 3; j++) {
            if (i == start.y && j >= start.x && j < start.x + 3) {
                pattern[i][j] = c;
            }
        }
    }
}

int main() {
    char pattern[SIZE][SIZE];
    Point start;
    char c;

    memset(pattern, ' ', SIZE * SIZE);

    printf("Enter the character for the pattern: ");
    scanf(" %c", &c);

    printf("Enter the position for the pattern (x y): ");
    scanf("%d%d", &start.x, &start.y);

    if (start.x < 0 || start.x >= SIZE || start.y < 0 || start.y >= SIZE) {
        printf("Invalid position.\n");
        return 1;
    }

    set_pattern(pattern, c, start);
    print_pattern(pattern);

    return 0;
}