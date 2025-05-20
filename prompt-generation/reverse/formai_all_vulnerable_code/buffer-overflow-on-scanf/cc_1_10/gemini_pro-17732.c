//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Happy Drone Control Function
void flyHappy(int speed, char direction) {
    printf("Zooming through the sky at %d mph, %c-ward!\n", speed, direction);
}

// Excited Drone Control Function
void spinExcited(int rotations) {
    printf("Twirling and swirling in the air, %d times around!\n", rotations);
}

// Content Drone Control Function
void hoverCalmly(int altitude) {
    printf("Floating peacefully at %d feet, just chillin'.\n", altitude);
}

// Playful Drone Control Function
void dancePlayfully(char sequence[]) {
    printf("Busting out some moves in the sky: %s\n", sequence);
}

int main() {
    // Welcome the user
    printf("Welcome to the Drone Remote Control! Get ready for some aerial adventures!\n");

    // Set the initial speed and direction
    int speed = 50;
    char direction = 'N';

    // Get user input
    while (1) {
        printf("Enter a command (fly, spin, hover, dance, exit): ");
        char command[10];
        scanf("%s", command);

        // Execute the command
        switch (command[0]) {
            case 'f': // Fly
                printf("Enter speed and direction (N/E/S/W): ");
                scanf("%d %c", &speed, &direction);
                flyHappy(speed, direction);
                break;
            case 's': // Spin
                printf("Enter number of rotations: ");
                int rotations;
                scanf("%d", &rotations);
                spinExcited(rotations);
                break;
            case 'h': // Hover
                printf("Enter altitude: ");
                int altitude;
                scanf("%d", &altitude);
                hoverCalmly(altitude);
                break;
            case 'd': // Dance
                printf("Enter dance sequence (e.g. LRUD): ");
                char sequence[10];
                scanf("%s", sequence);
                dancePlayfully(sequence);
                break;
            case 'e': // Exit
                printf("Thanks for flying! See you next time!\n");
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}