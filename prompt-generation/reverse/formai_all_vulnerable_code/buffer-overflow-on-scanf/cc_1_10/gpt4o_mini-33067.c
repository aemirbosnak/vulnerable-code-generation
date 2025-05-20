//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define NUM_LEDS 8  // Number of LEDs

// Function to turn ON an LED
unsigned char turnOn(unsigned char ledState, int position) {
    return ledState | (1 << position);
}

// Function to turn OFF an LED
unsigned char turnOff(unsigned char ledState, int position) {
    return ledState & ~(1 << position);
}

// Function to toggle an LED
unsigned char toggleLED(unsigned char ledState, int position) {
    return ledState ^ (1 << position);
}

// Function to display the current status of LEDs
void displayLEDs(unsigned char ledState) {
    for (int i = 0; i < NUM_LEDS; i++) {
        if (ledState & (1 << i)) {
            printf("LED %d: ON\n", i);
        } else {
            printf("LED %d: OFF\n", i);
        }
    }
}

// Function to clear the terminal screen
void clearScreen() {
    // ANSI escape code for clear screen
    printf("\033[H\033[J");
}

// Main function
int main() {
    unsigned char ledState = 0;  // LED state variable
    int choice, ledPosition;

    while (1) {
        clearScreen();
        printf("LED Control System\n");
        displayLEDs(ledState);
        
        printf("\n1. Turn ON an LED\n");
        printf("2. Turn OFF an LED\n");
        printf("3. Toggle an LED\n");
        printf("4. Exit\n");
        printf("Choose an operation (1-4): ");
        scanf("%d", &choice);

        // Validate choice
        if (choice < 1 || choice > 4) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        // Exit option
        if (choice == 4) {
            break;
        }

        // Get LED position from user
        printf("Enter LED position (0 to %d): ", NUM_LEDS - 1);
        scanf("%d", &ledPosition);

        // Validate LED position
        if (ledPosition < 0 || ledPosition >= NUM_LEDS) {
            printf("Invalid LED position, please try again.\n");
            continue;
        }

        // Perform chosen operation
        switch (choice) {
            case 1:
                ledState = turnOn(ledState, ledPosition);
                printf("LED %d turned ON.\n", ledPosition);
                break;
            case 2:
                ledState = turnOff(ledState, ledPosition);
                printf("LED %d turned OFF.\n", ledPosition);
                break;
            case 3:
                ledState = toggleLED(ledState, ledPosition);
                printf("LED %d toggled.\n", ledPosition);
                break;
        }

        // Pause for user to see the results
        printf("Press Enter to continue...");
        getchar(); // Consume newline character left in the buffer
        getchar(); // Wait for user input
    }

    printf("Exiting the LED control system. Goodbye!\n");
    return 0;
}