//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PLAYERS 10
#define STRING_LENGTH 256
#define TIME_BUFFER_LENGTH 20

void clear_screen() {
    printf("\033[H\033[J");
}

void print_welcome_message() {
    printf("Welcome to the Multiplayer Typing Speed Test!\n");
    printf("Type the following sentence as fast as you can:\n");
}

void print_leaderboard(char players[][STRING_LENGTH], double times[], int player_count) {
    printf("\n***** Leaderboard *****\n");
    for (int i = 0; i < player_count; i++) {
        printf("%s - %.2f seconds\n", players[i], times[i]);
    }
    printf("***********************\n");
}

int main() {
    char players[MAX_PLAYERS][STRING_LENGTH];
    double times[MAX_PLAYERS];
    char sentence[] = "The quick brown fox jumps over the lazy dog.";
    char input[STRING_LENGTH];
    clock_t start, end;
    int player_count = 0;

    clear_screen();
    print_welcome_message();
    printf("\"%s\"\n", sentence);
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    getchar(); // To consume newline left by scanf

    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the test.\n");
        return 1;
    }

    for (int i = 0; i < player_count; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i], STRING_LENGTH, stdin);
        players[i][strcspn(players[i], "\n")] = 0; // Remove newline character

        printf("Player %s, press Enter to start typing...\n", players[i]);
        getchar(); // Wait for player to press Enter

        clear_screen();
        printf("Player %s, type the following sentence:\n", players[i]);
        printf("\"%s\"\n", sentence);

        start = clock();
        fgets(input, STRING_LENGTH, stdin);
        end = clock();

        // Calculate time taken
        times[i] = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Check if input matches the sentence
        if (strcmp(sentence, input) == 0) {
            printf("Well done, Player %s! You completed it in %.2f seconds.\n\n", players[i], times[i]);
        } else {
            printf("Oops, Player %s! Your input did not match the sentence.\n\n", players[i]);
        }

        clear_screen();
    }

    print_leaderboard(players, times, player_count);

    return 0;
}