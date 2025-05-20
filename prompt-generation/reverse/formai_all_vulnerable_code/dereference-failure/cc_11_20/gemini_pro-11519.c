//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int x;
    int y;
} point;

int main() {
    srand(time(NULL));
    int n, m, k;
    printf("Enter the dimensions of the grid (n x m): ");
    scanf("%d %d", &n, &m);
    printf("Enter the number of pairs to be remembered: ");
    scanf("%d", &k);

    int** grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        grid[i] = (int*)malloc(m * sizeof(int));

    // Generate the pairs and place them randomly on the grid
    int* pairs = (int*)malloc(2 * k * sizeof(int));
    for (int i = 0; i < 2 * k; i++)
        pairs[i] = rand() % (n * m);

    for (int i = 0; i < 2 * k; i += 2) {
        int x1 = pairs[i] / m;
        int y1 = pairs[i] % m;
        int x2 = pairs[i + 1] / m;
        int y2 = pairs[i + 1] % m;
        grid[x1][y1] = grid[x2][y2] = i / 2 + 1;
    }

    // Print the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }

    // Get the user's input
    int** guesses = (int**)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++)
        guesses[i] = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < k; i++) {
        printf("Enter the coordinates of the first card (x y): ");
        scanf("%d %d", &guesses[i][0], &guesses[i][1]);
        printf("Enter the coordinates of the second card (x y): ");
        scanf("%d %d", &guesses[i][2], &guesses[i][3]);
    }

    // Check if the guesses are correct
    int score = 0;
    for (int i = 0; i < k; i++) {
        int x1 = guesses[i][0];
        int y1 = guesses[i][1];
        int x2 = guesses[i][2];
        int y2 = guesses[i][3];
        if (grid[x1][y1] == grid[x2][y2]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    // Print the score
    printf("Your score is %d out of %d.\n", score, k);

    // Free the memory
    for (int i = 0; i < n; i++)
        free(grid[i]);
    free(grid);
    free(pairs);
    for (int i = 0; i < k; i++)
        free(guesses[i]);
    free(guesses);

    return 0;
}