//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int a;
    int b;
    int c;
} Equation;

void readPoints(Point points[], int n) {
    printf("Enter the coordinates of %d points:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void calculateEquation(Equation equation, Point points[], int n) {
    equation.a = 0;
    equation.b = 0;
    equation.c = 0;

    for (int i = 0; i < n; i++) {
        equation.a += points[i].x;
        equation.b += points[i].y;
        equation.c += points[i].x * points[i].y;
    }

    equation.a /= n;
    equation.b /= n;
    equation.c /= n;
}

void solveEquation(Equation equation, double *x, double *y) {
    *x = -equation.b / (2 * equation.a);
    *y = -equation.c / (2 * equation.a);
}

void printEquation(Equation equation) {
    printf("y = %.2fx + %.2f\n", equation.a, equation.b);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (n > MAX_POINTS) {
        printf("Error: Maximum number of points is %d\n", MAX_POINTS);
        return 1;
    }

    Point points[n];
    readPoints(points, n);

    Equation equation;
    calculateEquation(equation, points, n);

    double x, y;
    solveEquation(equation, &x, &y);

    printf("The equation of the line is:\n");
    printEquation(equation);

    printf("The coordinates of the intersection point are:\n");
    printf("x = %.2f, y = %.2f\n", x, y);

    return 0;
}