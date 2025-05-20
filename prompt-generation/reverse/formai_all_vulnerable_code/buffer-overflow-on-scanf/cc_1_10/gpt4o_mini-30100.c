//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_NUMBERS 10
#define MAX_ATTEMPTS 3

void generate_sequence(int sequence[], int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 100; // Random numbers between 0-99
    }
}

void display_sequence(int sequence[], int length) {
    printf("Memorize this sequence:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", sequence[i]);
        fflush(stdout);
        usleep(1000000); // Display each number for 1 second
    }
    printf("\n");
}

void clear_screen() {
    printf("\033[H\033[J");
}

int get_player_input(int player_sequence[], int length) {
    printf("Enter the sequence (space-separated, followed by -1 to end):\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &player_sequence[i]);
        if (player_sequence[i] == -1) {
            break;
        }
    }
    
    return length; // Returning the number of elements entered
}

int check_sequence(int original[], int player[], int length) {
    for (int i = 0; i < length; i++) {
        if (original[i] != player[i]) {
            return 0; // Sequences do not match
        }
    }
    return 1; // Sequences match
}

void play_game() {
    srand(time(NULL)); // Seed random number generator
    int sequence[MAX_NUMBERS];
    int player_sequence[MAX_NUMBERS];
    
    int round = 1;
    while (round <= MAX_ATTEMPTS) {
        generate_sequence(sequence, round);
        clear_screen();
        display_sequence(sequence, round);

        clear_screen();
        int entered_length = get_player_input(player_sequence, round);
        
        if (check_sequence(sequence, player_sequence, round)) {
            printf("Correct! Moving to round %d...\n", round + 1);
            round++;
        } else {
            printf("Incorrect sequence! Game Over.\n");
            break;
        }

        sleep(2); // Wait before the next round
    }
    
    if (round > MAX_ATTEMPTS) {
        printf("Congratulations! You've completed all rounds!\n");
    }
}

int main() {
    printf("Welcome to the Memory Game!\n");
    sleep(1);
    play_game();
    return 0;
}