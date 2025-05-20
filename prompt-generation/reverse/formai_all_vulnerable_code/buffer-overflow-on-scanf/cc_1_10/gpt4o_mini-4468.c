//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTION_LENGTH 50
#define MAX_NAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 20

struct Question {
    char questionText[256];
    char options[4][MAX_OPTION_LENGTH];
    int correctOption; // index of the correct option (0-3)
};

struct User {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct Question questionBank[MAX_QUESTIONS];
int questionCount = 0;

void addQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Question bank is full!\n");
        return;
    }

    struct Question q;
    printf("Enter the question text: ");
    getchar(); // clear buffer
    fgets(q.questionText, sizeof(q.questionText), stdin);
    
    printf("Enter option 1: ");
    fgets(q.options[0], sizeof(q.options[0]), stdin);
    printf("Enter option 2: ");
    fgets(q.options[1], sizeof(q.options[1]), stdin);
    printf("Enter option 3: ");
    fgets(q.options[2], sizeof(q.options[2]), stdin);
    printf("Enter option 4: ");
    fgets(q.options[3], sizeof(q.options[3]), stdin);
    
    printf("Enter the correct option (1-4): ");
    scanf("%d", &q.correctOption);
    q.correctOption--; // convert to zero-indexed
    
    questionBank[questionCount] = q;
    questionCount++;
    printf("Question added successfully!\n");
}

void displayQuestions() {
    for (int i = 0; i < questionCount; i++) {
        printf("%d. %s", i + 1, questionBank[i].questionText);
        for (int j = 0; j < 4; j++) {
            printf("\t%d. %s", j + 1, questionBank[i].options[j]);
        }
        printf("Correct option: %d\n", questionBank[i].correctOption + 1);
    }
}

int evaluateQuiz() {
    int score = 0;
    for (int i = 0; i < questionCount; i++) {
        printf("%s", questionBank[i].questionText);
        for (int j = 0; j < 4; j++) {
            printf("\t%d. %s", j + 1, questionBank[i].options[j]);
        }
        int userAnswer;
        printf("Your answer (1-4): ");
        scanf("%d", &userAnswer);
        if (userAnswer - 1 == questionBank[i].correctOption) {
            score++;
        }
    }
    return score;
}

int login(struct User *user) {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your name: ");
    getchar(); // clear buffer
    fgets(username, sizeof(username), stdin);
    
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    username[strcspn(username, "\n")] = '\0'; // remove newline character
    password[strcspn(password, "\n")] = '\0'; // remove newline character

    if (strcmp(user->name, username) == 0 && strcmp(user->password, password) == 0) {
        return 1; // successful login
    }
    return 0; // failed login
}

void setupUser(struct User *user) {
    printf("Setup user account\n");
    printf("Enter your name: ");
    getchar();
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = 0; // remove newline character

    printf("Enter your password: ");
    fgets(user->password, sizeof(user->password), stdin);
    user->password[strcspn(user->password, "\n")] = 0; // remove newline character
}

int main() {
    struct User adminUser = {"admin", "admin123"};
    int menuChoice;
    int isLoggedIn = 0;

    while (1) {
        printf("\nOnline Examination System\n");
        if (!isLoggedIn) {
            printf("1. Login\n");
            printf("2. Setup User\n");
            printf("0. Exit\n");
            printf("Choose an option: ");
            scanf("%d", &menuChoice);
            switch (menuChoice) {
                case 1:
                    isLoggedIn = login(&adminUser);
                    if (isLoggedIn) {
                        printf("Login successful!\n");
                    } else {
                        printf("Login failed. Please try again.\n");
                    }
                    break;
                case 2:
                    setupUser(&adminUser);
                    break;
                case 0:
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        } else {
            printf("1. Add Question\n");
            printf("2. Display Questions\n");
            printf("3. Start Quiz\n");
            printf("0. Logout\n");
            printf("Choose an option: ");
            scanf("%d", &menuChoice);
            switch (menuChoice) {
                case 1:
                    addQuestion();
                    break;
                case 2:
                    displayQuestions();
                    break;
                case 3:
                    {
                        int score = evaluateQuiz();
                        printf("You scored %d out of %d.\n", score, questionCount);
                    }
                    break;
                case 0:
                    isLoggedIn = 0;
                    printf("Logged out successfully.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
    }
    return 0;
}