//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Function declarations
void display_menu();
void takeoff();
void land();
void move_forward();
void move_backward();
void move_left();
void move_right();
void rotate_left();
void rotate_right();

int main() {
    char username[MAX_NAME_LENGTH];
    printf("Welcome to the Cheerful Drone Remote Control!\n");
    printf("Please enter your name: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0; // Remove the trailing newline
    printf("Hello, %s! Let's get started with flying your drone!\n", username);

    int choice;

    do {
        display_menu();
        printf("Enter your choice (1-8) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeoff();
                break;
            case 2:
                land();
                break;
            case 3:
                move_forward();
                break;
            case 4:
                move_backward();
                break;
            case 5:
                move_left();
                break;
            case 6:
                move_right();
                break;
            case 7:
                rotate_left();
                break;
            case 8:
                rotate_right();
                break;
            case 0:
                printf("Thank you for flying with us, %s! Have a great day!\n", username);
                break;
            default:
                printf("Oops! That's not a valid option. Please try again!\n");
                break;
        }
        
        printf("\n"); // Add space for better readability

    } while (choice != 0);

    return 0;
}

void display_menu() {
    printf("=== Cheerful Drone Control Menu ===\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Move Left\n");
    printf("6. Move Right\n");
    printf("7. Rotate Left\n");
    printf("8. Rotate Right\n");
    printf("0. Exit\n");
    printf("===================================\n");
}

void takeoff() {
    printf("🛫 Whoo-hoo! The drone is taking off! Fly high and enjoy the view! 🌤️\n");
}

void land() {
    printf("🛬 Gently landing the drone. Hope you had a thrilling ride! 🌈\n");
}

void move_forward() {
    printf("➡️ Zooming forward! Look out below! 🚀\n");
}

void move_backward() {
    printf("⬅️ Reversing back... You got this! 🌟\n");
}

void move_left() {
    printf("⬅️ Whoa! Drifting left! Keep an eye on the surroundings! 🌳\n");
}

void move_right() {
    printf("➡️ Sliding to the right! What a smooth move! 🦋\n");
}

void rotate_left() {
    printf("🔄 Spinning left! Time to check out that lovely scenery! 🏞️\n");
}

void rotate_right() {
    printf("🔄 Spinning right! Quick, catch that sunset! 🌅\n");
}