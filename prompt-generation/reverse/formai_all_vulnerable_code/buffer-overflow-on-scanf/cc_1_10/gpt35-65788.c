//FormAI DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int correct_option;
} Question;

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions, score = 0;
    char responses[MAX_QUESTIONS];

    printf("Welcome to the online exam system!\n");

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the questions and options:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: ", i+1);
        scanf(" %[^\n]", questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Option %d: ", j+1);
            scanf(" %[^\n]", questions[i].options[j]);
        }
        printf("Correct option: ");
        scanf("%d", &questions[i].correct_option);
    }

    printf("The exam begins now!\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }
        printf("Response: ");
        scanf("%s", &responses[i]);
        if (responses[i] == questions[i].correct_option + '0') {
            score++;
        }
    }

    printf("Your score: %d/%d\n", score, num_questions);

    return 0;
}