//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTION 4
#define MAX_USERNAME 30

typedef struct {
    char question[100];
    char options[MAX_OPTION][50];
    int answer; // correct answer index (0, 1, 2, 3)
} Question;

typedef struct {
    char username[MAX_USERNAME];
    int score;
} User;

Question questions[MAX_QUESTIONS];
User user;

void createExam() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d: ", i + 1);
        getchar(); // consume leftover newline
        fgets(questions[i].question, sizeof(questions[i].question), stdin);
        printf("Enter option 0: ");
        fgets(questions[i].options[0], sizeof(questions[i].options[0]), stdin);
        printf("Enter option 1: ");
        fgets(questions[i].options[1], sizeof(questions[i].options[1]), stdin);
        printf("Enter option 2: ");
        fgets(questions[i].options[2], sizeof(questions[i].options[2]), stdin);
        printf("Enter option 3: ");
        fgets(questions[i].options[3], sizeof(questions[i].options[3]), stdin);
        
        printf("Enter the correct option index (0-3): ");
        scanf("%d", &questions[i].answer);
    }
}

void takeExam() {
    user.score = 0;
    printf("Enter your username: ");
    getchar(); // consume leftover newline
    fgets(user.username, sizeof(user.username), stdin);
    // Remove newline character from username
    user.username[strcspn(user.username, "\n")] = 0;
    
    printf("\nStarting the exam...\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("Option %d: %s", j, questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer (0-3): ");
        scanf("%d", &answer);
        
        if (answer == questions[i].answer) {
            printf("Correct!\n");
            user.score++;
        } else {
            printf("Wrong! The correct answer was option %d.\n", questions[i].answer);
        }
    }
}

void viewResults() {
    printf("\nResults for %s:\n", user.username);
    printf("Score: %d out of %d\n", user.score, MAX_QUESTIONS);
}

int main() {
    int choice;

    do {
        printf("\nOnline Examination System\n");
        printf("1. Create Exam\n");
        printf("2. Take Exam\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createExam();
                break;
            case 2:
                takeExam();
                break;
            case 3:
                viewResults();
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}