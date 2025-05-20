//FormAI DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random numbers between 1 and 10 */
int generate_random() {
    srand(time(NULL));
    return rand() % 10 + 1;
}

/* Function to calculate the factorial of a number */
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int a = generate_random();
    int b = generate_random();

    /* Add two random numbers */
    int sum = a + b;
    printf("What is %d + %d?\n", a, b);
    printf("Enter your answer: ");
    int user_answer;
    scanf("%d", &user_answer);

    if (user_answer == sum) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d\n", sum);
    }

    /* Subtract two random numbers */
    int difference = a - b;
    printf("What is %d - %d?\n", a, b);
    printf("Enter your answer: ");
    scanf("%d", &user_answer);

    if (user_answer == difference) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d\n", difference);
    }

    /* Calculate the factorial of a random number */
    printf("What is the factorial of %d?\n", a);
    printf("Enter your answer: ");
    scanf("%d", &user_answer);

    int fact = factorial(a);
    if (user_answer == fact) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d\n", fact);
    }

    return 0;
}