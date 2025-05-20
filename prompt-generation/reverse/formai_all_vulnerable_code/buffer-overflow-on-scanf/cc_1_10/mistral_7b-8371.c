//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to print a star
void print_star() {
    printf("*");
}

// Function to print a horizontal line of stars
void print_line(int length) {
    int i;
    for(i = 0; i < length; i++) {
        print_star();
    }
    printf("\n");
}

// Function to draw a circle using midpoint algorithm
void draw_circle(int x0, int y0, int radius) {
    int x = 0, y = radius;
    int decisionOver1 = 1, decisionOver2;
    double d;

    printf("(%d, %d)\n", x0, y0);

    print_line(2 * radius + 1);

    while(x >= 0 && y >= 0) {
        printf("(%d, %d)", x, y);
        print_line(2 * abs(x) + 1);
        print_line(2 * abs(y) + 1);

        d = 2.0 * (sqrt(2.0) * radius - x) + 2.0 * y + 0.5;
        decisionOver2 = floor(d);

        if(decisionOver1 > decisionOver2) {
            x--;
            y -= decisionOver2 - 1;
            decisionOver1 = decisionOver2;
        }

        x++;
        y += decisionOver1 - decisionOver2;
    }

    printf("\n");
}

// Main function
int main() {
    int center_x, center_y, radius;

    printf("Enter center x, center y and radius: ");
    scanf("%d %d %d", &center_x, &center_y, &radius);

    printf("Drawing a circle with center (%d, %d) and radius %d:\n", center_x, center_y, radius);

    draw_circle(center_x, center_y, radius);

    return 0;
}