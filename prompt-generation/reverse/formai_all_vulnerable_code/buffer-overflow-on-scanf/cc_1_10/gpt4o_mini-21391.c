//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][100];
    int answer; // index of the correct option
} Question;

typedef struct {
    char username[50];
    char password[50];
} User;

User users[MAX_USERS];
Question questions[MAX_QUESTIONS];
int userCount = 0, questionCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    
    userCount++;
    printf("User registered successfully!\n");
}

int authenticateUser() {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; ++i) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return 1; // authentication success
        }
    }
    printf("Invalid credentials.\n");
    return 0; // authentication failed
}

void addQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Question limit reached.\n");
        return;
    }
    
    printf("Enter question: ");
    getchar(); // clear buffer
    fgets(questions[questionCount].question, sizeof(questions[questionCount].question), stdin);
    questions[questionCount].question[strcspn(questions[questionCount].question, "\n")] = 0; // remove newline

    for (int i = 0; i < MAX_OPTIONS; ++i) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[questionCount].options[i], sizeof(questions[questionCount].options[i]), stdin);
        questions[questionCount].options[i][strcspn(questions[questionCount].options[i], "\n")] = 0; // remove newline
    }
    
    printf("Enter correct answer (option number 1-%d): ", MAX_OPTIONS);
    scanf("%d", &questions[questionCount].answer);
    questionCount++;
    printf("Question added successfully!\n");
}

void conductExam() {
    int score = 0;
    for (int i = 0; i < questionCount; ++i) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; ++j) {
            printf("  %d. %s\n", j + 1, questions[i].options[j]);
        }
        int userAnswer;
        printf("Your answer: ");
        scanf("%d", &userAnswer);
        if (userAnswer == questions[i].answer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer is %d.\n", questions[i].answer);
        }
    }
    printf("You scored %d out of %d.\n", score, questionCount);
}

void displayMenu() {
    printf("\nOnline Examination System\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Add Question\n");
    printf("4. Conduct Exam\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (authenticateUser()) {
                    printf("Logged in successfully!\n");
                }
                break;
            case 3:
                addQuestion();
                break;
            case 4:
                conductExam();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}