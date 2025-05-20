//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()

int main() {
    // seed for random number generator
    srand(time(NULL));
    
    // initialize player score
    int score = 0;
    
    // welcome the player to the game
    printf("Welcome to the Grateful Game!\n");
    printf("Your goal is to collect as many grateful points as possible.\n\n");
    
    // game loop
    while (1) {
        // generate a random grateful event
        int event = rand() % 3; // 0 = compliment, 1 = gift, 2 = thank you
        
        // display the event and add to score
        switch (event) {
            case 0:
                printf("You received a compliment! +1 grateful point.\n");
                score++;
                break;
            case 1:
                printf("You received a gift! +2 grateful points.\n");
                score += 2;
                break;
            case 2:
                printf("You received a thank you note! +3 grateful points.\n");
                score += 3;
                break;
        }
        
        // display current score and prompt for next event
        printf("Current score: %d\n", score);
        printf("What would you like to do next?\n");
        printf("1. Keep playing\n");
        printf("2. Quit and see final score\n");
        
        // get player's choice
        int choice;
        scanf("%d", &choice);
        
        // check if player wants to quit
        if (choice == 2) {
            break;
        }
    }
    
    // display final score
    printf("Final score: %d\n", score);
    
    return 0;
}