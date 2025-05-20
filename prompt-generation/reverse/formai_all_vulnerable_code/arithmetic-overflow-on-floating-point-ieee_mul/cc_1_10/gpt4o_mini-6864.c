//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

typedef struct {
    Point a, b, c;
} Triangle;

// Function prototypes
double area_triangle(Triangle t);
double area_circle(Circle c);
int point_in_circle(Point p, Circle c);
int point_in_triangle(Point p, Triangle t);
void get_point(Point *p);
void get_circle(Circle *c);
void get_triangle(Triangle *t);

int main() {
    int choice;
    do {
        printf("\n=== Geometric Algorithms Adventure ===\n");
        printf("1. Calculate Area of a Circle\n");
        printf("2. Calculate Area of a Triangle\n");
        printf("3. Check Point in Circle\n");
        printf("4. Check Point in Triangle\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Circle c;
                get_circle(&c);
                printf("Area of Circle: %.2f\n", area_circle(c));
                break;
            }
            case 2: {
                Triangle t;
                get_triangle(&t);
                printf("Area of Triangle: %.2f\n", area_triangle(t));
                break;
            }
            case 3: {
                Circle c;
                get_circle(&c);
                Point p;
                get_point(&p);
                if (point_in_circle(p, c)) {
                    printf("The point (%.2f, %.2f) is inside the circle.\n", p.x, p.y);
                } else {
                    printf("The point (%.2f, %.2f) is outside the circle.\n", p.x, p.y);
                }
                break;
            }
            case 4: {
                Triangle t;
                get_triangle(&t);
                Point p;
                get_point(&p);
                if (point_in_triangle(p, t)) {
                    printf("The point (%.2f, %.2f) is inside the triangle.\n", p.x, p.y);
                } else {
                    printf("The point (%.2f, %.2f) is outside the triangle.\n", p.x, p.y);
                }
                break;
            }
            case 0:
                printf("Exiting the adventure. Farewell!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void get_point(Point *p) {
    printf("Enter point coordinates (x y): ");
    scanf("%lf %lf", &p->x, &p->y);
}

void get_circle(Circle *c) {
    printf("Enter circle center coordinates (x y) and radius: ");
    scanf("%lf %lf %lf", &c->center.x, &c->center.y, &c->radius);
}

void get_triangle(Triangle *t) {
    printf("Enter triangle vertices coordinates (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &t->a.x, &t->a.y, &t->b.x, &t->b.y, &t->c.x, &t->c.y);
}

double area_triangle(Triangle t) {
    return fabs((t.a.x * (t.b.y - t.c.y) + t.b.x * (t.c.y - t.a.y) + t.c.x * (t.a.y - t.b.y)) / 2.0);
}

double area_circle(Circle c) {
    return PI * c.radius * c.radius;
}

int point_in_circle(Point p, Circle c) {
    double distance_squared = (p.x - c.center.x) * (p.x - c.center.x) + 
                              (p.y - c.center.y) * (p.y - c.center.y);
    return distance_squared <= (c.radius * c.radius);
}

int point_in_triangle(Point p, Triangle t) {
    double A = area_triangle(t);
    double A1 = area_triangle((Triangle){p, t.a, t.b});
    double A2 = area_triangle((Triangle){p, t.b, t.c});
    double A3 = area_triangle((Triangle){p, t.c, t.a});
    return (A == A1 + A2 + A3);
}