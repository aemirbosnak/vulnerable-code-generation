//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables
    int num1, num2, answer, user_answer;
    char operation;

    // Set seed for generating random numbers
    srand(time(0));

    // Print welcome message to user
    printf("Hello! I'm the funny math quiz bot. Let's have some fun with math!\n");

    // Loop through 5 questions
    for (int i = 0; i < 5; i++) {

        // Generate two random numbers between 1 and 10
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // Generate a random operator
        switch(rand() % 4) {
            case 0:
                operation = '+';
                answer = num1 + num2;
                break;
            case 1:
                operation = '-';
                answer = num1 - num2;
                break;
            case 2:
                operation = '*';
                answer = num1 * num2;
                break;
            case 3:
                operation = '/';
                answer = num1 / num2;
                break;
        }

        // Print the problem for the user to solve
        printf("\nQuestion %d: %d %c %d = ", i+1, num1, operation, num2);

        // Get the user's answer
        scanf("%d", &user_answer);

        // Check if the user's answer is correct
        if (user_answer == answer) {
            printf("Congratulations! You got it right!\n");
        }
        else {
            printf("Sorry, that's not the right answer. The correct answer is %d\n", answer);
        }

    }

    // Print final message to the user
    printf("\nThanks for playing! Come back soon for more funny math quizzes!\n");

    return 0;
}