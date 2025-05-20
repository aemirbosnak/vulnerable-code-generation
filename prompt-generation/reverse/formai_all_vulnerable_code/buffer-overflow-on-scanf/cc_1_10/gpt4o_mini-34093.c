//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_EXAMS 10
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[4][MAX_ANSWER_LENGTH];
    int answer; // index of correct option (0-3)
} Question;

typedef struct {
    char username[20];
    char password[20];
    int examsTaken;
} User;

typedef struct {
    char title[50];
    Question questions[MAX_QUESTIONS];
    int numQuestions;
} Exam;

User users[MAX_USERS];
int userCount = 0;

Exam exams[MAX_EXAMS];
int examCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    users[userCount].examsTaken = 0;
    userCount++;
    printf("User registered successfully!\n");
}

int loginUser() {
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // return user index
        }
    }
    printf("Login failed!\n");
    return -1; // login failed
}

void createExam() {
    if (examCount >= MAX_EXAMS) {
        printf("Max exams limit reached!\n");
        return;
    }
    printf("Enter exam title: ");
    scanf("%s", exams[examCount].title);
    exams[examCount].numQuestions = 0;

    while (exams[examCount].numQuestions < MAX_QUESTIONS) {
        Question q;
        printf("Enter question (or 'done' to finish): ");
        getchar(); // clear the buffer
        fgets(q.question, MAX_ANSWER_LENGTH, stdin);
        q.question[strcspn(q.question, "\n")] = 0; // remove newline

        if (strcmp(q.question, "done") == 0) break;

        for (int i = 0; i < 4; i++) {
            printf("Enter option %d: ", i + 1);
            fgets(q.options[i], MAX_ANSWER_LENGTH, stdin);
            q.options[i][strcspn(q.options[i], "\n")] = 0; // remove newline
        }

        printf("Enter correct option (1-4): ");
        scanf("%d", &q.answer);
        q.answer--; // adjust for index from 0-3

        exams[examCount].questions[exams[examCount].numQuestions] = q;
        exams[examCount].numQuestions++;
    }
    
    examCount++;
    printf("Exam created successfully!\n");
}

void takeExam(int userIndex) {
    if (examCount == 0) {
        printf("No exams available!\n");
        return;
    }

    printf("Available Exams:\n");
    for (int i = 0; i < examCount; i++) {
        printf("%d. %s\n", i + 1, exams[i].title);
    }

    int examChoice;
    printf("Select an exam to take (1-%d): ", examCount);
    scanf("%d", &examChoice);
    examChoice--; // adjust for index

    if (examChoice < 0 || examChoice >= examCount) {
        printf("Invalid exam choice!\n");
        return;
    }

    User *user = &users[userIndex];
    printf("Taking exam: %s\n", exams[examChoice].title);
    int score = 0;

    for (int i = 0; i < exams[examChoice].numQuestions; i++) {
        Question q = exams[examChoice].questions[i];
        printf("Q%d: %s\n", i + 1, q.question);
        for (int j = 0; j < 4; j++) {
            printf("  %d. %s\n", j + 1, q.options[j]);
        }
        
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer - 1 == q.answer) {
            score++;
        }
    }

    user->examsTaken++;
    printf("Exam finished! Your score: %d/%d\n", score, exams[examChoice].numQuestions);
}

int main() {
    int option;
    while (1) {
        printf("\n1. Register\n2. Login\n3. Create Exam\n4. Take Exam\n5. Exit\nEnter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                registerUser();
                break;
            case 2: {
                int userIndex = loginUser();
                if (userIndex != -1) {
                    printf("Welcome %s!\n", users[userIndex].username);
                }
                break;
            }
            case 3:
                createExam();
                break;
            case 4: {
                int userIndex = loginUser();
                if (userIndex != -1) {
                    takeExam(userIndex);
                }
                break;
            }
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}