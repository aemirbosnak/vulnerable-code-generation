//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y, z;
} point3D;

void print_menu() {
    printf("\n--- 3D Point Distance Calculator ---\n");
    printf("1. Input Point 1 coordinates\n");
    printf("2. Input Point 2 coordinates\n");
    printf("3. Calculate Distance\n");
    printf("4. Exit\n");
}

void input_point(point3D* p) {
    printf("Enter x coordinate: ");
    scanf("%lf", &p->x);
    printf("Enter y coordinate: ");
    scanf("%lf", &p->y);
    printf("Enter z coordinate: ");
    scanf("%lf", &p->z);
}

double euclidean_distance(point3D p1, point3D p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    point3D p1, p2;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Point 1:\n");
                input_point(&p1);
                break;
            case 2:
                printf("Point 2:\n");
                input_point(&p2);
                break;
            case 3:
                if (p1.x == 0 && p1.y == 0 && p1.z == 0 &&
                    p2.x == 0 && p2.y == 0 && p2.z == 0) {
                    printf("Error: Both points are at the origin.\n");
                    continue;
                }
                double distance = euclidean_distance(p1, p2);
                printf("The distance between Point 1 and Point 2 is: %.2lf\n", distance);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}