//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int score;
} Player;

void parse_date(const char *input, struct tm *date) {
    // A simple date parser (will only work for specific formats)
    int day, month, year;
    
    if (sscanf(input, "%d/%d/%d", &month, &day, &year) == 3) {
        date->tm_mday = day;
        date->tm_mon = month - 1; // Months are 0-11 in struct tm
        date->tm_year = year - 1900; // Years since 1900
        date->tm_hour = 0;
        date->tm_min = 0;
        date->tm_sec = 0;
        date->tm_isdst = -1; // Not considering daylight savings
    } else {
        printf("Invalid date format! Use MM/DD/YYYY.\n");
    }
}

void convert_date_to_string(struct tm *date, char *output) {
    strftime(output, MAX_LENGTH, "%B %d, %Y", date);
}

void play_game(Player *players, int num_players) {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    struct tm date;
    int round = 1;

    while (1) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < num_players; i++) {
            printf("%s, enter a date in MM/DD/YYYY format (or type 'exit' to quit): ", players[i].name);
            fgets(input, MAX_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character

            if (strcmp(input, "exit") == 0) {
                printf("%s has exited the game.\n", players[i].name);
                return;
            }

            parse_date(input, &date);
            convert_date_to_string(&date, output);
            printf("%s converted it to: %s\n", players[i].name, output);
            players[i].score++;
        }
        round++;
    }
}

void print_winner(Player *players, int num_players) {
    int max_score = -1;
    int winner_index = -1;

    for (int i = 0; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            winner_index = i;
        }
    }

    printf("\nThe winner is %s with %d points!\n", players[winner_index].name, max_score);
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Welcome to the Natural Language Date Converter game!\n");
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // Clear the newline from the buffer

    if (num_players > MAX_PLAYERS || num_players <= 0) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, MAX_LENGTH, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline
        players[i].score = 0;
    }

    play_game(players, num_players);
    print_winner(players, num_players);

    return 0;
}