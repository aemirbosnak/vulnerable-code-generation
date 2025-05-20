//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int score = 0;
    int count = 0;
    char guess;
    int num_guesses;
    
    srand(time(NULL));
    int secret_num = rand() % 100 + 1;
    
    while (count < 10) {
        printf("Guess a number between 1 and 100: ");
        scanf(" %c", &guess); // read user's guess
        
        if (guess < '0' || guess > '9') { // ensure the guess is a number
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        
        int guess_num = guess - '0'; // convert the guess to integer
        
        if (guess_num < 1 || guess_num > 100) { // ensure the guess is within the range
            printf("Invalid input! Please enter a number between 1 and 100.\n");
            continue;
        }
        
        num_guesses++; // increment number of guesses
        
        if (guess_num == secret_num) { // correct guess
            score += 10; // add points to score
            count = 0; // reset the number of failed attempts
            printf("Congratulations! You've guessed the secret number in %d attempts.\n", num_guesses);
            printf("Your current score is %d.\n", score);
            secret_num = rand() % 100 + 1; // generate a new secret number for the next round
        } else if (guess_num < secret_num) { // guess too low
            printf("Too low! Try again.\n");
            count++; // increment number of failed attempts
        } else { // guess too high
            printf("Too high! Try again.\n");
            count++; // increment number of failed attempts
        }
        
        if (count == 10) { // game over
            printf("Game over! You've failed to guess the secret number in 10 attempts.\n");
            printf("Your final score is %d.\n", score);
        }
    }
    
    return 0;
}