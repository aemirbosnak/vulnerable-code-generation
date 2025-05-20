//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int generateRandomNumber(int min, int max);
int guessTheNumber(int number);

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int min = 1;
    int max = 100;
    int number = generateRandomNumber(min, max);
    int guess;
    int attempts = 0;
    
    printf("Welcome to Sherlock Holmes' Number Guessing Game!\n");
    printf("I have chosen a number between %d and %d. Can you guess it?\n", min, max);
    
    while (attempts < 10 && guess!= number) {
        guess = guessTheNumber(number);
        attempts++;
        
        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        }
    }
    
    if (guess == number) {
        printf("Congratulations! You have correctly guessed the number in %d attempts.\n", attempts);
    } else {
        printf("Sorry, you have run out of attempts. The correct number was %d.\n", number);
    }
    
    return 0;
}

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int guessTheNumber(int number) {
    int guess;
    
    printf("Enter your guess: ");
    scanf("%d", &guess);
    
    return guess;
}