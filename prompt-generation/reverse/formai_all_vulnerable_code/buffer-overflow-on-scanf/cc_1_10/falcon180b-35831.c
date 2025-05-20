//Falcon-180B DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player {
    int id;
    char name[20];
    int score;
};

int main() {
    srand(time(0));
    int num_players, num_rounds;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    struct Player players[num_players];
    for (int i = 0; i < num_players; i++) {
        players[i].id = i + 1;
        printf("Enter player %d's name: ", players[i].id);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    printf("Enter the number of rounds: ");
    scanf("%d", &num_rounds);
    for (int round = 0; round < num_rounds; round++) {
        for (int i = 0; i < num_players - 1; i++) {
            int player1 = rand() % num_players;
            int player2 = rand() % num_players;
            while (player1 == player2) {
                player2 = rand() % num_players;
            }
            if (player1 < player2) {
                int temp = player1;
                player1 = player2;
                player2 = temp;
            }
            printf("Round %d, Matchup: %s vs %s\n", round + 1, players[player1].name, players[player2].name);
            int result = rand() % 2;
            if (result == 0) {
                players[player1].score++;
                printf("%s wins!\n", players[player1].name);
            } else {
                players[player2].score++;
                printf("%s wins!\n", players[player2].name);
            }
        }
    }
    printf("The winner of the tournament is %s with a score of %d!\n", players[0].name, players[0].score);
    return 0;
}