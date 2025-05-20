//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 50
#define MAX_OPTION_LENGTH 100

typedef struct {
    char question[MAX_OPTION_LENGTH];
    char options[4][MAX_OPTION_LENGTH];
    int answer; // index of the correct option (0-based)
} Question;

typedef struct {
    char username[MAX_OPTION_LENGTH];
    char password[MAX_OPTION_LENGTH];
    int score;
} User;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS];
int questionCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    users[userCount].score = 0;
    userCount++;
    printf("User registered successfully!\n");
}

void createQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Question limit reached!\n");
        return;
    }
    printf("Enter question: ");
    scanf(" %[^\n]", questions[questionCount].question);
    for (int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        scanf(" %[^\n]", questions[questionCount].options[i]);
    }
    printf("Enter the correct option number (1-4): ");
    scanf("%d", &questions[questionCount].answer);
    questions[questionCount].answer--; // 0-based index
    questionCount++;
    printf("Question created successfully!\n");
}

void takeExam(User *user) {
    printf("Starting exam...\n");
    for (int i = 0; i < questionCount; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer - 1 == questions[i].answer) {
            user->score++;
        }
    }
    printf("Exam finished! Your score: %d out of %d\n", user->score, questionCount);
}

void displayResults(User *user) {
    printf("Results for user: %s\n", user->username);
    printf("Score: %d out of %d\n", user->score, questionCount);
}

void loginUser(User **currentUser) {
    char username[MAX_OPTION_LENGTH], password[MAX_OPTION_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            *currentUser = &users[i];
            printf("Login successful!\n");
            return;
        }
    }
    printf("Login failed! Check credentials.\n");
    *currentUser = NULL;
}

int main() {
    User *currentUser = NULL;
    int choice;

    do {
        printf("\nOnline Examination System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Create Question\n");
        printf("4. Take Exam\n");
        printf("5. Display Results\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser(&currentUser);
                break;
            case 3:
                if (currentUser != NULL) {
                    createQuestion();
                } else {
                    printf("You need to login first.\n");
                }
                break;
            case 4:
                if (currentUser != NULL) {
                    takeExam(currentUser);
                } else {
                    printf("You need to login first.\n");
                }
                break;
            case 5:
                if (currentUser != NULL) {
                    displayResults(currentUser);
                } else {
                    printf("You need to login first.\n");
                }
                break;
            case 6:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}