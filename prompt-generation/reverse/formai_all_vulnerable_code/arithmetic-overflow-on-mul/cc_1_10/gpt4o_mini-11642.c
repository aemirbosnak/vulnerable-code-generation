//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Function to print the coordinates of the star
void print_star(int arms, float radius, float inner_radius) {
    float angle = 2 * PI / arms; // Total angle for each arm

    printf("Coordinates of the star with %d arms:\n", arms);
    for (int i = 0; i < arms * 2; i++) {
        // Alternate between arm and inner vertex
        float r = (i % 2 == 0) ? radius : inner_radius;
        float theta = angle * i;

        // Calculate x and y coordinates
        float x = r * cos(theta);
        float y = r * sin(theta);

        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, x, y);
    }
}

// Function to draw the star in the console
void draw_star(int arms, float radius, float inner_radius) {
    int height = 20; // Height of the drawing area
    int width = 40;  // Width of the drawing area
    char canvas[20][40];

    // Initialize canvas with spaces
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            canvas[y][x] = ' ';
        }
    }

    // Get the star coordinates
    float angle = 2 * PI / arms;
    for (int i = 0; i < arms * 2; i++) {
        float r = (i % 2 == 0) ? radius : inner_radius;
        float theta = angle * i;

        // Calculate x and y coordinates
        int x = (int)(20 + r * cos(theta));
        int y = (int)(10 + r * sin(theta));

        // Ensure x and y stay within canvas bounds
        if (x >= 0 && x < width && y >= 0 && y < height) {
            canvas[y][x] = '*'; // Mark the coordinate
        }
    }

    // Printing the canvas
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(canvas[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    int arms;
    float radius, inner_radius;

    // Get user input for star parameters
    printf("Enter the number of arms for the star (3 or more): ");
    scanf("%d", &arms);
    
    if (arms < 3) {
        printf("Error: Star must have at least 3 arms.\n");
        return -1;
    }

    printf("Enter the outer radius of the star: ");
    scanf("%f", &radius);

    printf("Enter the inner radius of the star: ");
    scanf("%f", &inner_radius);

    // Print the coordinates of the star vertices
    print_star(arms, radius, inner_radius);
    
    // Draw the star in the console
    printf("\nDrawing the star:\n");
    draw_star(arms, radius, inner_radius);

    return 0;
}