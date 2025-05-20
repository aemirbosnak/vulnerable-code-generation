//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTION_LENGTH 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[255];
    char options[4][MAX_OPTION_LENGTH];
    int answer; // Index of the correct answer
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Participant;

Question questionBank[MAX_QUESTIONS];
Participant participants[MAX_QUESTIONS];
int totalQuestions = 0;
int totalParticipants = 0;

void addQuestion();
void takeExam();
void displayResults();
void clearScreen();
void printMenu();

int main() {
    int choice;
    
    do {
        printMenu();
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
                displayResults();
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void printMenu() {
    clearScreen();
    printf("=== Online Examination System ===\n");
    printf("1. Add Question\n");
    printf("2. Take Exam\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

void addQuestion() {
    if (totalQuestions >= MAX_QUESTIONS) {
        printf("Cannot add more questions. Maximum limit reached.\n");
        return;
    }

    Question q;
    getchar(); // Clear the newline left in the buffer
    printf("Enter the question: ");
    fgets(q.question, sizeof(q.question), stdin);
    q.question[strcspn(q.question, "\n")] = 0; // Remove newline character

    for (int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(q.options[i], sizeof(q.options[i]), stdin);
        q.options[i][strcspn(q.options[i], "\n")] = 0; // Remove newline character
    }

    printf("Enter the correct answer (1-4): ");
    scanf("%d", &q.answer);
    questionBank[totalQuestions++] = q;

    printf("Question added successfully!\n");
    getchar(); // Clear newline again
    printf("Press Enter to continue...");
    getchar();
}

void takeExam() {
    if (totalQuestions == 0) {
        printf("No questions available for the exam. Please add questions first.\n");
        return;
    }

    Participant p;
    getchar(); // Clear the newline left in the buffer
    printf("Enter your name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0; // Remove newline character
    p.score = 0;

    printf("Starting the exam...\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questionBank[i].question);
        for (int j = 0; j < 4; j++) {
            printf(" %d. %s\n", j + 1, questionBank[i].options[j]);
        }
        int answer;
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == questionBank[i].answer) {
            p.score++;
        }
    }

    participants[totalParticipants++] = p;
    printf("Exam finished! %s, your score is: %d/%d\n", p.name, p.score, totalQuestions);
    printf("Press Enter to continue...");
    getchar(); // Clear newline
    getchar();
}

void displayResults() {
    if (totalParticipants == 0) {
        printf("No results to display. Please take the exam first.\n");
        return;
    }

    printf("\n=== Exam Results ===\n");
    for (int i = 0; i < totalParticipants; i++) {
        printf("Participant: %s, Score: %d/%d\n", participants[i].name, participants[i].score, totalQuestions);
    }
    printf("Press Enter to continue...");
    getchar(); // Clear newline
    getchar();
}