//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PLAYERS 2
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int score;
} Player;

void print_scoreboard(Player players[], int num_players) {
    printf("Scoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players = 0;
    char input[100];

    // Initialize players
    players[0].name[0] = '\0';
    players[0].score = 0;
    players[1].name[0] = '\0';
    players[1].score = 0;

    while (num_players < MAX_PLAYERS) {
        printf("Enter player name: ");
        scanf("%s", input);
        strcpy(players[num_players].name, input);
        num_players++;
    }

    int num_rounds = 0;
    while (num_rounds < MAX_ROUNDS) {
        int question_type = rand() % 3;
        int correct_answer = rand() % 10 + 1;
        int player_index = rand() % num_players;

        printf("Round %d question for %s: ", num_rounds + 1, players[player_index].name);

        switch (question_type) {
            case 0:
                printf("What is %d + %d? ", rand() % 10 + 1, rand() % 10 + 1);
                break;
            case 1:
                printf("What is %d - %d? ", rand() % 10 + 1, rand() % 10 + 1);
                break;
            case 2:
                printf("What is %d * %d? ", rand() % 10 + 1, rand() % 10 + 1);
                break;
        }

        char answer[100];
        scanf("%s", answer);

        int user_answer = atoi(answer);

        if (user_answer == correct_answer) {
            printf("Correct!\n");
            players[player_index].score++;
        } else {
            printf("Incorrect, the correct answer was %d.\n", correct_answer);
        }

        num_rounds++;
    }

    print_scoreboard(players, num_players);

    return 0;
}