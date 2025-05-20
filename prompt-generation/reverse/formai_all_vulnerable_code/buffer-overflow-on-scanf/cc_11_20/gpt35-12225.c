//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 100
#define MAX_MOVES 10

int main()
{
    int num_cars, num_steps;
    int current_pos[MAX_CARS];
    int moves[MAX_CARS][MAX_MOVES];
    int i, j;

    // Get user input for number of cars and number of steps
    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    printf("Enter the number of steps: ");
    scanf("%d", &num_steps);

    // Initialize the current positions of the cars randomly
    srand(time(NULL));
    for (i = 0; i < num_cars; i++) {
        current_pos[i] = rand() % (num_cars * 2);
    }

    // Generate random moves for each car
    for (i = 0; i < num_cars; i++) {
        for (j = 0; j < num_steps; j++) {
            moves[i][j] = rand() % 3 - 1;
        }
    }

    // Simulate the traffic flow
    for (i = 0; i < num_steps; i++) {
        for (j = 0; j < num_cars; j++) {
            // Calculate the new position of the car
            int new_pos = current_pos[j] + moves[j][i];
            if (new_pos >= 0 && new_pos < num_cars * 2) {
                // Move the car to the new position
                current_pos[j] = new_pos;
            }
        }

        // Print the current status of the traffic flow
        printf("Step %d:\n", i + 1);
        for (j = 0; j < num_cars * 2; j++) {
            int is_car = 0;
            for (int k = 0; k < num_cars; k++) {
                if (current_pos[k] == j) {
                    is_car = 1;
                    break;
                }
            }
            printf("%c ", is_car ? '*' : '-');
        }
        printf("\n");
    }

    return 0;
}