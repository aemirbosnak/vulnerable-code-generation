//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_RIDDLES 5
#define BUFFER_SIZE 256

typedef struct {
    char riddle[BUFFER_SIZE];
    char answer[BUFFER_SIZE];
} Riddle;

Riddle riddles[MAX_RIDDLES] = {
    {"What has keys but can't open locks?", "piano"},
    {"What can travel around the world while staying in a corner?", "stamp"},
    {"I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?", "echo"},
    {"What is so fragile that saying its name breaks it?", "silence"},
    {"I am taken from a mine, and shut up in a wooden case, from which I am never released. What am I?", "pencil lead"}
};

void display_riddle(int index) {
    printf("Riddle %d: %s\n", index + 1, riddles[index].riddle);
}

void handle_answer(int index) {
    char guess[BUFFER_SIZE];
    printf("Your answer: ");
    fgets(guess, BUFFER_SIZE, stdin);
    // Remove the trailing newline from input
    guess[strcspn(guess, "\n")] = 0;

    if (strcasecmp(guess, riddles[index].answer) == 0) {
        printf("Correct! 🎉\n");
    } else {
        printf("Incorrect! The correct answer was: %s\n", riddles[index].answer);
    }
}

int main() {
    int riddle_index = 0;
    char play_again;

    printf("Welcome to the Riddle Browser Plugin! 🤔\n");

    do {
        if (riddle_index >= MAX_RIDDLES) {
            printf("You've answered all the riddles! Thank you for playing!\n");
            break;
        }

        display_riddle(riddle_index);
        handle_answer(riddle_index);

        riddle_index++;

        if (riddle_index < MAX_RIDDLES) {
            printf("Would you like to answer another riddle? (y/n): ");
            scanf(" %c", &play_again);
            getchar();  // Consume the newline character left by scanf
            if (play_again != 'y') {
                printf("Thanks for playing! Goodbye! 👋\n");
                break;
            }
        }
    } while (riddle_index < MAX_RIDDLES);

    return 0;
}