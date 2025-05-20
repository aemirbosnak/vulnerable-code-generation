//FormAI DATASET v1.0 Category: Physics simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

int main() {

    float vel, acc, time, distance;
    int userChoice;
    const float gravity = 9.81;

    printf("======= Physics Calculator =======\n");
    printf("Select a calculation to perform:\n");
    printf("1. Calculate Distance\n");
    printf("2. Calculate Velocity\n");
    printf("3. Calculate Acceleration\n");
    printf("4. Quit\n\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch(userChoice) {
            case 1:
                printf("\nEnter velocity in m/s: ");
                scanf("%f", &vel);
                printf("Enter time in s: ");
                scanf("%f", &time);
                distance = vel * time;
                printf("Distance travelled: %f meters\n\n",distance);
                break;

            case 2:
                printf("\nEnter distance in m: ");
                scanf("%f", &distance);
                printf("Enter time in s: ");
                scanf("%f", &time);
                vel = distance / time;
                printf("Velocity: %f m/s\n\n", vel);
                break;

            case 3:
                printf("\nEnter velocity in m/s: ");
                scanf("%f", &vel);
                printf("Enter time in s: ");
                scanf("%f", &time);
                acc = (vel / time) - gravity;
                printf("Acceleration: %f m/s^2\n\n", acc);
                break;

            case 4:
                printf("\n======= Goodbye! =======\n");
                return 0;

            default:
                printf("\nInvalid choice, please try again.\n\n");
                break;
        }

    } while(userChoice != 4);

    return 0;
}