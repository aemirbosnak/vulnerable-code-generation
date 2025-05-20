//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Vector;

void move(double speed, double turn) {
    Vector v = {speed * cos(turn), speed * sin(turn)};
    printf("Moving at %.2f degrees with a speed of %.2f units per second.\n", turn, speed);
    printf("Current position: (%.2f, %.2f)\n", v.x, v.y);
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Move backward\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move(5.0, 0.0);
                break;
            case 2:
                move(5.0, rand() % 360);
                break;
            case 3:
                move(5.0, (rand() % 360) + 180);
                break;
            case 4:
                move(-5.0, 0.0);
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    } while (1);

    return 0;
}