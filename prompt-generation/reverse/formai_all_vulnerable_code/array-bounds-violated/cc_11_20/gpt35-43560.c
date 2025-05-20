//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

int main() {
    int n = 7; // number of rows
    int i, j, x, y;
    int arr[n][n]; // 2D array to store pattern
    
    // Initialize array elements to 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    
    x = n/2; // starting x position
    y = 0; // starting y position
    
    // Generate pattern
    for (i = 1; i <= n*n; i++) {
        arr[y][x] = i;
        
        // Move up and to the right
        if (y == 0 && x < n-1) {
            x++;
            y = n-1;
        }
        // Move down and to the left
        else if (x == 0 && y < n-1) {
            y++;
        }
        // Move up
        else if (x == n-1 && y > 0) {
            x--;
            y--;
        }
        // Move down
        else {
            x--;
        }
    }
    
    // Print pattern
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                printf("  "); // print space for 0
            } else {
                printf("%2d", arr[i][j]); // print number
            }
        }
        printf("\n"); // next row
    }
    
    return 0;
}