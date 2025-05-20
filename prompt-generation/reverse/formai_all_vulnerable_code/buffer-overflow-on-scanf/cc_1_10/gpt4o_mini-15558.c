//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_LENGTH 100

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct {
    char question[MAX_LENGTH];
    char options[4][MAX_LENGTH];
    int answer; // Index of correct answer (0-3)
} Question;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS];
int questionCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot register new users.\n");
        return;
    }
    
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[userCount++] = newUser;
    printf("User registered successfully!\n");
}

int loginUser() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && 
            strcmp(users[i].password, password) == 0) {
            printf("Login successful! Welcome, %s\n", username);
            return 1; // Successful login
        }
    }
    printf("Invalid username or password.\n");
    return 0; // Failed login
}

void addQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Question limit reached! Cannot add more questions.\n");
        return;
    }

    Question newQuestion;
    printf("Enter question: ");
    getchar(); // To consume newline character left by previous input
    fgets(newQuestion.question, MAX_LENGTH, stdin);
    newQuestion.question[strcspn(newQuestion.question, "\n")] = 0; // Remove newline

    for (int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(newQuestion.options[i], MAX_LENGTH, stdin);
        newQuestion.options[i][strcspn(newQuestion.options[i], "\n")] = 0; // Remove newline
    }

    printf("Enter correct option number (1-4): ");
    scanf("%d", &newQuestion.answer);
    newQuestion.answer--; // Convert to zero-based index

    questions[questionCount++] = newQuestion;
    printf("Question added successfully!\n");
}

void takeExam() {
    if (questionCount == 0) {
        printf("No questions available for the exam.\n");
        return;
    }

    int score = 0;
    for (int i = 0; i < questionCount; i++) {
        printf("\nQuestion %d: %s", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf(" %d: %s\n", j + 1, questions[i].options[j]);
        }

        int userAnswer;
        printf("Your answer (1-4): ");
        scanf("%d", &userAnswer);

        if (userAnswer - 1 == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %s\n", questions[i].options[questions[i].answer]);
        }
    }
    printf("Your total score: %d out of %d\n", score, questionCount);
}

int main() {
    int choice;
    do {
        printf("\nOnline Examination System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Add Question (Admin)\n");
        printf("4. Take Exam\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    // Login successful
                }
                break;
            case 3:
                addQuestion();
                break;
            case 4:
                takeExam();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}