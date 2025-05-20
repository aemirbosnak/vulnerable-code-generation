//FormAI DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 20
#define MAX_OPTIONS 4

/* Struct to represent a single question */
typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int correct_answer;
} Question;

int main() {
    /* Array to hold all the questions for the exam */
    Question questions[MAX_QUESTIONS];
    /* Counter variables */
    int i, j, num_questions;

    /* Prompt user for number of questions */
    printf("How many questions would you like to add? (maximum is %d)\n", MAX_QUESTIONS);
    scanf("%d", &num_questions);

    /* Loop through each question and prompt the user for details */
    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d:\n", i+1);
        getchar();
        fgets(questions[i].question, 100, stdin);
        /* Remove the newline character at the end of the question */
        questions[i].question[strcspn(questions[i].question, "\n")] = 0;

        /* Loop through each option and prompt the user for details */
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter option %c:\n", (char)(j+65));
            fgets(questions[i].options[j], 50, stdin);
            /* Remove the newline character at the end of the option */
            questions[i].options[j][strcspn(questions[i].options[j], "\n")] = 0;
        }

        printf("Enter the correct option (A=1, B=2, C=3, D=4):\n");
        scanf("%d", &questions[i].correct_answer);
    }

    /* Display all the questions and their options */
    printf("Exam questions:\n");
    for (i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%c) %s\n", (char)(j+65), questions[i].options[j]);
        }
    }

    printf("Exam completed!");

    return 0;
}