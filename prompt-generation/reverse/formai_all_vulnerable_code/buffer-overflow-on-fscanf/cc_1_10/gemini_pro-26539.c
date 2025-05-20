//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct {
    char question[256];
    char answer[256];
} Question;

// Function to read questions from a file
int readQuestions(Question *questions, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    int numQuestions = 0;
    while (fscanf(fp, "%[^;];%[^\n]\n", questions[numQuestions].question, questions[numQuestions].answer) != EOF) {
        numQuestions++;
    }

    fclose(fp);
    return numQuestions;
}

// Function to shuffle questions
void shuffleQuestions(Question *questions, int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        int j = rand() % numQuestions;
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

// Function to display a question and get user input
char *getAnswer(Question question) {
    printf("%s\n", question.question);
    char *answer = malloc(256);
    scanf("%s", answer);
    return answer;
}

// Function to check if user input is correct
int checkAnswer(char *answer, char *correctAnswer) {
    return strcmp(answer, correctAnswer) == 0;
}

// Function to print results
void printResults(int numCorrect, int numQuestions) {
    printf("You got %d out of %d questions correct\n", numCorrect, numQuestions);
}

int main() {
    // Read questions from file
    Question questions[100];
    int numQuestions = readQuestions(questions, "questions.txt");
    if (numQuestions == -1) {
        printf("Error reading questions from file\n");
        return 1;
    }

    // Shuffle questions
    shuffleQuestions(questions, numQuestions);

    // Get user input for each question
    int numCorrect = 0;
    for (int i = 0; i < numQuestions; i++) {
        char *answer = getAnswer(questions[i]);
        if (checkAnswer(answer, questions[i].answer)) {
            numCorrect++;
        }
        free(answer);
    }

    // Print results
    printResults(numCorrect, numQuestions);

    return 0;
}