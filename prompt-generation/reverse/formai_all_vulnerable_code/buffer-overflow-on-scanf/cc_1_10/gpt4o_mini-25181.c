//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

void printPoints(Point points[], int count);
void drawLine(Point p1, Point p2);
void drawCircle(Point center, double radius);
double distance(Point p1, Point p2);

int main() {
    Point romeo, juliet;
    Point circle_center;
    double radius;
    int choice;
    
    // Setting the scene
    romeo.x = 2.0; 
    romeo.y = 3.0; // Romeo's position
    juliet.x = 5.0; 
    juliet.y = 7.0; // Juliet's position

    printf("In a world where love flourishes, here lies the tale of:\n");
    printf("Romeo at (%.1f, %.1f) and Juliet at (%.1f, %.1f)\n", romeo.x, romeo.y, juliet.x, juliet.y);
    
    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Draw a line between Romeo and Juliet\n");
        printf("2. Draw a circle around Juliet\n");
        printf("3. Calculate the distance between Romeo and Juliet\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Drawing the line
                drawLine(romeo, juliet);
                break;

            case 2:
                // Drawing circle around Juliet
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                circle_center = juliet; // Centering the circle at Juliet's position
                drawCircle(circle_center, radius);
                break;

            case 3:
                // Calculating the distance
                printf("The distance between Romeo and Juliet is: %.2f\n", distance(romeo, juliet));
                break;

            case 4:
                // Exiting the program
                printf("The tale ends here. Farewell!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Choose again!\n");
        }
    }
    
    return 0;
}

void drawLine(Point p1, Point p2) {
    printf("Drawing a line from (%.1f, %.1f) to (%.1f, %.1f)...\n", p1.x, p1.y, p2.x, p2.y);
    // Here you would have graphical code using a library like SDL or OpenGL
}

void drawCircle(Point center, double radius) {
    printf("Drawing a circle around (%.1f, %.1f) with radius %.2f...\n", center.x, center.y, radius);
    // Here you would have graphical code using a library like SDL or OpenGL
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}