//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));
    
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    int guess = -1, tries = 0, num_letters = 5, successful_guesses = 0;
    char letters[num_letters];
    
    //Generate random letters
    for(int i = 0; i < num_letters; i++) {
        letters[i] = alphabet[rand() % 26];
    }
    
    printf("Welcome to Guess the Letters!\n");
    printf("I have generated %d random letters, can you guess them all?\n", num_letters);
    
    while(guess != 0) {
        printf("Enter your guess (Press 0 to quit):\n");
        scanf("%d", &guess);
        
        if(guess == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        
        tries++;
        
        for(int i = 0; i < num_letters; i++) {
            if(guess == letters[i]) {
                printf("You guessed letter %c correctly!\n", guess);
                successful_guesses++;
                break;
            }
        }
        
        if(successful_guesses == num_letters) {
            printf("Congratulations! You guessed all the letters!\n");
            break;
        }
        
        printf("You have guessed %d out of %d letters correctly in %d tries.\n", successful_guesses, num_letters, tries);
    }
    
    return 0;
}