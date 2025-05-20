//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTION 4
#define MAX_LENGTH 100

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTION][MAX_LENGTH];
    int answer; // index of the correct option (0-indexed)
} Question;

typedef struct {
    char name[MAX_LENGTH];
    Question questions[MAX_QUESTIONS];
    int questionCount;
} Exam;

// Function to add a question to the exam
void addQuestion(Exam *exam) {
    if (exam->questionCount >= MAX_QUESTIONS) {
        printf("Maximum questions reached!\n");
        return;
    }
    Question newQuestion;
    printf("Enter the question: ");
    getchar(); // To consume newline character
    fgets(newQuestion.question, MAX_LENGTH, stdin);
    newQuestion.question[strcspn(newQuestion.question, "\n")] = 0; // Remove newline

    for (int i = 0; i < MAX_OPTION; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(newQuestion.options[i], MAX_LENGTH, stdin);
        newQuestion.options[i][strcspn(newQuestion.options[i], "\n")] = 0; // Remove newline
    }

    printf("Enter the correct answer (1-%d): ", MAX_OPTION);
    scanf("%d", &newQuestion.answer);
    newQuestion.answer--; // Store as 0-indexed

    exam->questions[exam->questionCount++] = newQuestion;
    printf("Question added successfully!\n");
}

// Function to take an examination
void takeExam(Exam *exam) {
    printf("\nStarting Exam: %s\n", exam->name);
    int score = 0;

    for (int i = 0; i < exam->questionCount; i++) {
        printf("\nQuestion %d: %s", i + 1, exam->questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("\nOption %d: %s", j + 1, exam->questions[i].options[j]);
        }
        
        int userAnswer;
        printf("\nYour answer (1-%d): ", MAX_OPTION);
        scanf("%d", &userAnswer);
        userAnswer--; // Adjust to 0-index

        if (userAnswer == exam->questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was option %d.\n", exam->questions[i].answer + 1);
        }
    }

    printf("\nYou scored %d out of %d!\n", score, exam->questionCount);
}

// Function to view the exam results
void viewResults(Exam *exam) {
    printf("\nExam Results for: %s\n", exam->name);
    printf("You have successfully completed the examination.\n");
}

// Function to create an examination
void createExam(Exam *exam) {
    printf("Enter exam name: ");
    getchar(); // To consume newline character
    fgets(exam->name, MAX_LENGTH, stdin);
    exam->name[strcspn(exam->name, "\n")] = 0; // Remove newline
    exam->questionCount = 0;

    char addMore;
    do {
        addQuestion(exam);
        printf("Do you want to add more questions? (y/n): ");
        scanf(" %c", &addMore); // Space before %c to consume whitespace
    } while (addMore == 'y' && exam->questionCount < MAX_QUESTIONS);
}

// Main function to drive the program
int main() {
    Exam exam;
    int choice;

    printf("Welcome to the Online Examination System!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Create Exam\n");
        printf("2. Take Exam\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createExam(&exam);
                break;
            case 2:
                takeExam(&exam);
                break;
            case 3:
                viewResults(&exam);
                break;
            case 4:
                printf("Thank you for using the Online Examination System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}