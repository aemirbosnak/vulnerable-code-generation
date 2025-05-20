//FormAI DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void startQuiz();
void signUp();
void login();
void addQuestions();
void viewScores();

// Structure to store quiz questions
struct question {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int answer;
};

// Global variables
int numQuestions = 0; // Number of questions in the quiz
int score = 0; // User's score

// Array to store quiz questions
struct question quiz[50];

// Array to store signed-up users
struct user {
    char username[20];
    char password[20];
    int role; // 0: student, 1: teacher
} users[10];

// Main function
int main() {
    int choice;
    printf("Welcome to the Online Examination System!\n");
    printf("-----------------------------------------\n");

    while(1) {
        printf("\nMAIN MENU\n");
        printf("1. Sign Up\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: signUp(); break;
            case 2: login(); break;
            case 3: exit(0); break;
            default: printf("Invalid choice. Try again.\n"); break;
        }
    }

    return 0;
}

// Function to start quiz
void startQuiz() {
    int choice;
    printf("\nQUIZ\n");
    printf("----\n");

    for(int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d: %s\n", i+1, quiz[i].question);
        printf("1. %s\n", quiz[i].option1);
        printf("2. %s\n", quiz[i].option2);
        printf("3. %s\n", quiz[i].option3);
        printf("4. %s\n", quiz[i].option4);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == quiz[i].answer) {
            score++;
            printf("Correct answer!\n");
        } else {
            printf("Incorrect answer!\n");
        }
    }

    printf("\nYour score: %d/%d\n", score, numQuestions);
    score = 0; // Reset score for next user
}

// Function to sign up
void signUp() {
    char username[20], password[20];
    printf("\nSIGN UP\n");
    printf("-------\n");
    printf("Enter username: ");
    scanf("%s", username);

    // Check if user already exists
    for(int i = 0; i < 10; i++) {
        if(strcmp(users[i].username, username) == 0) {
            printf("User already exists. Try again.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);

    // Add user to array of users
    for(int i = 0; i < 10; i++) {
        if(users[i].username[0] == '\0') {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            printf("Sign up successful!\n");
            return;
        }
    }

    printf("Maximum number of users reached.\n");
    return;
}

// Function to login
void login() {
    char username[20], password[20];
    int role;

    printf("\nLOGIN\n");
    printf("-----\n");
    printf("Enter username: ");
    scanf("%s", username);

    // Check if user exists
    int found = 0;
    for(int i = 0; i < 10; i++) {
        if(strcmp(users[i].username, username) == 0) {
            found = 1;
            printf("Enter password: ");
            scanf("%s", password);

            // Check if password is correct
            if(strcmp(users[i].password, password) == 0) {
                printf("Login successful!\n");
                role = users[i].role;

                if(role == 0) {
                    startQuiz();
                } else {
                    addQuestions();
                }

                return;
            } else {
                printf("Invalid password. Try again.\n");
                return;
            }
        }
    }

    if(!found) {
        printf("User does not exist. Try again.\n");
        return;
    }
}

// Function to add questions
void addQuestions() {
    if(numQuestions == 50) {
        printf("Maximum number of questions reached.\n");
        return;
    }

    printf("\nADD QUESTIONS\n");
    printf("-------------\n");

    fflush(stdin);

    printf("Enter question: ");
    fgets(quiz[numQuestions].question, 100, stdin);

    printf("Enter option 1: ");
    fgets(quiz[numQuestions].option1, 50, stdin);

    printf("Enter option 2: ");
    fgets(quiz[numQuestions].option2, 50, stdin);

    printf("Enter option 3: ");
    fgets(quiz[numQuestions].option3, 50, stdin);

    printf("Enter option 4: ");
    fgets(quiz[numQuestions].option4, 50, stdin);

    printf("Enter answer (1/2/3/4): ");
    scanf("%d", &quiz[numQuestions].answer);

    numQuestions++;

    printf("Question added successfully!\n");
}

// Function to view scores
void viewScores() {
    printf("\nVIEW SCORES\n");
    printf("-----------\n");
    // TODO: Implement function to view scores
}