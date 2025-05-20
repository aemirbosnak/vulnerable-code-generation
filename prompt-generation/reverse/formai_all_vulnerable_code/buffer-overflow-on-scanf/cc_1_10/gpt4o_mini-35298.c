//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_LENGTH 100

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int answer; // 0-indexed
} Question;

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int score;
} User;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS];
int questionCount = 0;

void welcomeMessage() {
    printf("\n=============================\n");
    printf("  Welcome to Happy Exam!    \n");
    printf("=============================\n");
}

void addUser() {
    if(userCount < MAX_USERS) {
        printf("Enter username: ");
        scanf("%s", users[userCount].username);
        printf("Enter password: ");
        scanf("%s", users[userCount].password);
        users[userCount].score = 0; // Default score is 0
        userCount++;
        printf("User registered successfully!\n");
    } else {
        printf("User limit reached! Cannot add more users.\n");
    }
}

int authenticateUser(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return i; // Return user index if authenticated
        }
    }
    return -1; // Not found
}

void addQuestion() {
    if(questionCount < MAX_QUESTIONS) {
        printf("Enter question: ");
        getchar(); // Clear buffer
        fgets(questions[questionCount].question, MAX_LENGTH, stdin);
        printf("Enter correct answer index (0 to %d): ", MAX_OPTIONS - 1);
        scanf("%d", &questions[questionCount].answer);
        for (int i = 0; i < MAX_OPTIONS; i++) {
            printf("Enter option %d: ", i + 1);
            getchar(); // Clear buffer
            fgets(questions[questionCount].options[i], MAX_LENGTH, stdin);
        }
        questionCount++;
        printf("Question added successfully!\n");
    } else {
        printf("Question limit reached! Cannot add more questions.\n");
    }
}

void conductExam(int userIndex) {
    printf("Starting exam for %s...\n", users[userIndex].username);
    users[userIndex].score = 0; // Reset score before exam
    
    for (int i = 0; i < questionCount; i++) {
        printf("\nQuestion %d: %s", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Option %d: %s", j + 1, questions[i].options[j]);
        }
        int userAnswer;
        printf("Enter your answer (1 to %d): ", MAX_OPTIONS);
        scanf("%d", &userAnswer);
        if (userAnswer - 1 == questions[i].answer) {
            printf("Correct!\n");
            users[userIndex].score++;
        } else {
            printf("Wrong answer! The correct answer was option %d.\n", questions[i].answer + 1);
        }
    }
    printf("Exam completed! Your score: %d/%d\n", users[userIndex].score, questionCount);
}

void viewProfile(int userIndex) {
    printf("User Profile for %s:\n", users[userIndex].username);
    printf("Score: %d\n", users[userIndex].score);
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Register User\n");
    printf("2. Login User\n");
    printf("3. Add Question\n");
    printf("4. Conduct Exam\n");
    printf("5. View Profile\n");
    printf("6. Exit\n");
}

int main() {
    welcomeMessage();
    int choice;
    int loggedInUser = -1;

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addUser();
                break;
            case 2:
                {
                    char username[MAX_LENGTH], password[MAX_LENGTH];
                    printf("Enter username: ");
                    scanf("%s", username);
                    printf("Enter password: ");
                    scanf("%s", password);
                    loggedInUser = authenticateUser(username, password);
                    if (loggedInUser != -1) {
                        printf("Login successful!\n");
                    } else {
                        printf("Invalid credentials!\n");
                    }
                }
                break;
            case 3:
                addQuestion();
                break;
            case 4:
                if (loggedInUser != -1) {
                    conductExam(loggedInUser);
                } else {
                    printf("Please login first!\n");
                }
                break;
            case 5:
                if (loggedInUser != -1) {
                    viewProfile(loggedInUser);
                } else {
                    printf("Please login first!\n");
                }
                break;
            case 6:
                printf("Thanks for using Happy Exam! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}