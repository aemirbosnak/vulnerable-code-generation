//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    // Create an array to store the questions
    int questions[10];
    int num_questions = sizeof(questions) / sizeof(questions[0]);

    // Initialize the questions
    questions[0] = 1;
    questions[1] = 2;
    questions[2] = 3;
    questions[3] = 4;
    questions[4] = 5;
    questions[5] = 6;
    questions[6] = 7;
    questions[7] = 8;
    questions[8] = 9;
    questions[9] = 10;

    // Prompt the user to enter their name
    printf("Enter your name: ");
    char name[100];
    fgets(name, sizeof(name), stdin);

    // Prompt the user to choose a question
    int question_num;
    printf("Choose a question (1-%d): ", num_questions);
    scanf("%d", &question_num);
    if (question_num > 0 && question_num <= num_questions) {
        // Display the question
        printf("Question %d: %d\n", question_num, questions[question_num]);
    } else {
        printf("Invalid question number!\n");
    }

    // Prompt the user to enter their answer
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);

    // Check if the answer is correct
    if (answer == questions[question_num]) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    // Prompt the user to continue or quit
    char choice;
    printf("Enter 'Y' to continue, or any other key to quit: ");
    fgets(&choice, 1, stdin);
    if (choice == 'Y') {
        // Continue the exam
        main();
    } else {
        // End the exam
        printf("Thank you for taking the exam!\n");
    }

    return 0;
}