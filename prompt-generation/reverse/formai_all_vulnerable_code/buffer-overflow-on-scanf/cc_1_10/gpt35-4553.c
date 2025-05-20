//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants for the program
#define MAX_ELEMENTS 118 // Total number of elements in the periodic table
#define MIN_QUESTIONS 5 // Minimum number of questions in the quiz
#define MAX_QUESTIONS 20 // Maximum number of questions in the quiz
#define MAX_NAME_LENGTH 50 // Maximum length of an element name

// Function prototypes
void displayWelcomeMessage();
int getNumberOfQuestions();
void readElementsFromFile(char *filename, char **names, char **symbols, int *numbers);
void performQuiz(char **names, char **symbols, int *numbers, int numQuestions);
void shuffleArray(int *array, int size);
void displayScore(int score, int totalQuestions);

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Set up variables for quiz
    char *names[MAX_ELEMENTS];
    char *symbols[MAX_ELEMENTS];
    int numbers[MAX_ELEMENTS];
    
    // Read element data from file
    readElementsFromFile("elements.txt", names, symbols, numbers);
    
    // Display welcome message
    displayWelcomeMessage();
    
    // Get number of questions from user
    int numQuestions = getNumberOfQuestions();
    
    // Perform the quiz
    performQuiz(names, symbols, numbers, numQuestions);
    
    return 0;
}

// This function displays a welcome message to the user
void displayWelcomeMessage() {
    printf("Welcome to the Retro Periodic Table Quiz!\n");
    printf("-----------------------------------------\n\n");
}

// This function prompts the user for the number of questions they want in the quiz
// and returns the user's selection
int getNumberOfQuestions() {
    int numQuestions = 0;
    do {
        printf("How many questions would you like in the quiz? (minimum %d, maximum %d) ", MIN_QUESTIONS, MAX_QUESTIONS);
        scanf("%d", &numQuestions);
    } while (numQuestions < MIN_QUESTIONS || numQuestions > MAX_QUESTIONS);
    return numQuestions;
}

// This function reads the element data from a file and stores it in arrays
void readElementsFromFile(char *filename, char **names, char **symbols, int *numbers) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    
    // Make sure file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Read in data for each element
    int i = 0;
    while (!feof(file)) {
        // Allocate memory for name and symbol strings
        names[i] = (char*) malloc(MAX_NAME_LENGTH * sizeof(char));
        symbols[i] = (char*) malloc(3 * sizeof(char));
        
        // Read in data for current element
        fscanf(file, "%d %s %[^\n]s", &numbers[i], symbols[i], names[i]);
        
        // Increment index counter
        i++;
    }
    
    // Close the file
    fclose(file);
}

// This function performs the quiz
void performQuiz(char **names, char **symbols, int *numbers, int numQuestions) {
    // Set up variables for quiz
    int questionNumbers[MAX_ELEMENTS];
    int questionIndex = 0;
    int score = 0;
    
    // Generate random question numbers
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        questionNumbers[i] = i;
    }
    shuffleArray(questionNumbers, MAX_ELEMENTS);
    
    // Loop through each question and ask it
    printf("\nStarting quiz with %d questions.\n\n", numQuestions);
    for (int i = 0; i < numQuestions; i++) {
        // Get the index of the current question
        questionIndex = questionNumbers[i];
        
        // Display the current question
        printf("Question %d: What is the symbol for %s? ", i + 1, names[questionIndex]);
        
        // Get the user's answer
        char answer[3];
        scanf("%s", answer);
        
        // Check if the answer is correct
        if (strcmp(answer, symbols[questionIndex]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", symbols[questionIndex]);
        }
    }
    
    // Display final score
    displayScore(score, numQuestions);
}

// This function shuffles an array of integers
void shuffleArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// This function displays the user's final score
void displayScore(int score, int totalQuestions) {
    printf("\nQuiz complete. You scored %d out of %d.\n", score, totalQuestions);
    if (score == totalQuestions) {
        printf("Wow, you know your elements!\n");
    } else if (score >= (totalQuestions * 0.75)) {
        printf("Not bad, but there is still room for improvement.\n");
    } else {
        printf("Looks like you need to study up on your elements!\n");
    }
}