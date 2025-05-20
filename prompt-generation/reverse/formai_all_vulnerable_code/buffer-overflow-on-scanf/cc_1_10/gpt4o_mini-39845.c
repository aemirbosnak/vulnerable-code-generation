//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 50
#define MAX_ANSWER_LENGTH 100
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 20
#define MAX_TITLE_LENGTH 50

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int score;
} User;

typedef struct {
    char title[MAX_TITLE_LENGTH];
    Question questions[MAX_QUESTIONS];
    int total_questions;
} Exam;

Exam exam;
User users[MAX_USERS];
int user_count = 0;

void create_exam() {
    printf("Enter exam title: ");
    fgets(exam.title, MAX_TITLE_LENGTH, stdin);
    exam.title[strcspn(exam.title, "\n")] = 0; // Remove newline character

    printf("How many questions do you want to add? ");
    scanf("%d", &exam.total_questions);
    getchar(); // Consume newline character

    for (int i = 0; i < exam.total_questions; i++) {
        printf("Enter question %d: ", i + 1);
        fgets(exam.questions[i].question, MAX_ANSWER_LENGTH, stdin);
        exam.questions[i].question[strcspn(exam.questions[i].question, "\n")] = 0;

        printf("Enter answer for question %d: ", i + 1);
        fgets(exam.questions[i].answer, MAX_ANSWER_LENGTH, stdin);
        exam.questions[i].answer[strcspn(exam.questions[i].answer, "\n")] = 0;
    }
    printf("Exam created successfully!\n");
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    printf("Enter username: ");
    fgets(users[user_count].username, MAX_USERNAME_LENGTH, stdin);
    users[user_count].username[strcspn(users[user_count].username, "\n")] = 0;

    printf("Enter password: ");
    fgets(users[user_count].password, MAX_PASSWORD_LENGTH, stdin);
    users[user_count].password[strcspn(users[user_count].password, "\n")] = 0;

    users[user_count].score = 0;
    user_count++;
    printf("User registered successfully!\n");
}

int login_user(User *logged_user) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            *logged_user = users[i];
            return 1; // Login successful
        }
    }
    return 0; // Login failed
}

void take_exam(User *logged_user) {
    printf("Starting Exam: %s\n", exam.title);
    char answer[MAX_ANSWER_LENGTH];

    for (int i = 0; i < exam.total_questions; i++) {
        printf("Question %d: %s\n", i + 1, exam.questions[i].question);
        printf("Your answer: ");
        fgets(answer, MAX_ANSWER_LENGTH, stdin);
        answer[strcspn(answer, "\n")] = 0;

        if (strcmp(answer, exam.questions[i].answer) == 0) {
            logged_user->score++;
        }
    }
    printf("Exam finished! Your score: %d/%d\n", logged_user->score, exam.total_questions);
}

int main() {
    int choice;
    User logged_user;

    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Create Exam\n");
        printf("2. Register User\n");
        printf("3. Login User\n");
        printf("4. Take Exam\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                create_exam();
                break;
            case 2:
                register_user();
                break;
            case 3:
                if (login_user(&logged_user)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed!\n");
                }
                break;
            case 4:
                if (logged_user.score >= 0) {
                    take_exam(&logged_user);
                } else {
                    printf("You must log in first!\n");
                }
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}