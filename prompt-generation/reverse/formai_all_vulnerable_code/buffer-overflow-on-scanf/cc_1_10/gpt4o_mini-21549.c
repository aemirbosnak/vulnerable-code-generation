//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_USERS 50
#define QUESTION_LENGTH 256
#define OPTION_LENGTH 128
#define USERNAME_LENGTH 32
#define PASSWORD_LENGTH 32

typedef struct {
    char question[QUESTION_LENGTH];
    char options[MAX_OPTIONS][OPTION_LENGTH];
    int correct_option;
} Question;

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

Question questions[MAX_QUESTIONS];
User users[MAX_USERS];
int question_count = 0;
int user_count = 0;

void add_question() {
    if (question_count >= MAX_QUESTIONS) {
        printf("Cannot add more questions!\n");
        return;
    }
    
    printf("Enter the question: ");
    getchar(); // clear newline
    fgets(questions[question_count].question, QUESTION_LENGTH, stdin);
    questions[question_count].question[strcspn(questions[question_count].question, "\n")] = 0; // Remove newline character

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[question_count].options[i], OPTION_LENGTH, stdin);
        questions[question_count].options[i][strcspn(questions[question_count].options[i], "\n")] = 0;
    }

    printf("Enter the correct option number (1 to %d): ", MAX_OPTIONS);
    scanf("%d", &questions[question_count].correct_option);
    question_count++;
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    
    printf("Enter username: ");
    scanf("%s", users[user_count].username);
    
    printf("Enter password: ");
    scanf("%s", users[user_count].password);
    user_count++;
}

int authenticate_user() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Authenticated
        }
    }
    return 0; // Not authenticated
}

void take_exam() {
    int score = 0;

    for (int i = 0; i < question_count; i++) {
        printf("\nQuestion %d: %s", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Option %d: %s\n", j + 1, questions[i].options[j]);
        }
        int user_answer;
        printf("Enter your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &user_answer);
        if (user_answer == questions[i].correct_option) {
            score++;
        }
    }
    printf("Your total score is: %d out of %d\n", score, question_count);
}

void display_menu() {
    printf("\n1. Add Question\n");
    printf("2. Register User\n");
    printf("3. Take Exam\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                register_user();
                break;
            case 3:
                if (authenticate_user()) {
                    take_exam();
                } else {
                    printf("Authentication failed! Please try again.\n");
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}