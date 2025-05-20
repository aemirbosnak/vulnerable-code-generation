//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PLAYERS 5
#define BINGO_SIZE 5
#define MAX_NUM 75

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
    char name[30];
} Player;

void initialize_card(Player* player) {
    int nums[MAX_NUM + 1] = {0};

    for (int col = 0; col < BINGO_SIZE; col++) {
        int range_start = col * 15 + 1;
        int range_end = range_start + 14;
        int count = 0;

        while (count < BINGO_SIZE) {
            int num = rand() % (range_end - range_start + 1) + range_start;
            if (!nums[num]) {
                nums[num] = 1;
                player->card[count][col] = num;
                count++;
            }
        }
    }
    player->card[BINGO_SIZE / 2][BINGO_SIZE / 2] = 0; // Free space in the middle
}

void print_card(Player* player) {
    printf("%s's Bingo Card:\n", player->name);
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player->marked[i][j]) {
                printf("[*] ");
            } else {
                printf("[%2d] ", player->card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool mark_number(Player* player, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player->card[i][j] == number) {
                player->marked[i][j] = true;
                return true;
            }
        }
    }
    return false;
}

bool check_bingo(Player* player) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        bool row = true;
        bool col = true;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (!player->marked[i][j]) row = false;
            if (!player->marked[j][i]) col = false;
        }
        if (row || col) return true;
    }
    return false;
}

void play_bingo(Player players[], int num_players) {
    int drawn_numbers[MAX_NUM + 1] = {0};
    int total_drawn = 0;

    while (true) {
        int num;
        do {
            num = rand() % MAX_NUM + 1;
        } while (drawn_numbers[num]);

        drawn_numbers[num] = 1;
        total_drawn++;

        printf("Drawn Number: %d\n", num);
        for (int i = 0; i < num_players; i++) {
            if (mark_number(&players[i], num)) {
                printf("%s marked %d!\n", players[i].name, num);
            }
            if (check_bingo(&players[i])) {
                printf("%s wins Bingo!\n", players[i].name);
                return;
            }
        }
        printf("\n");
        for (int i = 0; i < num_players; i++) {
            print_card(&players[i]);
        }
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];

    int num_players;
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    num_players = num_players > MAX_PLAYERS ? MAX_PLAYERS : num_players;

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        initialize_card(&players[i]);
        for (int j = 0; j < BINGO_SIZE; j++) {
            for (int k = 0; k < BINGO_SIZE; k++) {
                players[i].marked[j][k] = false;
            }
        }
        print_card(&players[i]);
    }

    printf("Let's play Bingo!\n");
    play_bingo(players, num_players);

    return 0;
}