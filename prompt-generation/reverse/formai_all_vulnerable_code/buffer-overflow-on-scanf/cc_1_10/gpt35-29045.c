//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for easy reference
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

// Define a struct to hold question and answer information
typedef struct {
    char question[50];
    char options[MAX_OPTIONS][20];
    int answer;
} Question;

// Declare an array to hold all possible questions
Question questions[118] = {
    {"What is the symbol for Hydrogen?", {"H", "He", "O", "Na"}, 0},
    {"What is the symbol for Helium?", {"Ne", "Ar", "He", "Kr"}, 2},
    {"What is the symbol for Lithium?", {"Li", "Be", "Na", "K"}, 0},
    {"What is the symbol for Beryllium?", {"C", "B", "Mg", "Be"}, 3},
    {"What is the symbol for Boron?", {"C", "B", "N", "O"}, 1},
    {"What is the symbol for Carbon?", {"N", "O", "He", "C"}, 3},
    {"What is the symbol for Nitrogen?", {"H", "N", "He", "Ne"}, 1},
    {"What is the symbol for Oxygen?", {"O", "Li", "He", "Be"}, 0},
    {"What is the symbol for Fluorine?", {"F", "Cl", "Br", "I"}, 0},
    {"What is the symbol for Neon?", {"Ne", "Ar", "Kr", "Xe"}, 0},
    // Continue with rest of elements
    // Omitted for brevity's sake
};

// Declare functions for easy reference
void printWelcomeMessage();
int getRandomQuestionNumber(int* usedQuestions, int numUsedQuestions);
void printQuestion(Question q);
int getUserAnswer();
void printResult(int numCorrectAnswers);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Declare variables to keep track of state and score
    int usedQuestions[MAX_QUESTIONS] = {-1};
    int numUsedQuestions = 0;
    int numCorrectAnswers = 0;
    
    printWelcomeMessage();
    
    // Loop through and ask each question
    for (int i = 0; i < MAX_QUESTIONS && numUsedQuestions < 118; i++) {
        // Generate a random number that hasn't been used before
        int randomQuestionNumber = getRandomQuestionNumber(usedQuestions, numUsedQuestions);
        
        // Add the randomly selected question to the usedQuestions array
        usedQuestions[numUsedQuestions] = randomQuestionNumber;
        numUsedQuestions++;
        
        // Print the question and options
        printf("Question #%d:\n", i + 1);
        Question q = questions[randomQuestionNumber];
        printQuestion(q);

        // Get the user's answer
        int userAnswer = getUserAnswer();
        
        // Check the user's answer against the correct answer
        if (userAnswer == q.answer) {
            printf("Correct!\n\n");
            numCorrectAnswers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", q.options[q.answer]);
        }
    }
    
    // Print the final result
    printResult(numCorrectAnswers);

    return 0;
}

void printWelcomeMessage() {
    printf("Welcome to the Mind-Bending Periodic Table Quiz!\n");
    printf("You will be asked 10 random questions from the periodic table.\n");
    printf("Good luck!\n\n");
}

int getRandomQuestionNumber(int* usedQuestions, int numUsedQuestions) {
    int randomQuestionNumber;
    int isAlreadyUsed;
    
    do {
        isAlreadyUsed = 0;
        randomQuestionNumber = rand() % 118;
        
        // Check if the randomly selected question has already been used
        for (int i = 0; i < numUsedQuestions; i++) {
            if (usedQuestions[i] == randomQuestionNumber) {
                isAlreadyUsed = 1;
                break;
            }
        }
    } while (isAlreadyUsed);
    
    return randomQuestionNumber;
}

void printQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int getUserAnswer() {
    int userAnswer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &userAnswer);
    printf("\n");
    return userAnswer - 1;
}

void printResult(int numCorrectAnswers) {
    printf("==============================\n");
    printf("       Quiz Results:\n");
    printf("==============================\n");
    printf("Correct Answers: %d/10\n", numCorrectAnswers);
    if (numCorrectAnswers == 10) {
        printf("Congratulations! You got a perfect score!\n");
    } else {
        printf("Better luck next time!\n");
    }
}