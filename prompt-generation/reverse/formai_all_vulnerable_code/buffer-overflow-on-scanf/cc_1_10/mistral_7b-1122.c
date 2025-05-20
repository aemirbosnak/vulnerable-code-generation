//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4
#define MAX_NAME_LENGTH 50
#define MAX_ANSWERS 1

typedef struct Question {
    char question[100];
    char options[MAX_OPTIONS][50];
    char answer[50];
} Question;

void generate_questions(Question* questions) {
    int i;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i].question);
        printf("Enter option A for %s: ", questions[i].question);
        scanf("%s", questions[i].options[0]);
        printf("Enter option B for %s: ", questions[i].question);
        scanf("%s", questions[i].options[1]);
        printf("Enter option C for %s: ", questions[i].question);
        scanf("%s", questions[i].options[2]);
        printf("Enter option D for %s: ", questions[i].question);
        scanf("%s", questions[i].options[3]);
        printf("Enter answer for %s: ", questions[i].question);
        scanf("%s", questions[i].answer);
    }
}

void display_question(Question question) {
    printf("\n%s\n", question.question);
    int i;
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("%c) %s\n", 'A' + i, question.options[i]);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    int i, j, score = 0;
    char name[MAX_NAME_LENGTH];
    time_t t;

    printf("---------------------------------------------\n");
    printf("| Welcome to Online Examination System!      |\n");
    printf("|--------------------------------------------|\n");

    printf("\nEnter your name: ");
    scanf("%s", name);

    printf("\n---------------------------------------------\n");
    printf("| Name          | Score |\n");
    printf("-----------------------------------------------\n");

    generate_questions(questions);

    srand(time(&t));
    for (i = 0; i < MAX_QUESTIONS; i++) {
        int random_question = rand() % MAX_QUESTIONS;
        display_question(questions[random_question]);
        char user_answer[50];
        scanf("%s", user_answer);

        if (strcmp(questions[random_question].answer, user_answer) == 0) {
            score++;
        }

        printf("\n---------------------------------------------\n");
    }

    printf("\n---------------------------------------------\n");
    printf("| %-15s | %2d |\n", name, score);
    printf("-----------------------------------------------\n");

    return 0;
}