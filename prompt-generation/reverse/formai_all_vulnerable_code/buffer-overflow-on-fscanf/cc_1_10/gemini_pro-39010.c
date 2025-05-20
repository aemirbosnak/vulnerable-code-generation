//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct {
    char question[256];
    char answer[256];
} Question;

// Function to read questions from a file
Question *readQuestions(char *filename, int *numQuestions) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the number of questions
    fscanf(fp, "%d", numQuestions);

    // Allocate memory for the questions
    Question *questions = malloc(*numQuestions * sizeof(Question));
    if (questions == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the questions and answers
    for (int i = 0; i < *numQuestions; i++) {
        fscanf(fp, "%s %s", questions[i].question, questions[i].answer);
    }

    // Close the file
    fclose(fp);

    return questions;
}

// Function to ask the user a question and check their answer
int askQuestion(Question question) {
    // Print the question
    printf("%s\n", question.question);

    // Get the user's answer
    char answer[256];
    scanf("%s", answer);

    // Check if the answer is correct
    return strcmp(answer, question.answer) == 0;
}

int main() {
    // Read the questions from the file
    int numQuestions;
    Question *questions = readQuestions("questions.txt", &numQuestions);
    if (questions == NULL) {
        return 1;
    }

    // Ask the user the questions
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        if (askQuestion(questions[i])) {
            score++;
        }
    }

    // Print the score
    printf("Your score is %d out of %d\n", score, numQuestions);

    // Free the memory allocated for the questions
    free(questions);

    return 0;
}