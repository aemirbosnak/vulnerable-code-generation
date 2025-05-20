//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize game
void init_game() {
    system("clear");
    printf("Welcome to the Game of Guess!\n");
    printf("Guess a number between 1 and 100.\n");
    srand(time(NULL));
    int num = rand() % 100 + 1; // Generate random number
    printf("The number to guess is: %d\n", num);
    return;
}

// Function to check if the guessed number is correct
int check_guess(int guess, int num) {
    if (guess == num) {
        printf("Congratulations! You guessed the number correctly.\n");
        return 1;
    } else if (guess < num) {
        printf("Too low. Guess again.\n");
    } else {
        printf("Too high. Guess again.\n");
    }
    return 0;
}

// Function to play the game
int play_game() {
    int guess, num;
    init_game();
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guess = abs(guess); // Make sure guess is positive
        if (check_guess(guess, num)) {
            break;
        }
    }
    return 0;
}

int main() {
    int choice;
    while (1) {
        system("clear");
        printf("Game of Guess\n");
        printf("1. Play game\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                play_game();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}