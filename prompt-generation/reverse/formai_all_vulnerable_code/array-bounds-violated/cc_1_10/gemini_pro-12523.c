//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define N                       9
#define N2                      (N * N)

#define ROW_CONFLICT(p, i, v)    \
    p[(i) * N2 + (v) - 1]

#define COL_CONFLICT(p, i, v)    \
    p[(v) * N  + (i) - 1]

#define BOX_CONFLICT(p, i, v)    \
    p[(i) / 3 * N2 + (i) % 3 * N + (v) - 1]

typedef uint8_t v[N2];
typedef bool    conflict_v[N2];

static bool grid_has_conflict(const v p) {
    bool conflict = false;
    conflict_v row = { false }, col = { false }, box = { false };
    for (uint8_t i = 0; i < N2; i++) {
        uint8_t v = p[i];
        if (v) {
            if (ROW_CONFLICT(row, i, v)) {
                conflict = true;
                break;
            }
            ROW_CONFLICT(row, i, v) = true;

            if (COL_CONFLICT(col, i, v)) {
                conflict = true;
                break;
            }
            COL_CONFLICT(col, i, v) = true;

            if (BOX_CONFLICT(box, i, v)) {
                conflict = true;
                break;
            }
            BOX_CONFLICT(box, i, v) = true;
        }
    }
    return conflict;
}

static bool sudoku(v p, const uint8_t i, const uint8_t c) {
    if (i == N2) {
        return true;
    }

    if (c == N) {
        if (p[i] == 0) { return false; }
        return sudoku(p, i + 1, 1);
    }

    if (p[i] != 0) { return sudoku(p, i, c + 1); }

    bool conflict = false;
    for (uint8_t j = 1; j <= N; j++) {
        p[i] = j;
        conflict = grid_has_conflict(p);
        p[i] = 0;
        if (!conflict) {
            if (sudoku(p, i + 1, 1)) {
                return true;
            }
        }
    }
    return false;
}

static void print_sudoku(v p) {
    for (uint8_t i = 0; i < N2; i++) {
        write(STDOUT_FILENO, &p[i], sizeof(p[i]));
        if ((i + 1) % N == 0) {
            write(STDOUT_FILENO, "\n", 1);
        }
    }
}

int main(void) {
    v given = {
        5, 3, 0, 0, 7, 0, 0, 0, 0,
        6, 0, 0, 1, 9, 5, 0, 0, 0,
        0, 9, 8, 0, 0, 0, 0, 6, 0,
        8, 0, 0, 0, 6, 0, 0, 0, 3,
        4, 0, 0, 8, 0, 3, 0, 0, 1,
        7, 0, 0, 0, 2, 0, 0, 0, 6,
        0, 6, 0, 0, 0, 0, 2, 8, 0,
        0, 0, 0, 4, 1, 9, 0, 0, 5,
        0, 0, 0, 0, 8, 0, 0, 7, 9,
    };

    if (sudoku(given, 0, 1)) {
        print_sudoku(given);
    } else {
        write(STDOUT_FILENO, "No solution found.\n", strlen("No solution found.\n"));
    }
    return 0;
}