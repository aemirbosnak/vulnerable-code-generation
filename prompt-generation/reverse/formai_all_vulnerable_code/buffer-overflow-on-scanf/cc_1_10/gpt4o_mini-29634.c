//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_OPTION 4

typedef struct {
    char question[256];
    char options[MAX_OPTION][100];
    int answer; // index of the correct answer
} Question;

typedef struct {
    char username[50];
    int score;
} User;

Question questions[MAX_QUESTIONS];
User users[MAX_USERS];
int userCount = 0, questionCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    
    users[userCount].score = 0;
    userCount++;
    printf("User registered successfully!\n");
}

void createQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Question limit reached. Cannot add more questions.\n");
        return;
    }

    printf("Enter question: ");
    getchar(); 
    fgets(questions[questionCount].question, 256, stdin);
    strtok(questions[questionCount].question, "\n"); // Remove trailing newline
    
    for (int i = 0; i < MAX_OPTION; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[questionCount].options[i], 100, stdin);
        strtok(questions[questionCount].options[i], "\n");
    }

    printf("Enter the index of the correct answer (1-%d): ", MAX_OPTION);
    scanf("%d", &questions[questionCount].answer);
    
    questionCount++;
    printf("Question added successfully!\n");
}

void administerExam() {
    char username[50];
    printf("Enter username to take the exam: ");
    scanf("%s", username);

    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User not found!\n");
        return;
    }

    for (int i = 0; i < questionCount; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("\t%d. %s\n", j + 1, questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTION);
        scanf("%d", &answer);

        if (answer - 1 == questions[i].answer) {
            printf("Correct!\n");
            users[userIndex].score++;
        } else {
            printf("Wrong answer. The correct answer was: %s\n", questions[i].options[questions[i].answer]);
        }
    }
    
    printf("Exam completed! Your score: %d/%d\n", users[userIndex].score, questionCount);
}

void displayResults() {
    printf("\n--- User Scores ---\n");
    for (int i = 0; i < userCount; i++) {
        printf("User: %s, Score: %d\n", users[i].username, users[i].score);
    }
}

void menu() {
    int choice;
    do {
        printf("\nOnline Examination System\n");
        printf("1. Register User\n");
        printf("2. Create Question\n");
        printf("3. Administer Exam\n");
        printf("4. Display Results\n");
        printf("5. Quit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: registerUser(); break;
            case 2: createQuestion(); break;
            case 3: administerExam(); break;
            case 4: displayResults(); break;
            case 5: printf("Quitting the application...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}