//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Print the Fibonacci sequence
void print_fibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Draw a box with the given width and height
void draw_box(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Draw a Fibonacci spiral
void draw_fibonacci_spiral(int n) {
    int width = n * 2 + 1;
    int height = n * 2 + 1;

    // Create a 2D array to store the spiral
    int spiral[width][height];

    // Initialize the spiral to 0
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            spiral[i][j] = 0;
        }
    }

    // Draw the Fibonacci spiral
    int x = width / 2;
    int y = height / 2;
    int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up
    int value = 0;

    while (value < n) {
        // Draw the current value in the spiral
        spiral[x][y] = value;

        // Increment the value
        value++;

        // Move in the current direction
        switch (direction) {
            case 0: // Right
                x++;
                break;
            case 1: // Down
                y++;
                break;
            case 2: // Left
                x--;
                break;
            case 3: // Up
                y--;
                break;
        }

        // Check if we need to change direction
        if (x == width || x == -1 || y == height || y == -1) {
            direction = (direction + 1) % 4;
        }
    }

    // Print the spiral
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", spiral[j][i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of Fibonacci numbers to generate
    int n;
    printf("How many Fibonacci numbers do you want to generate? ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printf("The first %d Fibonacci numbers are:\n", n);
    print_fibonacci(n);

    // Generate a random number between 1 and 10
    int r = random_number(1, 10);

    // Draw a box with the given width and height
    printf("Here is a box with a width of %d and a height of %d:\n", r, r);
    draw_box(r, r);

    // Draw a Fibonacci spiral
    printf("Here is a Fibonacci spiral with %d squares:\n", n);
    draw_fibonacci_spiral(n);

    return 0;
}