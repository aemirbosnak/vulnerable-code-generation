//Falcon-180B DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions, correct_answers = 0;
    int user_score = 0, question_number = 1;
    char user_answer[50];
    int correct_answer;

    srand(time(0));

    printf("Welcome to the Educational Quiz!\n\n");

    // Ask the user how many questions they want to answer
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);

    // Loop through the desired number of questions
    for (int i = 0; i < num_questions; i++) {
        // Generate a random number between 1 and 10
        int random_number = rand() % 10 + 1;

        // Display the question to the user
        printf("\nQuestion %d: What is %d + %d?\n", question_number, random_number, random_number + 1);

        // Get the user's answer
        printf("Your answer: ");
        scanf("%s", user_answer);

        // Convert the user's answer to an integer
        correct_answer = atoi(user_answer);

        // Check if the user's answer is correct
        if (correct_answer == random_number + 1) {
            printf("\nCorrect!\n");
            correct_answers++;
        } else {
            printf("\nIncorrect. The correct answer is %d.\n", random_number + 1);
        }

        // Increment the question number
        question_number++;
    }

    // Display the user's score
    printf("\n\nYou got %d out of %d questions correct!\n", correct_answers, num_questions);

    return 0;
}