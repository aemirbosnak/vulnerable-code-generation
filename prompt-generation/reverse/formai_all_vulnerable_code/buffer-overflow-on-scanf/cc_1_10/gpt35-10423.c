//FormAI DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of questions
#define MAX_QUESTIONS 10

// define the maximum question length
#define MAX_QUESTION_LENGTH 100

// define the maximum answer length
#define MAX_ANSWER_LENGTH 50

// define the maximum number of attempts
#define MAX_ATTEMPTS 3

// define the maximum marks
#define MAX_MARKS 20

// define the question struct
typedef struct question {
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
    int marks;
} question;

// initialize the questions array
question questions[MAX_QUESTIONS];

// declare a variable to keep track of the number of questions
int num_questions = 0;

// main function
int main() {
    // display welcome message
    printf("Welcome to the Online Examination System!\n");

    // get the number of questions from the user
    printf("How many questions would you like to add? ");
    scanf("%d", &num_questions);

    // check if the number of questions is valid
    if (num_questions < 1 || num_questions > MAX_QUESTIONS) {
        printf("Please enter a number between 1 and %d.\n", MAX_QUESTIONS);
        return 1;
    }

    // loop through each question and get the question and answer from the user
    for (int i = 0; i < num_questions; i++) {
        printf("Question #%d: ", i + 1);
        scanf(" %[^\n]", questions[i].question);

        printf("Answer for #%d: ", i + 1);
        scanf(" %[^\n]", questions[i].answer);

        // get the marks for the question from the user
        printf("Number of marks for #%d: ", i + 1);
        scanf("%d", &questions[i].marks);
    }

    // display the questions and their corresponding answers
    printf("Here are the questions and their answers:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question #%d: %s\n", i + 1, questions[i].question);
        printf("Answer for #%d: %s\n", i + 1, questions[i].answer);
        printf("Number of marks for #%d: %d\n", i + 1, questions[i].marks);
    }

    // simulate an exam for a student
    char answer[MAX_ANSWER_LENGTH];
    int total_marks = 0;
    int attempts = 0;

    // loop through each question and ask for the answer from the student
    for (int i = 0; i < num_questions; i++) {
        // initialize the number of attempts for the question to 0
        attempts = 0;

        // while the student has not reached the maximum number of attempts and has not given the correct answer
        while (attempts < MAX_ATTEMPTS && strcmp(answer, questions[i].answer) != 0) {
            printf("Question #%d: %s\n", i + 1, questions[i].question);
            printf("Enter your answer: ");
            scanf(" %[^\n]", answer);

            // increment the number of attempts
            attempts++;
        }

        // check if the answer is correct
        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            total_marks += questions[i].marks;
        } else {
            printf("Incorrect.\n");
        }

        // reset the answer for the next question
        strcpy(answer, "");
    }

    // display the total marks obtained by the student
    printf("Total marks obtained: %d/%d\n", total_marks, MAX_MARKS);

    return 0;
}