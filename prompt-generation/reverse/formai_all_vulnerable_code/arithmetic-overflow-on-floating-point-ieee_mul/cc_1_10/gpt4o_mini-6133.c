//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <math.h>

#define MAX_VERTICES 100

typedef struct {
    double x;
    double y;
} Point;

double triangleArea(double base, double height) {
    return 0.5 * base * height;
}

double rectangleArea(double width, double height) {
    return width * height;
}

double circleArea(double radius) {
    return M_PI * radius * radius;
}

int isPointInPolygon(Point polygon[], int n, Point testPoint) {
    int i, j, inside = 0;

    for (i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > testPoint.y) != (polygon[j].y > testPoint.y)) &&
            (testPoint.x < (polygon[j].x - polygon[i].x) * (testPoint.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

void displayMenu() {
    printf("\nGeometric Area and Point-in-Polygon Checker\n");
    printf("1. Area of Triangle\n");
    printf("2. Area of Rectangle\n");
    printf("3. Area of Circle\n");
    printf("4. Check Point inside Polygon\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    int choice;
    double base, height, width, radius;
    Point polygon[MAX_VERTICES];
    int numVertices, i;
    Point testPoint;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter base and height of the triangle:\n");
                scanf("%lf %lf", &base, &height);
                printf("Area of Triangle: %.2lf\n", triangleArea(base, height));
                break;
            case 2:
                printf("Enter width and height of the rectangle:\n");
                scanf("%lf %lf", &width, &height);
                printf("Area of Rectangle: %.2lf\n", rectangleArea(width, height));
                break;
            case 3:
                printf("Enter radius of the circle:\n");
                scanf("%lf", &radius);
                printf("Area of Circle: %.2lf\n", circleArea(radius));
                break;
            case 4:
                printf("Enter number of vertices in the polygon: ");
                scanf("%d", &numVertices);
                if (numVertices > MAX_VERTICES) {
                    printf("Maximum number of vertices exceeded!\n");
                    break;
                }
                printf("Enter the vertices (x y) of the polygon:\n");
                for (i = 0; i < numVertices; i++) {
                    printf("Vertex %d: ", i + 1);
                    scanf("%lf %lf", &polygon[i].x, &polygon[i].y);
                }
                printf("Enter point to check (x y): ");
                scanf("%lf %lf", &testPoint.x, &testPoint.y);
                if (isPointInPolygon(polygon, numVertices, testPoint)) {
                    printf("The point (%.2lf, %.2lf) is inside the polygon.\n", testPoint.x, testPoint.y);
                } else {
                    printf("The point (%.2lf, %.2lf) is outside the polygon.\n", testPoint.x, testPoint.y);
                }
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}