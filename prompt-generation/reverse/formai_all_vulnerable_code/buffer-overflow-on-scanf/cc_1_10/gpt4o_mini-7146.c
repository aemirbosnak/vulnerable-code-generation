//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_STRING_LENGTH 100

typedef struct {
    char username[MAX_STRING_LENGTH];
    char password[MAX_STRING_LENGTH];
    int score;
} User;

typedef struct {
    char question[MAX_STRING_LENGTH];
    char options[4][MAX_STRING_LENGTH];
    int answer; // Index of correct answer (0 to 3)
} Question;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS];
int questionCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register new users.\n");
        return;
    }
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    newUser.score = 0;
    users[userCount++] = newUser;
    printf("Registration successful!\n");
}

int loginUser(User *currentUser) {
    char username[MAX_STRING_LENGTH];
    char password[MAX_STRING_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            *currentUser = users[i];
            return 1;
        }
    }
    printf("Invalid username or password.\n");
    return 0;
}

void addQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Question limit reached.\n");
        return;
    }

    Question newQuestion;
    printf("Enter question: ");
    getchar(); // Consume newline character
    fgets(newQuestion.question, MAX_STRING_LENGTH, stdin);
    printf("Enter 4 options:\n");
    for (int i = 0; i < 4; i++) {
        printf("Option %d: ", i + 1);
        fgets(newQuestion.options[i], MAX_STRING_LENGTH, stdin);
    }
    printf("Enter the correct option number (1-4): ");
    scanf("%d", &newQuestion.answer);
    newQuestion.answer -= 1; // Adjust for 0-based index

    questions[questionCount++] = newQuestion;
    printf("Question added successfully!\n");
}

void takeExam(User *currentUser) {
    int score = 0;

    printf("\nStarting the exam...\n");
    for (int i = 0; i < questionCount; i++) {
        printf("\nQuestion %d: %s", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d) %s", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer - 1 == questions[i].answer) {
            score++;
        }
    }
    currentUser->score = score;
    printf("\nExam completed! Your score: %d/%d\n", score, questionCount);
}

void viewResults(User *currentUser) {
    printf("\nYour previous score: %d\n", currentUser->score);
}

int main() {
    int choice;
    User currentUser;

    while (1) {
        printf("\n--- Online Examination System ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Add Question (Admin)\n");
        printf("4. Take Exam\n");
        printf("5. View Results\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser(&currentUser)) {
                    printf("Login successful! Welcome, %s\n", currentUser.username);
                }
                break;
            case 3:
                addQuestion();
                break;
            case 4:
                takeExam(&currentUser);
                break;
            case 5:
                viewResults(&currentUser);
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}