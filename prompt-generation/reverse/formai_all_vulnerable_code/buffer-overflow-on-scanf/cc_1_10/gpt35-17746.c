//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random signal strength values between -100 to 0
int generateSignalStrength() {
    return rand() % 101 - 100;
}

// Function to print the retro style signal meter ASCII art
void printSignalMeter(int signalStrength) {
    printf("\n\n\n");

    // Signal full bars
    if (signalStrength >= -50) {
        printf("     /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\ \n");
        printf("    |                          |\n");
        printf("    |    Wi-Fi Signal Strength |\n");
        printf("    |                          |\n");
        printf("     \\                        /\n");
        printf("      \\                      / \n");
        printf("       \\____________________/  \n");
    }
    // Signal 4 bars
    else if (signalStrength >= -70) {
        printf("     /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\ \n");
        printf("    |                          |\n");
        printf("    |    Wi-Fi Signal Strength |\n");
        printf("    |                          |\n");
        printf("     \\                      / \n");
        printf("      \\____________________/  \n");
    }
    // Signal 3 bars
    else if (signalStrength >= -80) {
        printf("     /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/   \n");
        printf("    |                        / \n");
        printf("    |    Wi-Fi Signal Strength \n");
        printf("    |                        \\ \n");
        printf("     \\                      / \n");
        printf("      \\____________________/  \n");
    }
    // Signal 2 bars
    else if (signalStrength >= -90) {
        printf("     /\\/\\/\\/\\/\\/\\/\\/\\/        \n");
        printf("    |                      / \n");
        printf("    |    Wi-Fi Signal Strength \n");
        printf("    |                      / \n");
        printf("     \\                    / \n");
        printf("      \\__________________/  \n");
    }
    // Signal 1 bar
    else if (signalStrength >= -100) {
       printf("      /\\/\\/\\/\\/\\/\\          \n");
       printf("     |                  /  \n");
       printf("     |    Wi-Fi Signal Strength \n");
       printf("     |                  /   \n");
       printf("      \\________________/  \n"); 
    }
    // No signal
    else {
        printf("     /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\ \n");
        printf("    |                          |\n");
        printf("    |      No Wi-Fi Signal     |\n");
        printf("    |                          |\n");
        printf("     \\                      /  \n");
        printf("      \\____________________/   \n");
    }

    printf("\n\n\n");
}

int main() {
    srand(time(0)); // Seed the random number generator

    printf("Welcome to Retro Wi-Fi Signal Strength Analyzer!\n\n");

    while (1) {
        int signalStrength = generateSignalStrength();
        printf("Current Signal Strength: %d dBm\n", signalStrength);
        printSignalMeter(signalStrength);

        char c;
        printf("Press 'q' to quit or any other key to continue: ");
        scanf(" %c", &c);

        if (c == 'q')
            break;

        system("clear"); // Clear the screen
    }

    return 0;
}