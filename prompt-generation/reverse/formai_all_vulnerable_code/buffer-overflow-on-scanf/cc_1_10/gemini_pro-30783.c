//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 5

typedef struct {
    char name[20];
    int numbers[MAX_CARDS][5];
    bool won;
} Player;

void print_card(int numbers[][5]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %s:\n", players[i].name);
        print_card(players[i].numbers);
    }
}

bool check_row(int numbers[][5], int row) {
    for (int i = 0; i < 5; i++) {
        if (numbers[row][i] != -1) {
            return false;
        }
    }
    return true;
}

bool check_column(int numbers[][5], int column) {
    for (int i = 0; i < 5; i++) {
        if (numbers[i][column] != -1) {
            return false;
        }
    }
    return true;
}

bool check_diagonal(int numbers[][5]) {
    for (int i = 0; i < 5; i++) {
        if (numbers[i][i] != -1) {
            return false;
        }
    }
    return true;
}

bool check_reverse_diagonal(int numbers[][5]) {
    for (int i = 0; i < 5; i++) {
        if (numbers[i][4 - i] != -1) {
            return false;
        }
    }
    return true;
}

bool check_winner(int numbers[][5]) {
    for (int i = 0; i < 5; i++) {
        if (check_row(numbers, i) || check_column(numbers, i)) {
            return true;
        }
    }
    if (check_diagonal(numbers) || check_reverse_diagonal(numbers)) {
        return true;
    }
    return false;
}

int main() {
    srand(time(NULL));

    int num_players;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];

    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);

        for (int j = 0; j < MAX_CARDS; j++) {
            for (int k = 0; k < 5; k++) {
                players[i].numbers[j][k] = -1;
            }
        }
    }

    int numbers[75];
    for (int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }

    for (int i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    int drawn_numbers[75];
    int num_drawn = 0;

    bool winner_found = false;

    while (!winner_found) {
        int drawn_number = numbers[num_drawn];
        drawn_numbers[num_drawn] = drawn_number;
        num_drawn++;

        for (int i = 0; i < num_players; i++) {
            for (int j = 0; j < MAX_CARDS; j++) {
                for (int k = 0; k < 5; k++) {
                    if (players[i].numbers[j][k] == drawn_number) {
                        players[i].numbers[j][k] = -1;
                    }
                }
            }

            if (check_winner(players[i].numbers)) {
                winner_found = true;
                printf("Player %s has won!\n", players[i].name);
                break;
            }
        }
    }

    printf("Drawn numbers:\n");
    for (int i = 0; i < num_drawn; i++) {
        printf("%d ", drawn_numbers[i]);
    }
    printf("\n");

    return 0;
}