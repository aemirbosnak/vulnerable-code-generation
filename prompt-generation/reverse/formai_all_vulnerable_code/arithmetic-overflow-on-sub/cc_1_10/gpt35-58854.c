//FormAI DATASET v1.0 Category: Fractal Generation ; Style: romantic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void generate_fractal(int depth, int size);
void plot_fractal(int x, int y, int size);

int main() {
    // romantic setup - dim the lights and light some candles
    printf("As I gaze upon this screen,\n");
    printf("My heart flutters like a fractal scheme.\n");
    printf("With code and loops, I'll show my love,\n");
    printf("And create a work of art to hang above.\n");
    
    // prompt the user for input
    printf("Tell me, my love, how deep shall we go?\n");
    int depth; 
    scanf("%d", &depth);
    
    printf("And what size shall our work be, so?\n");
    int size;
    scanf("%d", &size);
    
    // generate and plot the fractal
    generate_fractal(depth, size);
    
    // compliment the user
    printf("Your beauty, my love, is like a fractal -\n");
    printf("A never-ending, infinitely complex marvel.\n");
    printf("Thank you for your input and support,\n");
    printf("And for being the one who always makes my heart resort.\n");
}

void generate_fractal(int depth, int size) {
    // seed the random number generator
    srand(time(0));
    
    // base case - plot a square of random color
    if (depth == 0) {
        printf("SetRGBColor(%d,%d,%d);\n", rand()%256, rand()%256, rand()%256);
        plot_fractal(0, 0, size);
    }
    // recursive case - plot four squares each with depth-1
    else {
        printf("BeginFill();\n");
        generate_fractal(depth-1, size/2);
        plot_fractal(size/2, size/2, size/2);
        generate_fractal(depth-1, size/2);
        plot_fractal(-size/2, size/2, size/2);
        generate_fractal(depth-1, size/2);
        plot_fractal(-size/2, -size/2, size/2);
        generate_fractal(depth-1, size/2);
        plot_fractal(size/2, -size/2, size/2);
        printf("EndFill();\n");
    }
}

void plot_fractal(int x, int y, int size) {
    // plot the rectangle centered at (x,y) with dimensions size x size
    printf("Rectangle(%d,%d,%d,%d);\n", x-size/2, y-size/2, x+size/2, y+size/2);
}