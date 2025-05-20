//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_QUESTIONS 5

typedef struct {
    char question[256];
    char options[4][256];
    int answer; // correct answer index (0-3)
} Question;

typedef struct {
    char name[50];
    char username[50];
    char password[50];
    int score;
} User;

User users[MAX_USERS];
int user_count = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
    {"What is 2 + 2?", {"3", "4", "5", "6"}, 1},
    {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
    {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Tiger"}, 1},
    {"Who wrote 'Hamlet'?", {"Charles Dickens", "William Shakespeare", "Mark Twain", "Ernest Hemingway"}, 1}
};

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
        return;
    }
    User new_user;
    printf("Enter your name: ");
    scanf("%s", new_user.name);
    printf("Choose a username: ");
    scanf("%s", new_user.username);
    printf("Choose a password: ");
    scanf("%s", new_user.password);
    new_user.score = 0;
    users[user_count++] = new_user;
    printf("Registration successful! Welcome, %s!\n", new_user.name);
}

int authenticate_user(char* username, char* password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return user index for reference
        }
    }
    return -1; // Invalid user
}

void take_exam(int user_index) {
    int score = 0;
    printf("Starting the exam! You will be presented with %d questions.\n", MAX_QUESTIONS);
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("  %d. %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer - 1 == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %s\n", questions[i].options[questions[i].answer]);
        }
    }
    users[user_index].score = score;
    printf("Exam completed! Your score: %d/%d\n", score, MAX_QUESTIONS);
}

void view_results(int user_index) {
    printf("\nResults for %s:\n", users[user_index].name);
    printf("Your score: %d/%d\n", users[user_index].score, MAX_QUESTIONS);
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Online Examination System ===\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2: {
                char username[50], password[50];
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);
                int user_index = authenticate_user(username, password);
                if (user_index != -1) {
                    take_exam(user_index);
                    view_results(user_index);
                } else {
                    printf("Invalid username or password!\n");
                }
                break;
            }
            case 3:
                printf("Thank you for using the Online Examination System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}