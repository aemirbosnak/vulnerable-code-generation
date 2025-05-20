//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTION 4
#define MAX_LENGTH 256

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTION][MAX_LENGTH];
    int correctAnswer;
} Question;

typedef struct {
    Question questions[MAX_QUESTIONS];
    int totalQuestions;
} Exam;

void addQuestion(Exam *exam) {
    if (exam->totalQuestions >= MAX_QUESTIONS) {
        printf("Maximum question limit reached.\n");
        return;
    }

    Question newQuestion;
    printf("Enter the question text: ");
    getchar(); // discard newline left by previous input
    fgets(newQuestion.question, MAX_LENGTH, stdin);
    newQuestion.question[strcspn(newQuestion.question, "\n")] = 0; // remove newline

    for (int i = 0; i < MAX_OPTION; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(newQuestion.options[i], MAX_LENGTH, stdin);
        newQuestion.options[i][strcspn(newQuestion.options[i], "\n")] = 0; // remove newline
    }

    printf("Enter the correct answer (1-4): ");
    scanf("%d", &newQuestion.correctAnswer);
    if (newQuestion.correctAnswer < 1 || newQuestion.correctAnswer > MAX_OPTION) {
        printf("Invalid answer number. It should be between 1 and %d.\n", MAX_OPTION);
        return;
    }

    exam->questions[exam->totalQuestions++] = newQuestion;
    printf("Question added successfully!\n");
}

void takeExam(const Exam *exam) {
    int score = 0;

    for (int i = 0; i < exam->totalQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("\t%d. %s\n", j + 1, exam->questions[i].options[j]);
        }

        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == exam->questions[i].correctAnswer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! Correct answer is %d.\n", exam->questions[i].correctAnswer);
        }
    }

    printf("\nYour total score is: %d out of %d\n", score, exam->totalQuestions);
}

void displayQuestions(const Exam *exam) {
    if (exam->totalQuestions == 0) {
        printf("No questions available.\n");
        return;
    }

    for (int i = 0; i < exam->totalQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("\t%d. %s\n", j + 1, exam->questions[i].options[j]);
        }
        printf("Correct answer: %d\n", exam->questions[i].correctAnswer);
    }
}

int main() {
    Exam exam;
    exam.totalQuestions = 0;
    int choice;

    do {
        printf("\nOnline Examination System\n");
        printf("1. Add Question\n");
        printf("2. Take Exam\n");
        printf("3. Display Questions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion(&exam);
                break;
            case 2:
                takeExam(&exam);
                break;
            case 3:
                displayQuestions(&exam);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}