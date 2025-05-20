//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main()
{
    int baggage[ROWS][COLS]; // 2D array to simulate baggage on conveyor belt
    int baggage_count = 0, total_bags = 0; // counters for bags in system
    int row, col, conveyor_length, move_to_row, move_to_col, max_bags;
    int current_row = 0, current_col = 0, next_row = 0, next_col = 0;
    int total_time = 0, move_time = 0;
    int i, j;

    srand(time(NULL)); // seed random function

    printf("Enter conveyor length: ");
    scanf("%d", &conveyor_length);

    printf("Enter maximum number of bags: ");
    scanf("%d", &max_bags);

    // initialize baggage array with 0s
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            baggage[i][j] = 0;
        }
    }

    // simulate baggage on conveyor belt
    while (total_bags <= max_bags) {

        // check if there is room for more bags on conveyor belt
        if (baggage_count < conveyor_length) {
            baggage[current_row][current_col] = 1;
            baggage_count++;
            total_bags++;
        }

        // check if there is any baggage to move
        if (baggage_count > 0) {
            // move baggage to next position on conveyor belt
            if (current_col < (COLS-1)) {
                next_row = current_row;
                next_col = current_col + 1;
            } else {
                next_row = current_row + 1;
                next_col = 0;
            }

            if (next_row < ROWS) {
                // check if next position is empty
                if (baggage[next_row][next_col] == 0) {
                    move_to_row = next_row;
                    move_to_col = next_col;
                } else { // try to move baggage randomly
                    move_to_row = rand() % ROWS;
                    move_to_col = rand() % COLS;
                }

                // move baggage to new position
                baggage[move_to_row][move_to_col] = 1;
                baggage[current_row][current_col] = 0;
                baggage_count--;
                move_time = (rand() % 5) + 1; // generate random time for baggage to move
                total_time += move_time;
            }
        }

        current_row = next_row;
        current_col = next_col;
    }

    printf("Total bags processed: %d\n", total_bags);
    printf("Total time taken: %d seconds\n", total_time);

    return 0;
}