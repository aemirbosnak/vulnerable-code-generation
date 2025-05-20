//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTION 4
#define MAX_USERS 50

// Structure for Question
typedef struct {
    int id;
    char question[256];
    char options[MAX_OPTION][100];
    char answer;
} Question;

// Structure for User
typedef struct {
    int user_id;
    char username[50];
} User;

// Global Variables
Question questions[MAX_QUESTIONS];
User users[MAX_USERS];

// Function Prototypes
void loadQuestions();
void displayQuestion(int i);
int checkAnswer(int qIndex, char answer);
void startExam();
void registerUser(int userId, const char *username);

int main() {
    int userId;
    char username[50];

    printf("Welcome to the Online Examination System\n");
    printf("Enter User ID: ");
    scanf("%d", &userId);
    printf("Enter Username: ");
    scanf("%s", username);

    registerUser(userId, username);
    loadQuestions();
    startExam();

    return 0;
}

// Function to load questions from a static list
void loadQuestions() {
    // For simplicity, questions are hardcoded
    questions[0] = (Question){1, "What is the capital of France?", {"A) London", "B) Berlin", "C) Paris", "D) Madrid"}, 'C'};
    questions[1] = (Question){2, "Which language is primarily used for web development?", {"A) Python", "B) C#", "C) HTML", "D) Java"}, 'C'};
    questions[2] = (Question){3, "What does CPU stand for?", {"A) Central Processing Unit", "B) Computer Personal Unit", "C) Central Process Unit", "D) Control Program Unit"}, 'A'};
}

// Function to display a question
void displayQuestion(int index) {
    printf("Question %d: %s\n", questions[index].id, questions[index].question);
    for (int i = 0; i < MAX_OPTION; i++) {
        printf("%s\n", questions[index].options[i]);
    }
}

// Function to check the answer
int checkAnswer(int qIndex, char answer) {
    return questions[qIndex].answer == answer;
}

// Function to start the exam
void startExam() {
    char answer;
    int correctAnswers = 0;
    int totalQuestions = 3;  // Current implementation has 3 questions

    for (int i = 0; i < totalQuestions; i++) {
        displayQuestion(i);
        printf("Your Answer: ");
        getchar();  // Clean the input buffer
        scanf("%c", &answer);

        if (checkAnswer(i, answer)) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Wrong! The correct answer is %c\n", questions[i].answer);
        }
    }
    printf("You got %d out of %d questions right.\n", correctAnswers, totalQuestions);
}

// Function to register user
void registerUser(int userId, const char *username) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].user_id == 0) {  // Find an empty slot
            users[i].user_id = userId;
            strcpy(users[i].username, username);
            printf("User %s (ID: %d) registered successfully.\n", username, userId);
            return;
        }
    }
    printf("User registration failed: Max users reached.\n");
}