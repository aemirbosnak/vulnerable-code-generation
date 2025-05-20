//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between a and b
int randomNumber(int a, int b) {
    return rand() % (b-a+1) + a;
}

int main() {
    srand(time(NULL));
    int speed = 0, direction = 0, x = 0, y = 0;
    char input;

    printf("Welcome to the Future Remote Control Vehicle Simulator!\n\n");

    // Main Loop
    while (1) {
        printf("Enter a command (w/a/s/d): ");
        scanf("%c", &input);

        // Move Up
        if (input == 'w') {
            speed = randomNumber(1, 10);
            direction = 90;
            x += speed;
            printf("Moving Up at %d mph\n", speed);
        }
        // Move Left
        else if (input == 'a') {
            speed = randomNumber(1, 8);
            direction = 180;
            y -= speed;
            printf("Moving Left at %d mph\n", speed);
        }
        // Move Down
        else if (input == 's') {
            speed = randomNumber(1, 10);
            direction = 270;
            x -= speed;
            printf("Moving Down at %d mph\n", speed);
        }
        // Move Right
        else if (input == 'd') {
            speed = randomNumber(1, 8);
            direction = 0;
            y += speed;
            printf("Moving Right at %d mph\n", speed);
        }

        printf("New Position: (%d, %d), Direction: %d\n\n", x, y, direction);

        // Check if out of bounds
        if (x < -1000 || x > 1000 || y < -1000 || y > 1000) {
            printf("Out of Bounds! Vehicle has crashed!\n");
            break;
        }

        // Flush input buffer
        while ((getchar()) != '\n');
    }

    printf("\nProgram Terminating.\n");

    return 0;
}