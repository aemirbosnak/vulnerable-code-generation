//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to calculate the power of a number */
long long int power(int base, int exponent) {
    long long int result = 1;
    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    srand(time(NULL));  // seeding the random number generator

    int num_of_questions;  // variable to store number of questions
    printf("How many math exercises do you want to solve?: ");
    scanf("%d", &num_of_questions);

    for (int i = 1; i <= num_of_questions; i++) {
        int choice = (rand() % 3) + 1;  // generating a random number between 1-3 to select the type of problem

        // Addition operation
        if (choice == 1) {
            int num1 = (rand() % 100) + 1;  // generating two random numbers between 1-100
            int num2 = (rand() % 100) + 1;
            int answer = num1 + num2;
            int user_answer;
            printf("%d. %d + %d = ", i, num1, num2);
            scanf("%d", &user_answer);
            if (user_answer == answer) {
                printf("Correct!\n\n");
            }
            else {
                printf("Incorrect. The correct answer is %d.\n\n", answer);
            }
        }

        // Subtraction operation
        else if (choice == 2) {
            int num1 = (rand() % 100) + 1;  // generating two random numbers between 1-100
            int num2 = (rand() % 100) + 1;
            if (num2 > num1) {  // ensuring that the answer is always positive
                int temp = num1;
                num1 = num2;
                num2 = temp;
            }
            int answer = num1 - num2;
            int user_answer;
            printf("%d. %d - %d = ", i, num1, num2);
            scanf("%d", &user_answer);
            if (user_answer == answer) {
                printf("Correct!\n\n");
            }
            else {
                printf("Incorrect. The correct answer is %d.\n\n", answer);
            }
        }

        // Multiplication operation
        else {
            int num1 = (rand() % 12) + 1;  // generating two random numbers between 1-12
            int num2 = (rand() % 12) + 1;
            int answer = num1 * num2;
            int user_answer;
            printf("%d. %d x %d = ", i, num1, num2);
            scanf("%d", &user_answer);
            if (user_answer == answer) {
                printf("Correct!\n\n");
            }
            else {
                printf("Incorrect. The correct answer is %d.\n\n", answer);
            }
        }
    }

    return 0;
}