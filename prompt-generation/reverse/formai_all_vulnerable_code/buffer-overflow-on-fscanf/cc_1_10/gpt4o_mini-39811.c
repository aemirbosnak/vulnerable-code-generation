//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define BUFFER_SIZE 256

typedef struct {
    char element[BUFFER_SIZE];
    char symbol[BUFFER_SIZE];
} Question;

Question questions[MAX_QUESTIONS];
int question_count = 0;

void loadQuestions(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Couldn't open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", questions[question_count].element,
                  questions[question_count].symbol) == 2) {
        question_count++;
    }
    
    fclose(file);
}

void askQuestion(int index) {
    char answer[BUFFER_SIZE];
    printf("What is the symbol for %s? ", questions[index].element);
    scanf("%s", answer);
    if (strcmp(answer, questions[index].symbol) == 0) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is %s.\n", questions[index].symbol);
    }
}

void startQuiz() {
    int score = 0;
    for (int i = 0; i < question_count; i++) {
        printf("\nQuestion %d:\n", i + 1);
        askQuestion(i);
        score++;
    }
    printf("\nYour total score: %d/%d\n", score, question_count);
}

void displayMenu() {
    printf("Periodic Table Quiz\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    const char *filename = "elements.txt";
    loadQuestions(filename);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                startQuiz();
                break;
            case 2:
                printf("Exiting the quiz. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}