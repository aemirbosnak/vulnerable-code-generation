//FormAI DATASET v1.0 Category: Game ; Style: introspective
/* I am a game program that utilizes loops, conditionals, and arrays to create a unique experience for the user.
I will start by prompting the user to enter their name and welcoming them to the game. */

#include <stdio.h>
#include <string.h>

int main() {
    char name[20]; // create a character array to store the user's name
    int score = 0; // initialize score to 0
    
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("Welcome to the game, %s!\n", name);
    printf("Your current score is %d.\n", score);
    
    int choice; // create a variable to store the user's menu choice
    do {
        printf("1. Play a round\n");
        printf("2. View your current score\n");
        printf("3. Exit game\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // play a round
                printf("Playing a round...\n");
                int result = rand() % 2; // generate a random number (either 0 or 1) to simulate a coin flip
                if(result == 0) { // tails
                    printf("Sorry, it's tails. No points awarded.\n");
                } else { // heads
                    score += 10; // add 10 points to the score
                    printf("Congratulations, it's heads! You earned 10 points.\n");
                }
                break;
            case 2: // view current score
                printf("Your current score is %d.\n", score);
                break;
            case 3: // exit game
                printf("Thanks for playing, %s! Final score: %d.\n", name, score);
                break;
            default: // invalid menu choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while(choice != 3); // keep looping until user chooses to exit
    
    return 0;
}