//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_OPTION_LENGTH 50

typedef struct {
    char question[256];
    char options[4][MAX_OPTION_LENGTH];
    int correctAnswer; // 0-indexed
} Question;

typedef struct {
    char username[50];
    char password[50];
    int score;
} User;

typedef struct {
    char title[100];
    Question questions[MAX_QUESTIONS];
    int questionCount;
} Exam;

User users[MAX_USERS];
int userCount = 0;
Exam exams[MAX_USERS];
int examCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
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

void createExam() {
    if (examCount >= MAX_USERS) {
        printf("Exam limit reached. Cannot create more exams.\n");
        return;
    }

    printf("Enter exam title: ");
    scanf(" %[^\n]", exams[examCount].title);
    exams[examCount].questionCount = 0;

    int numberOfQuestions;
    printf("Enter number of questions: ");
    scanf("%d", &numberOfQuestions);

    for (int i = 0; i < numberOfQuestions; i++) {
        if (exams[examCount].questionCount >= MAX_QUESTIONS) {
            printf("Maximum number of questions reached for this exam.\n");
            break;
        }

        printf("Enter question %d: ", i + 1);
        scanf(" %[^\n]", exams[examCount].questions[exams[examCount].questionCount].question);

        for (int j = 0; j < 4; j++) {
            printf("Enter option %d: ", j + 1);
            scanf(" %[^\n]", exams[examCount].questions[exams[examCount].questionCount].options[j]);
        }

        printf("Enter the index of the correct answer (1-4): ");
        scanf("%d", &exams[examCount].questions[exams[examCount].questionCount].correctAnswer);
        exams[examCount].questions[exams[examCount].questionCount].correctAnswer--;

        exams[examCount].questionCount++;
    }

    examCount++;
    printf("Exam created successfully!\n");
}

void takeExam(char *username) {
    for (int i = 0; i < examCount; i++) {
        printf("\nExam Title: %s\n", exams[i].title);
        int score = 0;

        for (int j = 0; j < exams[i].questionCount; j++) {
            printf("Question %d: %s\n", j + 1, exams[i].questions[j].question);
            for (int k = 0; k < 4; k++) {
                printf("  %d. %s\n", k + 1, exams[i].questions[j].options[k]);
            }

            int answer;
            printf("Your answer (1-4): ");
            scanf("%d", &answer);
            if (answer - 1 == exams[i].questions[j].correctAnswer) {
                score++;
            }
        }

        printf("You scored %d out of %d in exam '%s'\n", score, exams[i].questionCount, exams[i].title);
        for (int u = 0; u < userCount; u++) {
            if (strcmp(users[u].username, username) == 0) {
                users[u].score += score; // Update user total score
            }
        }
    }
}

void displayScores() {
    printf("\nScores:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s: %d\n", users[i].username, users[i].score);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Register\n");
        printf("2. Create Exam\n");
        printf("3. Take Exam\n");
        printf("4. Display Scores\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                createExam();
                break;
            case 3: {
                char username[50];
                printf("Enter your username: ");
                scanf("%s", username);
                takeExam(username);
                break;
            }
            case 4:
                displayScores();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}