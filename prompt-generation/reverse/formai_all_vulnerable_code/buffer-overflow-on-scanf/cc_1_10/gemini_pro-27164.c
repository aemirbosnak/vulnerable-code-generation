//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions
#define NUM_QUESTIONS 10

// Define the number of choices per question
#define NUM_CHOICES 4

// Define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// Define the maximum number of correct answers
#define MAX_CORRECT 10

// Define the maximum number of incorrect answers
#define MAX_INCORRECT 10

// Create a struct to store the questions and answers
typedef struct {
    char question[100];
    char choices[NUM_CHOICES][100];
    int correct_answer;
} Question;

// Create an array of questions
Question questions[] = {
    {"What is the symbol for hydrogen?", {"H", "He", "Li", "Be"}, 0},
    {"What is the atomic number of oxygen?", {"6", "8", "10", "12"}, 1},
    {"What is the name of the element with the symbol Fe?", {"Iron", "Fluorine", "Francium", "Fermium"}, 0},
    {"What is the atomic mass of gold?", {"196.967", "207.2", "238.03", "243.06"}, 0},
    {"What is the period number of chlorine?", {"2", "3", "4", "5"}, 1},
    {"What is the group number of sodium?", {"1", "2", "3", "4"}, 0},
    {"What is the electronegativity of fluorine?", {"3.98", "4.00", "4.10", "4.20"}, 0},
    {"What is the ionization energy of lithium?", {"520 kJ/mol", "730 kJ/mol", "940 kJ/mol", "1150 kJ/mol"}, 0},
    {"What is the electron configuration of carbon?", {"1s2 2s2 2p2", "1s2 2s2 2p3", "1s2 2s2 2p4", "1s2 2s2 2p5"}, 0},
    {"What is the oxidation state of nitrogen in nitric oxide?", {"+1", "+2", "+3", "+4"}, 0}
};

// Create a function to generate a random number
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Create a function to ask a question
void ask_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < NUM_CHOICES; i++) {
        printf("%d. %s\n", i + 1, question.choices[i]);
    }
}

// Create a function to get the user's input
int get_user_input() {
    int input;
    scanf("%d", &input);
    return input;
}

// Create a function to check the user's answer
int check_answer(Question question, int user_input) {
    return user_input - 1 == question.correct_answer;
}

// Create a function to print the results
void print_results(int correct, int incorrect) {
    printf("Correct answers: %d\n", correct);
    printf("Incorrect answers: %d\n", incorrect);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an array to store the user's answers
    int answers[NUM_QUESTIONS];

    // Ask the user each question
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        ask_question(questions[i]);
        answers[i] = get_user_input();
    }

    // Check the user's answers
    int correct = 0;
    int incorrect = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int is_correct = check_answer(questions[i], answers[i]);
        if (is_correct) {
            correct++;
        } else {
            incorrect++;
        }
    }

    // Print the results
    print_results(correct, incorrect);

    return 0;
}