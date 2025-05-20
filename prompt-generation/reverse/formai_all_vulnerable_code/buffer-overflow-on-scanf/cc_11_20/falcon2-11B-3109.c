//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h> 
#define MAX_SIZE 1000 
#define BLOCKED 0 
#define VISITED 1 

int main() 
{ 
    int width = 10, height = 10; 
    int visited[MAX_SIZE][MAX_SIZE]; 

    printf("Enter the size of the grid: "); 
    scanf("%d %d", &width, &height); 

    for (int i = 0; i < MAX_SIZE; i++) 
        for (int j = 0; j < MAX_SIZE; j++) 
            visited[i][j] = BLOCKED; 

    // Simulate percolation process 
    for (int k = 0; k < MAX_SIZE; k++) 
    { 
        int count = 0; 

        // Check each cell in the grid 
        for (int i = 0; i < MAX_SIZE; i++) 
        { 
            for (int j = 0; j < MAX_SIZE; j++) 
            { 
                if (visited[i][j]!= BLOCKED) 
                { 
                    if (i!= 0 && visited[i-1][j] == VISITED) 
                    { 
                        visited[i][j] = VISITED; 
                        count++; 
                    } 
                    if (j!= 0 && visited[i][j-1] == VISITED) 
                    { 
                        visited[i][j] = VISITED; 
                        count++; 
                    } 
                } 
            } 
        } 

        if (count == width * height) 
        { 
            printf("Percolation has occurred!\n"); 
            break; 
        } 
    } 
}