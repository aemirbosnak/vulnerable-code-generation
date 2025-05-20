//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to initialize the system
void init() {
    printf("Welcome to the Online Examination System!\n");
}

// Function to display the main menu
void displayMenu() {
    printf("\nMain Menu:\n");
    printf("1. Create a new exam\n");
    printf("2. Take an exam\n");
    printf("3. View exam results\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

// Function to create a new exam
void createExam() {
    char examName[50];
    int numQuestions;
    printf("\nEnter the name of the exam: ");
    scanf("%s", examName);
    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);
    printf("Exam created successfully!\n");
}

// Function to take an exam
void takeExam() {
    char examName[50];
    int score = 0;
    printf("\nEnter the name of the exam: ");
    scanf("%s", examName);
    printf("Exam started...\n");
    for (int i = 1; i <= 10; i++) {
        printf("Question %d: ", i);
        char answer[50];
        scanf("%s", answer);
        if (strcmp(answer, "correct") == 0) {
            score++;
        }
    }
    printf("Exam finished.\n");
    printf("Your score is: %d out of 10.\n", score);
}

// Function to view exam results
void viewResults() {
    char examName[50];
    printf("\nEnter the name of the exam: ");
    scanf("%s", examName);
    printf("Exam results:\n");
    printf("Score: 10 out of 10\n");
}

// Function to get user input
char getInput(char* message) {
    printf("%s", message);
    char input[50];
    scanf("%s", input);
    return input[0];
}

// Main function
int main() {
    init();
    while (1) {
        displayMenu();
        char choice = getInput("Enter your choice: ");
        switch (choice) {
            case '1':
                createExam();
                break;
            case '2':
                takeExam();
                break;
            case '3':
                viewResults();
                break;
            case '4':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}