//MISTRAL-7B DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

void print_menu();
int generate_random_number();
int get_user_guess();
int check_guess(int secret_number, int user_guess);

int main() {
    int secret_number = generate_random_number();
    int user_guess;
    int guess_count = 0;

    print_menu();

    while (1) {
        user_guess = get_user_guess();

        if (user_guess == -1) {
            printf("Quitting the game...\n");
            break;
        }

        guess_count++;

        int result = check_guess(secret_number, user_guess);

        switch (result) {
            case 0:
                printf("Congratulations! You guessed the number (%d) correctly.\n", secret_number);
                break;
            case 1:
                printf("Incorrect guess. Try again.\n");
                break;
            case 2:
                printf("Your guess is too high. Try again.\n");
                break;
            case 3:
                printf("Your guess is too low. Try again.\n");
                break;
        }

        print_menu();
    }

    return 0;
}

void print_menu() {
    printf("\nNumber Guessing Game\n");
    printf("----------------------\n");
    printf("Enter your guess: ");
}

int generate_random_number() {
    srand(time(NULL));
    return rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

int get_user_guess() {
    int guess;
    scanf("%d", &guess);

    if (feof(stdin)) {
        printf("Error reading input.\n");
        return -1;
    }

    return guess;
}

int check_guess(int secret_number, int user_guess) {
    if (secret_number < user_guess) {
        return 3;
    } else if (secret_number > user_guess) {
        return 2;
    } else {
        return 0;
    }
}