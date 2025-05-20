//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define USERNAME_LENGTH 30
#define PASSWORD_LENGTH 30

// Structure to store user information
struct User {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int score;
};

// Structure to store questions
struct Question {
    char question[256];
    char options[4][50];
    int answer;
};

// Function prototypes
void registerUser(struct User users[], int *userCount);
void loginUser(struct User users[], int userCount);
void takeExamination(struct User *user);
void viewScore(struct User user);
void loadQuestions(struct Question questions[]);
void displayQuestions(struct Question questions[]);

int main() {
    struct User users[MAX_USERS];
    int userCount = 0;
    int choice;

    // Load initial user data
    FILE *userFile = fopen("users.dat", "rb");
    if (userFile != NULL) {
        fread(users, sizeof(struct User), MAX_USERS, userFile);
        fclose(userFile);
    }

    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser(users, &userCount);
                break;
            case 2:
                loginUser(users, userCount);
                break;
            case 3:
                // Save user data before exiting
                userFile = fopen("users.dat", "wb");
                fwrite(users, sizeof(struct User), userCount, userFile);
                fclose(userFile);
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void registerUser(struct User users[], int *userCount) {
    struct User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    newUser.score = 0;

    // Check if username already exists
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists!\n");
            return;
        }
    }

    users[*userCount] = newUser;
    (*userCount)++;
    printf("Registration successful!\n");
}

void loginUser(struct User users[], int userCount) {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int found = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            found = 1;
            printf("Login successful! Welcome, %s!\n", username);
            takeExamination(&users[i]);
            break;
        }
    }

    if (!found) {
        printf("Invalid username or password!\n");
    }
}

void takeExamination(struct User *user) {
    struct Question questions[MAX_QUESTIONS];
    loadQuestions(questions);

    int answer;
    printf("\nStarting Examination...\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].options[j]);
        }
        printf("Enter your answer (A/B/C/D): ");
        char option;
        scanf(" %c", &option);
        answer = option - 'A';

        if (answer == questions[i].answer) {
            user->score += 10; // Assume each question is worth 10 points
        }
    }

    printf("Examination completed! Your score: %d\n", user->score);
}

void loadQuestions(struct Question questions[]) {
    // Sample questions
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "Berlin");
    strcpy(questions[0].options[1], "Madrid");
    strcpy(questions[0].options[2], "Paris");
    strcpy(questions[0].options[3], "Lisbon");
    questions[0].answer = 2; // Correct answer index

    strcpy(questions[1].question, "Which is the largest ocean?");
    strcpy(questions[1].options[0], "Atlantic Ocean");
    strcpy(questions[1].options[1], "Indian Ocean");
    strcpy(questions[1].options[2], "Arctic Ocean");
    strcpy(questions[1].options[3], "Pacific Ocean");
    questions[1].answer = 3; // Correct answer index

    strcpy(questions[2].question, "What is the chemical symbol for water?");
    strcpy(questions[2].options[0], "CO2");
    strcpy(questions[2].options[1], "H2O");
    strcpy(questions[2].options[2], "O2");
    strcpy(questions[2].options[3], "NaCl");
    questions[2].answer = 1; // Correct answer index

    // Add more questions as needed...
}

void viewScore(struct User user) {
    printf("Your score: %d\n", user.score);
}