//Falcon-180B DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

int main() {
    srand(time(NULL));
    int num_players = rand() % MAX_PLAYERS + 2;
    int scores[MAX_PLAYERS] = {0};
    char names[MAX_PLAYERS][20];

    printf("Welcome to the game!\n");
    printf("Enter the names of the players:\n");
    for (int i = 0; i < num_players; i++) {
        scanf("%s", names[i]);
    }

    printf("The players are: %s, %s, %s, and %s.\n", names[0], names[1], names[2], names[3]);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        int question_type = rand() % 3;
        int question_difficulty = rand() % 3;
        int question_value = rand() % 100 + 1;

        switch (question_type) {
        case 0:
            printf("Round %d question: What is the capital of France?\n", round);
            break;
        case 1:
            printf("Round %d question: Who wrote the book 'To Kill a Mockingbird'?\n", round);
            break;
        case 2:
            printf("Round %d question: What is the highest mountain in the world?\n", round);
            break;
        }

        int correct_answers = 0;
        for (int i = 0; i < num_players; i++) {
            char answer[50];
            scanf("%s", answer);

            if (strcmp(answer, "Paris") == 0 || strcmp(answer, "France") == 0) {
                scores[i] += question_value;
                printf("%s got it right!\n", names[i]);
            } else {
                printf("%s got it wrong.\n", names[i]);
            }
        }
    }

    printf("The game is over. The scores are:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", names[i], scores[i]);
    }

    return 0;
}