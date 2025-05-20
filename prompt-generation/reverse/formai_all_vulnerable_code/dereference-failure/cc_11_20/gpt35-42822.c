//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
/* It was a gloomy day in London, and Sherlock Holmes was engrossed in programming a percolation simulator to help him solve his latest case.
   As he typed away on his computer, he muttered to himself, "Elementary, my dear Watson, all we need is a good percolation program to crack this case."

   With that, he began to code... */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int size, probability, count, i, j, k;
    char** grid;
    int* indices;

    printf("Welcome to Sherlock Holmes' Percolation Simulator!\n");
    printf("Please enter the size of the grid you wish to simulate: ");
    scanf("%d", &size); // get user input for grid size

    printf("Please enter the probability of each cell being open (0-100): ");
    scanf("%d", &probability); // get user input for probability of each cell being open

    grid = (char**)malloc(size * sizeof(char*)); // allocate memory for the grid
    for (i = 0; i < size; i++) {
        grid[i] = (char*)malloc(size * sizeof(char));
        for (j = 0; j < size; j++) {
            if (rand() % 100 < probability) { // randomly determine if each cell is open or closed
                grid[i][j] = 'o'; // 'o' represents an open cell
            }
            else {
                grid[i][j] = 'x'; // 'x' represents a closed cell
            }
        }
    }

    count = 0; // initialize count of open cells to 0
    for (i = 0; i < size; i++) {
        if (grid[0][i] == 'o') { // check if top row of cells are open
            indices = (int*)malloc(size * sizeof(int)); // allocate memory for indices of open cells
            indices[0] = i; // add first open cell to the indices array
            k = 1;
            for (j = 1; j < size; j++) {
                if (grid[j][i] == 'o') { // check if next cell in this column is open
                    indices[k] = i * size + j; // calculate index of this cell and add it to the indices array
                    k++;
                }
            }
            if (k == size) { // if all cells in this column are open, we have a percolation
                count += k; // add count of open cells to overall count of open cells
                printf("The grid percolates!\n");
                free(indices); // free memory allocated for indices array
                for (j = 0; j < size; j++) {
                    grid[j][i] = 'P'; // 'P' represents a percolating cell
                }
            }
            else { // if not all cells in this column are open, we do not have a percolation
                free(indices); // free memory allocated for indices array
            }
        }
    }

    printf("The grid has %d open cells.\n", count); // print number of open cells
    
    // free memory allocated for grid
    for (i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0; // program termination
}