//FormAI DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>

// declare global variables
int bodySize = 2;
int legLength = 4;
int armLength = 3;

// define functions
void shrink() {
    if (bodySize > 1) {
        bodySize--;
        legLength--;
        armLength--;
        printf("Shrinking robot...\n");
    }
}

void grow() {
    bodySize++;
    legLength++;
    armLength++;
    printf("Growing robot...\n");
}

void moveForward() {
    printf("Moving %d steps forward...\n", legLength);
}

void moveBackward() {
    printf("Moving %d steps backward...\n", legLength);
}

void wave() {
    printf("Waving arms...\n");
}

int main() {
    // initial message
    printf("Starting shape-shifting robot control program...\n");

    // set up loop
    char input = ' ';
    while (input != 'q') {
        printf("\n");
        printf("Current body size: %d\n", bodySize);
        printf("Current leg length: %d\n", legLength);
        printf("Current arm length: %d\n", armLength);
        printf("\n");

        // user input
        printf("Enter command: (g)row, (s)hrink, (f)orward, (b)ackward, (w)ave, (q)uit\n");
        scanf(" %c", &input);

        // execute command
        switch (input) {
            case 'g':
                grow();
                break;
            case 's':
                shrink();
                break;
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
            case 'w':
                wave();
                break;
            case 'q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}