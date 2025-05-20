//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 5
#define MAX_OPTION 4
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int score;
} User;

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTION][MAX_LENGTH];
    int answer; // index of the correct answer
} Question;

int userCount = 0;
User users[MAX_USERS];

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
    {"What is 2 + 2?", {"3", "4", "2", "5"}, 1},
    {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
    {"What is the largest mammal in the world?", {"Elephant", "Blue Whale", "Giraffe", "Shark"}, 1},
    {"What is the boiling point of water?", {"50°C", "100°C", "0°C", "150°C"}, 1}
};

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
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

int loginUser(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return i; // return user index
        }
    }
    return -1;
}

void takeExam(int userIndex) {
    printf("Starting exam for user: %s\n", users[userIndex].username);
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Your answer (1-%d): ", MAX_OPTION);
        int answer;
        scanf("%d", &answer);
        if (answer - 1 == questions[i].answer) {
            printf("Correct!\n");
            users[userIndex].score++;
        } else {
            printf("Wrong! The correct answer was: %s\n", questions[i].options[questions[i].answer]);
        }
    }
    printf("Exam finished! Your score: %d/%d\n", users[userIndex].score, MAX_QUESTIONS);
}

void viewResults(int userIndex) {
    printf("Results for user: %s\n", users[userIndex].username);
    printf("Score: %d/%d\n", users[userIndex].score, MAX_QUESTIONS);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Online Examination System ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2: {
                char username[MAX_LENGTH], password[MAX_LENGTH];
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                
                int userIndex = loginUser(username, password);
                if (userIndex != -1) {
                    takeExam(userIndex);
                    viewResults(userIndex);
                } else {
                    printf("Login failed! Invalid username or password.\n");
                }
                break;
            }
            case 3:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}