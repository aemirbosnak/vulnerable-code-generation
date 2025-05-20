//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a question
typedef struct {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

// Function to read questions from a file
Question* read_questions(char *filename, int *num_questions) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the number of questions
    fscanf(fp, "%d", num_questions);

    // Allocate memory for the questions
    Question *questions = malloc(*num_questions * sizeof(Question));

    // Read each question
    for (int i = 0; i < *num_questions; i++) {
        // Read the question
        fgets(questions[i].question, sizeof(questions[i].question), fp);
        questions[i].question[strcspn(questions[i].question, "\n")] = '\0';

        // Read the options
        for (int j = 0; j < 4; j++) {
            fgets(questions[i].options[j], sizeof(questions[i].options[j]), fp);
            questions[i].options[j][strcspn(questions[i].options[j], "\n")] = '\0';
        }

        // Read the correct option
        fscanf(fp, "%d", &questions[i].correct_option);
    }

    fclose(fp);

    return questions;
}

// Function to print a question
void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to take an exam
int take_exam(Question *questions, int num_questions) {
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        // Print the question
        print_question(questions[i]);

        // Get the user's answer
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correct_option) {
            score++;
        }
    }

    return score;
}

// Main function
int main() {
    // Read the questions from a file
    int num_questions;
    Question *questions = read_questions("questions.txt", &num_questions);

    // Take the exam
    int score = take_exam(questions, num_questions);

    // Print the score
    printf("Your score is %d out of %d\n", score, num_questions);

    // Free the memory allocated for the questions
    free(questions);

    return 0;
}