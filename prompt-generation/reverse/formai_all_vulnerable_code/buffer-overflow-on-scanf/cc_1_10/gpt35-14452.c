//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYER 5
#define MAX_SENTIMENT_LEN 100

typedef struct Player {
    char name[20];
    int score;
} Player;

void analyze_sentiment(char* sentiment, Player* players, int num_players) {
    char* positive_words[] = {"love", "happy", "amazing", "fantastic", "great"};
    char* negative_words[] = {"hate", "sad", "terrible", "awful", "horrible"};
    int positive_score = 0;
    int negative_score = 0;

    // Calculate sentiment score
    for (int i = 0; i < 5; i++) {
        if (strstr(sentiment, positive_words[i]) != NULL) {
            positive_score++;
        }
        if (strstr(sentiment, negative_words[i]) != NULL) {
            negative_score++;
        }
    }

    // Update player scores
    for (int i = 0; i < num_players; i++) {
        if (positive_score > negative_score) {
            players[i].score += 10;
        } else if (negative_score > positive_score) {
            players[i].score -= 5;
        }
    }
}

int main() {
    Player players[MAX_PLAYER];
    int num_players;
    char player_name[20];
    char sentiment[MAX_SENTIMENT_LEN];

    // Get number of players
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    // Get player names
    for (int i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", player_name);
        strcpy(players[i].name, player_name);
        players[i].score = 0;
    }

    // Game loop
    printf("Enter a sentiment: ");
    scanf(" %[^\n]s", sentiment);
    analyze_sentiment(sentiment, players, num_players);

    // Print player scores
    for (int i = 0; i < num_players; i++) {
        printf("%s's score: %d\n", players[i].name, players[i].score);
    }

    return 0;
}