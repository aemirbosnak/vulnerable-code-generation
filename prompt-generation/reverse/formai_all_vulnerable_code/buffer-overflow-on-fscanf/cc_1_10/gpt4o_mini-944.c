//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_LENGTH 100

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int answer; // option number (0-3) of the correct answer
} Question;

typedef struct {
    char name[MAX_LENGTH];
    int scores;
} User;

Question questions[MAX_QUESTIONS];
int totalQuestions = 0;

void loadQuestions() {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        printf("Could not open questions file!\n");
        return;
    }
    while (fscanf(file, " %[^\n] ", questions[totalQuestions].question) != EOF) {
        for (int i = 0; i < MAX_OPTIONS; i++) {
            fscanf(file, " %[^\n] ", questions[totalQuestions].options[i]);
        }
        fscanf(file, "%d", &questions[totalQuestions].answer);
        totalQuestions++;
    }
    fclose(file);
}

void displayQuestion(int index) {
    printf("Q%d: %s\n", index + 1, questions[index].question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf(" %c. %s\n", 'A' + i, questions[index].options[i]);
    }
}

int takeExam() {
    int score = 0;
    for (int i = 0; i < totalQuestions; i++) {
        displayQuestion(i);
        printf("Your answer (A/B/C/D): ");
        char answer;
        scanf(" %c", &answer);
        int selectedOption = answer - 'A';
        if (selectedOption >= 0 && selectedOption < MAX_OPTIONS) {
            if (selectedOption == questions[i].answer) {
                score++;
            }
        }
    }
    return score;
}

void saveResult(char *name, int score) {
    FILE *file = fopen("results.txt", "a");
    if (file == NULL) {
        printf("Could not open results file!\n");
        return;
    }
    fprintf(file, "%s: %d\n", name, score);
    fclose(file);
}

void displayResults() {
    FILE *file = fopen("results.txt", "r");
    if (file == NULL) {
        printf("No results available!\n");
        return;
    }
    char line[MAX_LENGTH];
    printf("Results:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    loadQuestions();
    
    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Take Exam\n");
        printf("2. View Results\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[MAX_LENGTH];
                printf("Enter your name: ");
                scanf(" %[^\n]", name);
                int score = takeExam();
                printf("You scored: %d out of %d\n", score, totalQuestions);
                saveResult(name, score);
                break;
            }
            case 2:
                displayResults();
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}