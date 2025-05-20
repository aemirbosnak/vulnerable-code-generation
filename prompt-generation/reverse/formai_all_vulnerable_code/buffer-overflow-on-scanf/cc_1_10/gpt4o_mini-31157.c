//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void takeOff() {
    printf("🚀 The drone is taking off!\n");
    sleep(2);
    printf("🛩️ The drone is now airborne!\n");
}

void land() {
    printf("🛬 The drone is landing!\n");
    sleep(2);
    printf("🛩️ The drone has successfully landed!\n");
}

void moveForward() {
    printf("⬆️ The drone is moving forward!\n");
    sleep(1);
}

void moveBackward() {
    printf("⬇️ The drone is moving backward!\n");
    sleep(1);
}

void moveLeft() {
    printf("⬅️ The drone is moving left!\n");
    sleep(1);
}

void moveRight() {
    printf("➡️ The drone is moving right!\n");
    sleep(1);
}

void rotateClockwise() {
    printf("🔄 The drone is rotating clockwise!\n");
    sleep(1);
}

void rotateCounterClockwise() {
    printf("🔄 The drone is rotating counterclockwise!\n");
    sleep(1);
}

void showMenu() {
    printf("\n========== DRONE REMOTE CONTROL ==========\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Move Left\n");
    printf("6. Move Right\n");
    printf("7. Rotate Clockwise\n");
    printf("8. Rotate Counter Clockwise\n");
    printf("0. Exit\n");
    printf("==========================================\n");
    printf("Please enter your choice: ");
}

int main() {
    int choice;

    printf("🛩️ Welcome to the Drone Control Program! 🎮\n");

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeOff();
                break;
            case 2:
                land();
                break;
            case 3:
                moveForward();
                break;
            case 4:
                moveBackward();
                break;
            case 5:
                moveLeft();
                break;
            case 6:
                moveRight();
                break;
            case 7:
                rotateClockwise();
                break;
            case 8:
                rotateCounterClockwise();
                break;
            case 0:
                printf("👋 Thank you for using the Drone Control Program. Safe flying!\n");
                exit(0);
                break;
            default:
                printf("🚫 Invalid choice! Please try again.\n");
        }
    }

    return 0;
}