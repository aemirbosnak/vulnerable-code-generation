//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: relaxed
/*
 * A table game example program in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Define constants
#define MAX_PLAYERS 4
#define MAX_ROUNDS 10
#define MAX_TABLE_SIZE 100

// Define structures
typedef struct player {
    char name[20];
    int score;
} player_t;

typedef struct table {
    player_t players[MAX_PLAYERS];
    int rounds;
    int size;
} table_t;

// Define functions
void init_table(table_t *table) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        table->players[i].score = 0;
    }
    table->rounds = 0;
    table->size = 0;
}

void add_player(table_t *table, char *name) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (table->players[i].score == 0) {
            strcpy(table->players[i].name, name);
            break;
        }
    }
}

void remove_player(table_t *table, char *name) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(table->players[i].name, name) == 0) {
            table->players[i].score = 0;
            break;
        }
    }
}

void play_round(table_t *table) {
    srand(time(NULL));
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int sum = dice1 + dice2;
    printf("Dice 1: %d\n", dice1);
    printf("Dice 2: %d\n", dice2);
    printf("Sum: %d\n", sum);

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (table->players[i].score > 0) {
            table->players[i].score += sum;
            if (table->players[i].score > table->size) {
                table->size = table->players[i].score;
            }
        }
    }

    table->rounds++;
}

void show_table(table_t *table) {
    printf("Rounds: %d\n", table->rounds);
    printf("Table size: %d\n", table->size);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (table->players[i].score > 0) {
            printf("%s: %d\n", table->players[i].name, table->players[i].score);
        }
    }
}

int main() {
    table_t table;
    init_table(&table);

    char name[20];
    while (true) {
        printf("Enter a name: ");
        scanf("%s", name);
        add_player(&table, name);

        printf("Players: ");
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (table.players[i].score > 0) {
                printf("%s ", table.players[i].name);
            }
        }
        printf("\n");

        if (table.rounds < MAX_ROUNDS) {
            play_round(&table);
            show_table(&table);
        } else {
            printf("Game over!\n");
            break;
        }
    }

    return 0;
}