//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: protected
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
    int correctOption;
} Question;

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int score;
} User;

User users[MAX_USERS];
Question questions[MAX_QUESTIONS];

int userCount = 0;

void addQuestion(int index) {
    printf("Enter question %d: ", index + 1);
    getchar(); // clear newline character from previous input
    fgets(questions[index].question, MAX_LENGTH, stdin);
    printf("Enter option A: ");
    fgets(questions[index].options[0], MAX_LENGTH, stdin);
    printf("Enter option B: ");
    fgets(questions[index].options[1], MAX_LENGTH, stdin);
    printf("Enter option C: ");
    fgets(questions[index].options[2], MAX_LENGTH, stdin);
    printf("Enter option D: ");
    fgets(questions[index].options[3], MAX_LENGTH, stdin);
    printf("Enter correct option (0 for A, 1 for B, 2 for C, 3 for D): ");
    scanf("%d", &questions[index].correctOption);
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register.\n");
        return;
    }
    printf("Register User\n");
    printf("Enter username: ");
    getchar(); // clear newline character
    fgets(users[userCount].username, MAX_LENGTH, stdin);
    printf("Enter password: ");
    fgets(users[userCount].password, MAX_LENGTH, stdin);
    users[userCount].score = 0; // Initialize score
    userCount++;
    printf("User registered successfully!\n");
}

int loginUser(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return user index
        }
    }
    return -1; // User not found
}

void takeTest(int userIndex) {
    printf("Taking the test...\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Q%d: %s", i + 1, questions[i].question);
        printf("A: %s", questions[i].options[0]);
        printf("B: %s", questions[i].options[1]);
        printf("C: %s", questions[i].options[2]);
        printf("D: %s", questions[i].options[3]);
        printf("Your answer (0/1/2/3): ");
        int answer;
        scanf("%d", &answer);
        if (answer == questions[i].correctOption) {
            users[userIndex].score++;
        }
    }
    printf("Test completed! Your score: %d/%d\n", users[userIndex].score, MAX_QUESTIONS);
}

void displayResults(int userIndex) {
    printf("Results for %s", users[userIndex].username);
    printf("Score: %d/%d\n", users[userIndex].score, MAX_QUESTIONS);
}

int main() {
    int choice;
    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Register User\n");
        printf("2. Login User\n");
        printf("3. Add Questions\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2: {
                char username[MAX_LENGTH];
                char password[MAX_LENGTH];
                printf("Enter username: ");
                getchar(); // clear newline character
                fgets(username, MAX_LENGTH, stdin);
                printf("Enter password: ");
                fgets(password, MAX_LENGTH, stdin);
                int userIndex = loginUser(username, password);
                if (userIndex != -1) {
                    takeTest(userIndex);
                    displayResults(userIndex);
                } else {
                    printf("Invalid credentials!\n");
                }
                break;
            }
            case 3:
                for (int i = 0; i < MAX_QUESTIONS; i++) {
                    addQuestion(i);
                }
                printf("Questions added successfully!\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}