//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>

#define MAX_SPEED 100
#define MAX_ANGLE 180

int main() {
    int speed = 0;
    int droneAngle = 0;
    int remoteAngle = 0;
    char input;

    printf("Welcome to the C Drone Remote Control Program\n\n");

    do {
        printf("Current speed: %d\n", speed);
        printf("Current drone angle: %d\n", droneAngle);

        printf("\nChoose an option:\n");
        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Quit\n\n");

        printf("Enter your selection: ");
        scanf("%c", &input);
        printf("\n");

        switch(input) {
            case '1':
                if(speed < MAX_SPEED) {
                    speed += 10;
                    printf("Speed increased to %d\n", speed);
                } else {
                    printf("Cannot increase speed past maximum\n");
                }
                break;
            case '2':
                if(speed > 0) {
                    speed -= 10;
                    printf("Speed decreased to %d\n", speed);
                } else {
                    printf("Cannot decrease speed past minimum\n");
                }
                break;
            case '3':
                printf("Enter turn angle (-180 to 0): ");
                scanf("%d", &remoteAngle);

                if(remoteAngle < -MAX_ANGLE || remoteAngle > 0) {
                    printf("Invalid angle entered\n");
                } else {
                    droneAngle += remoteAngle;
                    printf("Turning left %d degrees, drone angle now %d\n", remoteAngle, droneAngle);
                }
                break;
            case '4':
                printf("Enter turn angle (0 to 180): ");
                scanf("%d", &remoteAngle);

                if(remoteAngle < 0 || remoteAngle > MAX_ANGLE) {
                    printf("Invalid angle entered\n");
                } else {
                    droneAngle += remoteAngle;
                    printf("Turning right %d degrees, drone angle now %d\n", remoteAngle, droneAngle);
                }
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid selection\n");
        }

        printf("\n");

    } while (input != '5');

    return 0;
}