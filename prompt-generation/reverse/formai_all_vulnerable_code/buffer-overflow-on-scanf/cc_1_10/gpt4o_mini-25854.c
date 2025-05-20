//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMANDS 7

// Function prototypes
void take_off();
void land();
void move_forward();
void move_backward();
void turn_left();
void turn_right();
void display_menu();
void exit_program();

// Main function
int main() {
    int choice;

    printf("\033[1;32m");
    printf("******** Welcome to the Cheerful Drone Remote Control! ********\n");
    printf("                 Take to the skies and have fun!                \n");
    printf("***************************************************************\n");
    
    do {
        display_menu();
        printf("\n  Choose an option (1-%d): ", MAX_COMMANDS);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                take_off();
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
                turn_left();
                break;
            case 6:
                turn_right();
                break;
            case 7:
                exit_program();
                break;
            default:
                printf("\033[1;31mInvalid choice! Please try again.\033[0m\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

// Function implementations
void take_off() {
    printf("\033[1;34mTaking off! 🚀 Your drone is soaring high! 🌤️\033[0m\n");
}

void land() {
    printf("\033[1;34mLanding! 🛬 Your drone is coming back to earth! 🌍\033[0m\n");
}

void move_forward() {
    printf("\033[1;34mMoving forward! 🚁 Your drone is racing ahead! 🌟\033[0m\n");
}

void move_backward() {
    printf("\033[1;34mMoving backward! 🔙 Your drone is drifting back! 🚁\033[0m\n");
}

void turn_left() {
    printf("\033[1;34mTurning left! ⬅️ Your drone is changing direction! 🎉\033[0m\n");
}

void turn_right() {
    printf("\033[1;34mTurning right! ➡️ Your drone is flying in a new way! 🌈\033[0m\n");
}

void display_menu() {
    printf("\n\033[1;33m***** Drone Control Menu *****\033[0m\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Turn Left\n");
    printf("6. Turn Right\n");
    printf("7. Exit\n");
}

void exit_program() {
    printf("\033[1;32mThank you for using the Cheerful Drone Remote Control! 🎈✈️\n");
    printf("                 Have a wonderful day! 🌞\033[0m\n");
    exit(0);
}