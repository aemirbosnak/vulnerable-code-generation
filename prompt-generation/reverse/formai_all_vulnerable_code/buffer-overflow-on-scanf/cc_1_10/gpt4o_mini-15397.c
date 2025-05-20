//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 5

typedef struct {
    char username[50];
    char password[50];
    int score;
} User;

typedef struct {
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char correctOption;
} Question;

User users[MAX_USERS];
Question questions[MAX_QUESTIONS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register.\n");
        return;
    }
    
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    
    users[userCount].score = 0;
    userCount++;
    printf("Registration successful!\n");
}

int loginUser(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return user index
        }
    }
    return -1; // User not found
}

void createExam() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d: ", i + 1);
        scanf(" %[^\n]%*c", questions[i].question);
        
        printf("Enter option A: ");
        scanf(" %[^\n]%*c", questions[i].optionA);
        
        printf("Enter option B: ");
        scanf(" %[^\n]%*c", questions[i].optionB);
        
        printf("Enter option C: ");
        scanf(" %[^\n]%*c", questions[i].optionC);
        
        printf("Enter option D: ");
        scanf(" %[^\n]%*c", questions[i].optionD);
        
        printf("Correct option (A/B/C/D): ");
        scanf(" %c", &questions[i].correctOption);
    }
}

void takeExam(int userIndex) {
    int correctAnswers = 0;
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        printf("A: %s\n", questions[i].optionA);
        printf("B: %s\n", questions[i].optionB);
        printf("C: %s\n", questions[i].optionC);
        printf("D: %s\n", questions[i].optionD);
        
        char answer;
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        
        if (answer == questions[i].correctOption) {
            correctAnswers++;
        }
    }
    
    users[userIndex].score = correctAnswers;
    printf("You answered %d out of %d questions correctly!\n", correctAnswers, MAX_QUESTIONS);
}

void displayResults() {
    printf("\nExam Results:\n");
    for (int i = 0; i < userCount; i++) {
        printf("User: %s, Score: %d\n", users[i].username, users[i].score);
    }
}

int main() {
    int choice;
    char username[50], password[50], tempUsername[50], tempPassword[50];

    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Create Exam\n");
        printf("4. Take Exam\n");
        printf("5. Display Results\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                int userIndex = loginUser(username, password);
                if (userIndex != -1) {
                    printf("Login successful! Welcome, %s.\n", username);
                } else {
                    printf("Invalid credentials! Please try again.\n");
                }
                break;
            case 3:
                createExam();
                break;
            case 4:
                printf("Enter your username: ");
                scanf("%s", tempUsername);
                printf("Enter your password: ");
                scanf("%s", tempPassword);
                int idx = loginUser(tempUsername, tempPassword);
                if (idx != -1) {
                    takeExam(idx);
                } else {
                    printf("Invalid credentials! Please try again.\n");
                }
                break;
            case 5:
                displayResults();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}