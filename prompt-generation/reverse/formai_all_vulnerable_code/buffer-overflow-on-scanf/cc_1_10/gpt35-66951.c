//FormAI DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4

struct question {
    int id;
    char statement[100];
    char options[MAX_OPTIONS][50];
    int correct_option;
};

struct exam {
    char name[50];
    int duration;
    int num_questions;
    struct question questions[MAX_QUESTIONS];
};

void create_exam(struct exam *ex) {
    printf("Enter exam name: ");
    scanf("%s", ex->name);

    printf("Enter exam duration in minutes: ");
    scanf("%d", &ex->duration);

    printf("Enter number of questions for the exam: ");
    scanf("%d", &ex->num_questions);

    for(int i = 0; i < ex->num_questions; i++) {
        printf("\n\nEnter details for question %d:", i+1);
        printf("\n----------------------------------\n");
        printf("Enter statement for the question: ");
        scanf(" %[^\n]", ex->questions[i].statement);

        printf("Enter options for the question:\n");
        for(int j = 0; j < MAX_OPTIONS; j++) {
            printf("Option %d: ", j+1);
            scanf(" %[^\n]", ex->questions[i].options[j]);
        }

        printf("Enter correct option: ");
        scanf("%d", &ex->questions[i].correct_option);
    }

    printf("\n\nExam created successfully!\n");
}

void display_exam(struct exam ex) {
    printf("\nExam Name: %s\n", ex.name);
    printf("Duration: %d minutes\n", ex.duration);
    printf("Number of questions: %d\n", ex.num_questions);

    for(int i = 0; i < ex.num_questions; i++) {
        printf("\n\nQuestion %d:", i+1);
        printf("\n----------------\n");
        printf("Statement: %s\n", ex.questions[i].statement);

        printf("Options:\n");
        for(int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, ex.questions[i].options[j]);
        }

        printf("Correct option: %d\n", ex.questions[i].correct_option);
    }
}

int main() {
    struct exam my_exam;

    create_exam(&my_exam);
    display_exam(my_exam);

    return 0;
}