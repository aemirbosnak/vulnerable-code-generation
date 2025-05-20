//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[4][MAX_ANSWER_LENGTH]; // four options
    int correctAnswer; // index of the correct answer
} Question;

typedef struct {
    char username[MAX_ANSWER_LENGTH];
    int score;
} User;

User users[MAX_USERS];
Question questions[MAX_QUESTIONS];

int userCount = 0;
int questionCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Registration full! Cannot register more users.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    users[userCount].score = 0; // Initial score is 0
    userCount++;
    printf("User registered successfully!\n");
}

void addQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Question bank full! Cannot add more questions.\n");
        return;
    }
    
    printf("Enter the question: ");
    getchar(); // To consume newline left by previous input
    fgets(questions[questionCount].question, MAX_ANSWER_LENGTH, stdin);
    questions[questionCount].question[strcspn(questions[questionCount].question, "\n")] = 0; // Remove newline

    for (int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[questionCount].options[i], MAX_ANSWER_LENGTH, stdin);
        questions[questionCount].options[i][strcspn(questions[questionCount].options[i], "\n")] = 0; // Remove newline
    }

    printf("Enter the correct answer (1-4): ");
    scanf("%d", &questions[questionCount].correctAnswer);
    questionCount++;
    printf("Question added successfully!\n");
}

void takeQuiz(const char *username) {
    User *currentUser = NULL;
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            currentUser = &users[i];
            break;
        }
    }
    
    if (!currentUser) {
        printf("User not found!\n");
        return;
    }

    currentUser->score = 0; // Reset score for new quiz

    for (int i = 0; i < questionCount; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("   %d. %s\n", j + 1, questions[i].options[j]);
        }

        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);

        if (answer == questions[i].correctAnswer) {
            printf("Correct!\n");
            currentUser->score++;
        } else {
            printf("Wrong! The correct answer was %d.\n", questions[i].correctAnswer);
        }
    }
    printf("Quiz completed! Your score: %d/%d\n", currentUser->score, questionCount);
}

void viewScores() {
    printf("Scores of all users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("User: %s, Score: %d\n", users[i].username, users[i].score);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Register User\n");
        printf("2. Add Question\n");
        printf("3. Take Quiz\n");
        printf("4. View Scores\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                registerUser();
                break;
            case 2: 
                addQuestion();
                break;
            case 3: 
                {
                    char username[MAX_ANSWER_LENGTH];
                    printf("Enter your username: ");
                    scanf("%s", username);
                    takeQuiz(username);
                }
                break;
            case 4: 
                viewScores();
                break;
            case 5: 
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}