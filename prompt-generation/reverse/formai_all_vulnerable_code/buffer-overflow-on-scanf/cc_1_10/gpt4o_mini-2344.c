//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE 10
#define MAX_LEVEL 5

void generate_sequence(int sequence[], int level) {
    for (int i = 0; i < level; i++) {
        sequence[i] = rand() % 10;  // Generate numbers from 0 to 9
    }
}

void display_sequence(int sequence[], int level) {
    printf("Memorize this sequence:\n");
    for (int i = 0; i < level; i++) {
        printf("%d ", sequence[i]);
        fflush(stdout);
        sleep(1);  // Wait for a second before showing the next number
    }
    printf("\n");
    sleep(2);  // Give some time before clearing the screen
    printf("\033[H\033[J");  // ANSI escape code to clear the screen
}

void get_player_input(int player_input[], int level) {
    printf("Enter the sequence (space-separated): ");
    for (int i = 0; i < level; i++) {
        scanf("%d", &player_input[i]);
    }
}

int check_sequence(int sequence[], int player_input[], int level) {
    for (int i = 0; i < level; i++) {
        if (sequence[i] != player_input[i]) {
            return 0;  // Sequence does not match
        }
    }
    return 1;  // Sequence matches
}

void play_game() {
    int level = 1;
    int sequence[MAX_SEQUENCE];
    int player_input[MAX_SEQUENCE];

    printf("Welcome to the Memory Game!\n");
    sleep(1);  // Pause for dramatic effect

    while (level <= MAX_LEVEL) {
        generate_sequence(sequence, level);
        display_sequence(sequence, level);
        
        get_player_input(player_input, level);

        if (check_sequence(sequence, player_input, level)) {
            printf("Correct! Moving to the next level...\n");
            level++;  // Increase level for the next round
        } else {
            printf("Incorrect! The correct sequence was: ");
            for (int i = 0; i < level; i++) {
                printf("%d ", sequence[i]);
            }
            printf("\nGame Over! You reached level %d.\n", level);
            break;  // End game
        }
    }
    
    if (level > MAX_LEVEL) {
        printf("Congratulations! You have memorized all levels!\n");
    }
}

int main() {
    srand(time(NULL));  // Seed for random number generation
    play_game();
    return 0;
}