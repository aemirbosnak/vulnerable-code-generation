//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void initialize_grid(int grid[N][N], float p) {
    srand(time(NULL));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            float r = (float) rand() / RAND_MAX;
            if(r < p) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

void print_grid(int grid[N][N], int player) {
    printf("Player %d grid:\n", player);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void percolate(int grid[N][N], int player) {
    int visited[N][N] = {0};
    int stack[N*N][2];
    int top = -1;

    // Check if top row has a percolating cluster
    for(int i=0; i<N; i++) {
        if(grid[0][i] == 1 && !visited[0][i]) {
            visited[0][i] = 1;
            stack[++top][0] = 0;
            stack[top][1] = i;
        }
    }

    // Start DFS
    while(top >= 0) {
        int i = stack[top][0];
        int j = stack[top][1];
        top--;

        if(i > 0 && grid[i-1][j] == 1 && !visited[i-1][j]) {
            visited[i-1][j] = 1;
            stack[++top][0] = i-1;
            stack[top][1] = j;
        }

        if(i < N-1 && grid[i+1][j] == 1 && !visited[i+1][j]) {
            visited[i+1][j] = 1;
            stack[++top][0] = i+1;
            stack[top][1] = j;
        }

        if(j > 0 && grid[i][j-1] == 1 && !visited[i][j-1]) {
            visited[i][j-1] = 1;
            stack[++top][0] = i;
            stack[top][1] = j-1;
        }

        if(j < N-1 && grid[i][j+1] == 1 && !visited[i][j+1]) {
            visited[i][j+1] = 1;
            stack[++top][0] = i;
            stack[top][1] = j+1;
        }
    }

    // Check if bottom row has a percolating cluster
    for(int i=0; i<N; i++) {
        if(grid[N-1][i] == 1 && visited[N-1][i]) {
            printf("Player %d wins!\n", player);
            return;
        }
    }

    printf("Player %d did not win. Try again.\n", player);
}

int main() {
    int grid[2][N][N];
    float p;
    printf("Enter probability of Xs appearing on the grid: ");
    scanf("%f", &p);

    // Initialize grids for both players
    initialize_grid(grid[0], p);
    initialize_grid(grid[1], p);

    // Start game
    for(int i=0; i<10; i++) {
        printf("Turn %d:\n", i+1);
        print_grid(grid[0], 0);
        print_grid(grid[1], 1);

        int player;
        printf("Player 1, select a block: ");
        scanf("%d", &player);
        int row = player / N;
        int col = player % N;
        if(grid[1][row][col] == 1) {
            grid[1][row][col] = 0;
        } else {
            grid[1][row][col] = 1;
        }
        percolate(grid[1], 1);

        printf("Player 2, select a block: ");
        scanf("%d", &player);
        row = player / N;
        col = player % N;
        if(grid[0][row][col] == 1) {
            grid[0][row][col] = 0;
        } else {
            grid[0][row][col] = 1;
        }
        percolate(grid[0], 0);
    }

    return 0;
}