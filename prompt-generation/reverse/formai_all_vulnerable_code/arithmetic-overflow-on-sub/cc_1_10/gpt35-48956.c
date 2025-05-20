//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

// Function to print the maze
void print_maze(char **maze, int n) {
    for(int i=0; i<n; i++) {
        printf("%s\n", maze[i]);
    }
    printf("\n");
}

// Function to check if the current position is valid or not
int is_valid(char **maze, int n, int row, int col) {
    if(row>=0 && row<n && col>=0 && col<n && maze[row][col]!='*')
        return 1;
    return 0;
}

// Function to find the route in the maze
void find_route(char **maze, int n, int row, int col) {
    if(row==n-1 && col==n-1) { // Reached the destination
        maze[row][col] = 'X'; // Mark the destination
        print_maze(maze, n); // Print the maze
        exit(0); // Exit the program
    }
    if(is_valid(maze, n, row, col)) {
        maze[row][col] = 'X'; // Mark the current position
        find_route(maze, n, row, col+1); // Move right
        find_route(maze, n, row+1, col); // Move down
        find_route(maze, n, row, col-1); // Move left
        find_route(maze, n, row-1, col); // Move up
        maze[row][col] = ' '; // Unmark the current position
    }
}

int main() {
    int n;
    printf("Enter the size of the maze: ");
    scanf("%d", &n);
    char **maze = (char **) malloc(n * sizeof(char *)); // Allocate memory for the maze
    for(int i=0; i<n; i++) {
        maze[i] = (char *) malloc(n * sizeof(char));
        for(int j=0; j<n; j++)
            scanf(" %c", &maze[i][j]); // Taking input from user
    }
    printf("\nThe maze is:\n");
    print_maze(maze, n); // Printing the maze
    printf("\nFinding the route...\n\nThe solution is:\n");
    find_route(maze, n, 0, 0); // Starting from (0, 0)
    printf("\nNo solution found!\n"); // If the solution is not found
    return 0;
}