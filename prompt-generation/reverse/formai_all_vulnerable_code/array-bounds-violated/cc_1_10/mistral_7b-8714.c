//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define WIDTH 21
#define HEIGHT 7
#define CHAR_COUNT 5
#define PATTERN_FILE "pattern.txt"

typedef struct {
    char symbol;
    int x, y;
} Point;

void print_pattern(Point start, int direction, int count) {
    Point current = start;
    char symbols[CHAR_COUNT][WIDTH];

    for (int i = 0; i < CHAR_COUNT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            symbols[i][j] = ' ';
        }
    }

    for (int i = 0; i < count; ++i) {
        current.x += current.y >= 0 ? 1 : -1;
        current.y += direction;

        symbols[current.y / abs(current.y) % CHAR_COUNT][current.x % WIDTH] = current.y >= 0 ? 'O' : 'X';
    }

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            putchar(symbols[i % CHAR_COUNT][j]);
        }
        putchar('\n');
    }
}

int main() {
    Point start = { 'S', 0, 0 };
    int direction = 1;

    if (access(PATTERN_FILE, F_OK) == -1) {
        printf("Pattern file not found.\n");
        return 1;
    }

    if (open(PATTERN_FILE, O_RDONLY) == -1) {
        printf("Failed to open pattern file.\n");
        return 1;
    }

    char buffer[1024];
    ssize_t bytes_read = read(0, buffer, sizeof(buffer) - 1);

    if (bytes_read <= 0) {
        printf("Error reading from standard input.\n");
        return 1;
    }

    buffer[bytes_read] = '\0';

    if (sscanf(buffer, "%d", &direction) != 1) {
        printf("Invalid input. Expected an integer.\n");
        return 1;
    }

    if (direction != 1 && direction != -1) {
        printf("Invalid direction. Expected 1 or -1.\n");
        return 1;
    }

    print_pattern(start, direction, WIDTH / 2 + 1);

    close(0);
    return 0;
}