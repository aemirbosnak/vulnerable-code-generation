//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_FORTUNE 5

typedef struct {
    char name[50];
    int fortune_index;
} Player;

void display_fortunes() {
    const char *fortunes[MAX_FORTUNE] = {
        "You will find happiness in unexpected places.",
        "A great opportunity is coming your way.",
        "Expect a surprise from someone you trust.",
        "Your hard work will pay off soon.",
        "You will encounter a problem that requires a unique solution."
    };

    printf("Fortune Options:\n");
    for (int i = 0; i < MAX_FORTUNE; i++) {
        printf("%d: %s\n", i + 1, fortunes[i]);
    }
}

void choose_fortunes(Player players[], int player_count) {
    srand(time(NULL));
    const char *fortunes[MAX_FORTUNE] = {
        "You will find happiness in unexpected places.",
        "A great opportunity is coming your way.",
        "Expect a surprise from someone you trust.",
        "Your hard work will pay off soon.",
        "You will encounter a problem that requires a unique solution."
    };

    for (int i = 0; i < player_count; i++) {
        players[i].fortune_index = rand() % MAX_FORTUNE;
        printf("%s's fortune: %s\n", players[i].name, fortunes[players[i].fortune_index]);
    }
}

void get_player_names(Player players[], int *player_count) {
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", player_count);
    while (*player_count < 1 || *player_count > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 1 and %d: ", MAX_PLAYERS);
        scanf("%d", player_count);
    }

    for (int i = 0; i < *player_count; i++) {
        printf("Enter name for player #%d: ", i + 1);
        scanf("%s", players[i].name);
    }
}

void play_game() {
    Player players[MAX_PLAYERS];
    int player_count;

    printf("Welcome to the Multiplayer Fortune Teller!\n");
    get_player_names(players, &player_count);
    display_fortunes();
    choose_fortunes(players, player_count);

    printf("Thank you for playing the Multiplayer Fortune Teller! Goodbye!\n");
}

int main() {
    play_game();
    return 0;
}