//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show_intro() {
    printf("================================================\n");
    printf("               ESCAPE THE DUNGEON               \n");
    printf("================================================\n");
    printf("You find yourself trapped in a dark and mysterious dungeon.\n");
    printf("Your goal is to escape by making the right choices.\n");
    printf("Be careful! You may encounter dangerous creatures or treasure.\n\n");
}

int random_event() {
    return rand() % 3; // Returns 0, 1, or 2 for events
}

void encounter_monster() {
    printf("A wild monster appears!\n");
    printf("Do you want to (1) Fight or (2) Run? ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You bravely fight the monster and defeat it!\n");
    } else {
        printf("You run away safely, but lose a turn.\n");
    }
}

void find_treasure() {
    printf("You found a treasure chest!\n");
    printf("Do you want to (1) Open it or (2) Leave it? ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Congratulations! You found some gold!\n");
    } else {
        printf("You decide to leave the treasure behind.\n");
    }
}

void game_over() {
    printf("================================================\n");
    printf("             GAME OVER! YOU DID NOT ESCAPE.    \n");
    printf("================================================\n");
    exit(0);
}

void victory() {
    printf("================================================\n");
    printf("                YOU ESCAPED!                    \n");
    printf("================================================\n");
    exit(0);
}

void choose_path() {
    printf("You encounter a fork in the path.\n");
    printf("Do you want to go (1) Left or (2) Right? ");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You chose the left path.\n");
        int event = random_event();
        if (event == 0) {
            encounter_monster();
        } else if (event == 1) {
            find_treasure();
        } else {
            printf("The left path leads to a dead end.\n");
            game_over();
        }
    } else if (choice == 2) {
        printf("You chose the right path.\n");
        int event = random_event();
        if (event == 0) {
            encounter_monster();
        } else if (event == 1) {
            find_treasure();
        } else {
            printf("You walked into a trap!\n");
            game_over();
        }
    } else {
        printf("Invalid choice, game over!\n");
        game_over();
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    show_intro();
    
    while (1) {
        choose_path();
        printf("\n");
    }
    
    return 0;
}