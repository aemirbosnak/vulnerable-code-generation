//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_intro() {
    printf("Welcome to 'Shape Shifter Adventure'!\n");
    printf("You are a shape-shifting creature in a mystical land.\n");
    printf("Choose your path wisely, as each choice will shape your destiny!\n\n");
}

void shape_shift(char *current_shape) {
    if (strcmp(current_shape, "human") == 0) {
        strcpy(current_shape, "wolf");
        printf("You have transformed into a mighty wolf!\n");
    } else if (strcmp(current_shape, "wolf") == 0) {
        strcpy(current_shape, "eagle");
        printf("You have taken the form of a majestic eagle!\n");
    } else if (strcmp(current_shape, "eagle") == 0) {
        strcpy(current_shape, "human");
        printf("You have reverted back to your human form.\n");
    } else {
        printf("You are unable to shape-shift further.\n");
    }
}

void choose_path(char *current_shape) {
    int choice;

    if (strcmp(current_shape, "human") == 0) {
        printf("You encounter a fork in the road.\n");
        printf("1. Follow the light path.\n");
        printf("2. Venture into the dark woods.\n");
        printf("Choose your path (1-2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You follow the light path and discover a hidden village!\n");
        } else {
            printf("You venture into the dark woods and confront a mystical creature!\n");
        }
    } else if (strcmp(current_shape, "wolf") == 0) {
        printf("You are in the dense forest.\n");
        printf("1. Hunt down a deer.\n");
        printf("2. Climb up a hill.\n");
        printf("Choose your action (1-2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You successfully catch your prey. You feel powerful!\n");
        } else {
            printf("You climb the hill and overlook a vast territory.\n");
        }
    } else if (strcmp(current_shape, "eagle") == 0) {
        printf("You soar high above the mountains.\n");
        printf("1. Dive into a lake.\n");
        printf("2. Investigate a distant castle.\n");
        printf("Choose your next move (1-2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You dive into the lake and find a treasure chest!\n");
        } else {
            printf("You reach the castle and discover ancient secrets!\n");
        }
    }
}

int main() {
    char current_shape[10];
    int game_continue = 1;
    int shape_choice;

    display_intro();
    strcpy(current_shape, "human");

    while (game_continue) {
        printf("\nYou are currently in the form of a %s.\n", current_shape);
        printf("1. Shape-shift.\n");
        printf("2. Choose a path.\n");
        printf("0. Exit the game.\n");
        printf("What would you like to do? (1-2 or 0 to exit): ");
        scanf("%d", &shape_choice);

        if (shape_choice == 1) {
            shape_shift(current_shape);
        } else if (shape_choice == 2) {
            choose_path(current_shape);
        } else if (shape_choice == 0) {
            game_continue = 0;
            printf("Thank you for playing! Goodbye!\n");
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}