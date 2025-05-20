//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 5
#define USERNAME_LEN 20
#define PASSWORD_LEN 20
#define QUESTION_LEN 100

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    int score;
} User;

typedef struct {
    char question[QUESTION_LEN];
    char options[4][QUESTION_LEN];
    int answer; // Index of correct answer
} Question;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is 2 + 2?", {"1", "2", "3", "4"}, 3},
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
    {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
    {"Who wrote 'To Kill a Mockingbird'?", {"Harper Lee", "Mark Twain", "Ernest Hemingway", "F. Scott Fitzgerald"}, 0},
    {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 3}
};

void welcomeMessage() {
    printf("Welcome to the Online Examination System\n");
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    newUser.score = 0;

    users[userCount++] = newUser;
    printf("Registration successful!\n");
}

int loginUser(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

void takeExam(int userIndex) {
    printf("Starting exam...\n");
    users[userIndex].score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer - 1 == questions[i].answer) {
            users[userIndex].score++;
        }
    }

    printf("Exam completed! Your score: %d out of %d\n", users[userIndex].score, MAX_QUESTIONS);
}

void viewResults(int userIndex) {
    printf("Your score: %d out of %d\n", users[userIndex].score, MAX_QUESTIONS);
}

int main() {
    int choice;
    welcomeMessage();
    
    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            char username[USERNAME_LEN], password[PASSWORD_LEN];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            int userIndex = loginUser(username, password);
            if (userIndex != -1) {
                printf("Login successful!\n");
                takeExam(userIndex);
                viewResults(userIndex);
            } else {
                printf("Invalid username or password.\n");
            }
        } else if (choice == 3) {
            printf("Exiting the system. Thank you!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}