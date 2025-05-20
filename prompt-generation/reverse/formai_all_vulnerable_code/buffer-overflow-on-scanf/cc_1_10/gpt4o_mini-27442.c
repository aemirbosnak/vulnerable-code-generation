//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CANDIDATES 50
#define MAX_NAME_LENGTH 100
#define MAX_OPTION_LENGTH 10

typedef struct {
    char question[256];
    char options[4][MAX_OPTION_LENGTH];
    int correct_option; // index of the correct option (0-based)
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Candidate;

Question questions[MAX_QUESTIONS];
Candidate candidates[MAX_CANDIDATES];
int totalQuestions = 0;
int totalCandidates = 0;

void addQuestion() {
    if (totalQuestions >= MAX_QUESTIONS) {
        printf("Maximum number of questions reached.\n");
        return;
    }

    printf("Enter the question: ");
    getchar();
    fgets(questions[totalQuestions].question, 256, stdin);
    questions[totalQuestions].question[strcspn(questions[totalQuestions].question, "\n")] = 0; // remove newline

    printf("Enter 4 options (separate by newlines):\n");
    for (int i = 0; i < 4; i++) {
        fgets(questions[totalQuestions].options[i], MAX_OPTION_LENGTH, stdin);
        questions[totalQuestions].options[i][strcspn(questions[totalQuestions].options[i], "\n")] = 0; // remove newline
    }

    printf("Enter the index of the correct option (0-3): ");
    scanf("%d", &questions[totalQuestions].correct_option);
    
    totalQuestions++;
    printf("Question added successfully!\n");
}

void registerCandidate() {
    if (totalCandidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    getchar();
    fgets(candidates[totalCandidates].name, MAX_NAME_LENGTH, stdin);
    candidates[totalCandidates].name[strcspn(candidates[totalCandidates].name, "\n")] = 0; // remove newline
    candidates[totalCandidates].score = 0; // initialize score

    totalCandidates++;
    printf("Candidate registered successfully!\n");
}

void conductExam() {
    for (int i = 0; i < totalCandidates; i++) {
        printf("\nStarting exam for %s. Good luck!\n", candidates[i].name);
        for (int j = 0; j < totalQuestions; j++) {
            printf("\nQ%d: %s\n", j + 1, questions[j].question);
            for (int k = 0; k < 4; k++) {
                printf("  %d. %s\n", k + 1, questions[j].options[k]);
            }

            int answer;
            printf("Your answer (1-4): ");
            scanf("%d", &answer);
            if (answer - 1 == questions[j].correct_option) {
                candidates[i].score++;
                printf("Correct!\n");
            } else {
                printf("Incorrect. The right answer was option %d.\n", questions[j].correct_option + 1);
            }
        }
        printf("\nExam finished! %s, your score: %d out of %d\n", candidates[i].name, candidates[i].score, totalQuestions);
    }
}

int main() {
    int choice;
    do {
        printf("\n*** Online Examination System ***\n");
        printf("1. Add Question\n");
        printf("2. Register Candidate\n");
        printf("3. Conduct Exam\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion();
                break;
            case 2:
                registerCandidate();
                break;
            case 3:
                conductExam();
                break;
            case 4:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}