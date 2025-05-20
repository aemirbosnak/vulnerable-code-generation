//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTION 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[256];
    char options[MAX_OPTION][256];
    int answer; // index of the correct option
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} User;

void displayMenu() {
    printf("\n================== Online Examination System ==================\n");
    printf("1. Start Examination\n");
    printf("2. Exit\n");
    printf("===============================================================\n");
    printf("Please choose an option: ");
}

void loadQuestions(Question *questions, int *numQuestions) {
    // Simulating question loading (can be replaced with file handling)
    *numQuestions = 3; // Let's say we have 3 questions for simplicity

    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "1. Berlin");
    strcpy(questions[0].options[1], "2. Madrid");
    strcpy(questions[0].options[2], "3. Paris");
    strcpy(questions[0].options[3], "4. Rome");
    questions[0].answer = 2;

    strcpy(questions[1].question, "Which gas do plants absorb?");
    strcpy(questions[1].options[0], "1. Oxygen");
    strcpy(questions[1].options[1], "2. Nitrogen");
    strcpy(questions[1].options[2], "3. Carbon dioxide");
    strcpy(questions[1].options[3], "4. Hydrogen");
    questions[1].answer = 2;

    strcpy(questions[2].question, "What is the smallest prime number?");
    strcpy(questions[2].options[0], "1. 0");
    strcpy(questions[2].options[1], "2. 1");
    strcpy(questions[2].options[2], "3. 2");
    strcpy(questions[2].options[3], "4. 3");
    questions[2].answer = 2;
}

void startExamination(User *user, Question *questions, int numQuestions) {
    user->score = 0;
    printf("Welcome, %s! Let's start the examination!\n", user->name);

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("%s\n", questions[i].options[j]);
        }

        printf("Please enter your answer (1-%d): ", MAX_OPTION);
        int answer;
        scanf("%d", &answer);

        if (answer - 1 == questions[i].answer) {
            printf("Correct!\n");
            user->score++;
        } else {
            printf("Wrong! The correct answer was: %s\n", questions[i].options[questions[i].answer]);
        }
    }

    printf("\nExamination over! Your score: %d out of %d\n", user->score, numQuestions);
}

int main() {
    User user;
    Question questions[MAX_QUESTIONS];
    int numQuestions;

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    fgets(user.name, MAX_NAME_LENGTH, stdin);
    user.name[strcspn(user.name, "\n")] = 0; // Remove newline character

    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loadQuestions(questions, &numQuestions);
                startExamination(&user, questions, numQuestions);
                break;
            case 2:
                printf("Thank you for using the Online Examination System! Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}