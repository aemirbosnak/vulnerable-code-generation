//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_TURN 100
#define MIN_TURN 0
#define MAX_ACCEL 100
#define MIN_ACCEL 0

void drive(int speed, int turn, int accel) {
    printf("Driving at %d speed with %d turn and %d acceleration.\n", speed, turn, accel);
}

int main() {
    int speed = 0;
    int turn = 0;
    int accel = 0;
    int choice;

    srand(time(NULL));

    while(1) {
        printf("Enter your choice:\n1. Increase speed\n2. Decrease speed\n3. Increase turn\n4. Decrease turn\n5. Increase acceleration\n6. Decrease acceleration\n7. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                speed += rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
                printf("Speed increased to %d.\n", speed);
                break;
            case 2:
                speed -= rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
                printf("Speed decreased to %d.\n", speed);
                break;
            case 3:
                turn += rand() % (MAX_TURN - MIN_TURN) + MIN_TURN;
                printf("Turn increased to %d.\n", turn);
                break;
            case 4:
                turn -= rand() % (MAX_TURN - MIN_TURN) + MIN_TURN;
                printf("Turn decreased to %d.\n", turn);
                break;
            case 5:
                accel += rand() % (MAX_ACCEL - MIN_ACCEL) + MIN_ACCEL;
                printf("Acceleration increased to %d.\n", accel);
                break;
            case 6:
                accel -= rand() % (MAX_ACCEL - MIN_ACCEL) + MIN_ACCEL;
                printf("Acceleration decreased to %d.\n", accel);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        drive(speed, turn, accel);
    }

    return 0;
}