//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FORWARD 'W'
#define BACKWARD 'S'
#define LEFT 'A'
#define RIGHT 'D'
#define QUIT 'Q'

void introduceKnight();
void displayMenu();
void executeCommand(char command);
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void idle();

int main() {
    char command;
    
    introduceKnight();
    displayMenu();
    
    while (1) {
        printf("Enter thy desired command: ");
        scanf(" %c", &command);

        if (command == QUIT) {
            printf("The knight shall return to the castle. Farewell!\n");
            break;
        }

        executeCommand(command);
    }

    return 0;
}

void introduceKnight() {
    printf("A valiant knight of yore emerges from the shadows of the realm.\n");
    printf("He stands ready to obey thy commands, traveling across the land!\n");
    printf("***********************************************\n");
}

void displayMenu() {
    printf("To command the knight, use the following keys:\n");
    printf(" - %c: Move Forward\n", FORWARD);
    printf(" - %c: Move Backward\n", BACKWARD);
    printf(" - %c: Turn Left\n", LEFT);
    printf(" - %c: Turn Right\n", RIGHT);
    printf(" - %c: To bid farewell and end thy journey\n", QUIT);
    printf("***********************************************\n");
}

void executeCommand(char command) {
    switch (command) {
        case FORWARD:
            moveForward();
            break;
        case BACKWARD:
            moveBackward();
            break;
        case LEFT:
            turnLeft();
            break;
        case RIGHT:
            turnRight();
            break;
        default:
            printf("Alas! That command is not recognized by the knight.\n");
            idle();
            break;
    }
}

void moveForward() {
    printf("The knight advances into the unknown, steadfast and brave!\n");
    sleep(1); // Simulate movement delay
}

void moveBackward() {
    printf("The knight retreats, ever prudent and wise in his decisions.\n");
    sleep(1); // Simulate movement delay
}

void turnLeft() {
    printf("The knight turns left, to face new challenges and opportunities!\n");
    sleep(1); // Simulate turning delay
}

void turnRight() {
    printf("The knight pivots to the right, keeping his foes on guard!\n");
    sleep(1); // Simulate turning delay
}

void idle() {
    printf("The knight stands ready for thy next command, awaiting further valor!\n");
    sleep(1); // Simulate idle delay
}