//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLAYERS 5
#define MAX_URL_LENGTH 2048

// Function to sanitize the URL by encoding unsafe characters
void sanitize_url(const char *input, char *output) {
    const char *unsafe_chars = " <>\"#%{}|\\^~[]`\n";
    char *current = output;
    while (*input) {
        if (strchr(unsafe_chars, *input)) {
            sprintf(current, "%%%02X", (unsigned char)*input);
            current += 3;  // Move pointer ahead by 3 characters
        } else {
            *current++ = *input;  // Copy character as is
        }
        input++;
    }
    *current = '\0';  // Null-terminate the string
}

// Function to handle a single player's URL input
void player_input(int player_number) {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    printf("Player %d, enter your URL: ", player_number);
    if (fgets(url, sizeof(url), stdin) != NULL) {
        url[strcspn(url, "\n")] = 0;  // Remove newline character
        sanitize_url(url, sanitized_url);
        printf("Sanitized URL for Player %d: %s\n", player_number, sanitized_url);
    } else {
        printf("Failed to read input for Player %d.\n", player_number);
    }
}

int main() {
    int player_count;

    printf("Welcome to the URL Sanitizer Game!\n");
    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    getchar();  // Consume the newline character after the number input

    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players! Please restart the game.\n");
        return 1;
    }

    // Loop through each player
    for (int i = 1; i <= player_count; i++) {
        player_input(i);
    }

    printf("All players have submitted their URLs. Thank you for playing!\n");
    return 0;
}