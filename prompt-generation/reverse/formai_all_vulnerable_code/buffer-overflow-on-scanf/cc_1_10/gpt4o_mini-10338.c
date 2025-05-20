//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_LEVEL 10
#define SEQUENCE_SIZE 20

void generate_sequence(int sequence[], int level) {
    srand(time(NULL));
    for (int i = 0; i < level; i++) {
        sequence[i] = rand() % 10; // Random number between 0 and 9
    }
}

void display_sequence(int sequence[], int level) {
    printf("Memorize this sequence:\n");
    for (int i = 0; i < level; i++) {
        printf("%d ", sequence[i]);
        fflush(stdout);
        usleep(1000000); // Sleep for 1 second to allow memorization
    }
    printf("\n");
    sleep(2); // Pause before clearing the screen
    printf("\033[H\033[J"); // Clear the screen
}

int get_player_input(int player_sequence[], int level) {
    printf("Enter the sequence (one number at a time):\n");
    for (int i = 0; i < level; i++) {
        scanf("%d", &player_sequence[i]);
    }
    
    return 1;
}

int check_sequence(int sequence[], int player_sequence[], int level) {
    for (int i = 0; i < level; i++) {
        if (sequence[i] != player_sequence[i]) {
            return 0; // Sequence incorrect
        }
    }
    return 1; // Sequence correct
}

void play_memory_game() {
    int level = 1;
    int sequence[SEQUENCE_SIZE];
    int player_sequence[SEQUENCE_SIZE];

    printf("Welcome to the Memory Game!\n");
    while (level <= MAX_LEVEL) {
        generate_sequence(sequence, level);
        display_sequence(sequence, level);
        get_player_input(player_sequence, level);
        
        if (check_sequence(sequence, player_sequence, level)) {
            printf("Correct! Moving to level %d.\n\n", level + 1);
            level++;
        } else {
            printf("Incorrect sequence! Game Over. You reached level %d.\n", level);
            break;
        }
    }
}

int main() {
    play_memory_game();
    return 0;
}