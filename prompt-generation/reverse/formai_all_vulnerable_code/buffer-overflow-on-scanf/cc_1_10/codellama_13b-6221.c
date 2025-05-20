//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 100
#define MAX_TABLE_SIZE 10

typedef struct {
    int id;
    int score;
    char name[20];
} Player;

void print_players(Player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %s (%d)\n", players[i].id, players[i].name, players[i].score);
    }
}

void print_table(int *table, int num_rounds) {
    for (int i = 0; i < num_rounds; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

void shuffle_table(int *table, int num_rounds) {
    srand(time(NULL));
    for (int i = 0; i < num_rounds; i++) {
        int random_index = rand() % num_rounds;
        int temp = table[i];
        table[i] = table[random_index];
        table[random_index] = temp;
    }
}

void generate_table(int *table, int num_rounds, int max_value) {
    for (int i = 0; i < num_rounds; i++) {
        table[i] = rand() % max_value + 1;
    }
}

int main() {
    int num_players = 0;
    int num_rounds = 0;
    int max_value = 0;

    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    printf("Enter the number of rounds: ");
    scanf("%d", &num_rounds);
    printf("Enter the maximum value for the table: ");
    scanf("%d", &max_value);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].id = i + 1;
        players[i].score = 0;
    }

    int table[MAX_TABLE_SIZE];
    generate_table(table, num_rounds, max_value);
    shuffle_table(table, num_rounds);

    print_players(players, num_players);
    print_table(table, num_rounds);

    for (int i = 0; i < num_rounds; i++) {
        int player_id = rand() % num_players + 1;
        players[player_id - 1].score += table[i];
    }

    print_players(players, num_players);

    return 0;
}