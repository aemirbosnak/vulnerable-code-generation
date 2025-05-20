//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct {
    char question[256];
    char options[4][100];
    int answer; // index of the correct option (0-3)
} Question;

typedef struct {
    Question questions[MAX_QUESTIONS];
    int count;
} Exam;

void createExam(Exam *exam) {
    exam->count = 0;
    printf("Enter number of questions (max %d): ", MAX_QUESTIONS);
    int n;
    scanf("%d", &n);
    getchar(); // clear newline from buffer
    if (n > MAX_QUESTIONS) n = MAX_QUESTIONS;

    for (int i = 0; i < n; i++) {
        printf("Enter Question %d: ", i + 1);
        fgets(exam->questions[i].question, sizeof(exam->questions[i].question), stdin);
        exam->questions[i].question[strcspn(exam->questions[i].question, "\n")] = 0; // remove newline
        for (int j = 0; j < 4; j++) {
            printf("Enter option %d: ", j + 1);
            fgets(exam->questions[i].options[j], sizeof(exam->questions[i].options[j]), stdin);
            exam->questions[i].options[j][strcspn(exam->questions[i].options[j], "\n")] = 0; // remove newline
        }
        printf("Enter the correct option number (1-4): ");
        scanf("%d", &exam->questions[i].answer);
        exam->questions[i].answer--; // to make it zero indexed
        getchar(); // clear newline from buffer
        exam->count++;
    }
}

void takeExam(Exam *exam) {
    int score = 0;
    printf("\nStarting the exam...\n");
    for (int i = 0; i < exam->count; i++) {
        printf("\nQuestion %d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("Option %d: %s\n", j + 1, exam->questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer - 1 == exam->questions[i].answer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer was: %s\n", exam->questions[i].options[exam->questions[i].answer]);
        }
    }

    printf("\nYour total score is: %d out of %d\n", score, exam->count);
}

void viewQuestions(Exam *exam) {
    printf("\nExam Questions:\n");
    for (int i = 0; i < exam->count; i++) {
        printf("%d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("   Option %d: %s\n", j + 1, exam->questions[i].options[j]);
        }
        printf("   Correct answer: %d\n", exam->questions[i].answer + 1);
    }
}

int main() {
    int choice;
    Exam exam;
    do {
        printf("\nOnline Examination System\n");
        printf("1. Create Exam\n");
        printf("2. Take Exam\n");
        printf("3. View Questions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice) {
            case 1:
                createExam(&exam);
                break;
            case 2:
                takeExam(&exam);
                break;
            case 3:
                viewQuestions(&exam);
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}