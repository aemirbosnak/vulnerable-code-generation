//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: random
/*
 * Haunted House Simulator
 * by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_instructions();
void play_game();
int is_user_ready();
void show_house();
void start_ghost_attack();
void print_score(int score);

// Global variables
int score = 0;

int main() {
    print_instructions();

    if (is_user_ready()) {
        play_game();
    }

    return 0;
}

void print_instructions() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You must navigate through the haunted house and defeat the ghosts.\n");
    printf("Use the arrow keys to move and the space bar to attack.\n");
    printf("Good luck!\n");
}

void play_game() {
    show_house();
    start_ghost_attack();
    print_score(score);
}

int is_user_ready() {
    int ready;
    printf("Are you ready to play? (y/n) ");
    scanf("%d", &ready);
    return ready;
}

void show_house() {
    printf("You are in the haunted house.\n");
    printf("You are in the living room.\n");
}

void start_ghost_attack() {
    printf("The ghosts are attacking!\n");
    printf("You have 30 seconds to defeat them.\n");

    for (int i = 0; i < 30; i++) {
        printf("You have %d seconds left.\n", 30 - i);
        sleep(1);
    }

    printf("The ghosts have been defeated!\n");
}

void print_score(int score) {
    printf("Your score is %d.\n", score);
}