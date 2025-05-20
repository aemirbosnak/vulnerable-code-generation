//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the robot's initial position and direction
typedef struct {
    int x;
    int y;
    char direction[10];
} Robot;

// Function declarations
void initializeRobot(Robot *bot);
void displayPosition(Robot *bot);
void moveForward(Robot *bot);
void moveBackward(Robot *bot);
void turnLeft(Robot *bot);
void turnRight(Robot *bot);
void printLine(char ch, int length);

int main() {
    Robot myRobot;
    initializeRobot(&myRobot);
    
    char command[10];
    int shouldExit = 0;

    printf("🎉 Welcome to the Joyful Robot Movement Control! 🎉\n\n");

    while (!shouldExit) {
        displayPosition(&myRobot);
        printf("What a beautiful day! How would you like to move the robot? (forward/backward/left/right/exit): ");
        scanf("%s", command);

        // Command handling
        if (strcmp(command, "forward") == 0) {
            moveForward(&myRobot);
        } else if (strcmp(command, "backward") == 0) {
            moveBackward(&myRobot);
        } else if (strcmp(command, "left") == 0) {
            turnLeft(&myRobot);
        } else if (strcmp(command, "right") == 0) {
            turnRight(&myRobot);
        } else if (strcmp(command, "exit") == 0) {
            shouldExit = 1;
            printf("🤖 Goodbye, friend! Until next time! 🌈\n");
        } else {
            printf("Oops! I didn't understand that. Please try 'forward', 'backward', 'left', 'right', or 'exit'.\n");
        }
        
        printLine('=', 30);
    }

    return 0;
}

// Initialize the robot's starting position
void initializeRobot(Robot *bot) {
    bot->x = 0; // Starting x coordinate
    bot->y = 0; // Starting y coordinate
    strcpy(bot->direction, "North"); // Initial facing direction
    printf("🤖 Robot initialized at position (%d, %d) facing %s.\n", bot->x, bot->y, bot->direction);
}

// Display the current position of the robot
void displayPosition(Robot *bot) {
    printf("\nCurrent Position: (%d, %d), Facing: %s\n", bot->x, bot->y, bot->direction);
}

// Move the robot forward based on its current direction
void moveForward(Robot *bot) {
    if (strcmp(bot->direction, "North") == 0) {
        bot->y += 1;
    } else if (strcmp(bot->direction, "South") == 0) {
        bot->y -= 1;
    } else if (strcmp(bot->direction, "East") == 0) {
        bot->x += 1;
    } else if (strcmp(bot->direction, "West") == 0) {
        bot->x -= 1;
    }
    printf("🚀 The robot moved forward! Now at (%d, %d) facing %s.\n", bot->x, bot->y, bot->direction);
}

// Move the robot backward based on its current direction
void moveBackward(Robot *bot) {
    if (strcmp(bot->direction, "North") == 0) {
        bot->y -= 1;
    } else if (strcmp(bot->direction, "South") == 0) {
        bot->y += 1;
    } else if (strcmp(bot->direction, "East") == 0) {
        bot->x -= 1;
    } else if (strcmp(bot->direction, "West") == 0) {
        bot->x += 1;
    }
    printf("🔙 The robot moved backward! Now at (%d, %d) facing %s.\n", bot->x, bot->y, bot->direction);
}

// Turn the robot left
void turnLeft(Robot *bot) {
    if (strcmp(bot->direction, "North") == 0) {
        strcpy(bot->direction, "West");
    } else if (strcmp(bot->direction, "West") == 0) {
        strcpy(bot->direction, "South");
    } else if (strcmp(bot->direction, "South") == 0) {
        strcpy(bot->direction, "East");
    } else if (strcmp(bot->direction, "East") == 0) {
        strcpy(bot->direction, "North");
    }
    printf("↪️ The robot turned left! Now facing %s.\n", bot->direction);
}

// Turn the robot right
void turnRight(Robot *bot) {
    if (strcmp(bot->direction, "North") == 0) {
        strcpy(bot->direction, "East");
    } else if (strcmp(bot->direction, "East") == 0) {
        strcpy(bot->direction, "South");
    } else if (strcmp(bot->direction, "South") == 0) {
        strcpy(bot->direction, "West");
    } else if (strcmp(bot->direction, "West") == 0) {
        strcpy(bot->direction, "North");
    }
    printf("↩️ The robot turned right! Now facing %s.\n", bot->direction);
}

// Function to print a decorative line
void printLine(char ch, int length) {
    for (int i = 0; i < length; i++) {
        putchar(ch);
    }
    putchar('\n');
}