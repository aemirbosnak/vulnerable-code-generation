//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
/*
 * This program generates a fractal pattern using recursive iteration
 * based on the Koch Snowflake fractal. It generates a fractal with
 * specified number of iterations and size.
 * 
 * Ada Lovelace Style C Program
 * Author: [Your Name]
 */

#include <stdio.h>
#include <math.h>

void koch_snowflake(int x1, int y1, int x2, int y2, int iterations);

int main() {
    int x1, y1, x2, y2, iterations;

    printf("Enter the coordinates of the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    koch_snowflake(x1, y1, x2, y2, iterations);

    return 0;
}

void koch_snowflake(int x1, int y1, int x2, int y2, int iterations) {
    if (iterations == 0) {
        // Base case: Draw a straight line
        printf("Line from (%d,%d) to (%d,%d)\n", x1, y1, x2, y2);
        return;
    }

    // Calculate the points for the new shapes
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;
    int x4 = (x1 + x2) / 2 + (int)((y2 - y1) * sqrt(3) / 6);
    int y4 = (y1 + y2) / 2 + (int)((x1 - x2) * sqrt(3) / 6);
    int x5 = (x1 + 2 * x2) / 3;
    int y5 = (y1 + 2 * y2) / 3;

    // Draw the four smaller snowflakes
    koch_snowflake(x1, y1, x3, y3, iterations - 1);
    koch_snowflake(x3, y3, x4, y4, iterations - 1);
    koch_snowflake(x4, y4, x5, y5, iterations - 1);
    koch_snowflake(x5, y5, x2, y2, iterations - 1);
}