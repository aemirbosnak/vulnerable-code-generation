//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 5
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50
#define MAX_OPTION_LENGTH 100

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

typedef struct {
    char question[256];
    char options[4][MAX_OPTION_LENGTH];
    int answer; // index of the correct answer (0-3)
} Question;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
    {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
    {"What is the largest mammal in the world?", {"Elephant", "Blue Whale", "Giraffe", "Hippo"}, 1},
    {"Who wrote 'Romeo and Juliet'?", {"Mark Twain", "Jane Austen", "William Shakespeare", "Charles Dickens"}, 2},
    {"What is the chemical symbol for water?", {"H2O", "O2", "CO2", "NaCl"}, 0}
};

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
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Try a different one.\n");
            return;
        }
    }
    
    users[userCount++] = newUser;
    printf("User registered successfully!\n");
}

int loginUser() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
    }
    
    printf("Invalid username or password.\n");
    return 0;
}

void startExamination() {
    int score = 0;
    int answer;
    
    printf("Starting the examination...\n");
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d: %s\n", j + 1, questions[i].options[j]);
        }
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        
        if (answer - 1 == questions[i].answer) {
            score++;
        }
    }
    
    printf("You scored %d out of %d\n", score, MAX_QUESTIONS);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    startExamination();
                }
                break;
            case 3:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}