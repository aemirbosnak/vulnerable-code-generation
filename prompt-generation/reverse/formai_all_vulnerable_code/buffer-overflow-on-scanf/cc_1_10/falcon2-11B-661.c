//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_QUESTIONS 10
#define MAX_NUM_OPTIONS 5
#define MAX_LEN_ANSWER 100

typedef struct {
    char question[MAX_LEN_ANSWER];
    char option1[MAX_LEN_ANSWER];
    char option2[MAX_LEN_ANSWER];
    char option3[MAX_LEN_ANSWER];
    char option4[MAX_LEN_ANSWER];
    char answer[MAX_LEN_ANSWER];
} Question;

int main() {
    Question questions[MAX_NUM_QUESTIONS];
    int num_questions = 0;

    printf("Welcome to the Online Examination System!\n");

    printf("Enter the number of questions: ");
    int num_questions_input = scanf("%d", &num_questions);

    if (num_questions_input!= num_questions) {
        printf("Invalid number of questions entered.\n");
        return 1;
    }

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d:\n", i + 1);
        scanf("%s", questions[i].question);

        printf("Enter option 1:\n");
        scanf("%s", questions[i].option1);

        printf("Enter option 2:\n");
        scanf("%s", questions[i].option2);

        printf("Enter option 3:\n");
        scanf("%s", questions[i].option3);

        printf("Enter option 4:\n");
        scanf("%s", questions[i].option4);

        printf("Enter correct answer:\n");
        scanf("%s", questions[i].answer);

        printf("Question %d entered.\n", i + 1);
    }

    printf("Now you can start the examination!\n");

    int num_correct_answers = 0;

    while (num_correct_answers < num_questions) {
        printf("Enter your answer for question %d:\n", num_correct_answers + 1);
        char answer_input[MAX_LEN_ANSWER];
        scanf("%s", answer_input);

        if (strcmp(answer_input, questions[num_correct_answers].answer) == 0) {
            printf("Correct answer!\n");
            num_correct_answers++;
        } else {
            printf("Incorrect answer.\n");
        }
    }

    printf("Congratulations! You have completed the examination.\n");
    return 0;
}