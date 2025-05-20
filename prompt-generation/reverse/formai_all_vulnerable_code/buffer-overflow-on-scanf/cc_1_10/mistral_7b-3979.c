//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

int reveal_number(int number, int guess);
int ask_user_for_guess();

int main() {
    int number, guess;
    srand(time(NULL));

    number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

    printf("Welcome to the GuessNumber game!\n");
    printf("I have chosen a random number between 1 and 100.\n");
    printf("Can you guess it?\n");

    guess = ask_user_for_guess();

    while (guess != number) {
        number = reveal_number(number, guess);
        guess = ask_user_for_guess();
    }

    printf("Congratulations! You have guessed the number: %d\n", number);

    return 0;
}

int ask_user_for_guess() {
    int guess;

    scanf("%d", &guess);

    return guess;
}

int reveal_number(int number, int guess) {
    int revealed_number = number;

    if (guess > number) {
        printf("Your guess is too high. The number has %d digits and the last digit is %d.\n", count_digits(number), number % 10);
        revealed_number = number / 10;
        number = revealed_number;
    } else if (guess < number) {
        printf("Your guess is too low. The number has %d digits and the last digit is %d.\n", count_digits(number), number % 10);
        revealed_number = number;
        number = revealed_number / 100;
    }

    return revealed_number;
}

int count_digits(int number) {
    int count = 0;

    while (number != 0) {
        number /= 10;
        count++;
    }

    return count;
}