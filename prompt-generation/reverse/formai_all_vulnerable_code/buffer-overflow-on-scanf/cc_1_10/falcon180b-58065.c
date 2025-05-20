//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void start();
void play();
void end();

int main() {
    srand(time(NULL));
    start();
    play();
    end();
    return 0;
}

// Start of the game
void start() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark, mysterious forest.\n");
    printf("What would you like to do?\n");
}

// Main part of the game
void play() {
    int choice;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    while(1) {
        printf("\n%s, what would you like to do?\n", name);
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Look around\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou move forward and find a small clearing.\n");
                break;
            case 2:
                printf("\nYou turn left and see a large tree.\n");
                break;
            case 3:
                printf("\nYou turn right and see a small stream.\n");
                break;
            case 4:
                printf("\nYou look around and see the beauty of the forest.\n");
                break;
            case 5:
                printf("\n%s, thank you for playing!\n", name);
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
}

// End of the game
void end() {
    printf("\nThank you for playing the Text-Based Adventure Game!\n");
}