//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: funny
#include <stdio.h>
#include <unistd.h>

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define STOP 'S'

void moveRobot(char direction) {
    switch (direction) {
        case FORWARD:
            printf("🚀 ZOOM! The robot moves forward like it's late for a date!\n");
            break;
        case BACKWARD:
            printf("🔙 Whoa! Backing it up like a toddler with a full diaper!\n");
            break;
        case LEFT:
            printf("⬅️ Turning left like it's about to get hit by a rain cloud!\n");
            break;
        case RIGHT:
            printf("➡️ Turning right as if trying to dodge an awkward conversation!\n");
            break;
        case STOP:
            printf("🛑 Engaging the brakes like a snail on a coffee break!\n");
            break;
        default:
            printf("🤔 Hmm... The robot is confused! It does not compute!\n");
    }
}

void robotDanceParty() {
    printf("🎉 Welcome to the Robot Dance Party! 🕺💃\n");
    printf("☝️ Choose a direction: F (forward), B (backward), L (left), R (right), S (stop), Q (quit)\n");

    char input;
    while (1) {
        printf("💃 Input your command: ");
        scanf(" %c", &input);
        input = toupper(input); // Make it user-friendly for lazy fingers!

        if (input == 'Q') {
            printf("👋 Thanks for partying with me! Remember to robot dance everywhere you go!\n");
            break;
        }

        moveRobot(input);
        printf("🌀 Rotating sensor like it's taking a selfie after every move!\n");
        sleep(1); // Simulate a cool down time like it's catching its breath up!
    }
}

int main() {
    printf("🤖 Welcome to the Crazy Robot Movement Control! 🤖\n");
    robotDanceParty();
    return 0;
}