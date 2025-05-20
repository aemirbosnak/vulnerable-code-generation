//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_LENGTH 256

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int correctOption;
} Question;

typedef struct {
    Question questions[MAX_QUESTIONS];
    int totalQuestions;
} Quiz;

// Function to add questions to the quiz
void addQuestion(Quiz *quiz) {
    if (quiz->totalQuestions >= MAX_QUESTIONS) {
        printf("Cannot add more questions, limit reached!\n");
        return;
    }

    Question newQuestion;
    int i;
    
    printf("Enter the question: ");
    getchar();  // Clear the newline from previous input
    fgets(newQuestion.question, sizeof(newQuestion.question), stdin);
    strtok(newQuestion.question, "\n"); // Remove newline character

    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(newQuestion.options[i], sizeof(newQuestion.options[i]), stdin);
        strtok(newQuestion.options[i], "\n"); // Remove newline character
    }

    printf("Enter correct option number (1-%d): ", MAX_OPTIONS);
    scanf("%d", &newQuestion.correctOption);
    quiz->questions[quiz->totalQuestions] = newQuestion;
    quiz->totalQuestions++;
    printf("Question added successfully!\n");
}

// Function to display the quiz
void displayQuiz(const Quiz *quiz) {
    int i, j;
    for (i = 0; i < quiz->totalQuestions; i++) {
        printf("Q%d: %s\n", i + 1, quiz->questions[i].question);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("  Option %d: %s\n", j + 1, quiz->questions[i].options[j]);
        }
    }
}

// Function to conduct the quiz
void conductQuiz(const Quiz *quiz) {
    int i, answer, score = 0;

    for (i = 0; i < quiz->totalQuestions; i++) {
        printf("Q%d: %s\n", i + 1, quiz->questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("  Option %d: %s\n", j + 1, quiz->questions[i].options[j]);
        }
        
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);

        if (answer == quiz->questions[i].correctOption) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer was option %d.\n", quiz->questions[i].correctOption);
        }
    }

    printf("You scored %d out of %d.\n", score, quiz->totalQuestions);
}

// Main function
int main() {
    Quiz myQuiz;
    myQuiz.totalQuestions = 0;
    int choice;

    do {
        printf("\nOnline Examination System\n");
        printf("1. Add Question\n");
        printf("2. Display Quiz\n");
        printf("3. Conduct Quiz\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion(&myQuiz);
                break;
            case 2:
                displayQuiz(&myQuiz);
                break;
            case 3:
                conductQuiz(&myQuiz);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 4);

    return 0;
}