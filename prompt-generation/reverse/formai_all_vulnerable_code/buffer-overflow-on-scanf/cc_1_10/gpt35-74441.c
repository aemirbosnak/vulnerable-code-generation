//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_NAME_LEN 20
#define MAX_GUESSES 10

// Function to calculate Levenshtein Distance between two strings
int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    int dp[len1 + 1][len2 + 1];
    
    for(int i = 0; i <= len1; i++)
        dp[i][0] = i;
        
    for(int i = 0; i <= len2; i++)
        dp[0][i] = i;
        
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
    }
    
    return dp[len1][len2];
}

int min(int a, int b, int c) {
    if(a <= b && a <= c)
        return a;
    if(b <= a && b <= c)
        return b;
    return c;
}

int main() {
    char players[MAX_PLAYERS][MAX_NAME_LEN];
    int scores[MAX_PLAYERS] = {0};
    int numPlayers, guessesLeft, currentPlayer = 0, targetScore, winningPlayer;
    char targetWord[MAX_NAME_LEN], guessWord[MAX_NAME_LEN];
    printf("Welcome to the Levenshtein Distance Game!\n");
    printf("How many players will be playing? (Max 5): ");
    scanf("%d", &numPlayers);
    
    // Input names of players
    for(int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i]);
    }
    
    printf("Maximum score to win? (Minimum 10): ");
    scanf("%d", &targetScore);
    if(targetScore < 10)
        targetScore = 10;
    
    // Game loop
    while(1) {
        printf("\n\nNew round!\n");
        printf("\n%s's turn to play.", players[currentPlayer]);
        printf("\nEnter target word (Max %d chars): ", MAX_NAME_LEN);
        scanf("%s", targetWord);
        
        // Guess loop
        guessesLeft = MAX_GUESSES;
        while(guessesLeft > 0) {
            printf("\nGuess word (Max %d chars, %d guesses left): ", MAX_NAME_LEN, guessesLeft);
            scanf("%s", guessWord);
            
            int dist = levenshteinDistance(targetWord, guessWord);
            if(dist == 0) {
                // Player guessed correctly
                scores[currentPlayer]++;
                printf("\nCongratulations! %s guessed correctly!", players[currentPlayer]);
                break;
            }
            else {
                printf("\nNot quite! The Levenshtein Distance between target and guess is %d.", dist);
                guessesLeft--;
            }
        }
        
        if(guessesLeft == 0) {
            // Player used up all their guesses
            printf("\n\nAll guesses used up! Better luck next time!");
        }
        
        // Check if any player has reached target score
        int maxScore = -1;
        for(int i = 0; i < numPlayers; i++) {
            if(scores[i] > maxScore) {
                maxScore = scores[i];
                winningPlayer = i;
            }
        }
        if(maxScore >= targetScore) {
            // Some player has reached target score
            printf("\n%s has won with a score of %d! Congratulations!", players[winningPlayer], maxScore);
            break;
        }
        
        // Move on to next player
        currentPlayer = (currentPlayer + 1) % numPlayers;
    }
    return 0;
}