//FormAI DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[128];
    char answer[128];
} Question;

typedef struct {
    char username[64];
    int score;
    int num_questions;
    Question questions[10];
} Exam;

void add_question(Question questions[], int num_questions) {
    printf("Enter question:\n");
    fgets(questions[num_questions].question, sizeof(questions[num_questions].question), stdin);
    printf("Enter answer:\n");
    fgets(questions[num_questions].answer, sizeof(questions[num_questions].answer), stdin);
}

int take_exam(Exam exam) {
    int num_correct = 0;
    char answer[128];
    for (int i = 0; i < exam.num_questions; i++) {
        printf("Question %d: %s", i+1, exam.questions[i].question);
        fgets(answer, sizeof(answer), stdin);
        if (strcmp(answer, exam.questions[i].answer) == 0) {
            num_correct++;
        }
    }
    printf("You scored %d out of %d\n", num_correct, exam.num_questions);
    return num_correct;
}

int main() {
    Exam exam;
    int choice;
    do {
        printf("1. Login\n");
        printf("2. Create Account\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter username:\n");
                scanf("%s", exam.username);
                printf("Enter number of questions:\n");
                scanf("%d", &exam.num_questions);
                for (int i = 0; i < exam.num_questions; i++) {
                    add_question(exam.questions, i);
                }
                exam.score = take_exam(exam);
                printf("Your score has been saved.\n");
                break;
            case 2:
                printf("Enter username:\n");
                scanf("%s", exam.username);
                printf("Account created successfully.\n");
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}