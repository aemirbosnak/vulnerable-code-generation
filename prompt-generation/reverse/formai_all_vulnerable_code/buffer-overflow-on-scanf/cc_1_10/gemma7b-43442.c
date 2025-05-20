//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    system("clear");
    char c;

    printf("Enter a command (help, forward, back, left, right): ");
    scanf("%c", &c);

    switch (c)
    {
        case 'h':
            system("clear");
            printf("C-Robot commands:\n");
            printf("  help: Displays this message.\n");
            printf("  forward: Makes the robot move forward.\n");
            printf("  back: Makes the robot move back.\n");
            printf("  left: Makes the robot move left.\n");
            printf("  right: Makes the robot move right.\n");
            break;
        case 'f':
            system("clear");
            printf("Moving forward...\n");
            sleep(2);
            system("clear");
            printf("Robot is at the front of the room.\n");
            break;
        case 'b':
            system("clear");
            printf("Moving back...\n");
            sleep(2);
            system("clear");
            printf("Robot is at the back of the room.\n");
            break;
        case 'l':
            system("clear");
            printf("Moving left...\n");
            sleep(2);
            system("clear");
            printf("Robot is at the left side of the room.\n");
            break;
        case 'r':
            system("clear");
            printf("Moving right...\n");
            sleep(2);
            system("clear");
            printf("Robot is at the right side of the room.\n");
            break;
        default:
            system("clear");
            printf("Invalid command.\n");
            break;
    }

    return 0;
}