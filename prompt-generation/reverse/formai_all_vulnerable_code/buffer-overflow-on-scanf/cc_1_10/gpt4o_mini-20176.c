//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the area of a polygon using the Shoelace theorem
double polygonArea(Point* points, int numPoints) {
    double area = 0.0;
    for (int i = 0; i < numPoints; i++) {
        int nextIndex = (i + 1) % numPoints;
        area += (points[i].x * points[nextIndex].y) - (points[nextIndex].x * points[i].y);
    }
    return fabs(area) / 2.0;
}

// Function to draw the polygon in ASCII art
void drawPolygon(Point* points, int numPoints) {
    int width = 20, height = 20;
    char grid[21][41];  // 20x20 grid plus borders

    // Initialize the grid
    for (int i = 0; i < height + 1; i++) {
        for (int j = 0; j < width * 2 + 1; j++) {
            grid[i][j] = ' ';
        }
    }

    // Draw the edges of the polygon
    for (int i = 0; i < numPoints; i++) {
        int x1 = (int)(points[i].x * (width / 10.0)) + width;    // Scale and offset
        int y1 = (int)(points[i].y * (height / 10.0)) + height;  // Scale and offset
        int x2 = (int)(points[(i + 1) % numPoints].x * (width / 10.0)) + width;
        int y2 = (int)(points[(i + 1) % numPoints].y * (height / 10.0)) + height;

        // Draw a line between two points
        while (!(x1 == x2 && y1 == y2)) {
            if (x1 >= 0 && x1 < width * 2 && y1 >= 0 && y1 < height) {
                grid[y1][x1] = '*';
            }
            if (x1 < x2) x1++;
            else if (x1 > x2) x1--;
            if (y1 < y2) y1++;
            else if (y1 > y2) y1--;
        }
    }

    // Print the grid
    for (int i = 0; i < height + 1; i++) {
        for (int j = 0; j < width * 2 + 1; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int numPoints;

    printf("Enter the number of vertices for the polygon (3 or more): ");
    scanf("%d", &numPoints);

    if (numPoints < 3) {
        printf("A polygon must have at least 3 vertices!\n");
        return 1;
    }

    Point* points = (Point*)malloc(numPoints * sizeof(Point));

    printf("Enter the coordinates of the vertices:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("Vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double area = polygonArea(points, numPoints);
    printf("The area of the polygon is: %.2f\n", area);

    printf("\nVisual Representation of the Polygon:\n\n");
    drawPolygon(points, numPoints);

    free(points);
    return 0;
}