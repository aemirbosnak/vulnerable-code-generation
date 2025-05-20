//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Function to print a surprised face
void print_surprise(void) {
    printf("😱");
}

// Function to print a happy face
void print_happy(void) {
    printf("😊");
}

// Function to print a sad face
void print_sad(void) {
    printf("😔");
}

// Game loop
void game_loop(void) {
    int choice;
    char message[100];

    // Print the game menu
    printf("Welcome to the Surprise Game!\n");
    printf("Choose a game mode:\n");
    printf("1. Surprise Me!\n");
    printf("2. Happy Mode\n");
    printf("3. Sad Mode\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Handle user's choice
    switch (choice) {
        case 1:
            // Print a surprised face and play a sound effect
            print_surprise();
            system("play sound_effect.wav");
            break;
        case 2:
            // Print a happy face and play a sound effect
            print_happy();
            system("play happy_sound.wav");
            break;
        case 3:
            // Print a sad face and play a sound effect
            print_sad();
            system("play sad_sound.wav");
            break;
        default:
            printf("Invalid choice. Try again!\n");
            game_loop();
            break;
    }
}

int main(void) {
    srand(time(NULL));

    // Game loop
    game_loop();

    return 0;
}