//FormAI DATASET v1.0 Category: Online Examination System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUESTIONS 50
#define MAX_ANSWER_LENGTH 100

struct Question {
    char question[1000];
    char correct_answer[100];
    char user_answer[100];
};

int main() {
    struct Question questions[MAX_QUESTIONS];
    int num_questions;
    int num_correct_answers = 0;

    // The case begins
    printf("Greetings, my dear Watson. Today, we shall be investigating an online examination system.\n");

    // The first clue: the number of questions
    printf("First, let us determine the number of questions in this examination.\n");
    printf("How many questions are there, Watson? Please type a number:\n");
    scanf("%d", &num_questions);

    // The second clue: the questions themselves
    printf("Excellent, Watson. Now we shall gather the questions themselves.\n");
    printf("Please enter each question followed by its correct answer, separated by a semicolon.\n");
    printf("For example:\n");
    printf("What color is the sky?;Blue\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        scanf("%[^;];%s", questions[i].question, questions[i].correct_answer);
        fflush(stdin); // To clear the input buffer
    }

    // The third clue: the user's answers
    printf("Now we shall see how our candidate has fared on the examination.\n");
    printf("Please enter your answer to each question, one at a time.\n");
    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        scanf("%s", questions[i].user_answer);
        fflush(stdin); // To clear the input buffer
    }

    // The final verdict: the correct answers and the score
    printf("And now, the moment of truth. Let us see how many questions our candidate has answered correctly.\n");
    for (int i = 0; i < num_questions; i++) {
        if (strcmp(questions[i].correct_answer, questions[i].user_answer) == 0) {
            num_correct_answers++;
            printf("Question %d: Correct\n", i+1);
        } else {
            printf("Question %d: Incorrect\n", i+1);
        }
    }

    printf("The examination is now concluded. Our candidate has answered %d out of %d questions correctly.\n", num_correct_answers, num_questions);

    return 0;
}