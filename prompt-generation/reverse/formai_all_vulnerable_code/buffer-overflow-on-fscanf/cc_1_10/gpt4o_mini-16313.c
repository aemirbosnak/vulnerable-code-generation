//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTION_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[255];
    char options[4][MAX_OPTION_LENGTH];
    int correct_option; // 0-based index for correct answer
} Question;

Question questions[MAX_QUESTIONS];
int question_count = 0;

void load_questions(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open questions file.\n");
        return;
    }
    
    while (fscanf(file, " %[^\n]\n", questions[question_count].question) != EOF) {
        for (int i = 0; i < 4; i++) {
            fscanf(file, " %[^\n]\n", questions[question_count].options[i]);
        }
        fscanf(file, "%d\n", &questions[question_count].correct_option);
        question_count++;
    }
    
    fclose(file);
}

void display_questions() {
    for (int i = 0; i < question_count; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("   %c. %s\n", 'A' + j, questions[i].options[j]);
        }
        printf("\n");
    }
}

int take_exam() {
    int score = 0;
    for (int i = 0; i < question_count; i++) {
        char answer;
        printf("Q%d: %s\n", i + 1, questions[i].question);
        
        for (int j = 0; j < 4; j++) {
            printf("   %c. %s\n", 'A' + j, questions[i].options[j]);
        }
        
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        answer = toupper(answer);
        
        if (answer >= 'A' && answer <= 'D' && (answer - 'A') == questions[i].correct_option) {
            score++;
        }
        printf("\n");
    }
    return score;
}

void save_results(const char *name, int score) {
    FILE *file = fopen("results.txt", "a");
    fprintf(file, "Name: %s, Score: %d/%d\n", name, score, question_count);
    fclose(file);
}

void view_results() {
    char line[255];
    FILE *file = fopen("results.txt", "r");
    if (!file) {
        printf("No results to display.\n");
        return;
    }
    
    printf("Exam Results:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    fclose(file);
}

int main() {
    char name[MAX_NAME_LENGTH];
    int choice;
    load_questions("questions.txt");
    
    printf("Welcome to the Online Examination System\n");
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character
    
    do {
        printf("\nMenu:\n");
        printf("1. Take Exam\n");
        printf("2. View Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                {
                    int score = take_exam();
                    printf("You scored %d out of %d\n", score, question_count);
                    save_results(name, score);
                }
                break;
            case 2:
                view_results();
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}