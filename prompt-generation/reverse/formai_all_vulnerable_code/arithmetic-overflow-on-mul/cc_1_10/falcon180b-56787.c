//Falcon-180B DATASET v1.0 Category: Educational ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of variables and the range of values for each variable
#define NUM_VARS 5
#define MIN_VALUE -100
#define MAX_VALUE 100

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize variables with random values within the specified range
    int vars[NUM_VARS];
    for (int i = 0; i < NUM_VARS; i++) {
        vars[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    // Print initial values of variables
    printf("Initial values:\n");
    for (int i = 0; i < NUM_VARS; i++) {
        printf("%d\t", vars[i]);
    }
    printf("\n");

    // Perform a series of operations on the variables
    for (int i = 0; i < 10; i++) {
        // Randomly select two variables and an operation
        int var1 = rand() % NUM_VARS;
        int var2 = rand() % NUM_VARS;
        int op = rand() % 4; // 0 = addition, 1 = subtraction, 2 = multiplication, 3 = division

        // Perform the selected operation and store the result in a temporary variable
        int result;
        switch (op) {
            case 0:
                result = vars[var1] + vars[var2];
                break;
            case 1:
                result = vars[var1] - vars[var2];
                break;
            case 2:
                result = vars[var1] * vars[var2];
                break;
            case 3:
                if (vars[var2] == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                result = vars[var1] / vars[var2];
                break;
        }

        // Update the values of the selected variables
        vars[var1] = result;
        vars[var2] = result;

        // Print the current values of the variables
        printf("After operation %d:\n", i+1);
        for (int j = 0; j < NUM_VARS; j++) {
            printf("%d\t", vars[j]);
        }
        printf("\n");
    }

    return 0;
}