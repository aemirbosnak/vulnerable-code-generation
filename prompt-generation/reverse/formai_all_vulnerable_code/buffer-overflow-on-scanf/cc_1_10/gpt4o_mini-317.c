//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_LEN 256

typedef struct {
    char question[MAX_LEN];
    char options[MAX_OPTIONS][MAX_LEN];
    int answer; // index of the correct option
} Question;

Question questions[MAX_QUESTIONS];
int question_count = 0;

void add_question() {
    if (question_count >= MAX_QUESTIONS) {
        printf("Cannot add more questions!\n");
        return;
    }

    printf("Enter the question: ");
    getchar(); // Consume newline
    fgets(questions[question_count].question, MAX_LEN, stdin);
    questions[question_count].question[strcspn(questions[question_count].question, "\n")] = 0; // Remove newline

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[question_count].options[i], MAX_LEN, stdin);
        questions[question_count].options[i][strcspn(questions[question_count].options[i], "\n")] = 0; // Remove newline
    }
    
    printf("Enter the correct option number (1-%d): ", MAX_OPTIONS);
    scanf("%d", &questions[question_count].answer);
    questions[question_count].answer--; // Store zero-based index

    question_count++;
    printf("Question added successfully!\n");
}

void save_questions() {
    FILE *file = fopen("questions.dat", "wb");
    if (!file) {
        printf("Error saving questions!\n");
        return;
    }
    fwrite(questions, sizeof(Question), question_count, file);
    fclose(file);
    printf("Questions saved successfully!\n");
}

void load_questions() {
    FILE *file = fopen("questions.dat", "rb");
    if (!file) {
        printf("No saved questions found!\n");
        return;
    }
    
    question_count = fread(questions, sizeof(Question), MAX_QUESTIONS, file);
    fclose(file);
    printf("%d questions loaded successfully!\n", question_count);
}

void take_exam() {
    if (question_count == 0) {
        printf("No questions available for examination! Please add questions first.\n");
        return;
    }

    int score = 0;
    for (int i = 0; i < question_count; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("  Option %d: %s\n", j + 1, questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);
        
        if (answer - 1 == questions[i].answer) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Wrong answer. The correct answer was option %d.\n", questions[i].answer + 1);
        }
    }
    printf("Exam finished! Your score: %d out of %d\n", score, question_count);
}

void display_menu() {
    printf("\n===== Online Examination System =====\n");
    printf("1. Add Question\n");
    printf("2. Save Questions\n");
    printf("3. Load Questions\n");
    printf("4. Take Exam\n");
    printf("5. Exit\n");
    printf("=====================================\n");
    printf("Select an option: ");
}

int main() {
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                save_questions();
                break;
            case 3:
                load_questions();
                break;
            case 4:
                take_exam();
                break;
            case 5:
                printf("Thank you for using the Online Examination System!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    
    return 0;
}