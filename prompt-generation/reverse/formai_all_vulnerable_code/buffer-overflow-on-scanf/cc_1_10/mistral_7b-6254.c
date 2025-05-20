//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SITE_SIZE 10
#define SITE_COUNT (SITE_SIZE * SITE_SIZE)

typedef struct {
    int x, y;
} point;

point grid[SITE_COUNT];
bool visited[SITE_COUNT];
int num_open_sites = 0;

void print_grid() {
    int i;
    for (i = 0; i < SITE_COUNT; i++) {
        if (i % SITE_SIZE == 0)
            printf("\n");
        if (grid[i].x < 0 || grid[i].y < 0)
            printf(" %2d ", -1);
        else
            printf(" %2d ", grid[i].x);
    }
    printf("\n");
}

bool is_valid(int x, int y) {
    return x >= 0 && x < SITE_SIZE && y >= 0 && y < SITE_SIZE;
}

void dfs(int x, int y) {
    if (!is_valid(x, y) || visited[x * SITE_SIZE + y])
        return;

    visited[x * SITE_SIZE + y] = true;
    num_open_sites++;

    if (x > 0 && grid[x * SITE_SIZE + y - 1].x == 0)
        dfs(x - 1, y);
    if (x < SITE_SIZE - 1 && grid[x * SITE_SIZE + y + 1].x == 0)
        dfs(x + 1, y);
    if (y > 0 && grid[(x - (y % SITE_SIZE)) * SITE_SIZE + y - 1].x == 0)
        dfs(x, y - 1);
    if (y < SITE_SIZE - 1 && grid[(x - (y % SITE_SIZE)) * SITE_SIZE + y + 1].x == 0)
        dfs(x, y + 1);
}

void simulate_percolation(int seed) {
    int i, x, y;
    srand(seed);

    for (i = 0; i < SITE_COUNT; i++) {
        x = rand() % SITE_SIZE;
        y = rand() % SITE_SIZE;
        grid[i] = (point) { x, y };
        num_open_sites += grid[i].x;
    }

    printf("Initial condition:\n");
    print_grid();

    visited[0] = true;
    dfs(0, 0);

    printf("\nPercolation probability: %.2f%%\n", (float)num_open_sites / SITE_COUNT * 100);
}

int main() {
    int seed;

    printf("Enter the seed value for random number generator: ");
    scanf("%d", &seed);

    simulate_percolation(seed);

    return 0;
}