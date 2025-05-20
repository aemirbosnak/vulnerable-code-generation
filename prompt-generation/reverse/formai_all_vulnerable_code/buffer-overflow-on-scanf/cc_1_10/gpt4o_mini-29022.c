//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10

typedef struct {
    char question[256];
    char options[4][256];
    int answer;
} Question;

typedef struct {
    char username[50];
    char password[50];
    int score;
} User;

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"1. Paris", "2. London", "3. Berlin", "4. Rome"}, 1},
    {"Which planet is known as the Red Planet?", {"1. Earth", "2. Mars", "3. Jupiter", "4. Venus"}, 2},
    {"What is 5 + 3?", {"1. 6", "2. 7", "3. 8", "4. 9"}, 3},
    {"What does HTML stand for?", {"1. Hypertext Markup Language", "2. Highlevel Test Markup Language", 
                                    "3. Hyperlink and Text Markup Language", "4. Hypertext Multi Language"}, 1},
    {"Who wrote 'To Kill a Mockingbird'?", {"1. Harper Lee", "2. J.K. Rowling", "3. Mark Twain", "4. Ernest Hemingway"}, 1},
    {"What is the largest mammal?", {"1. Elephant", "2. Blue Whale", "3. Giraffe", "4. Hippopotamus"}, 2},
    {"Which element has the chemical symbol O?", {"1. Gold", "2. Oxygen", "3. Osmium", "4. Silver"}, 2},
    {"How many continents are there?", {"1. 5", "2. 6", "3. 7", "4. 8"}, 3},
    {"What is the hardest natural substance on Earth?", {"1. Gold", "2. Iron", "3. Diamond", "4. Quartz"}, 3},
    {"What is the freezing point of water?", {"1. 0 degrees", "2. 32 degrees", "3. 100 degrees", "4. -32 degrees"}, 1}
};

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
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

int loginUser(User *currentUser) {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            *currentUser = users[i];
            return 1; // Login successful
        }
    }
    printf("Invalid username or password.\n");
    return 0; // Login failed
}

void takeQuiz(User *currentUser) {
    printf("\nStarting the quiz...\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == questions[i].answer) {
            printf("Correct answer!\n");
            currentUser->score++;
        } else {
            printf("Wrong answer! The correct answer was: %d\n", questions[i].answer);
        }
    }
    printf("\nYou scored: %d out of %d\n", currentUser->score, MAX_QUESTIONS);
}

int main() {
    int choice;
    User currentUser;

    while (1) {
        printf("\nWelcome to the Online Examination System!\n");
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
                if (loginUser(&currentUser)) {
                    takeQuiz(&currentUser);
                    printf("Your final score has been recorded.\n");
                }
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}