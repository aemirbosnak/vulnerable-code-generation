//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    int number = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess;
    int attempts = 1;

    printf("Welcome to the Great Guessing Game! I'm thinking of a number between 1 and 100. Can you guess it?\n");

    // loop until the user guesses correctly or has used up all their attempts
    while (attempts <= 5) {
        printf("Attempt #%d: ", attempts);
        scanf("%d", &guess);

        if (guess == number) {
            printf("Congratulations! You guessed it in %d attempts.\n", attempts);
            return 0;
        } else if (guess < number) {
            printf("Too low! ");
        } else {
            printf("Too high! ");
        }

        int hints[] = {1, 2, 3, 4, 5, 6};
        int hint = hints[rand() % 6];       
        
        if(hint == 1) {
            printf("Here's a hint: the number is divisible by %d.\n", rand() % 10 + 1);
        } else if (hint == 2) {
            printf("Here's a hint: the number is between %d and %d.\n", number - rand() % 10, number + rand() % 10);
        } else if (hint == 3) {
            printf("Here's a hint: the number has %d digits.\n", (int) log10(number) + 1);
        } else if (hint == 4) {
            printf("Here's a hint: the sum of the digits in the number is %d.\n", sumDigits(number));
        } else if (hint == 5) {
            printf("Here's a hint: the number is a %s number.\n", isEven(number) ? "even" : "odd");
        } else {
            printf("Here's a hint: the number is %s.\n", isPrime(number) ? "prime" : "not prime");
        }

        attempts++;
    }

    printf("Sorry, you didn't guess it in time. The number was %d.\n", number);

    return 0;
}

int sumDigits(int n) {
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int isEven(int n) {
    return n % 2 == 0;
}

int isPrime(int n) {
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}