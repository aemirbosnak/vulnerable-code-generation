//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100
#define MAX_NAME_LENGTH 50
#define FILENAME "questions.txt"

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    int correct_option; // Store index of the correct option
} Question;

Question questions[MAX_QUESTIONS];
int question_count = 0;

void load_questions() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%[^\n]\n", questions[question_count].question) != EOF) {
        for (int i = 0; i < MAX_OPTIONS; i++) {
            fscanf(file, "%[^\n]\n", questions[question_count].options[i]);
        }
        fscanf(file, "%d\n", &questions[question_count].correct_option);
        question_count++;
    }
    fclose(file);
}

void display_questions() {
    for (int i = 0; i < question_count; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
    }
}

void take_exam() {
    int score = 0;

    for (int i = 0; i < question_count; i++) {
        int answer;
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);
        
        if (answer - 1 == questions[i].correct_option) {
            score++;
        }
    }
    
    printf("\nYour score: %d out of %d\n", score, question_count);
}

void save_question() {
    Question new_question;
    
    printf("Enter your question: ");
    getchar(); 
    fgets(new_question.question, MAX_ANSWER_LENGTH, stdin);
    new_question.question[strcspn(new_question.question, "\n")] = 0; // Remove newline

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(new_question.options[i], MAX_ANSWER_LENGTH, stdin);
        new_question.options[i][strcspn(new_question.options[i], "\n")] = 0; // Remove newline
    }
    
    printf("Enter correct option number (1-%d): ", MAX_OPTIONS);
    scanf("%d", &new_question.correct_option);
    new_question.correct_option -= 1; // Store zero-indexed in the struct

    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "%s\n", new_question.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        fprintf(file, "%s\n", new_question.options[i]);
    }
    fprintf(file, "%d\n", new_question.correct_option);
    fclose(file);
    
    printf("Question saved successfully!\n");
}

int main() {
    int choice;
    load_questions();
    
    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Take Exam\n");
        printf("2. View Questions\n");
        printf("3. Add Question\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                take_exam();
                break;
            case 2:
                display_questions();
                break;
            case 3:
                save_question();
                break;
            case 4:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}