//FormAI DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
/* Claude Shannon Style C Math Exercise */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 100
int randomNumber() {
    srand(time(NULL));
    return (rand() % 100) + 1;
}

// Function to determine if user input is a prime number
int isPrimeNumber(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i < num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to compute the factorial of a number
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int a = randomNumber();
    int b = randomNumber();

    printf("Welcome to the C Math Exercise!\n\n");
    printf("Let's start with some simple addition.\n");
    printf("What is %d + %d?\n", a, b);

    int input, ans;
    scanf("%d", &input);
    ans = a + b;

    if (input == ans) {
        printf("Great job! Now let's move on to division.\n");
        printf("What is %d / %d (rounded down to the nearest whole number)?\n", a*b, a);
        scanf("%d", &input);
        ans = b;

        if (input == ans) {
            printf("Excellent! Next up is the factorial.\n");
            printf("What is the factorial of %d?\n", b);
            scanf("%d", &input);
            ans = factorial(b);

            if (input == ans) {
                printf("Amazing! Let's finish up with some prime numbers.\n");
                printf("Is %d a prime number (1 for YES, 0 for NO)?\n", a);
                scanf("%d", &input);
                ans = isPrimeNumber(a);

                if (input == ans) {
                    printf("Congratulations! You've completed the C Math Exercise!\n");
                } else {
                    printf("Sorry, %d is not a prime number.\n", a);
                }

            } else {
                printf("Sorry, the factorial of %d is %d.\n", b, ans);
            }

        } else {
            printf("Sorry, %d / %d is %d.\n", a*b, a, ans);
        }

    } else {
        printf("Sorry, %d + %d is %d.\n", a, b, ans);
    }

    return 0;
}