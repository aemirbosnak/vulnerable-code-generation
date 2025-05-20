//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_QUESTIONS 5

typedef struct {
    char username[20];
    char password[20];
    int score;
} User;

typedef struct {
    char question[100];
    char options[4][50];
    int answer; // correct answer index (0-based)
} Question;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
    {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 1},
    {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 3},
    {"What year did the Titanic sink?", {"1912", "1905", "1895", "1915"}, 0},
    {"What is the chemical symbol for water?", {"H20", "O2", "CO2", "NaCl"}, 0}
};

void signUp() {
    if (userCount >= MAX_USERS) {
        printf("Cannot sign up. Maximum users reached.\n");
        return;
    }
    
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    users[userCount].score = 0;
    userCount++;
    printf("Sign up successful!\n");
}

int logIn() {
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return index of logged-in user
        }
    }
    printf("Invalid username or password.\n");
    return -1;
}

void takeTest(int userIndex) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int answer;
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        
        if (answer - 1 == questions[i].answer) {
            printf("Correct!\n");
            users[userIndex].score++;
        } else {
            printf("Incorrect! The correct answer was: %s\n", questions[i].options[questions[i].answer]);
        }
    }
    printf("Test completed! Your score: %d/%d\n", users[userIndex].score, MAX_QUESTIONS);
}

int main() {
    int choice;
    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Sign Up\n");
        printf("2. Log In\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2: {
                int userIndex = logIn();
                if (userIndex != -1) {
                    takeTest(userIndex);
                }
                break;
            }
            case 3:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}