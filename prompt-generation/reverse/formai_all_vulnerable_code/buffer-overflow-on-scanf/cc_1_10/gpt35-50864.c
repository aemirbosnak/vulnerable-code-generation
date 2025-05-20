//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_ROUND 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score[MAX_ROUND];
    int totalScore;
} Player;

int calculateWordCount(const char *input) {
    int count = 0;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}

float calculateTypingSpeed(int seconds, const char *input) {
    int wordCount = calculateWordCount(input);
    return ((float)wordCount / (float)seconds) * 60.0;
}

int playRound(Player *player, const char *randomWord) {
    char input[100];
    printf("Type this word: %s\n", randomWord);
    scanf(" %[^\n]", input);
    int elapsedTime = time(NULL) - time(0);
    player->score[MAX_ROUND - 1] = (int)calculateTypingSpeed(elapsedTime, input);
    player->totalScore += player->score[MAX_ROUND - 1];
    printf("%s finished in %d seconds with a score of %d.\n", player->name, elapsedTime, player->score[MAX_ROUND - 1]);
    return player->score[MAX_ROUND - 1];
}

void printLeaderboard(Player players[], int count) {
    printf("%-20s|%-10s|%-10s|%-10s|%-10s\n", "Name", "Round 1", "Round 2", "Round 3", "Total");
    for (int i = 0; i < count; i++) {
        printf("%-20s|%-10d|%-10d|%-10d|%-10d\n", players[i].name, players[i].score[0], players[i].score[1], players[i].score[2], players[i].totalScore);
    }
}

void sortPlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (players[j].totalScore > players[i].totalScore) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    Player players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf(" %[^\n]", players[i].name);
        players[i].totalScore = 0;
        for (int j = 0; j < MAX_ROUND; j++) {
            players[i].score[j] = 0;
        }
    }

    char words[][50] = {"incredible", "fascinating", "impressive", "excellent", "amazing", "fabulous", "fantastic", "outstanding", "splendid", "marvellous"};
    int round = 1;
    while (round <= MAX_ROUND) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < numPlayers; i++) {
            printf("\n%s's turn:\n", players[i].name);
            int index = rand() % 10;
            int score = playRound(&players[i], words[index]);
        }
        round++;
    }

    sortPlayers(players, numPlayers);

    printf("\n\n--- Leaderboard ---\n");
    printLeaderboard(players, numPlayers);

    return 0;
}