//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for max number of questions and answers
#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4

// Define structs for question and answer
struct Answer {
    char text[100];
    int is_correct;
};

struct Question {
    char text[200];
    struct Answer answers[MAX_ANSWERS];
    int correct_answer;
};

int main() {
    // Get exam details from user
    char exam_title[100];
    int num_questions;
    printf("Enter exam title: ");
    fgets(exam_title, 100, stdin);
    printf("Enter number of questions: ");
    scanf("%d", &num_questions);
    getchar(); // clear input buffer

    // Store questions and answers in array of structs
    struct Question questions[MAX_QUESTIONS];
    for (int i=0; i<num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        printf("Enter question text:\n");
        fgets(questions[i].text, 200, stdin);
        printf("Enter answer 1:\n");
        fgets(questions[i].answers[0].text, 100, stdin);
        printf("Is answer 1 correct? (1 for yes, 0 for no)\n");
        scanf("%d", &questions[i].answers[0].is_correct);
        getchar(); // clear input buffer
        printf("Enter answer 2:\n");
        fgets(questions[i].answers[1].text, 100, stdin);
        printf("Is answer 2 correct? (1 for yes, 0 for no)\n");
        scanf("%d", &questions[i].answers[1].is_correct);
        getchar(); // clear input buffer
        printf("Enter answer 3:\n");
        fgets(questions[i].answers[2].text, 100, stdin);
        printf("Is answer 3 correct? (1 for yes, 0 for no)\n");
        scanf("%d", &questions[i].answers[2].is_correct);
        getchar(); // clear input buffer
        printf("Enter answer 4:\n");
        fgets(questions[i].answers[3].text, 100, stdin);
        printf("Is answer 4 correct? (1 for yes, 0 for no)\n");
        scanf("%d", &questions[i].answers[3].is_correct);
        getchar(); // clear input buffer
        printf("Enter correct answer number (1-4):\n");
        scanf("%d", &questions[i].correct_answer);
        getchar(); // clear input buffer
    }

    // Display exam to user
    printf("\n%s", exam_title);
    for (int i=0; i<num_questions; i++) {
        printf("\n%d. %s", i+1, questions[i].text);
        printf("1. %s", questions[i].answers[0].text);
        printf("2. %s", questions[i].answers[1].text);
        printf("3. %s", questions[i].answers[2].text);
        printf("4. %s", questions[i].answers[3].text);
    }

    // Take exam from user and grade it
    int total_score = 0;
    for (int i=0; i<num_questions; i++) {
        printf("\n%d. %s", i+1, questions[i].text);
        printf("1. %s", questions[i].answers[0].text);
        printf("2. %s", questions[i].answers[1].text);
        printf("3. %s", questions[i].answers[2].text);
        printf("4. %s", questions[i].answers[3].text);
        int user_answer;
        printf("\nEnter your answer (1-4):\n");
        scanf("%d", &user_answer);
        getchar(); // clear input buffer
        if (user_answer == questions[i].correct_answer) {
            total_score++;
        }
    }

    // Display exam results to user
    printf("\nYour score is %d out of %d.\n", total_score, num_questions);
    if (total_score >= num_questions*0.6) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }

    return 0;
}