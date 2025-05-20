//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of questions
#define MAX_QUESTIONS 10

// Define the maximum length of a question or answer
#define MAX_LENGTH 50

// Define a struct for a quiz question
typedef struct {
    char question[MAX_LENGTH];
    char correctAnswer[MAX_LENGTH];
    char answerOne[MAX_LENGTH];
    char answerTwo[MAX_LENGTH];
    char answerThree[MAX_LENGTH];
} Question;

// Define a function to load the questions from a file
void loadQuestions(Question *questions, const char *filename);

// Define a function to shuffle the answers for a question
void shuffleAnswers(char *answerOne, char *answerTwo, char *answerThree, char *correctAnswer);

// Define a function to check if a given answer is correct
bool checkAnswer(char *userAnswer, char *correctAnswer);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create an array to hold the quiz questions
    Question questions[MAX_QUESTIONS];
    
    // Load the questions from a file
    loadQuestions(questions, "questions.txt");
    
    // Keep track of the user's score
    int score = 0;
    
    // Loop through each question
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        // Print the question and the shuffled answers
        printf("Question %d: %s\n", i+1, questions[i].question);
        shuffleAnswers(questions[i].answerOne, questions[i].answerTwo, questions[i].answerThree, questions[i].correctAnswer);
        printf("A) %s\nB) %s\nC) %s\nD) %s\n", questions[i].answerOne, questions[i].answerTwo, questions[i].answerThree, questions[i].correctAnswer);
        
        // Get the user's answer
        char userAnswer[MAX_LENGTH];
        printf("Enter your answer (A/B/C/D): ");
        scanf("%s", userAnswer);
        
        // Check if the answer is correct and update the score accordingly
        if (checkAnswer(userAnswer, questions[i].correctAnswer)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", questions[i].correctAnswer);
        }
        
        // Print the user's current score
        printf("Current score: %d/%d\n\n", score, i+1);
    }
    
    // Print the final score
    printf("Quiz complete! Final score: %d/%d\n", score, MAX_QUESTIONS);
    
    return 0;
}

// Implement the loadQuestions function
void loadQuestions(Question *questions, const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // Loop through each question in the file
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        // Read in the question and answers
        fscanf(file, "%s %s %s %s %s", questions[i].question, questions[i].correctAnswer, questions[i].answerOne, questions[i].answerTwo, questions[i].answerThree);
    }
    
    // Close the file
    fclose(file);
}

// Implement the shuffleAnswers function
void shuffleAnswers(char *answerOne, char *answerTwo, char *answerThree, char *correctAnswer) {
    // Create an array to hold the answers
    char answers[4][MAX_LENGTH];
    strcpy(answers[0], answerOne);
    strcpy(answers[1], answerTwo);
    strcpy(answers[2], answerThree);
    strcpy(answers[3], correctAnswer);
    
    // Shuffle the answers using the Fisher-Yates algorithm
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i+1);
        char temp[MAX_LENGTH];
        strcpy(temp, answers[i]);
        strcpy(answers[i], answers[j]);
        strcpy(answers[j], temp);
    }
    
    // Copy the shuffled answers back into the original variables
    strcpy(answerOne, answers[0]);
    strcpy(answerTwo, answers[1]);
    strcpy(answerThree, answers[2]);
    strcpy(correctAnswer, answers[3]);
}

// Implement the checkAnswer function
bool checkAnswer(char *userAnswer, char *correctAnswer) {
    // Convert the user's answer to uppercase
    char uppercaseUserAnswer[MAX_LENGTH];
    strcpy(uppercaseUserAnswer, userAnswer);
    for (int i = 0; i < strlen(userAnswer); i++) {
        uppercaseUserAnswer[i] = toupper(uppercaseUserAnswer[i]);
    }
    
    // Convert the correct answer to uppercase
    char uppercaseCorrectAnswer[MAX_LENGTH];
    strcpy(uppercaseCorrectAnswer, correctAnswer);
    for (int i = 0; i < strlen(correctAnswer); i++) {
        uppercaseCorrectAnswer[i] = toupper(uppercaseCorrectAnswer[i]);
    }
    
    // Compare the two answers
    if (strcmp(uppercaseUserAnswer, uppercaseCorrectAnswer) == 0) {
        return true;
    } else {
        return false;
    }
}