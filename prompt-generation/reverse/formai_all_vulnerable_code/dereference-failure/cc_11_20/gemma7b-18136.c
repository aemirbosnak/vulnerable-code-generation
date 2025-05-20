//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct Word {
    char *word;
    int frequency;
};

int main() {
    int numPlayers = 2;
    struct Word **words = (struct Word **)malloc(numPlayers * sizeof(struct Word *));

    for (int i = 0; i < numPlayers; i++) {
        words[i] = (struct Word *)malloc(MAX_WORDS * sizeof(struct Word));
        words[i]->word = (char *)malloc(MAX_WORDS * sizeof(char));
        words[i]->frequency = 0;
    }

    char **messages = (char **)malloc(numPlayers * sizeof(char *));

    for (int i = 0; i < numPlayers; i++) {
        messages[i] = (char *)malloc(1024 * sizeof(char));
    }

    // Game loop
    while (1) {
        // Each player enters a message
        for (int i = 0; i < numPlayers; i++) {
            printf("Player %d: ", i + 1);
            fgets(messages[i], 1024, stdin);
        }

        // Calculate word frequency for each player
        for (int i = 0; i < numPlayers; i++) {
            char *message = messages[i];
            char *word = strtok(message, " ");

            while (word) {
                int found = 0;
                for (int j = 0; j < words[i]->frequency; j++) {
                    if (strcmp(words[i]->word, word) == 0) {
                        words[i]->frequency++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    words[i]->word = strdup(word);
                    words[i]->frequency = 1;
                }
                word = strtok(NULL, " ");
            }
        }

        // Print word frequency for each player
        for (int i = 0; i < numPlayers; i++) {
            printf("Player %d's word frequency:", i + 1);
            for (int j = 0; j < words[i]->frequency; j++) {
                printf(" %s", words[i]->word);
            }
            printf("\n");
        }

        // Check if any player wants to quit
        for (int i = 0; i < numPlayers; i++) {
            printf("Player %d, do you want to quit? (Y/N): ", i + 1);
            char answer;
            scanf(" %c", &answer);

            if (answer == 'Y') {
                // Exit the game
                exit(0);
            }
        }
    }

    return 0;
}