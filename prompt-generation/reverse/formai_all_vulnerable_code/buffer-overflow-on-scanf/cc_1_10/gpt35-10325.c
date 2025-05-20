//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
/*
 * This program generates a custom fractal pattern using mathematical functions
 * and modular programming techniques.
 *
 * The pattern is designed to resemble a snowflake.
 *
 * The program accepts user input for the number of layers in the fractal
 * and the size of the pattern.
 *
 * Author: [Your Name]
 * Date: [Date of creation]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589

void draw_line(double, double, double, double);
void generate_fractal(int, int);

int main() {
    int layers, size;
    printf("Enter the number of fractal layers: ");
    scanf("%d", &layers);
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);
    generate_fractal(layers, size);
    return 0;
}

void generate_fractal(int layers, int size) {
    double x = 0.0, y = 0.0, angle;
    double factor = 2 * PI / 6.0;
    draw_line(x, y, x+size, y);
    x += size;
    for (int i=0; i<6; i++) {
        angle = i * factor;
        x += size * cos(angle);
        y += size * sin(angle);
        draw_line(x, y, x+size, y);
        x += size * cos(angle);
        y += size * sin(angle);
        for (int j=0; j<layers; j++) {
            draw_line(x, y, x+size*pow(3,j), y);
            x += size * pow(3,j) * cos(angle + factor);
            y += size * pow(3,j) * sin(angle + factor);
            draw_line(x, y, x-size*pow(3,j+1), y+size*pow(3,j));
            x -= size * pow(3,j) * cos(angle);
            y -= size * pow(3,j) * sin(angle);
        }
    }
}

void draw_line(double x1, double y1, double x2, double y2) {
    printf("LINE %lf,%lf %lf,%lf\n", x1, y1, x2, y2);
}