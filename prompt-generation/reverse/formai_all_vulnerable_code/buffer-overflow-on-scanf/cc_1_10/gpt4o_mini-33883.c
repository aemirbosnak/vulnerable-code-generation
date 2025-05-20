//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int sentimentScore; // Positive: >0, Negative: <0, Neutral: 0
} Player;

void initPlayers(Player players[], int count);
void analyzeMessage(const char *message, Player *player);
void displayScore(Player players[], int count);
void toLowerCase(char *str);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    char playerName[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int i;

    printf("Welcome to the Multiplayer Sentiment Analysis Game!\n");
    
    // Get the number of players
    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount > MAX_PLAYERS || playerCount <= 0) {
        printf("Invalid number of players!\n");
        return 1;
    }
    
    // Initialize players
    initPlayers(players, playerCount);
    
    // Game loop
    while (1) {
        for (i = 0; i < playerCount; i++) {
            printf("%s, enter a message (or type 'exit' to quit): ", players[i].name);
            getchar(); // Consume newline character
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; // Remove newline

            if (strcmp(message, "exit") == 0) {
                printf("Exiting game. Final scores:\n");
                displayScore(players, playerCount);
                return 0;
            }

            analyzeMessage(message, &players[i]);
        }
    }

    return 0;
}

void initPlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].sentimentScore = 0; // Initialize score to zero
    }
}

void analyzeMessage(const char *message, Player *player) {
    const char *positiveWords[] = {"good", "happy", "great", "excellent", "love", NULL};
    const char *negativeWords[] = {"bad", "sad", "terrible", "hate", "angry", NULL};
    int score = 0;
    
    char *msgCopy = strdup(message);
    toLowerCase(msgCopy);

    // Count positive words
    for (int i = 0; positiveWords[i] != NULL; i++) {
        if (strstr(msgCopy, positiveWords[i]) != NULL) {
            score++;
        }
    }

    // Count negative words
    for (int i = 0; negativeWords[i] != NULL; i++) {
        if (strstr(msgCopy, negativeWords[i]) != NULL) {
            score--;
        }
    }

    // Update player's sentiment score
    player->sentimentScore += score;

    if (score > 0) {
        printf("%s, your message was positive!\n", player->name);
    } else if (score < 0) {
        printf("%s, your message was negative!\n", player->name);
    } else {
        printf("%s, your message was neutral!\n", player->name);
    }

    free(msgCopy);
}

void displayScore(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Player %s: Sentiment Score = %d\n", players[i].name, players[i].sentimentScore);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}