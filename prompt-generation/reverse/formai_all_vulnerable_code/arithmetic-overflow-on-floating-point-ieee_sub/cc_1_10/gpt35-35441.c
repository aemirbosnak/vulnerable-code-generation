//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>

// struct for holding the coordinates of a point
struct Point {
    float x;
    float y;
};

// calculates distance between two points
float calculateDistance(struct Point p1, struct Point p2) {
    float x_diff_squared = (p2.x-p1.x) * (p2.x-p1.x);
    float y_diff_squared = (p2.y-p1.y) * (p2.y-p1.y);
    return sqrt(x_diff_squared + y_diff_squared);
}

// determines whether the point is inside the given circle
int isInsideCircle(struct Point point, struct Point center, float radius) {
    float distance = calculateDistance(point, center);
    return distance <= radius;
}

// determines whether the point is inside the given rectangle
int isInsideRectangle(struct Point point, struct Point corner1, struct Point corner2) {
    return (point.x >= corner1.x && point.x <= corner2.x)
        && (point.y >= corner1.y && point.y <= corner2.y);
}

int main() {
    struct Point point;
    struct Point circle_center;
    float circle_radius;
    struct Point rect_corner1;
    struct Point rect_corner2;

    // read in point
    printf("Enter point coordinates (x,y): ");
    scanf("%f,%f", &point.x, &point.y);

    // read in circle specifications
    printf("Enter circle center (x,y): ");
    scanf("%f,%f", &circle_center.x, &circle_center.y);
    printf("Enter circle radius: ");
    scanf("%f", &circle_radius);

    // read in rectangle specifications
    printf("Enter rectangle upper-left corner (x,y): ");
    scanf("%f,%f", &rect_corner1.x, &rect_corner1.y);
    printf("Enter rectangle lower-right corner (x,y): ");
    scanf("%f,%f", &rect_corner2.x, &rect_corner2.y);

    // check if the point is inside the circle or rectangle
    if (isInsideCircle(point, circle_center, circle_radius)) {
        printf("The point is inside the circle.\n");
    } else {
        printf("The point is not inside the circle.\n");
    }

    if (isInsideRectangle(point, rect_corner1, rect_corner2)) {
        printf("The point is inside the rectangle.\n");
    } else {
        printf("The point is not inside the rectangle.\n");
    }

    return 0;
}