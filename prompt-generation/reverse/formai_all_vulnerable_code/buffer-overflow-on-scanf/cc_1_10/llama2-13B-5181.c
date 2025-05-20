//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRATITUDE_LEVELS 5
#define GRATITUDE_SCALE 2

typedef struct {
    int level;
    int score;
} gratitude_t;

gratitude_t gratitude[GRATITUDE_LEVELS];

void init_gratitude() {
    int i;
    for (i = 0; i < GRATITUDE_LEVELS; i++) {
        gratitude[i].level = i;
        gratitude[i].score = 0;
    }
}

void update_gratitude(int score) {
    int i;
    for (i = 0; i < GRATITUDE_LEVELS; i++) {
        if (score >= gratitude[i].score) {
            gratitude[i].score = score;
            gratitude[i].level = i;
        }
    }
}

void print_gratitude() {
    int i;
    for (i = 0; i < GRATITUDE_LEVELS; i++) {
        printf("Level %d: %d points\n", gratitude[i].level, gratitude[i].score);
    }
}

void game_loop() {
    int choice;
    char command[10];

    do {
        printf("Welcome to Gratitude Game!\n");
        printf("Your current level is %d\n", gratitude[0].level);
        printf("What would you like to do? (1-5, q to quit)\n");

        scanf("%d%9s", &choice, command);

        switch (choice) {
            case 1:
                // Increase gratitude level
                gratitude[0].level++;
                update_gratitude(gratitude[0].score);
                break;
            case 2:
                // Decrease gratitude level
                gratitude[0].level--;
                update_gratitude(gratitude[0].score);
                break;
            case 3:
                // Print gratitude levels
                print_gratitude();
                break;
            case 4:
                // Skip current level
                gratitude[0].level++;
                break;
            case 5:
                // Quit game
                printf("Thanks for playing! Goodbye!\n");
                return;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    init_gratitude();

    game_loop();

    return 0;
}