//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int choice;
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double jx, jy, jz;
    double kx, ky, kz;
    double Lx, Ly, Lz;
    double Mx, My, Mz;

    printf("Welcome to the Drone Remote Control!\n");
    printf("Please enter your choice:\n");
    printf("1. Take off\n");
    printf("2. Fly forward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Fly backward\n");
    printf("6. Fly left\n");
    printf("7. Fly right\n");
    printf("8. Land\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Taking off...\n");
            break;
        case 2:
            printf("Flying forward...\n");
            break;
        case 3:
            printf("Turning left...\n");
            break;
        case 4:
            printf("Turning right...\n");
            break;
        case 5:
            printf("Flying backward...\n");
            break;
        case 6:
            printf("Flying left...\n");
            break;
        case 7:
            printf("Flying right...\n");
            break;
        case 8:
            printf("Landing...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}