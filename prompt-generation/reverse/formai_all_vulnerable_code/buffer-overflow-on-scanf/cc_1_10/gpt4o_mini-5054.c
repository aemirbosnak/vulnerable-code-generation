//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of questions and users
#define MAX_QUESTIONS 100
#define MAX_USERS 50
#define MAX_OPTIONS 4

// Structure to hold a question
typedef struct {
    char question[256];
    char options[MAX_OPTIONS][100];
    int answer; // index of the correct answer
} Question;

// Structure to hold user data
typedef struct {
    char username[50];
    int score;
} User;

// Function prototypes
void displayMenu();
void addQuestion(Question questions[], int *count);
void takeExam(Question questions[], int count, User *user);
void displayResults(User *user);

// Main function
int main() {
    Question questions[MAX_QUESTIONS];
    User users[MAX_USERS];
    int userCount = 0;
    int questionCount = 0;
    int option;
    
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addQuestion(questions, &questionCount);
                break;
            case 2:
                if (questionCount == 0) {
                    printf("No questions available to take the exam.\n");
                    break;
                }
                if (userCount >= MAX_USERS) {
                    printf("Maximum user limit reached. Cannot add more users.\n");
                    break;
                }
                printf("Enter your username: ");
                scanf("%s", users[userCount].username);
                users[userCount].score = 0;
                takeExam(questions, questionCount, &users[userCount]);
                userCount++;
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);
    
    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n=== Online Examination System ===\n");
    printf("1. Add Question\n");
    printf("2. Take Exam\n");
    printf("3. Exit\n");
}

// Function to add a question
void addQuestion(Question questions[], int *count) {
    if (*count >= MAX_QUESTIONS) {
        printf("Maximum question limit reached. Cannot add more questions.\n");
        return;
    }
    
    printf("Enter question: ");
    getchar(); // Consume newline
    fgets(questions[*count].question, sizeof(questions[*count].question), stdin);
    questions[*count].question[strcspn(questions[*count].question, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[*count].options[i], sizeof(questions[*count].options[i]), stdin);
        questions[*count].options[i][strcspn(questions[*count].options[i], "\n")] = 0; // Remove newline
    }
    
    printf("Enter correct answer (1-%d): ", MAX_OPTIONS);
    scanf("%d", &questions[*count].answer);
    (*count)++;
    printf("Question added successfully!\n");
}

// Function to take the exam
void takeExam(Question questions[], int count, User *user) {
    printf("\n=== Welcome to the Exam, %s ===\n", user->username);
    
    for (int i = 0; i < count; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf(" %d. %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);
        if (answer == questions[i].answer) {
            printf("Correct!\n");
            user->score++;
        } else {
            printf("Wrong! The correct answer was %d.\n", questions[i].answer);
        }
    }
    
    displayResults(user);
}

// Function to display results
void displayResults(User *user) {
    printf("\n=== Exam Completed ===\n");
    printf("User: %s\n", user->username);
    printf("Your Score: %d\n", user->score);
}