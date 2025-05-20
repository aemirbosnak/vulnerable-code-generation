//Falcon-180B DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 100
#define MAX_SCORE 1000

typedef struct {
    char name[50];
    int score;
} Player;

void generateRandomName(char* name) {
    const char* chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 10; i++) {
        name[i] = chars[rand() % strlen(chars)];
    }
    name[10] = '\0';
}

void shuffleArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void displayLeaderboard(Player players[], int numPlayers) {
    printf("Leaderboard:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%d. %s - %d points\n", i+1, players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));

    int numPlayers;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &numPlayers);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        generateRandomName(players[i].name);
        players[i].score = 0;
    }

    int numRounds;
    printf("Enter the number of rounds (1-100): ");
    scanf("%d", &numRounds);

    int round = 1;
    while (round <= numRounds) {
        int correctAnswers = 0;
        for (int i = 0; i < numPlayers; i++) {
            char answer[50];
            printf("Player %s, enter your answer:\n", players[i].name);
            scanf("%s", answer);

            if (strcmp(answer, "correct answer") == 0) {
                players[i].score++;
                correctAnswers++;
            }
        }

        if (correctAnswers == 0) {
            printf("No one got the correct answer in round %d.\n", round);
        } else {
            printf("In round %d, %d player(s) got the correct answer.\n", round, correctAnswers);
        }

        round++;
    }

    displayLeaderboard(players, numPlayers);

    return 0;
}