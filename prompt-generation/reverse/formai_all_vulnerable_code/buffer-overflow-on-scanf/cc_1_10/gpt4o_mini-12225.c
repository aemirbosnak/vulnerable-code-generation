//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTION 4

typedef struct {
    int question_id;
    char question[256];
    char options[MAX_OPTION][256];
    int answer;
} Question;

typedef struct {
    char name[50];
    int score;
} User;

int total_questions = 0;
Question questions[MAX_QUESTIONS];
User user;

void addQuestion();
void takeExam();
void viewResults();
void clearScreen();

int main() {
    int choice;

    while (1) {
        clearScreen();
        printf("======= Online Examination System =======\n");
        printf("1. Add Question\n");
        printf("2. Take Exam\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion();
                break;
            case 2:
                takeExam();
                break;
            case 3:
                viewResults();
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        getchar(); // to consume the newline character after the choice
        printf("Press Enter to continue...");
        getchar();
    }
    return 0;
}

void addQuestion() {
    if (total_questions >= MAX_QUESTIONS) {
        printf("You cannot add more questions.\n");
        return;
    }

    Question q;
    q.question_id = total_questions + 1;
    printf("Enter the question: ");
    getchar(); // To consume the newline character
    fgets(q.question, sizeof(q.question), stdin);
    q.question[strcspn(q.question, "\n")] = 0; // Remove newline character

    for (int i = 0; i < MAX_OPTION; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(q.options[i], sizeof(q.options[i]), stdin);
        q.options[i][strcspn(q.options[i], "\n")] = 0; // Remove newline
    }
    
    printf("Enter the correct answer (1-%d): ", MAX_OPTION);
    scanf("%d", &q.answer);
    while(q.answer < 1 || q.answer > MAX_OPTION) {
        printf("Incorrect answer! Please enter a number between 1 and %d: ", MAX_OPTION);
        scanf("%d", &q.answer);
    }
    
    questions[total_questions++] = q;
    printf("Question added successfully!\n");
}

void takeExam() {
    clearScreen();
    printf("Enter your name: ");
    getchar(); // To consume the newline left by previous input
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = 0; // Remove newline character
    user.score = 0;

    for (int i = 0; i < total_questions; i++) {
        printf("Q%d: %s\n", questions[i].question_id, questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("  %d. %s\n", j + 1, questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTION);
        scanf("%d", &answer);
        
        if (answer == questions[i].answer) {
            user.score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer was: %d\n", questions[i].answer);
        }
    }
    printf("Exam completed! You scored %d out of %d\n", user.score, total_questions);
}

void viewResults() {
    clearScreen();
    if (user.score == 0) {
        printf("No exam taken yet!\n");
    } else {
        printf("Name: %s\n", user.name);
        printf("Score: %d out of %d\n", user.score, total_questions);
    }
}

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}