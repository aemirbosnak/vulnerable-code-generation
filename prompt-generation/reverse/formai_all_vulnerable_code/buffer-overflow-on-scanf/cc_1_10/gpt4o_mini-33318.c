//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_USERS 100
#define FILENAME "exam_results.txt"

typedef struct {
    char username[50];
    char password[50];
    int score;
} User;

typedef struct {
    char question[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char answer;
} Question;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", "A) Berlin", "B) Madrid", "C) Paris", "D) Rome", 'C'},
    {"What is 2 + 2?", "A) 3", "B) 4", "C) 5", "D) 6", 'B'},
    {"Which planet is known as the Red Planet?", "A) Earth", "B) Mars", "C) Jupiter", "D) Saturn", 'B'},
    {"Who wrote 'Hamlet'?", "A) Mark Twain", "B) William Shakespeare", "C) Charles Dickens", "D) Jane Austen", 'B'},
    {"What is the largest ocean on Earth?", "A) Atlantic", "B) Indian", "C) Arctic", "D) Pacific", 'D'}
};

void registerUser() {
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    users[userCount].score = 0;
    userCount++;
    printf("Registration successful! You can now log in.\n");
}

int loginUser() {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // return user index
        }
    }
    printf("Invalid username or password.\n");
    return -1;
}

void takeExam(int userIndex) {
    int score = 0;
    char answer;

    printf("\nStarting the exam...\n\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        printf("%s\n", questions[i].optionA);
        printf("%s\n", questions[i].optionB);
        printf("%s\n", questions[i].optionC);
        printf("%s\n", questions[i].optionD);
        printf("Your answer: ");
        scanf(" %c", &answer);

        if (answer == questions[i].answer) {
            score++;
        }
    }

    users[userIndex].score = score;
    printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);
    
    // Save result to file
    FILE *fp = fopen(FILENAME, "a");
    if (fp != NULL) {
        fprintf(fp, "User: %s, Score: %d\n", users[userIndex].username, score);
        fclose(fp);
    } else {
        perror("Error opening file");
    }
}

void viewResults() {
    char buffer[256];
    FILE *fp = fopen(FILENAME, "r");
    
    if (fp == NULL) {
        printf("No results available yet.\n");
        return;
    }
    
    printf("\nExam Results:\n");
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    
    fclose(fp);
}

int main() {
    int choice, loggedInIndex;

    do {
        printf("\n=== Online Examination System ===\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loggedInIndex = loginUser();
                if (loggedInIndex != -1) {
                    takeExam(loggedInIndex);
                }
                break;
            case 3:
                viewResults();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}