//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 5
#define MAX_STRING_LENGTH 100

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int left = 0, right = strlen(str) - 1;

    while (left < right) {
        // Ignore non-alphanumeric characters
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;

        // Compare characters (case insensitive)
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int num_players;
    char strings[MAX_PLAYERS][MAX_STRING_LENGTH];

    printf("Welcome to the Multiplayer Palindrome Checker!\n");
    printf("How many players will participate (up to %d)? ", MAX_PLAYERS);
    scanf("%d", &num_players);
    clear_input_buffer(); // Clear the newline character from the buffer

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the program.\n");
        return 1;
    }

    // Input strings from players
    for (int i = 0; i < num_players; i++) {
        printf("Player %d, enter your string: ", i + 1);
        fgets(strings[i], MAX_STRING_LENGTH, stdin);
        // Remove newline character from string if present
        strings[i][strcspn(strings[i], "\n")] = 0; 
    }

    printf("\nChecking for palindromes...\n");

    // Check each player's string
    for (int i = 0; i < num_players; i++) {
        if (is_palindrome(strings[i])) {
            printf("Player %d, your string \"%s\" is a palindrome!\n", i + 1, strings[i]);
        } else {
            printf("Player %d, your string \"%s\" is NOT a palindrome.\n", i + 1, strings[i]);
        }
    }

    printf("\nThank you for playing the Multiplayer Palindrome Checker!\n");

    return 0;
}