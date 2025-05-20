//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLAYERS 5
#define MAX_STRING_LENGTH 100

// Function prototypes
bool isPalindrome(const char *str);
void toLowerCase(char *str);

int main() {
    int numPlayers;
    char players[MAX_PLAYERS][50];
    int scores[MAX_PLAYERS] = {0};
    char input[MAX_STRING_LENGTH];
    
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    // Input player names
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i]);
    }

    // Game loop
    for (int round = 1; round <= 10; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < numPlayers; i++) {
            printf("%s, enter a string (or type 'exit' to end the game): ", players[i]);
            scanf(" %[^\n]", input);
            
            // Check for exit condition
            if (strcmp(input, "exit") == 0) {
                printf("Ending the game. Final scores:\n");
                for (int j = 0; j < numPlayers; j++) {
                    printf("%s: %d\n", players[j], scores[j]);
                }
                return 0;
            }

            // Check if the input is a palindrome
            if (isPalindrome(input)) {
                printf("%s, you entered a palindrome!\n", players[i]);
                scores[i]++;
            } else {
                printf("%s, '%s' is not a palindrome.\n", players[i], input);
            }
        }
    }

    // Display final scores
    printf("\n--- Final Scores ---\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i], scores[i]);
    }

    return 0;
}

// Function to check if a string is a palindrome
bool isPalindrome(const char *str) {
    int len = strlen(str);
    char temp[MAX_STRING_LENGTH];
    
    strcpy(temp, str);
    toLowerCase(temp);
    
    for (int i = 0; i < len / 2; i++) {
        if (temp[i] != temp[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}