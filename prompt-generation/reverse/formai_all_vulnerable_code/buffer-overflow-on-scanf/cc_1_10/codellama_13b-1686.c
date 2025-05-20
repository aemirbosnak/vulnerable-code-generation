//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_ANSWERS 5

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answers[MAX_ANSWERS][100];
} Question;

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions, num_options, num_answers, i, j;

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        fgets(questions[i].question, 100, stdin);

        printf("Enter the number of options: ");
        scanf("%d", &num_options);

        for (j = 0; j < num_options; j++) {
            printf("Enter option %d: ", j + 1);
            fgets(questions[i].options[j], 100, stdin);
        }

        printf("Enter the number of answers: ");
        scanf("%d", &num_answers);

        for (j = 0; j < num_answers; j++) {
            printf("Enter answer %d: ", j + 1);
            fgets(questions[i].answers[j], 100, stdin);
        }
    }

    printf("Questions: \n");
    for (i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (j = 0; j < num_options; j++) {
            printf("%s\n", questions[i].options[j]);
        }
        for (j = 0; j < num_answers; j++) {
            printf("%s\n", questions[i].answers[j]);
        }
    }

    return 0;
}