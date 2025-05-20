//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_LENGTH 100

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int correct_answer;  // Index of the correct answer
} Question;

typedef struct {
    Question questions[MAX_QUESTIONS];
    int total_questions;
} Exam;

void add_question(Exam *exam) {
    if (exam->total_questions >= MAX_QUESTIONS) {
        printf("Maximum questions reached!\n");
        return;
    }
    
    Question new_question;
    printf("Enter the question: ");
    getchar();  // Consume newline left by previous input
    fgets(new_question.question, MAX_LENGTH, stdin);
    new_question.question[strcspn(new_question.question, "\n")] = 0; // Remove newline

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(new_question.options[i], MAX_LENGTH, stdin);
        new_question.options[i][strcspn(new_question.options[i], "\n")] = 0; // Remove newline
    }

    printf("Enter the correct option number (1-%d): ", MAX_OPTIONS);
    scanf("%d", &new_question.correct_answer);
    exam->questions[exam->total_questions++] = new_question;

    printf("Question added successfully!\n");
}

void take_exam(Exam *exam) {
    int score = 0;

    printf("\nStarting the exam... \n");
    for (int i = 0; i < exam->total_questions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Option %d: %s\n", j + 1, exam->questions[i].options[j]);
        }

        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);

        if (answer == exam->questions[i].correct_answer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct answer was option %d.\n", exam->questions[i].correct_answer);
        }
    }

    printf("\nYour total score: %d out of %d\n", score, exam->total_questions);
}

void display_menu() {
    printf("\nOnline Examination System\n");
    printf("1. Add Question\n");
    printf("2. Take Exam\n");
    printf("3. Exit\n");
}

int main() {
    Exam exam;
    exam.total_questions = 0;
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_question(&exam);
                break;
            case 2:
                if (exam.total_questions == 0) {
                    printf("No questions available. Please add questions first.\n");
                } else {
                    take_exam(&exam);
                }
                break;
            case 3:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}