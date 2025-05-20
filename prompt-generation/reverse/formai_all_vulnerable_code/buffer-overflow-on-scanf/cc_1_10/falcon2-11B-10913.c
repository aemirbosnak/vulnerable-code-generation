//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

typedef struct player {
    char name[100];
    char choice;
} Player;

void print_player(const Player player) {
    printf("%s: %c\n", player.name, player.choice);
}

void ask_for_player_choice(Player *player) {
    printf("Please choose your weapon: ");
    scanf(" %c", &player->choice);
}

void print_menu() {
    printf("ROCK\n");
    printf("PAPER\n");
    printf("SCISSORS\n");
}

int is_choice_valid(char choice) {
    return (choice == 'r' || choice == 'p' || choice =='s');
}

int main() {
    Player player1, player2;

    printf("Player 1: ");
    ask_for_player_choice(&player1);

    print_menu();
    printf("Player 2: ");
    ask_for_player_choice(&player2);

    printf("Player 1 chose %s\n", player1.name);
    printf("Player 2 chose %s\n", player2.name);

    if (player1.choice == player2.choice) {
        printf("It's a tie!\n");
    } else if (is_choice_valid(player1.choice) && is_choice_valid(player2.choice)) {
        if (player1.choice == 'r' && player2.choice =='s') {
            printf("Player 1 wins!\n");
        } else if (player1.choice =='s' && player2.choice == 'p') {
            printf("Player 1 wins!\n");
        } else if (player1.choice == 'p' && player2.choice == 'r') {
            printf("Player 1 wins!\n");
        } else {
            printf("Player 2 wins!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}