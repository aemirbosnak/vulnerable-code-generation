//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void start();
void play();
void end();

int main() {
    srand(time(0));
    start();
    return 0;
}

void start() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer in search of treasure.\n");
    printf("Your journey begins in a dark forest.\n");
    play();
}

void play() {
    int choice;
    printf("What would you like to do?\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Search for treasure\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You move forward through the dark forest.\n");
            play();
            break;
        case 2:
            printf("You turn left and find a hidden path.\n");
            play();
            break;
        case 3:
            printf("You turn right and find a stream.\n");
            play();
            break;
        case 4:
            printf("You search for treasure and find a shiny gold coin!\n");
            end();
            break;
        default:
            printf("Invalid choice. Try again.\n");
            play();
            break;
    }
}

void end() {
    printf("Congratulations! You have found the treasure!\n");
    printf("Thank you for playing the Text-Based Adventure Game.\n");
}