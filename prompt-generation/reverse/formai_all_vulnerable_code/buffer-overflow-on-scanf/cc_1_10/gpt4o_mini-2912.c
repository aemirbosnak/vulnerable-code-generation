//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define MAX_DEPTH 7

void draw_branch(int depth, double length, double angle) {
    if (depth == 0) {
        return;
    }
    
    // Calculate the new branch position
    double new_x = length * cos(angle);
    double new_y = length * sin(angle);
    
    // Move to the new branch location
    printf("Drawing branch at depth %d, length %.2f, angle %.2f\n", depth, length, angle);
    printf("Branch from (0, 0) to (%.2f, %.2f)\n", new_x, new_y);
    
    // Recursive calls to draw the right and left branches
    draw_branch(depth - 1, length * 0.7, angle + M_PI / 6); // right branch
    draw_branch(depth - 1, length * 0.7, angle - M_PI / 6); // left branch
}

void draw_tree() {
    printf("Let's grow a beautiful fractal tree!\n");
    printf("Starting tree generation...\n");
    
    // Set origin for the trunk of the tree
    double trunk_length = 10.0;
    double angle = M_PI / 2; // initial angle pointing up
    
    // Draw the main trunk and call recursive drawing function
    draw_branch(MAX_DEPTH, trunk_length, angle);
    
    printf("Yay! The tree has grown! 🌳\n");
}

int main() {
    printf("Welcome to the Happy Fractal Tree Generator!\n");
    printf("This program will generate a delightful fractal tree in your terminal.\n\n");

    // Ask the user for input before generating the tree
    char proceed;
    printf("Are you ready to see a fractal tree? (y/n): ");
    scanf(" %c", &proceed);

    if (proceed == 'y' || proceed == 'Y') {
        draw_tree();
    } else {
        printf("No worries! Come back when you're ready. 😊\n");
    }

    printf("Thanks for playing with fractals! Have a great day! 🌈\n");
    return 0;
}