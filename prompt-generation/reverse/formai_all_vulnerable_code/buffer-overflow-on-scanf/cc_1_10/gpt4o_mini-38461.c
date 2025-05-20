//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEIGHT 20
#define MAX_ANGLE 45

typedef struct {
    int x, y;
} Point;

Point branch_points[MAX_HEIGHT];

void draw_branch(int depth, Point start, double angle, int length) {
    if (depth == 0) {
        return;
    }
    
    // Calculate the new branch's end point
    Point end;
    end.x = start.x + (int)(length * cos(angle));
    end.y = start.y - (int)(length * sin(angle));
    
    // Print the line from start to end
    for (int i = 0; i <= length; i++) {
        int x_pos = start.x + (int)(i * cos(angle));
        int y_pos = start.y - (int)(i * sin(angle));
        if (y_pos >= 0 && y_pos < MAX_HEIGHT) {
            branch_points[y_pos] = (Point){.x = x_pos, .y = y_pos};
        }
    }
    
    // Recursive calls to draw the left and right branches
    draw_branch(depth - 1, end, angle - M_PI / 6, length * 2 / 3);
    draw_branch(depth - 1, end, angle + M_PI / 6, length * 2 / 3);
}

void init_branch_points() {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        branch_points[i] = (Point){.x = 0, .y = 0};
    }
}

void print_tree() {
    printf("\n");
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < 80; j++) {
            if (branch_points[i].y == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int depth;
    
    printf("Enter the depth of the fractal tree (1 to 10): ");
    scanf("%d", &depth);
    
    // Validate depth
    if (depth < 1 || depth > 10) {
        printf("Depth should be between 1 and 10.\n");
        return 1;
    }
    
    // Initialize the branch points
    init_branch_points();
    
    // Start drawing branches
    Point start = {40, MAX_HEIGHT - 1}; // Start in the middle bottom of the console
    draw_branch(depth, start, -M_PI / 2, 10);
    
    // Print the result
    print_tree();
    
    return 0;
}