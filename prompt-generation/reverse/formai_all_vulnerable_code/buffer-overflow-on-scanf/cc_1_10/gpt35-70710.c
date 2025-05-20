//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_PLAYERS 10
#define MAX_MESSAGE_LENGTH 100

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    int sentiment_score;
} Message;

typedef struct {
    char name[20];
    int num_messages;
    Message messages[MAX_MESSAGE_LENGTH];
} Player;

int get_sentiment_score(char *message) {
    /* This is where the sentiment analysis algorithm would go */
    /* For the purposes of this example, let's just return a random score */
    return rand() % 101;
}

void print_message(Message message) {
    printf("%s (Sentiment Score: %d)\n", message.message, message.sentiment_score);
}

void print_player_messages(Player player) {
    int i;
    for (i = 0; i < player.num_messages; i++) {
        print_message(player.messages[i]);
    }
}

int main() {
    int num_players, i, j;
    Player players[MAX_NUM_PLAYERS];

    /* Get number of players and their names */
    printf("Enter number of players (up to %d): ", MAX_NUM_PLAYERS);
    scanf("%d", &num_players);
    for (i = 0; i < num_players; i++) {
        printf("Enter name of Player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].num_messages = 0;
    }

    /* Get messages from players and calculate sentiment score */
    int round_num;
    char input[MAX_MESSAGE_LENGTH];
    for (round_num = 1; round_num <= 3; round_num++) { /* Three rounds */
        printf("ROUND %d\n", round_num);
        for (i = 0; i < num_players; i++) {
            for (j = 0; j < num_players; j++) {
                if (i != j) { /* Don't allow a player to send a message to themselves */
                    printf("%s, enter message for %s: ", players[i].name, players[j].name);
                    scanf("%s", input);

                    /* Add message to other player's messages and calculate sentiment score */
                    Message new_message;
                    strcpy(new_message.message, input);
                    new_message.sentiment_score = get_sentiment_score(input);
                    players[j].messages[players[j].num_messages] = new_message;
                    players[j].num_messages++;
                }
            }
        }

        /* Print all messages for all players */
        printf("Messages for each player:\n");
        for (i = 0; i < num_players; i++) {
            printf("%s:\n", players[i].name);
            print_player_messages(players[i]);
            printf("\n");
            players[i].num_messages = 0; /* Clear messages for next round */
        }
    }

    return 0;
}