//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Define the ASCII art characters
const char* asciiChars[] = {
    "  ,------------------------,   \n",
    " |                          |  \n",
    " |                          |  \n",
    " |                          |  \n",
    " |                          |  \n",
    " |                          |  \n",
    "  `------------------------'   \n"
};

int main() {
    char input[256];
    int playerCount = 0;
    int players[10]; // Maximum of 10 players
    
    // Get the number of players
    printf("Enter the number of players: ");
    scanf("%d", &playerCount);
    
    // Get the names of the players and store their IDs
    for (int i = 0; i < playerCount; i++) {
        char playerName[256];
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", playerName);
        players[i] = i;
        printf("%s has joined the game!\n", playerName);
    }
    
    // Main multiplayer loop
    while (1) {
        // Get the input from each player
        for (int i = 0; i < playerCount; i++) {
            char playerName[256];
            sprintf(playerName, "Player %d", i+1);
            printf("%s, enter your input: ", playerName);
            scanf("%s", input);
            
            // Convert the input to ASCII art
            for (int j = 0; j < strlen(input); j++) {
                if ((int)input[j] >= 97 && (int)input[j] <= 122) {
                    printf("%s", asciiChars[(int)input[j]-97]);
                } else {
                    printf("\n");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}