//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int choice;
    double x, y, theta, v, w;
    double l, r;

    printf("Enter robot initial position (x y theta): ");
    scanf("%lf %lf %lf", &x, &y, &theta);

    printf("Enter robot initial linear velocity v: ");
    scanf("%lf", &v);

    printf("Enter robot initial angular velocity w: ");
    scanf("%lf", &w);

    printf("Enter left wheel radius: ");
    scanf("%lf", &l);

    printf("Enter right wheel radius: ");
    scanf("%lf", &r);

    while(1) {
        printf("\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Rotate left\n");
        printf("5. Rotate right\n");
        printf("6. Stop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                v += 0.1;
                break;
            case 2:
                w -= 0.1;
                break;
            case 3:
                w += 0.1;
                break;
            case 4:
                theta -= 0.1;
                break;
            case 5:
                theta += 0.1;
                break;
            case 6:
                v = 0;
                w = 0;
                break;
            default:
                printf("Invalid choice\n");
        }

        x += v*cos(theta);
        y += v*sin(theta);
        theta += w;

        printf("Current position (x y theta): (%lf, %lf, %lf)\n", x, y, theta);
        printf("Current linear velocity v: %lf\n", v);
        printf("Current angular velocity w: %lf\n", w);

        if(fabs(v) < 0.01 && fabs(w) < 0.01) {
            printf("Robot stopped\n");
            break;
        }
    }

    return 0;
}