//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 10

void print_message(char* message) {
    printf("\n%s\n", message);
}

int generate_random_number() {
    int num;
    srand(time(NULL));
    num = rand() % (MAX - MIN + 1) + MIN;
    return num;
}

void print_array(char* message, int array[], int size) {
    printf("\n%s:\n", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int user_number, computer_number, attempts = 0;
    int user_guesses[5];

    computer_number = generate_random_number();

    print_message("Hello, welcome to the Guess the Number game!");
    print_message("I have generated a random number between 1 and 10.");
    print_message("You have 5 attempts to guess the number.");

    while (attempts < 5) {
        print_message("Attempt: ");
        scanf("%d", &user_number);

        attempts++;

        if (user_number > computer_number) {
            print_message("Oops! Your number is greater than the computer's number.");
            user_guesses[attempts - 1] = user_number;
        } else if (user_number < computer_number) {
            print_message("Oops! Your number is less than the computer's number.");
            user_guesses[attempts - 1] = user_number;
        } else {
            print_message("Congratulations! You guessed the number in attempt: ");
            printf("%d", attempts);
            print_message("Here are your previous guesses:");
            print_array("Your guesses: ", user_guesses, attempts);
            break;
        }
    }

    if (attempts == 5) {
        print_message("Game over! The computer's number was: ");
        print_message("Your previous guesses:");
        print_array("Your guesses: ", user_guesses, attempts);
    }

    return 0;
}