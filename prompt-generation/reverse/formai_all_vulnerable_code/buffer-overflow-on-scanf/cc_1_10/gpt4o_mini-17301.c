//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10 // Change this value to configure the number of questions
#define MAX_OPTIONS 4 // Maximum number of options per question
#define MAX_LENGTH 100 // Maximum length for strings

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int answer; // Index of the correct option
} Question;

typedef struct {
    Question questions[MAX_QUESTIONS];
    int totalQuestions;
} Quiz;

void addQuestion(Quiz *quiz) {
    if (quiz->totalQuestions >= MAX_QUESTIONS) {
        printf("Cannot add more questions. Maximum limit reached!\n");
        return;
    }

    Question *q = &quiz->questions[quiz->totalQuestions];

    printf("Enter the question: ");
    getchar(); // To consume the newline character from previous input
    fgets(q->question, MAX_LENGTH, stdin);
    q->question[strcspn(q->question, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(q->options[i], MAX_LENGTH, stdin);
        q->options[i][strcspn(q->options[i], "\n")] = '\0'; // Remove newline character
    }

    printf("Enter correct answer (1-%d): ", MAX_OPTIONS);
    scanf("%d", &q->answer);
    quiz->totalQuestions++;
    printf("Question added successfully!\n");
}

void conductExam(Quiz *quiz) {
    int score = 0;
    for (int i = 0; i < quiz->totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, quiz->questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, quiz->questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);
        if (answer - 1 == quiz->questions[i].answer) {
            score++;
        }
    }
    printf("You scored %d out of %d\n", score, quiz->totalQuestions);
}

void displayMenu() {
    printf("\nOnline Examination System\n");
    printf("1. Add Question\n");
    printf("2. Conduct Exam\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Quiz quiz = { .totalQuestions = 0 };
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion(&quiz);
                break;
            case 2:
                conductExam(&quiz);
                break;
            case 3:
                printf("Exiting... Thank you for using the Examination System.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}