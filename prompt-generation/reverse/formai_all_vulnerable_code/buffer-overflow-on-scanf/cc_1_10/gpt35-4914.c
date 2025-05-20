//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, level;
    int x[3], y[3], newx, newy, midpointx, midpointy;
    srand(time(0));  // Set seed for random number generator
    
    // User input for number of levels
    printf("Enter the number of levels: ");
    scanf("%d", &level);
    
    // Initialize first triangle points
    x[0] = 400;
    y[0] = 50;
    x[1] = 50;
    y[1] = 750;
    x[2] = 750;
    y[2] = 750;

    // Loop through each level of recursion
    for (n = 0; n < level; n++) {
        // Draw current level triangle
        for (i = 0; i < 3; i++) {
            printf("%d %d\n", x[i], y[i]);
        }
        printf("%d %d\n\n", x[0], y[0]);  // Connect final points to first for a closed loop
        
        // Initialize new points
        for (i = 0; i < 3; i++) {
            // Find midpoint between current and next point
            midpointx = (x[i] + x[(i+1)%3]) / 2;
            midpointy = (y[i] + y[(i+1)%3]) / 2;
            
            // Randomly adjust new point's position
            newx = midpointx + (rand() % 200) - 100;
            newy = midpointy + (rand() % 200) - 100;
            
            // Ensure new points stay within boundaries of window
            if (newx < 0) {
                newx += 800;
            }
            else if (newx > 800) {
                newx -= 800;
            }
            if (newy < 0) {
                newy += 800;
            }
            else if (newy > 800) {
                newy -= 800;
            }
            
            // Update current point with new point coordinates
            x[i] = newx;
            y[i] = newy;
        }
    }
    return 0;
}