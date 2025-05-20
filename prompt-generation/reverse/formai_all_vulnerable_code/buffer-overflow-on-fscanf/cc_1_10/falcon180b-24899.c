//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of questions
#define MAX_QUESTIONS 10

// Define the structure of a question
typedef struct {
    char question[100];
    char option1[100];
    char option2[100];
    char option3[100];
    char answer[3];
} Question;

// Function to display the menu
void display_menu() {
    printf("\n");
    printf("1. Start Exam\n");
    printf("2. Exit\n");
    printf("\n");
}

// Function to start the exam
void start_exam() {
    // Initialize the variables
    int score = 0;
    int question_number = 1;

    // Load the questions from a file
    FILE *questions_file = fopen("questions.txt", "r");
    Question questions[MAX_QUESTIONS];
    int num_questions = 0;
    while (fscanf(questions_file, "%s %s %s %s %s", questions[num_questions].question, questions[num_questions].option1, questions[num_questions].option2, questions[num_questions].option3, questions[num_questions].answer)!= EOF) {
        num_questions++;
    }
    fclose(questions_file);

    // Start the exam
    while (question_number <= num_questions) {
        // Display the question
        printf("\nQuestion %d:\n%s\n", question_number, questions[question_number - 1].question);

        // Display the options
        printf("A: %s\n", questions[question_number - 1].option1);
        printf("B: %s\n", questions[question_number - 1].option2);
        printf("C: %s\n", questions[question_number - 1].option3);

        // Get the user's answer
        char answer_buffer[3];
        scanf("%s", answer_buffer);

        // Check the answer
        if (strcmp(answer_buffer, questions[question_number - 1].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }

        // Move to the next question
        question_number++;
    }

    // Display the final score
    printf("\nYour score is: %d out of %d\n", score, num_questions);
}

// Main function
int main() {
    // Initialize the variables
    int choice;

    // Start the program
    while (1) {
        // Display the menu
        display_menu();

        // Get the user's choice
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                // Start the exam
                start_exam();
                break;

            case 2:
                // Exit the program
                exit(0);

            default:
                // Invalid choice
                printf("Invalid choice.\n");
        }
    }

    return 0;
}