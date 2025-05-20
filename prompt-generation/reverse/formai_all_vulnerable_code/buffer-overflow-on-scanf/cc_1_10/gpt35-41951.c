//FormAI DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include <stdio.h>

// Structure to hold question information
struct Question {
    int id;
    char prompt[100];
    char options[4][50];
    int correct_option;
};

int main() {
    int num_questions;
    printf("Welcome to the Online Examination System\n");

    // Get the number of questions from the user
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    // Create an array to hold the questions
    struct Question questions[num_questions];

    // Loop through each question and ask for input
    for(int i=0; i<num_questions; i++) {
        printf("\nEnter details for question %d:\n", i+1);

        // Get the question prompt from the user
        printf("Enter question prompt: ");
        scanf(" %[^\n]", questions[i].prompt);

        // Get the answers to the question
        for(int j=0; j<4; j++) {
            printf("Enter option %d: ", j+1);
            scanf(" %[^\n]", questions[i].options[j]);
        }

        // Get the correct option for the question
        printf("Enter the correct option: ");
        scanf("%d", &questions[i].correct_option);

        // Assign the question ID
        questions[i].id = i+1;
    }

    // Print out the questions and options for the user to answer
    printf("\n\n-- Exam Questions --\n");
    for(int i=0; i<num_questions; i++) {
        printf("\n\n%d. %s\n", questions[i].id, questions[i].prompt);
        for(int j=0; j<4; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }
    }

    // Get the answers from the student
    printf("\n\n-- Answer the questions by typing the corresponding option number --\n");
    int student_answers[num_questions];
    for(int i=0; i<num_questions; i++) {
        printf("\nQuestion %d: ", i+1);
        scanf("%d", &student_answers[i]);
    }

    // Calculate the score for the student
    int score = 0;
    for(int i=0; i<num_questions; i++) {
        if(student_answers[i] == questions[i].correct_option) {
            score++;
        }
    }

    // Print out the student's score
    printf("\n\n-- Exam Results --\n");
    printf("You answered %d out of %d questions correctly!\n", score, num_questions);

    return 0;
}