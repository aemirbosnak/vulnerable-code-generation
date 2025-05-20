//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User structure
typedef struct {
    char username[50];
    char password[50];
} User;

// Question structure
typedef struct {
    int id;
    char question[256];
    char options[4][100];
    char correctAnswer;
} Question;

// Function prototypes
void registerUser(User *users, int *userCount);
int loginUser(User *users, int userCount);
void conductExam(Question *questions, int questionCount);

int main() {
    User users[100];
    int userCount = 0;
    Question questions[] = {
        {1, "What is the capital of France?", {"A. Berlin", "B. Madrid", "C. Paris", "D. Lisbon"}, 'C'},
        {2, "What is 2 + 2?", {"A. 3", "B. 4", "C. 5", "D. 6"}, 'B'},
        {3, "Which planet is known as the Red Planet?", {"A. Earth", "B. Mars", "C. Venus", "D. Jupiter"}, 'B'},
        {4, "Who wrote 'Romeo and Juliet'?", {"A. Mark Twain", "B. Charles Dickens", "C. William Shakespeare", "D. Jane Austen"}, 'C'}
    };
    int questionCount = sizeof(questions) / sizeof(questions[0]);
    
    int choice;
    do {
        printf("\n--- Online Examination System ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                registerUser(users, &userCount);
                break;
            case 2:
                if (loginUser(users, userCount)) {
                    conductExam(questions, questionCount);
                }
                break;
            case 3:
                printf("Exiting the system. Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}

void registerUser(User *users, int *userCount) {
    printf("Enter username: ");
    scanf("%s", users[*userCount].username);
    printf("Enter password: ");
    scanf("%s", users[*userCount].password);
    (*userCount)++;
    printf("Registration successful!\n");
}

int loginUser(User *users, int userCount) {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    for(int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return 1; // User authenticated
        }
    }
    
    printf("Invalid username or password. Please try again.\n");
    return 0; // Authentication failed
}

void conductExam(Question *questions, int questionCount) {
    char answer;
    int score = 0;

    printf("\n--- Exam Start ---\n");
    for(int i = 0; i < questionCount; i++) {
        printf("Q%d: %s\n", questions[i].id, questions[i].question);
        for(int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }
        printf("Your answer: ");
        scanf(" %c", &answer);

        if (answer == questions[i].correctAnswer) {
            score++;
        }
    }

    printf("\n--- Exam End ---\n");
    printf("Your score: %d out of %d\n", score, questionCount);
}