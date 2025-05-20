//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: optimized
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
#define MAX_RECURSION_DEPTH 200
#define MAX_FAILS 1000

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef u32 Square;
typedef u64 Row;
typedef u64 Col;
typedef u64 Block;

int solved;
int fails;
int recursion_depth;

Square grid[SIZE][SIZE];

Square* get_square(int x, int y) {
    return &grid[y][x];
}

void set_square(int x, int y, Square value) {
    Square* square = get_square(x, y);
    *square = value;
}

void print_grid() {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            printf("%d ", *get_square(x, y));
        }
        printf("\n");
    }
}

Row get_row(int y) {
    Row row = 0;
    for (int x = 0; x < SIZE; x++) {
        row |= 1ULL << *get_square(x, y);
    }
    return row;
}

void set_row(int y, Row row) {
    for (int x = 0; x < SIZE; x++) {
        *get_square(x, y) = 63 - __builtin_clzll(row & ~(1ULL << *get_square(x, y)));
    }
}

Col get_col(int x) {
    Col col = 0;
    for (int y = 0; y < SIZE; y++) {
        col |= 1ULL << *get_square(x, y);
    }
    return col;
}

void set_col(int x, Col col) {
    for (int y = 0; y < SIZE; y++) {
        *get_square(x, y) = 63 - __builtin_clzll(col & ~(1ULL << *get_square(x, y)));
    }
}

Block get_block(int x, int y) {
    int bx = x / 3;
    int by = y / 3;
    Block block = 0;
    for (int dy = 0; dy < 3; dy++) {
        for (int dx = 0; dx < 3; dx++) {
            block |= 1ULL << *get_square(bx * 3 + dx, by * 3 + dy);
        }
    }
    return block;
}

void set_block(int x, int y, Block block) {
    int bx = x / 3;
    int by = y / 3;
    for (int dy = 0; dy < 3; dy++) {
        for (int dx = 0; dx < 3; dx++) {
            *get_square(bx * 3 + dx, by * 3 + dy) = 63 - __builtin_clzll(block & ~(1ULL << *get_square(bx * 3 + dx, by * 3 + dy)));
        }
    }
}

int is_valid(int x, int y) {
    Square value = *get_square(x, y);
    if (value == 0) {
        return 1;
    }
    Row row = get_row(y);
    Col col = get_col(x);
    Block block = get_block(x, y);
    return !(row & (1ULL << value) || col & (1ULL << value) || block & (1ULL << value));
}

int solve(int x, int y) {
    recursion_depth++;
    if (recursion_depth > MAX_RECURSION_DEPTH) {
        return 0;
    }
    if (x == SIZE) {
        x = 0;
        y++;
        if (y == SIZE) {
            solved = 1;
            return 1;
        }
    }
    Square* square = get_square(x, y);
    if (*square != 0) {
        return solve(x + 1, y);
    }
    for (Square value = 1; value <= SIZE; value++) {
        *square = value;
        if (is_valid(x, y)) {
            if (solve(x + 1, y)) {
                return 1;
            }
        }
        *square = 0;
    }
    fails++;
    if (fails > MAX_FAILS) {
        return 0;
    }
    return 0;
}

int main() {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            scanf(" %hu", get_square(x, y));
        }
    }
    solve(0, 0);
    if (solved) {
        print_grid();
    } else {
        printf("No solution found.\n");
    }
    return 0;
}