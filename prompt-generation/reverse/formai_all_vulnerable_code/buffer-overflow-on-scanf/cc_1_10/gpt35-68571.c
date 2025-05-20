//FormAI DATASET v1.0 Category: Educational ; Style: artistic
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

int main() { 
    char colors[] = {'R', 'G', 'B', 'Y', 'O', 'M', 'C', 'W'}; // array of colors 
    int colorCount = sizeof(colors)/sizeof(char); // number of colors in the array
    int guessCount = 0; // set guess count to 0
    int maxGuesses = 10; // maximum number of guesses allowed
    int guessIncorrect = 1; // set guessIncorrect to true
    char answer[4]; // array to store the answer
    
    srand(time(NULL)); // seed random number generator
    for(int i = 0; i < 4; i++) { // generate the answer
        int randomIndex = rand()%colorCount; // pick a random color from the array
        answer[i] = colors[randomIndex]; // assign the color to the answer
    }

    printf("**MASTERMIND GAME**\n"); // print the title
    printf("Guess the 4 color code (select from RGBYOMCW) in less than 10 tries!\n\n"); // print instructions

    // loop while guesses are incorrect and less than max guesses
    while(guessIncorrect && guessCount < maxGuesses) { 
        char guess[4]; // array to store the guess
        printf("%d. Enter your guess: ", guessCount+1); // prompt for guess
        scanf("%s", guess); // read in the guess
        
        int correctCount = 0; // set correctCount to 0
        int incorrectCount = 0; // set incorrectCount to 0
        // loop through each color in the guess
        for(int i = 0; i < 4; i++) { 
            if(guess[i] == answer[i]) { // if the color is in the correct position
                correctCount++; // increment correctCount
            } else { // if the color is not in the correct position
                for(int j = 0; j < 4; j++) { // loop through each color in the answer
                    if(guess[i] == answer[j]) { // if the color is in the answer
                        incorrectCount++; // increment incorrectCount
                        break; // break out of the loop
                    }
                }
            }
        }

        // print the result of the guess
        printf("%d correct, %d incorrect\n\n", correctCount, incorrectCount); 
        guessCount++; // increment guess count
        if(correctCount == 4) { // if the guess is correct
            guessIncorrect = 0; // set guessIncorrect to false
        }
    }

    // print the final result
    if(guessIncorrect) { // if the guess was incorrect
        printf("Sorry, you ran out of guesses! The answer was %c%c%c%c.\n", answer[0], answer[1], answer[2], answer[3]); 
    } else { // if the guess was correct
        printf("Congratulations! You guessed the code in %d tries!\n", guessCount); 
    }
    
    return 0; // end the program
}