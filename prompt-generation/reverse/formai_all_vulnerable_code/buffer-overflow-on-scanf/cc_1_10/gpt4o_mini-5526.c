//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define MAX_TRIES 3

void to_binary(int num, char *binary) {
    int idx = 0;
    if (num == 0) {
        binary[idx++] = '0';
    } else {
        while (num > 0) {
            binary[idx++] = (num % 2) + '0';
            num /= 2;
        }
    }
    // Reverse the binary representation
    for (int i = 0; i < idx / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[idx - 1 - i];
        binary[idx - 1 - i] = temp;
    }
    binary[idx] = '\0'; // Null-terminate the string
}

int main() {
    int numPlayers;
    int scores[MAX_PLAYERS] = {0};
    char playerNames[MAX_PLAYERS][20];
    
    printf("Welcome to the Multiplayer Binary Converter Game!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    // Register player names
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", playerNames[i]);
    }
    
    // Game Loop
    for (int round = 1; round <= MAX_TRIES; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < numPlayers; i++) {
            int number;
            char binary[32];
            printf("%s's turn!\n", playerNames[i]);
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            
            to_binary(number, binary);
            printf("Convert the number %d to binary: ", number);
            char answer[32];
            scanf("%s", answer);
            
            if (strcmp(answer, binary) == 0) {
                printf("Correct! You gain a point.\n");
                scores[i]++;
            } else {
                printf("Incorrect! The correct answer is %s.\n", binary);
            }
        }
    }
    
    // Final Scores
    printf("\n--- Final Scores ---\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d points\n", playerNames[i], scores[i]);
    }
    
    // Determine the winner
    int maxScore = -1;
    int winnerIndex = -1;
    for (int i = 0; i < numPlayers; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            winnerIndex = i;
        }
    }
    
    printf("The winner is %s with %d points!\n", playerNames[winnerIndex], maxScore);
    
    return 0;
}