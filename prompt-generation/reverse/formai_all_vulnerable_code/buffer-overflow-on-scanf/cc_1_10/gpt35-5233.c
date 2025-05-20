//FormAI DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50

// Structure for storing questions and answers
typedef struct {
    char question[100];
    char option[4][50];
    int correct_option;
} Question;

int main() {
    // Initialize variables
    Question questions[MAX_QUESTIONS];
    int num_questions, score = 0;
    char response[10];

    // Prompt user for number of questions
    printf("Enter number of questions (max %d): ", MAX_QUESTIONS);
    scanf("%d", &num_questions);

    // Prompt user for questions and answers
    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf(" %[^\n]s", questions[i].question);

        printf("Enter option 1: ");
        scanf(" %[^\n]s", questions[i].option[0]);

        printf("Enter option 2: ");
        scanf(" %[^\n]s", questions[i].option[1]);

        printf("Enter option 3: ");
        scanf(" %[^\n]s", questions[i].option[2]);

        printf("Enter option 4: ");
        scanf(" %[^\n]s", questions[i].option[3]);

        printf("Enter correct option (1-4): ");
        scanf("%d", &questions[i].correct_option);
    }

    // Begin exam
    printf("Ready to start the exam? (yes/no): ");
    scanf("%s", response);

    if (strcmp(response, "yes") == 0) {
        // Loop through questions and present to user
        for (int i = 0; i < num_questions; i++) {
            printf("\nQ%d: %s\n", i + 1, questions[i].question);
            for (int j = 0; j < 4; j++) {
                printf("%d. %s\n", j + 1, questions[i].option[j]);
            }

            int choice;
            printf("Enter your choice (1-4): ");
            scanf("%d", &choice);

            // Check if answer is correct
            if (choice == questions[i].correct_option) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect!\n");
            }
        }

        // Display final score
        printf("\nYour score is: %d/%d\n", score, num_questions);
    } else {
        printf("Exiting...\n");
    }

    return 0;
}