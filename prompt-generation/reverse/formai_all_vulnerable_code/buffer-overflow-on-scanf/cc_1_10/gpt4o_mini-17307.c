//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

double calculateArea(Point* vertices, int n) {
    double area = 0.0;

    for (int i = 0; i < n; i++) {
        area += (vertices[i].x * vertices[(i + 1) % n].y) - (vertices[(i + 1) % n].x * vertices[i].y);
    }
    return 0.5 * fabs(area);
}

void inputVertices(Point* vertices, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates for vertex %d (x y): ", i + 1);
        while (scanf("%lf %lf", &vertices[i].x, &vertices[i].y) != 2) {
            printf("Invalid input. Please enter two numbers (x y): ");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
}

void displayVertices(Point* vertices, int n) {
    printf("The vertices of the polygon are:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: (%.2lf, %.2lf)\n", i + 1, vertices[i].x, vertices[i].y);
    }
}

int main() {
    int n;

    printf("Enter the number of vertices in the polygon (minimum 3): ");
    while (scanf("%d", &n) != 1 || n < 3) {
        printf("Invalid input. Please enter an integer greater than or equal to 3: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    Point* vertices = (Point*)malloc(n * sizeof(Point));
    if (vertices == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    inputVertices(vertices, n);
    displayVertices(vertices, n);

    double area = calculateArea(vertices, n);
    printf("The area of the polygon is: %.2lf\n", area);

    free(vertices);
    return EXIT_SUCCESS;
}