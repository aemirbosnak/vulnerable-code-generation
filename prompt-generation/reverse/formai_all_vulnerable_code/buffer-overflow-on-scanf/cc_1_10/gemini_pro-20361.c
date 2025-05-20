//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: imaginative
// Embark on a whimsical journey into the realm of C, where your imagination will ignite and your smart home will come alive!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the enchanting abode
typedef struct SmartHome {
    bool lightsOn;
    int temperature;
    int humidity;
    bool doorLocked;
    bool motionDetected;
} SmartHome;

// Greet the user with a dash of whimsy
void greetUser() {
    printf("Greetings, Master of the Enchanted Abode! Welcome to your smart home adventure.\n");
}

// Toggle the lights with a flick of the wrist
void toggleLights(SmartHome* home) {
    home->lightsOn = !home->lightsOn;
    printf(home->lightsOn ? "The lights dance to life, illuminating your abode.\n" : "The lights fade into slumber, leaving you in a cozy twilight.\n");
}

// Adjust the temperature to your liking
void adjustTemperature(SmartHome* home) {
    int newTemperature;
    printf("Speak the magic word for your desired temperature, Master: ");
    scanf("%d", &newTemperature);
    home->temperature = newTemperature;
    printf("The temperature shifts to %d degrees, enveloping you in comfort.\n", home->temperature);
}

// Monitor humidity levels with a watchful eye
void checkHumidity(SmartHome* home) {
    int currentHumidity = rand() % 100;
    home->humidity = currentHumidity;
    printf("The air whispers its humidity at %d percent, creating an enchanting atmosphere.\n", home->humidity);
}

// Secure your realm from intruders
void lockUnlockDoor(SmartHome* home) {
    char command;
    printf("To lock your abode, enter 'L'. To unlock its embrace, enter 'U': ");
    scanf(" %c", &command);
    home->doorLocked = (command == 'L');
    printf(home->doorLocked ? "The door stands firm, guarding your sanctuary.\n" : "The door beckons you, welcoming you home.\n");
}

// Detect motion with the sensitivity of a whisper
void checkMotion(SmartHome* home) {
    home->motionDetected = (rand() % 2);
    printf(home->motionDetected ? "A faint shimmer in the shadows... Motion detected!\n" : "All is still and serene within your abode.\n");
}

// Main function: the heart of your smart home
int main() {
    greetUser();

    // Initialize the magical abode
    SmartHome myHome = {false, 22, 60, false, false};

    // Enter the infinite loop of home automation bliss
    while (true) {
        int choice;
        printf("\nChoose your magical command, Master:\n");
        printf("1. Toggle the enchanting lights\n");
        printf("2. Adjust the temperature to your whims\n");
        printf("3. Monitor the humidity in the air\n");
        printf("4. Lock or unlock your fortress\n");
        printf("5. Detect motion within your domain\n");
        printf("6. End the enchantment\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                toggleLights(&myHome);
                break;
            case 2:
                adjustTemperature(&myHome);
                break;
            case 3:
                checkHumidity(&myHome);
                break;
            case 4:
                lockUnlockDoor(&myHome);
                break;
            case 5:
                checkMotion(&myHome);
                break;
            case 6:
                printf("Farewell, Master. May your smart home continue to enchant you.\n");
                return 0;
            default:
                printf("Invalid command, Master. Please choose wisely.\n");
        }
    }

    return 0;
}