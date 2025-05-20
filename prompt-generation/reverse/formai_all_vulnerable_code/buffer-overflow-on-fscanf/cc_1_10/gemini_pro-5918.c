//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and options
typedef struct Question {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

// Function to read questions from file
void read_questions(Question questions[], int *num_questions) {
    FILE *fp;
    char line[256];

    // Open file for reading
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening questions file\n");
        exit(1);
    }

    // Read number of questions from file
    fscanf(fp, "%d", num_questions);

    // Read each question and options
    for (int i = 0; i < *num_questions; i++) {
        fgets(line, sizeof(line), fp);
        strcpy(questions[i].question, line);

        for (int j = 0; j < 4; j++) {
            fgets(line, sizeof(line), fp);
            strcpy(questions[i].options[j], line);
        }

        // Read correct option
        fscanf(fp, "%d", &questions[i].correct_option);
    }

    // Close file
    fclose(fp);
}

// Function to display question and options
void display_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get user input
int get_user_input() {
    int input;

    printf("Enter your choice: ");
    scanf("%d", &input);

    return input;
}

// Function to check if user input is correct
int check_answer(Question question, int input) {
    return question.correct_option == input;
}

// Function to display result
void display_result(int score, int num_questions) {
    printf("Your score is %d out of %d\n", score, num_questions);
}

// Main function
int main() {
    // Declare array of questions
    Question questions[100];

    // Read questions from file
    int num_questions;
    read_questions(questions, &num_questions);

    // Declare variables to store score and user input
    int score = 0;
    int user_input;

    // Iterate over each question and display it
    for (int i = 0; i < num_questions; i++) {
        display_question(questions[i]);

        // Get user input
        user_input = get_user_input();

        // Check if user input is correct
        if (check_answer(questions[i], user_input)) {
            score++;
        }
    }

    // Display result
    display_result(score, num_questions);

    return 0;
}