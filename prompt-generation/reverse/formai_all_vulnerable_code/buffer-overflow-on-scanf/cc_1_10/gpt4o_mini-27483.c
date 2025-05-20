//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 50
#define MAX_LEN 100

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
} User;

typedef struct {
    int id;
    char question[MAX_LEN];
    char options[4][MAX_LEN];
    int answer; // index of correct answer
} Question;

User users[MAX_USERS];
int user_count = 0;

Question questions[MAX_QUESTIONS];
int question_count = 0;

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User registration limit reached!\n");
        return;
    }
    
    printf("Enter username: ");
    scanf("%s", users[user_count].username);
    printf("Enter password: ");
    scanf("%s", users[user_count].password);
    user_count++;
    printf("User registered successfully!\n");
}

void add_question() {
    if (question_count >= MAX_QUESTIONS) {
        printf("Question limit reached!\n");
        return;
    }
    
    printf("Enter question ID: ");
    scanf("%d", &questions[question_count].id);
    printf("Enter question: ");
    getchar(); // consume the newline character
    fgets(questions[question_count].question, MAX_LEN, stdin);
    questions[question_count].question[strcspn(questions[question_count].question, "\n")] = 0; // remove newline

    for (int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[question_count].options[i], MAX_LEN, stdin);
        questions[question_count].options[i][strcspn(questions[question_count].options[i], "\n")] = 0; // remove newline
    }
    
    printf("Enter index of correct answer (0 to 3): ");
    scanf("%d", &questions[question_count].answer);
    question_count++;
    printf("Question added successfully!\n");
}

void take_exam() {
    int score = 0;
    for (int i = 0; i < question_count; i++) {
        printf("\nQuestion %d: %s\n", questions[i].id, questions[i].question);
        
        for (int j = 0; j < 4; j++) {
            printf("Option %d: %s\n", j + 1, questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        
        if (answer - 1 == questions[i].answer) {
            score++;
        }
    }
    printf("Your score: %d out of %d\n", score, question_count);
}

void display_menu() {
    printf("\nOnline Examination System\n");
    printf("1. Register User\n");
    printf("2. Add Question\n");
    printf("3. Take Exam\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                add_question();
                break;
            case 3:
                take_exam();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}