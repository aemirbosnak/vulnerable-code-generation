//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_QUESTIONS 10

typedef struct {
    char name[20];
    int score;
} Player;

void shuffle(char *array[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    srand(time(0));

    Player players[MAX_PLAYERS];
    char questions[MAX_QUESTIONS][100];
    int num_players, num_questions, correct_answers[MAX_PLAYERS];

    printf("Enter the number of players (1-4): ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    printf("Enter the number of questions (1-10): ");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i]);
    }

    shuffle(questions, num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i]);
        for (int j = 0; j < num_players; j++) {
            printf("Player %d's answer: ", j + 1);
            scanf("%s", players[j].name);

            if (strcmp(players[j].name, questions[i]) == 0) {
                players[j].score++;
            }
        }
    }

    for (int i = 0; i < num_players; i++) {
        printf("Player %d's score: %d\n", i + 1, players[i].score);
    }

    return 0;
}