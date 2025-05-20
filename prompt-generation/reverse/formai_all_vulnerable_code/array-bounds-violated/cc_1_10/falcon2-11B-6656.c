//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find a maze route
bool findMazeRoute(int maze[10][10], int rows, int cols) {
    // Mark starting position as visited
    maze[0][0] = 1;
    
    // Create a queue for BFS
    int queue[rows][cols];
    int front = 0;
    int rear = 0;
    queue[0][0] = 1;
    rear++;
    
    // Create a visited matrix
    bool visited[rows][cols];
    for (int i = 0; i < rows; i++) {
        visited[i][0] = false;
        visited[i][cols-1] = false;
    }
    
    // BFS algorithm to find the route
    while (front!= rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;
        
        // Check if the current position is the end position
        if (x == rows-1 && y == cols-1) {
            return true;
        }
        
        // Check all possible directions (up, down, left, right)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            // Check if the new position is within the maze boundaries and unvisited
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&!visited[newX][newY]) {
                // Mark the new position as visited
                visited[newX][newY] = true;
                
                // Add the new position to the queue
                queue[rear][0] = newX;
                queue[rear][1] = newY;
                rear++;
            }
        }
    }
    
    // If no route is found, return false
    return false;
}

int main() {
    int maze[10][10] = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0}
    };
    int rows = 5;
    int cols = 5;
    
    // Call the function to find the maze route
    bool result = findMazeRoute(maze, rows, cols);
    
    // Print the result
    if (result) {
        printf("Maze route found!\n");
    } else {
        printf("Maze route not found.\n");
    }
    
    return 0;
}