//FormAI DATASET v1.0 Category: Fractal Generation ; Style: lively
// Welcome to the Fractal Generation Program!
// This program generates a Sierpinski Carpet fractal pattern.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to print the fractal pattern
void printPattern(char **grid, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%c ", grid[i][j]);    // Print each character in a cell of the grid
        }
        printf("\n");    // Move to the next row
    }
}

// Function to generate the fractal pattern
void generatePattern(char **grid, int size, int x, int y) {
    if(size==1) {
        grid[x][y] = ' ';    // Base case, fill the cell with ' '
    }
    else {
        int subSize = size/3;    // Sub-grid size
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i==1 && j==1) {
                    grid[x+subSize][y+subSize] = ' ';    // Leave the center cell empty
                }
                else {
                    generatePattern(grid, subSize, x+(i*subSize), y+(j*subSize));    // Recursively generate the pattern in sub-grids
                }
            }
        }
    }
}

// Main function
int main() {
    printf("Welcome to the Sierpinski Carpet Fractal Generation Program!\n\n");
    
    int size;    // Size of the fractal pattern
    printf("Enter the size of the fractal (a power of 3): ");
    scanf("%d", &size);

    // Check if size is a postive power of 3
    if(size<=0 || (int)log10(size)/log10(3)!=(log10(size)/log10(3))) {
        printf("Invalid size, please enter a positive power of 3.\n");
        return 0;
    }

    char **grid = (char**)malloc(size * sizeof(char*));    // Allocate memory for the grid
    for(int i=0; i<size; i++) {
        grid[i] = (char*)malloc(size * sizeof(char));    // Allocate memory for each row of characters
        memset(grid[i], 'X', size);    // Initialize all characters to 'X', i.e., all cells filled
    }
    
    printf("\nGenerating the fractal pattern...\n");
    generatePattern(grid, size, 0, 0);    // Generate the fractal pattern
    printf("\n");
    
    printPattern(grid, size);    // Print the fractal pattern

    for(int i=0; i<size; i++) {
        free(grid[i]);    // Free memory for each row of characters
    }
    free(grid);    // Free memory for the grid
    
    return 0;
}