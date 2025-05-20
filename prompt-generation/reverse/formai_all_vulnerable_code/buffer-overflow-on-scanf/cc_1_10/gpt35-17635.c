//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate a random internet speed in Mbps
float generateSpeed() {
    float speed = 0;
    int random = rand() % 3;
    switch (random) {
        case 0: speed = rand() % 5 + 5; break;
        case 1: speed = rand() % 30 + 5; break;
        case 2: speed = rand() % 90 + 10; break;
    }
    return speed;
}

// Function to convert Mbps to KBps
float convertToKBps(float speed) {
    return speed * 125;
}

// Function to display the results to the user
void displayResults(float speed) {
    printf("Your internet speed is: %.2f Mbps\n", speed);
    printf("That is equivalent to: %.2f KB/s\n", convertToKBps(speed));
}

// Main function
int main() {
    bool testAgain = true;
    char answer = ' ';
    srand(time(0)); // Set random seed

    printf("Welcome to the Internet Speed Test Application!\n");

    while (testAgain) {
        // Generate speed and display results
        displayResults(generateSpeed());

        // Ask user if they want to test again
        while (answer != 'y' && answer != 'n') {
            printf("Do you want to test again? (y/n): ");
            scanf(" %c", &answer);
        }

        // Check user's answer
        if (answer == 'y') {
            testAgain = true;
        } else {
            testAgain = false;
        }
        answer = ' ';
    }
    printf("Thank you for using the Internet Speed Test Application!\n");

    return 0;
}