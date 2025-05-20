//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define BUFFER_SIZE 100

// Structure for user information
typedef struct {
    char username[50];
    char password[50];
} User;

// Structure for questions
typedef struct {
    char question[BUFFER_SIZE];
    char options[4][BUFFER_SIZE];
    int answer; // Index of the correct option (0 to 3)
} Question;

// Function prototypes
void registerUser();
int loginUser();
void conductExam(User currentUser);
void displayResult(int score);

User users[MAX_USERS];
int userCount = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Lisbon"}, 2},
    {"What is 2 + 2?", {"3", "4", "1", "2"}, 1},
    {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
    {"What is the largest animal on Earth?", {"Elephant", "Blue Whale", "Giraffe", "Shark"}, 1},
    {"What language is primarily spoken in Brazil?", {"Spanish", "Portuguese", "English", "French"}, 1},
    {"How many continents are there?", {"5", "6", "7", "8"}, 2},
    {"What is the chemical symbol for water?", {"H2O", "O2", "C2", "H2"}, 0},
    {"What is the capital of Japan?", {"Seoul", "Beijing", "Tokyo", "Bangkok"}, 2},
    {"What is the strongest muscle in the human body?", {"Biceps", "Heart", "Jaw", "Legs"}, 2},
    {"What is the speed of light?", {"299,792 km/s", "150,000 km/s", "1,000 km/s", "300 km/s"}, 0}
};

int main() {
    int choice;

    printf("Welcome to the Online Examination System\n");
    do {
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser() != -1) {
                conductExam(users[loginUser()]);
            } else {
                printf("Login failed.\n");
            }
            break;
        case 3:
            printf("Exiting the system. Goodbye!\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    } while (choice != 3);

    return 0;
}

void registerUser() {
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[userCount++] = newUser;
    printf("Registration successful!\n");
}

int loginUser() {
    char username[50], password[50];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful! Welcome, %s!\n", username);
            return i; // Return user index
        }
    }
    return -1; // Login failed
}

void conductExam(User currentUser) {
    int score = 0;
    printf("\nStarting the exam...\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("\t%d) %s\n", j + 1, questions[i].options[j]);
        }

        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer - 1 == questions[i].answer) {
            score++;
        }
    }

    printf("\nExam finished!\n");
    displayResult(score);
}

void displayResult(int score) {
    printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);
    float percentage = ((float)score / MAX_QUESTIONS) * 100;
    printf("Percentage: %.2f%%\n", percentage);
}