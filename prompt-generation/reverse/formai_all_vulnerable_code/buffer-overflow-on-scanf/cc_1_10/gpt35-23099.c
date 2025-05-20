//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>

//Function prototypes
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
void increaseSpeed();
void decreaseSpeed();
void takeOff();
void land();
void emergencyStop();

int main() {
    int speed = 0;
    int altitude = 0;
    int x = 0;
    int y = 0;

    while(1) {
        //Prompt the user to choose an action
        printf("What would you like to do?\n");
        printf("Press u to move up\n");
        printf("Press d to move down\n");
        printf("Press l to move left\n");
        printf("Press r to move right\n");
        printf("Press + to increase speed\n");
        printf("Press - to decrease speed\n");
        printf("Press t to take off\n");
        printf("Press s to land\n");
        printf("Press e for emergency stop\n");

        //Get the user's choice
        char choice;
        scanf("%c", &choice);

        //Perform the chosen action
        switch(choice) {
            case 'u':
                moveUp(&altitude);
                printf("Altitude is now %d meters\n", altitude);
                break;
            case 'd':
                moveDown(&altitude);
                printf("Altitude is now %d meters\n", altitude);
                break;
            case 'l':
                moveLeft(&x);
                printf("Position is now (%d, %d)\n", x, y);
                break;
            case 'r':
                moveRight(&x);
                printf("Position is now (%d, %d)\n", x, y);
                break;
            case '+':
                increaseSpeed(&speed);
                printf("Speed is now %d km/h\n", speed);
                break;
            case '-':
                decreaseSpeed(&speed);
                printf("Speed is now %d km/h\n", speed);
                break;
            case 't':
                takeOff(&altitude);
                printf("The drone is now taking off\n");
                break;
            case 's':
                land(&altitude);
                printf("The drone is now landing\n");
                break;
            case 'e':
                emergencyStop(&altitude, &speed);
                printf("The drone has been stopped\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        //Flush the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    return 0;
}

void moveUp(int *altitude) {
    (*altitude)++;
}

void moveDown(int *altitude) {
    (*altitude)--;
}

void moveLeft(int *x) {
    (*x)--;
}

void moveRight(int *x) {
    (*x)++;
}

void increaseSpeed(int *speed) {
    (*speed)++;
}

void decreaseSpeed(int *speed) {
    (*speed)--;
}

void takeOff(int *altitude) {
    (*altitude) = 10;
}

void land(int *altitude) {
    (*altitude) = 0;
}

void emergencyStop(int *altitude, int *speed) {
    (*altitude) = 0;
    (*speed) = 0;
}