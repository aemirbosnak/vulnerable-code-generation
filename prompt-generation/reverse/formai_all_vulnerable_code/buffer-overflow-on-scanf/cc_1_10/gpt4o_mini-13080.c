//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // 4x4 grid
#define TOTAL_TILES (SIZE * SIZE)

char grid[SIZE][SIZE];
char revealed[SIZE][SIZE];
char chars[TOTAL_TILES];
int pairs_found = 0;

void initialize_grid() {
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index = 0;
    
    for (int i = 0; i < TOTAL_TILES / 2; i++) {
        chars[index++] = alpha[i];
        chars[index++] = alpha[i];
    }

    // Shuffle the characters
    for (int i = TOTAL_TILES - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }

    // Populate the grid
    index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = chars[index++];
            revealed[i][j] = ' ';
        }
    }
}

void print_grid() {
    printf("  ");
    for (int j = 0; j < SIZE; j++) {
        printf(" %d ", j);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("[%c]", revealed[i][j]);
        }
        printf("\n");
    }
}

int check_match(int x1, int y1, int x2, int y2) {
    return grid[x1][y1] == grid[x2][y2];
}

void reveal_tile(int x, int y) {
    revealed[x][y] = grid[x][y];
}

void hide_tile(int x, int y) {
    revealed[x][y] = ' ';
}

int main() {
    srand(time(NULL));
    initialize_grid();

    while (pairs_found < TOTAL_TILES / 2) {
        print_grid();

        int x1, y1, x2, y2;
        printf("Select first tile (row col): ");
        scanf("%d %d", &x1, &y1);
        printf("Select second tile (row col): ");
        scanf("%d %d", &x2, &y2);

        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) {
            printf("Invalid input! Try again.\n");
            continue;
        }

        if (x1 == x2 && y1 == y2) {
            printf("You must select two different tiles!\n");
            continue;
        }

        reveal_tile(x1, y1);
        reveal_tile(x2, y2);
        print_grid();

        if (check_match(x1, y1, x2, y2)) {
            printf("Match found: %c\n", grid[x1][y1]);
            pairs_found++;
        } else {
            printf("No match. Try again.\n");
            hide_tile(x1, y1);
            hide_tile(x2, y2);
        }

        printf("\n");
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}