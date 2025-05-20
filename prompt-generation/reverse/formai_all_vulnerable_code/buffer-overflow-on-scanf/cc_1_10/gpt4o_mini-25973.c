//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

#define TOTAL_LEDS 8

void displayLEDs(int state) {
    printf("LED State: ");
    for (int i = TOTAL_LEDS - 1; i >= 0; i--) {
        if (state & (1 << i)) {
            printf("1 "); // LED is ON
        } else {
            printf("0 "); // LED is OFF
        }
    }
    printf("\n");
}

int main() {
    int ledState = 0b00000000; // All LEDs initially OFF
    int command;
    
    printf("Welcome to the LED Control Program!\n");
    printf("Commands:\n");
    printf("1. Turn ON LED X (1-8)\n");
    printf("2. Turn OFF LED X (1-8)\n");
    printf("3. Toggle LED X (1-8)\n");
    printf("4. Show current LED state\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter command: ");
        scanf("%d", &command);
        
        if(command == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        int ledNumber;
        switch (command) {
            case 1:
                printf("Enter LED number to turn ON (1-8): ");
                scanf("%d", &ledNumber);
                if (ledNumber < 1 || ledNumber > TOTAL_LEDS) {
                    printf("Invalid LED number!\n");
                    continue;
                }
                ledState |= (1 << (ledNumber - 1)); // Set bit to 1
                break;
                
            case 2:
                printf("Enter LED number to turn OFF (1-8): ");
                scanf("%d", &ledNumber);
                if (ledNumber < 1 || ledNumber > TOTAL_LEDS) {
                    printf("Invalid LED number!\n");
                    continue;
                }
                ledState &= ~(1 << (ledNumber - 1)); // Set bit to 0
                break;

            case 3:
                printf("Enter LED number to toggle (1-8): ");
                scanf("%d", &ledNumber);
                if (ledNumber < 1 || ledNumber > TOTAL_LEDS) {
                    printf("Invalid LED number!\n");
                    continue;
                }
                ledState ^= (1 << (ledNumber - 1)); // Toggle the bit
                break;

            case 4:
                displayLEDs(ledState);
                break;

            default:
                printf("Unknown command! Please try again.\n");
        }
    }

    return 0;
}