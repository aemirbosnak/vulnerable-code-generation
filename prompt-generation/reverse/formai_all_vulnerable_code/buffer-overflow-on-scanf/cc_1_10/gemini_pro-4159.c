//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_TEXT_LEN 1000

// Player struct
typedef struct {
    char name[20];
    int score;
    char text[MAX_TEXT_LEN];
    int text_len;
} Player;

// Function to summarize text using a sliding window approach
char *summarize_text(char *text, int len) {
    char *summary = malloc(len / 2 + 1);  // Allocate memory for summary
    int window_size = 5;                  // Sliding window size
    int max_score = 0;                    // Max score for a window
    int start_idx = 0;                   // Start index of the window
    int end_idx = start_idx + window_size; // End index of the window

    // Iterate over the text using a sliding window
    while (end_idx <= len) {
        int score = 0;  // Score for the current window

        // Calculate the score for the current window
        for (int i = start_idx; i < end_idx; i++) {
            score += text[i] - 'a' + 1;  // Add the score of each character
        }

        // If the current score is higher than the max score, update the summary
        if (score > max_score) {
            max_score = score;
            strncpy(summary, text + start_idx, window_size);  // Copy the window to the summary
            summary[window_size] = '\0';  // Null-terminate the summary
        }

        // Shift the window by one character
        start_idx++;
        end_idx++;
    }

    return summary;
}

// Main function
int main() {
    // Initialize players
    Player players[MAX_PLAYERS];
    int num_players;

    // Get the number of players
    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    // Get the text and name for each player
    for (int i = 0; i < num_players; i++) {
        printf("Player %d, enter your name: ", i + 1);
        scanf("%s", players[i].name);

        printf("Player %s, enter your text: ", players[i].name);
        scanf("%s", players[i].text);

        players[i].text_len = strlen(players[i].text);
    }

    // Summarize the text for each player
    char *summaries[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        summaries[i] = summarize_text(players[i].text, players[i].text_len);
    }

    // Print the summaries for each player
    for (int i = 0; i < num_players; i++) {
        printf("Player %s, your summary: %s\n", players[i].name, summaries[i]);
    }

    return 0;
}