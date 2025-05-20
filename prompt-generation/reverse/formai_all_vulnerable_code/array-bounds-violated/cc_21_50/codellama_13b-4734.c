//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
int main() {
    int numbers[15];
    int i, j, k;
    int count;
    int player[2][15];
    int drawn[15];
    char grid[5][5];

    // Initialize the numbers array
    for (i = 0; i < 15; i++) {
        numbers[i] = i + 1;
    }

    // Initialize the drawn array
    for (i = 0; i < 15; i++) {
        drawn[i] = 0;
    }

    // Initialize the player grids
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 15; j++) {
            player[i][j] = 0;
        }
    }

    // Initialize the grid
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            grid[i][j] = ' ';
        }
    }

    // Set the starting player
    count = 0;
    while (count < 15) {
        // Draw a number
        i = rand() % 15;

        // Check if the number has already been drawn
        if (drawn[i] == 0) {
            // Add the number to the drawn array
            drawn[i] = 1;

            // Add the number to the player grid
            player[count % 2][i] = 1;

            // Print the number on the grid
            grid[i / 5][i % 5] = 'X';

            // Increment the count
            count++;
        }
    }

    // Print the grid
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    // Check for bingo
    for (i = 0; i < 2; i++) {
        // Check the rows
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if (player[i][j * 5 + k] == 0) {
                    break;
                }
            }
            if (k == 5) {
                printf("Player %d has won!\n", i + 1);
                return 0;
            }
        }

        // Check the columns
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if (player[i][k * 5 + j] == 0) {
                    break;
                }
            }
            if (k == 5) {
                printf("Player %d has won!\n", i + 1);
                return 0;
            }
        }

        // Check the diagonals
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if (player[i][j * 5 + k] == 0) {
                    break;
                }
            }
            if (k == 5) {
                printf("Player %d has won!\n", i + 1);
                return 0;
            }
        }
    }

    return 0;
}