//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void clearScreen() {
    printf("\033[H\033[J");
}

void printWelcomeMessage() {
    printf("🎉 Welcome to the Happy Drone Remote Control! 🎉\n");
    printf("Let's have some fun flying your drone!\n");
}

void showMenu() {
    printf("\n🌟 Choose your action:\n");
    printf("1. Fly Up\n");
    printf("2. Fly Down\n");
    printf("3. Fly Left\n");
    printf("4. Fly Right\n");
    printf("5. Take Picture\n");
    printf("6. Land\n");
    printf("7. Exit\n");
}

void flyDrone(const char *direction) {
    printf("🚁 The drone is flying %s! 🚁\n", direction);
    sleep(1); // Simulates time taken to fly in that direction
}

void takePicture() {
    printf("📸 Snap! Picture taken! 📸\n");
    sleep(1); // Simulates time taken to take a picture
}

void landDrone() {
    printf("🏴 The drone is landing safely! 🏴\n");
    sleep(1); // Simulates landing
}

int main() {
    int choice;

    clearScreen();
    printWelcomeMessage();

    while (1) {
        showMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flyDrone("Up");
                break;
            case 2:
                flyDrone("Down");
                break;
            case 3:
                flyDrone("Left");
                break;
            case 4:
                flyDrone("Right");
                break;
            case 5:
                takePicture();
                break;
            case 6:
                landDrone();
                break;
            case 7:
                printf("👋 Thank you for flying with us! Goodbye! 👋\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please select a number between 1 and 7.\n");
                break;
        }
    }

    return 0;
}