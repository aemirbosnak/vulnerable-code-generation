//Falcon-180B DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10
#define MAX_PLAYERS 4
#define MIN_ROLL 1
#define MAX_ROLL 6

typedef struct {
    int id;
    int position;
    int score;
} player_t;

void initialize_table(player_t table[MAX_PLAYERS]) {
    for(int i=0; i<MAX_PLAYERS; i++) {
        table[i].id = i+1;
        table[i].position = 0;
        table[i].score = 0;
    }
}

void display_table(player_t table[MAX_PLAYERS]) {
    printf("\n");
    for(int i=0; i<MAX_PLAYERS; i++) {
        printf("Player %d: Position %d, Score %d\n", table[i].id, table[i].position, table[i].score);
    }
}

int roll_dice() {
    int dice;
    srand(time(NULL));
    dice = rand() % 6 + 1;
    return dice;
}

int move_player(player_t *player, int steps) {
    int new_position = player->position + steps;
    if(new_position >= TABLE_SIZE) {
        new_position = new_position - TABLE_SIZE;
    }
    player->position = new_position;
    return new_position;
}

int main() {
    player_t table[MAX_PLAYERS];
    initialize_table(table);
    int active_player = 1;
    int current_player = 1;
    int steps;
    char choice;
    
    do {
        printf("\n");
        display_table(table);
        printf("Player %d's turn\n", current_player);
        printf("Enter the number of steps to move (1-6): ");
        scanf("%d", &steps);
        steps = move_player(&table[current_player-1], steps);
        table[current_player-1].score += steps;
        printf("You moved %d steps and scored %d points.\n", steps, table[current_player-1].score);
        current_player++;
        if(current_player > MAX_PLAYERS) {
            current_player = 1;
        }
        printf("Press any key to continue...\n");
        scanf(" %c", &choice);
    } while(choice!= 'q');
    
    return 0;
}