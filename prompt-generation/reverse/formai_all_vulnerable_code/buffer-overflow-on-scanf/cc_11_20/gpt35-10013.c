//FormAI DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int players;
    int i, j;
    srand(time(NULL));
    
    // Ask for number of players
    printf("How many players? ");
    scanf("%d", &players);
    
    // Allocate memory for player information
    char **names = (char**)malloc(players * sizeof(char*));
    int *scores = (int*)calloc(players, sizeof(int));
    
    // Randomize player names
    for(i = 0; i < players; i++) {
        names[i] = (char*)malloc(20 * sizeof(char));
        for(j = 0; j < 20; j++) {
            names[i][j] = rand() % 26 + 'a';
        }
    }
    
    // Start game loop
    while(1) {
        for(i = 0; i < players; i++) {
            // Generate random math exercise
            int a = rand() % 10;
            int b = rand() % 10;
            int operator = rand() % 4;
            int answer, guess;
            
            switch(operator) {
                case 0:
                    printf("%s: %d + %d = ", names[i], a, b);
                    answer = a + b;
                    break;
                case 1:
                    printf("%s: %d - %d = ", names[i], a, b);
                    answer = a - b;
                    break;
                case 2:
                    printf("%s: %d * %d = ", names[i], a, b);
                    answer = a * b;
                    break;
                case 3:
                    printf("%s: %d / %d = ", names[i], a, b);
                    answer = a / b;
                    break;
            }
            
            // Get player's guess
            scanf("%d", &guess);
            
            // Compare guess to answer
            if(guess == answer) {
                printf("Correct!\n");
                scores[i]++;
            }
            else {
                printf("Wrong!\n");
            }
        }
        
        // Check if game is over
        int game_over = 0;
        for(i = 0; i < players; i++) {
            if(scores[i] >= 10) {
                game_over = 1;
                break;
            }
        }
        
        // If game is over, print results and ask to play again
        if(game_over) {
            printf("Game over!\n");
            for(i = 0; i < players; i++) {
                printf("%s: %d\n", names[i], scores[i]);
            }
            printf("Play again? (y/n)");
            
            char answer;
            scanf(" %c", &answer);
            if(answer == 'n') {
                break;
            }
            else {
                // Reset scores
                for(i = 0; i < players; i++) {
                    scores[i] = 0;
                }
            }
        }
    }
    
    // Free memory
    for(i = 0; i < players; i++) {
        free(names[i]);
    }
    free(names);
    free(scores);
    
    return 0;
}