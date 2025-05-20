//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MSG_LENGTH 100
#define MAX_PLAYERS 5

int main(void) {
    // initialize variables
    char players[MAX_PLAYERS][MAX_MSG_LENGTH];
    bool isSpam[MAX_PLAYERS] = {false};
    int numPlayers = 0;
    int spamCount = 0;

    // get number of players
    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d\n", &numPlayers);

    // get names of players
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name of player %d: ", i+1);
        fgets(players[i], MAX_MSG_LENGTH, stdin);
        players[i][strcspn(players[i], "\n")] = '\0'; // remove newline character
    }

    // enter chat room loop
    while (true) {
        // get message input from user
        char message[MAX_MSG_LENGTH];
        printf("\nEnter message: ");
        fgets(message, MAX_MSG_LENGTH, stdin);
        message[strcspn(message, "\n")] = '\0';

        if (strlen(message) == 0) {
            // ignore empty messages
            continue;
        }

        // check if message contains spam keywords
        bool isSpamMessage = false;
        char* spamKeywords[] = {"buy", "discount", "click here"};
        int numKeywords = sizeof(spamKeywords) / sizeof(spamKeywords[0]);
        for (int i = 0; i < numKeywords; i++) {
            if (strstr(message, spamKeywords[i]) != NULL) {
                isSpamMessage = true;
                break;
            }
        }

        // assign spam status to player
        for (int i = 0; i < numPlayers; i++) {
            if (strstr(message, players[i]) != NULL) {
                isSpam[i] = isSpamMessage;
                if (isSpamMessage) {
                    spamCount++;
                }
                break;
            }
        }

        // display message and spam status
        printf("Message: %s\n", message);
        for (int i = 0; i < numPlayers; i++) {
            printf("%s is%s spamming\n", players[i], isSpam[i] ? "" : " not");
        }

        // check if spam count is over 50
        if (spamCount > 50) {
            printf("\nSpam count threshold reached!\n");
            break;
        }
    }

    return 0;
}