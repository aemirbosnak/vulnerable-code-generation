//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][256];
    int correctAnswer; // 0-indexed
} Question;

typedef struct {
    char name[50];
    int score;
    int totalQuestions;
} Participant;

Question questions[MAX_QUESTIONS];
int totalQuestions = 0;
Participant currentParticipant;

void addQuestion() {
    if (totalQuestions < MAX_QUESTIONS) {
        printf("Enter Question: ");
        getchar(); // to consume the newline character from previous input
        fgets(questions[totalQuestions].question, 256, stdin);
        questions[totalQuestions].question[strcspn(questions[totalQuestions].question, "\n")] = 0; // remove newline
        
        for (int i = 0; i < MAX_OPTIONS; i++) {
            printf("Enter option %d: ", i + 1);
            fgets(questions[totalQuestions].options[i], 256, stdin);
            questions[totalQuestions].options[i][strcspn(questions[totalQuestions].options[i], "\n")] = 0; // remove newline
        }
        
        printf("Enter the correct answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &questions[totalQuestions].correctAnswer);
        questions[totalQuestions].correctAnswer--; // Store as 0-indexed

        totalQuestions++;
        printf("Question added successfully!\n");
    } else {
        printf("Maximum number of questions reached.\n");
    }
}

void takeExam() {
    currentParticipant.score = 0;
    currentParticipant.totalQuestions = totalQuestions;

    printf("Welcome to the exam, %s!\n", currentParticipant.name);
    for (int i = 0; i < totalQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);
        
        if (answer - 1 == questions[i].correctAnswer) {
            printf("Correct!\n");
            currentParticipant.score++;
        } else {
            printf("Incorrect! The correct answer was %d. %s\n", questions[i].correctAnswer + 1, questions[i].options[questions[i].correctAnswer]);
        }
    }
    printf("Exam finished! You scored %d out of %d.\n", currentParticipant.score, currentParticipant.totalQuestions);
}

void displayResult() {
    printf("\nParticipant Name: %s\n", currentParticipant.name);
    printf("Total Questions: %d\n", currentParticipant.totalQuestions);
    printf("Score: %d\n", currentParticipant.score);
}

int main() {
    int choice;

    printf("Enter your name: ");
    fgets(currentParticipant.name, 50, stdin);
    currentParticipant.name[strcspn(currentParticipant.name, "\n")] = 0; // removing newline

    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Add Question\n");
        printf("2. Take Exam\n");
        printf("3. Display Result\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion();
                break;
            case 2:
                takeExam();
                break;
            case 3:
                displayResult();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}