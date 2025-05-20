//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point on the graph
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate roots of a quadratic equation ax^2 + bx + c = 0
void calculateRoots(double a, double b, double c, double *root1, double *root2, int *numRoots) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        *root2 = (-b - sqrt(discriminant)) / (2 * a);
        *numRoots = 2; // Two distinct roots
    } else if (discriminant == 0) {
        *root1 = *root2 = -b / (2 * a);
        *numRoots = 1; // One root (double root)
    } else {
        *numRoots = 0; // No real roots
    }
}

// Function to evaluate the quadratic function at a given x
double evaluateQuadratic(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

// Function to generate points for the quadratic graph
void generateQuadraticPoints(double a, double b, double c, Point *points, int numPoints) {
    double step = 2.0; // Distance between points
    for (int i = 0; i < numPoints; i++) {
        points[i].x = (i - numPoints / 2) * step; // Center the graph around the origin
        points[i].y = evaluateQuadratic(a, b, c, points[i].x);
    }
}

// Function to print the graph to the console
void printGraph(Point *points, int numPoints, double scale) {
    for (int i = 0; i < numPoints; i++) {
        int yPos = (int)(scale * points[i].y);
        yPos = yPos > 20 ? 20 : (yPos < -20 ? -20 : yPos); // Limit the graph height
        for (int j = -20; j < yPos; j++) {
            printf(" ");
        }
        printf("*\n");
    }
}

// Main function
int main() {
    double a, b, c;
    double root1, root2;
    int numRoots;

    // User input for the coefficients of the quadratic equation
    printf("Welcome to the Quadratic Roots Finder!\n");
    printf("Please enter the coefficients of the quadratic equation (ax^2 + bx + c = 0):\n");
    
    printf("Enter a: ");
    scanf("%lf", &a);
    if (a == 0) {
        printf("Coefficient 'a' cannot be zero for a quadratic equation!\n");
        return 1; // Exit if 'a' is zero
    }

    printf("Enter b: ");
    scanf("%lf", &b);
    
    printf("Enter c: ");
    scanf("%lf", &c);

    // Calculate the roots
    calculateRoots(a, b, c, &root1, &root2, &numRoots);

    // Display the results
    if (numRoots == 2) {
        printf("The roots of the equation are: root1 = %.2lf, root2 = %.2lf\n", root1, root2);
    } else if (numRoots == 1) {
        printf("The equation has one double root: root = %.2lf\n", root1);
    } else {
        printf("The equation has no real roots.\n");
    }

    // Prepare points for the graph
    int numPoints = 41; // Total points on the graph for a range [-20, 20]
    Point *points = (Point *)malloc(numPoints * sizeof(Point));
    if (!points) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generateQuadraticPoints(a, b, c, points, numPoints);

    // Print the quadratic equation graph
    printf("\nGraph of the quadratic function:\n");
    printGraph(points, numPoints, 0.1); // Scale the y-values

    free(points); // Free allocated memory
    return 0;
}