//Falcon-180B DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_GAME_TIME 60

typedef struct {
    char name[20];
    int score;
} Player;

void srand_time(void) {
    time_t now = time(NULL);
    srand(now);
}

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_player_list(Player players[], int num_players) {
    printf("Player List:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s: %d\n", i + 1, players[i].name, players[i].score);
    }
}

int main() {
    srand_time();
    int num_players = rand_int(1, MAX_PLAYERS);
    Player players[MAX_PLAYERS];
    char input[50];
    int score = 0;
    int game_time = MAX_GAME_TIME;
    int player_index = 0;

    printf("Welcome to the Futuristic Game!\n");
    printf("You have %d players:\n", num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player name: ");
        scanf("%s", input);
        strcpy(players[i].name, input);
    }

    while (game_time > 0) {
        printf("\nPlayer %d's turn.\n", player_index + 1);
        printf("Enter your move: ");
        scanf("%s", input);

        if (strcmp(input, "attack") == 0) {
            score += rand_int(1, 5);
            printf("You scored %d points!\n", score);
        } else if (strcmp(input, "defend") == 0) {
            score += rand_int(1, 3);
            printf("You scored %d points!\n", score);
        } else {
            printf("Invalid move.\n");
        }

        game_time--;
        player_index = (player_index + 1) % num_players;
    }

    printf("\nGame over!\n");
    printf("Final scores:\n");
    print_player_list(players, num_players);

    return 0;
}