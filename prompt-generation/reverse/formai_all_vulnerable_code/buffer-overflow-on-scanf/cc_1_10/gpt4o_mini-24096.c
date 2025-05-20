//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_USERS 100
#define FILENAME "results.txt"

typedef struct {
    int id;
    char question[256];
    char options[4][100];
    char answer;
} Question;

typedef struct {
    int user_id;
    char name[50];
    int score;
} User;

Question questions[MAX_QUESTIONS];
User users[MAX_USERS];
int userCount = 0;

void loadQuestions() {
    // Sample questions loaded directly into the program for simplicity
    // In a real application, questions may be loaded from a database or a file.
    
    questions[0] = (Question){1, "What is the capital of France?", {"A. Berlin", "B. Madrid", "C. Paris", "D. Lisbon"}, 'C'};
    questions[1] = (Question){2, "Which planet is known as the Red Planet?", {"A. Earth", "B. Mars", "C. Jupiter", "D. Venus"}, 'B'};
    questions[2] = (Question){3, "What is the largest mammal in the world?", {"A. Elephant", "B. Blue Whale", "C. Giraffe", "D. Great White Shark"}, 'B'};
    questions[3] = (Question){4, "Who wrote 'Romeo and Juliet'?", {"A. Mark Twain", "B. William Shakespeare", "C. Ernest Hemingway", "D. J.K. Rowling"}, 'B'};
    questions[4] = (Question){5, "Which element has the chemical symbol 'O'?", {"A. Gold", "B. Oxygen", "C. Silver", "D. Helium"}, 'B'};
    // Add more questions as needed
}

void displayQuestions() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQ%d: %s\n", questions[i].id, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }
        printf("Enter your answer (A/B/C/D): ");
    }
}

int evaluateAnswers(char answers[]) {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (answers[i] == questions[i].answer) {
            score++;
        }
    }
    return score;
}

void saveResults(User user) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "User ID: %d, Name: %s, Score: %d\n", user.user_id, user.name, user.score);
    fclose(file);
}

void inputUserDetails(User *user) {
    printf("Enter your User ID: ");
    scanf("%d", &user->user_id);
    printf("Enter your Name: ");
    scanf("%s", user->name);
}

void takeExam(User *user) {
    char answers[MAX_QUESTIONS];
    printf("\nStarting the exam...\n");
    displayQuestions();
  
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        char response;
        printf("Your answer for Q%d: ", questions[i].id);
        scanf(" %c", &response);
        answers[i] = response;
    }

    user->score = evaluateAnswers(answers);
    printf("\nExam Finished! Your score: %d/%d\n", user->score, MAX_QUESTIONS);
    saveResults(*user);
}

void viewScores() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    char line[256];
    printf("\n--- Exam Results ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    int choice;
    User currentUser;

    loadQuestions();

    while (1) {
        printf("\n--- Online Examination System ---\n");
        printf("1. Take Exam\n");
        printf("2. View Scores\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputUserDetails(&currentUser);
                takeExam(&currentUser);
                break;
            case 2:
                viewScores();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}