//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>

int main() {
    char command;
    int height = 0, speed = 0, direction = 0;
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Here are some commands you can use:\n");
    printf("r: turn right\n");
    printf("l: turn left\n");
    printf("u: move up\n");
    printf("d: move down\n");
    printf("f: increase speed\n");
    printf("s: decrease speed\n");
    printf("q: quit program\n");

    // Loop until user quits program
    while (command != 'q') {
        printf("Enter command: ");
        scanf(" %c", &command);
        switch (command) {
            case 'r':
                direction += 90;
                printf("Turning right...\n");
                break;
            case 'l':
                direction -= 90;
                printf("Turning left...\n");
                break;
            case 'u':
                height += 10;
                printf("Moving up...\n");
                break;
            case 'd':
                height -= 10;
                printf("Moving down...\n");
                break;
            case 'f':
                speed += 1;
                printf("Increasing speed...\n");
                break;
            case 's':
                speed -= 1;
                printf("Decreasing speed...\n");
                break;
            case 'q':
                printf("Quitting program...\n");
                break;
            default:
                printf("Unknown command. Please try again.\n");
        }
        // Print current status of drone
        printf("Current height: %d\n", height);
        printf("Current speed: %d\n", speed);
        printf("Current direction: %d degrees\n", direction);
    }
    return 0;
}