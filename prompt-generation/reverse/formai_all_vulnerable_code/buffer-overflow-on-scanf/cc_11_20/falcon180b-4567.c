//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846

int main() {
    int choice;
    double x1, y1, z1, x2, y2, z2, distance;
    char name[50];

    printf("Welcome to the Love Drone Remote Control!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you are now in control of a love drone.\n", name);
    printf("Use the following commands to navigate:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Move left\n");
    printf("4. Move right\n");
    printf("5. Ascend\n");
    printf("6. Descend\n");
    printf("7. Rotate left\n");
    printf("8. Rotate right\n");
    printf("9. Hover\n");
    printf("10. Return home\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nMoving forward...\n");
                break;
            case 2:
                printf("\nMoving backward...\n");
                break;
            case 3:
                printf("\nMoving left...\n");
                break;
            case 4:
                printf("\nMoving right...\n");
                break;
            case 5:
                printf("\nAscending...\n");
                break;
            case 6:
                printf("\nDescending...\n");
                break;
            case 7:
                printf("\nRotating left...\n");
                break;
            case 8:
                printf("\nRotating right...\n");
                break;
            case 9:
                printf("\nHovering in place...\n");
                break;
            case 10:
                printf("\nReturning home to %s...\n", name);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\nPress enter to continue...\n");
        getchar();
    } while(1);

    return 0;
}