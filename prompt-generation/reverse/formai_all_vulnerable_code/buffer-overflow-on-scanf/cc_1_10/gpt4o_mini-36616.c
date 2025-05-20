//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_STRING_LENGTH 100

typedef struct {
    char question[MAX_STRING_LENGTH];
    char optionA[MAX_STRING_LENGTH];
    char optionB[MAX_STRING_LENGTH];
    char optionC[MAX_STRING_LENGTH];
    char optionD[MAX_STRING_LENGTH];
    char answer;
} Question;

typedef struct {
    char title[MAX_STRING_LENGTH];
    Question questions[MAX_QUESTIONS];
    int questionCount;
} Exam;

void createExam(Exam *exam) {
    printf("Let's create an exam! What's the title of the exam? ");
    fgets(exam->title, MAX_STRING_LENGTH, stdin);
    exam->title[strcspn(exam->title, "\n")] = 0; // Remove newline character

    printf("How many questions do you want to add (maximum %d)? ", MAX_QUESTIONS);
    scanf("%d", &exam->questionCount);
    getchar(); // To consume the newline character

    for (int i = 0; i < exam->questionCount; i++) {
        printf("Enter question %d: ", i + 1);
        fgets(exam->questions[i].question, MAX_STRING_LENGTH, stdin);
        exam->questions[i].question[strcspn(exam->questions[i].question, "\n")] = 0;

        printf("Enter option A: ");
        fgets(exam->questions[i].optionA, MAX_STRING_LENGTH, stdin);
        exam->questions[i].optionA[strcspn(exam->questions[i].optionA, "\n")] = 0;

        printf("Enter option B: ");
        fgets(exam->questions[i].optionB, MAX_STRING_LENGTH, stdin);
        exam->questions[i].optionB[strcspn(exam->questions[i].optionB, "\n")] = 0;

        printf("Enter option C: ");
        fgets(exam->questions[i].optionC, MAX_STRING_LENGTH, stdin);
        exam->questions[i].optionC[strcspn(exam->questions[i].optionC, "\n")] = 0;

        printf("Enter option D: ");
        fgets(exam->questions[i].optionD, MAX_STRING_LENGTH, stdin);
        exam->questions[i].optionD[strcspn(exam->questions[i].optionD, "\n")] = 0;

        printf("Enter the correct answer (A/B/C/D): ");
        scanf(" %c", &exam->questions[i].answer);
        getchar(); // To consume the newline character
        printf("\n");
    }
}

void takeExam(Exam *exam) {
    int score = 0;
    printf("Starting the exam: %s\n", exam->title);

    for (int i = 0; i < exam->questionCount; i++) {
        printf("Question %d: %s\n", i + 1, exam->questions[i].question);
        printf("A. %s\n", exam->questions[i].optionA);
        printf("B. %s\n", exam->questions[i].optionB);
        printf("C. %s\n", exam->questions[i].optionC);
        printf("D. %s\n", exam->questions[i].optionD);

        char answer;
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        getchar(); // To consume the newline character

        if (answer == exam->questions[i].answer) {
            score++;
            printf("Correct!\n\n");
        } else {
            printf("Wrong! The correct answer was %c.\n\n", exam->questions[i].answer);
        }
    }

    printf("You scored %d out of %d\n", score, exam->questionCount);
}

int main() {
    Exam exam;
    int choice;

    do {
        printf("Welcome to the Online Examination System!\n");
        printf("1. Create Exam\n");
        printf("2. Take Exam\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                createExam(&exam);
                break;
            case 2:
                takeExam(&exam);
                break;
            case 3:
                printf("Thank you for using the Online Examination System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}