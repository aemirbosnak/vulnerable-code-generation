//FormAI DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer[4];  // array to hold the secret code
    int guess[4];   // array to hold the user's guess
    int num_guesses = 0;    // counter for number of guesses
    int correct_color = 0;  // counter for number of correct colors in the correct position
    int correct_spot = 0;   // counter for number of correct colors in incorrect positions
    
    // initialize random number generator
    srand(time(0));
    
    // generate secret code
    for(int i = 0; i < 4; i++) {
        answer[i] = rand() % 6 + 1;
    }
    
    // loop until user guesses code correctly or reaches 10 guesses
    while(num_guesses < 10) {
        // get user's guess
        printf("\nEnter four colors (1-6) separated by spaces: ");
        scanf("%d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3]);
        
        // check if guess is correct
        if(guess[0] == answer[0] && guess[1] == answer[1] && guess[2] == answer[2] && guess[3] == answer[3]) {
            printf("\nYou guessed the code in %d tries!", num_guesses+1);
            return 0;
        }
        
        // check for correct color in correct position
        for(int i = 0; i < 4; i++) {
            if(guess[i] == answer[i]) {
                correct_color++;
                continue;
            }
        }
        
        // check for correct color in incorrect position
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(guess[i] == answer[j] && i != j) {
                    correct_spot++;
                    break;
                }
            }
        }
        
        // print feedback to user
        printf("\nCorrect Color: %d\nCorrect Spot: %d\n", correct_color, correct_spot);
        
        // reset counters for next guess
        correct_color = 0;
        correct_spot = 0;
        num_guesses++;
    }
    
    // if user reaches 10 guesses, print out the answer
    printf("\nYou were unable to guess the code in 10 tries. The code was: %d %d %d %d\n", answer[0], answer[1], answer[2], answer[3]);
    
    return 0;
}