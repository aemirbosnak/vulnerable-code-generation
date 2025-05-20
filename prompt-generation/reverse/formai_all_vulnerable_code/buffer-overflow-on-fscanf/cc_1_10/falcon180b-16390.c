//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 50

// Structure for a question
typedef struct {
    char question[100];
    int correct_answer;
    char options[MAX_OPTIONS][100];
} Question;

// Structure for a student
typedef struct {
    int id;
    char name[50];
    int score;
} Student;

// Function to read questions from a file
void readQuestions(Question questions[], FILE *fp) {
    int i = 0;
    while (fscanf(fp, "%s %d %s %s %s %s", questions[i].question, &questions[i].correct_answer, questions[i].options[0], questions[i].options[1], questions[i].options[2], questions[i].options[3])!= EOF) {
        i++;
    }
}

// Function to evaluate answers
int evaluateAnswers(int answer, int correct_answer) {
    if (answer == correct_answer) {
        return 1;
    } else {
        return 0;
    }
}

// Function to display score
void displayScore(int score, int total_questions) {
    printf("Your score is %d out of %d\n", score, total_questions);
}

// Main function
int main() {
    // Declare variables
    FILE *fp;
    Question questions[MAX_QUESTIONS];
    int num_questions, i, j, k, l, score = 0, option;
    char filename[50];

    // Get filename from user
    printf("Enter the name of the file containing questions: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read questions from file
    readQuestions(questions, fp);
    num_questions = i;

    // Loop through each question
    for (i = 0; i < num_questions; i++) {
        // Display question and options
        printf("%s\n", questions[i].question);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        // Get answer from user
        printf("Enter your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &option);

        // Evaluate answer
        if (evaluateAnswers(option, questions[i].correct_answer) == 1) {
            score++;
        }
    }

    // Display score
    displayScore(score, num_questions);

    // Close file
    fclose(fp);

    return 0;
}