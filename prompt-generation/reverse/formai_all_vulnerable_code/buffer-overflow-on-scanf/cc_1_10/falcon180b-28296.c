//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    double theta;
    double v;
    double w;
    Point p;
} Robot;

void move(Robot* r) {
    r->p.x += r->v * cos(r->theta);
    r->p.y += r->v * sin(r->theta);
}

void turn(Robot* r, double dtheta) {
    r->theta += dtheta;
    if (r->theta > 2 * PI) {
        r->theta -= 2 * PI;
    } else if (r->theta < 0) {
        r->theta += 2 * PI;
    }
}

int main() {
    Robot r = {0};
    r.p.x = 0;
    r.p.y = 0;
    r.theta = PI / 4;
    r.v = 1;

    int choice;
    do {
        printf("Enter your choice:\n1. Move forward\n2. Turn left\n3. Turn right\n4. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move(&r);
                break;
            case 2:
                turn(&r, -PI / 4);
                break;
            case 3:
                turn(&r, PI / 4);
                break;
            case 4:
                r.v = 0;
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Current position: (%lf, %lf)\n", r.p.x, r.p.y);
        printf("Current heading: %lf\n", r.theta);
    } while (1);

    return 0;
}