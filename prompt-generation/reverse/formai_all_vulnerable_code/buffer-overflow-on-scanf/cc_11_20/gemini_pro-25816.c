//GEMINI-pro DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

char *words[] = {
    "apple", "banana", "orange", "pear", "grape",
    "strawberry", "blueberry", "raspberry", "blackberry", "watermelon",
    "cantaloupe", "honeydew", "mango", "papaya", "pineapple",
    "coconut", "lime", "lemon", "grapefruit", "tangerine",
    "peach", "plum", "nectarine", "apricot", "cherry"
};

struct player {
    char name[MAX_WORD_LENGTH];
    int score;
};

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of players
    int num_players;
    printf("How many players are there? ");
    scanf("%d", &num_players);

    // Create an array of players
    struct player players[num_players];

    // Get the names of the players
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Choose a random word
    int word_index = rand() % (sizeof(words) / sizeof(char *));
    char *word = words[word_index];

    // Print the word
    printf("The word is: %s\n", word);

    // Initialize the scores of the players
    for (int i = 0; i < num_players; i++) {
        players[i].score = 0;
    }

    // Start the game loop
    int current_player = 0;
    while (1) {
        // Get a letter from the current player
        char letter;
        printf("%s, enter a letter: ", players[current_player].name);
        scanf(" %c", &letter);

        // Check if the letter is in the word
        int found = 0;
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == letter) {
                found = 1;
                players[current_player].score++;
            }
        }

        // Print the updated scores of the players
        for (int i = 0; i < num_players; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }

        // Check if the word has been completed
        int completed = 1;
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] != '_') {
                completed = 0;
            }
        }

        // If the word has been completed, end the game
        if (completed) {
            printf("Congratulations, %s! You have completed the word!\n", players[current_player].name);
            break;
        }

        // Move on to the next player
        current_player++;
        if (current_player >= num_players) {
            current_player = 0;
        }
    }

    return 0;
}