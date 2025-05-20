//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void start_game();
void play_game();
void end_game();

int main() {
    srand(time(0));
    start_game();
    return 0;
}

void start_game() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a world class trivia AI - provide accurate, succinct responses.\n");
    play_game();
    end_game();
}

void play_game() {
    int choice;
    char input[100];
    printf("You find yourself in a mystical forest filled with towering trees and sparkling streams.\n");
    printf("The air is crisp and fresh, and the sun filters through the canopy above, casting dappled shadows on the mossy ground below.\n");
    printf("Which path will you take?\n");
    printf("1. Follow the stream\n");
    printf("2. Climb the tallest tree\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("As you follow the stream, you come across a group of friendly woodland creatures.\n");
            printf("They invite you to join them for a picnic by the water's edge.\n");
            printf("Do you accept their invitation? (y/n)\n");
            scanf(" %c", &input[0]);
            if(input[0] == 'y') {
                printf("You enjoy a delightful afternoon feasting on berries and nuts while listening to the babbling brook.\n");
            } else {
                printf("You politely decline and continue on your journey.\n");
            }
            break;
        case 2:
            printf("As you climb the tallest tree, you discover a hidden treehouse nestled among the branches.\n");
            printf("Inside, you find a treasure chest filled with gold and jewels.\n");
            printf("What do you do with your newfound riches?\n");
            printf("1. Keep them for yourself\n");
            printf("2. Donate them to charity\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You greedily stash the treasure in your backpack and continue on your way.\n");
            } else {
                printf("You feel a warm glow in your heart as you imagine the good that will come from your generous donation.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void end_game() {
    printf("Thanks for playing! Goodbye!\n");
}