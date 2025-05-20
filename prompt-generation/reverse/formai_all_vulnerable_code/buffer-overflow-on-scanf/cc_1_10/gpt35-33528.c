//FormAI DATASET v1.0 Category: Online Examination System ; Style: shape shifting
// C Online Examination System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

// Define a structure to hold a question and its options
struct question {
    char question_text[100];
    char options[MAX_OPTIONS][50];
    int correct_option;
};

// Function to display a question and its options
void display_question(struct question *q) {
    printf("%s\n", q->question_text);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i+1, q->options[i]);
    }
}

int main() {
    // Declare variables
    int num_questions, total_score = 0;
    struct question questions[MAX_QUESTIONS];

    // Get number of questions from user
    printf("How many questions do you want to add? ");
    scanf("%d", &num_questions);

    // Get questions and options from user
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        fflush(stdin); // Clear input buffer
        printf("Enter the question: ");
        fgets(questions[i].question_text, 100, stdin);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter option %d: ", j+1);
            fgets(questions[i].options[j], 50, stdin);
        }
        printf("Enter the correct option number: ");
        scanf("%d", &questions[i].correct_option);
    }

    // Display questions and get user's answers
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        display_question(&questions[i]);
        int user_answer;
        printf("Enter your answer: ");
        scanf("%d", &user_answer);
        if (user_answer == questions[i].correct_option) {
            printf("Correct!\n");
            total_score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    // Calculate and display final score
    printf("\nYour final score is %d/%d.\n", total_score, num_questions);

    return 0;
}