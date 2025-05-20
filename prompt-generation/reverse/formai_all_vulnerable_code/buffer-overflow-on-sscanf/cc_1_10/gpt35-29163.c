//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the element name
#define MAX_STRING_SIZE 50

// Define the maximum number of elements
#define MAX_ELEMENTS 118

// Define the number of questions for the quiz
#define NUM_QUESTIONS 10

// Define the number of answer choices for each question
#define NUM_ANSWER_CHOICES 4

// Define the struct for an element
typedef struct {
    int atomic_number;
    char symbol[3];
    char name[MAX_STRING_SIZE];
    float atomic_weight;
} element;

// Define the array of elements
element elements[MAX_ELEMENTS];

// Function to initialize the elements array
void initialize_elements() {
    // Open the data file for the elements
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open elements file!\n");
        exit(1);
    }

    // Read the data into the elements array
    char line[MAX_STRING_SIZE*4];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Read the data into the element struct
        sscanf(line, "%d %s %[^\n] %f", &elements[i].atomic_number, elements[i].symbol, elements[i].name, &elements[i].atomic_weight);
        i++;
    }

    // Close the file
    fclose(fp);
}

// Function to shuffle an array
void shuffle_array(int *array, int size) {
    for (int i = size-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to start the quiz
void start_quiz() {
    // Initialize the array of questions
    int question_numbers[MAX_ELEMENTS];
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        question_numbers[i] = i;
    }

    // Shuffle the questions array
    shuffle_array(question_numbers, MAX_ELEMENTS);

    // Print the quiz instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about elements.\n", NUM_QUESTIONS);
    printf("For each question, choose the correct answer choice (a, b, c, or d).\n");
    printf("Let's begin!\n\n");

    // Initialize the score
    int score = 0;

    // Loop through the questions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Get the current question and shuffle the answer choices
        int question_number = question_numbers[i];
        char answer_choices[NUM_ANSWER_CHOICES] = {'a', 'b', 'c', 'd'};
        shuffle_array(answer_choices, NUM_ANSWER_CHOICES);

        // Print the question and answer choices
        printf("%d. What is the name of the element with symbol %s?\n", i+1, elements[question_number].symbol);
        printf("   %c. %s\n", answer_choices[0], elements[question_numbers[(question_number+1)%MAX_ELEMENTS]].name);
        printf("   %c. %s\n", answer_choices[1], elements[question_numbers[(question_number+2)%MAX_ELEMENTS]].name);
        printf("   %c. %s\n", answer_choices[2], elements[question_numbers[(question_number+3)%MAX_ELEMENTS]].name);
        printf("   %c. %s\n", answer_choices[3], elements[question_numbers[(question_number+4)%MAX_ELEMENTS]].name);

        // Get the user's answer and check if it is correct
        char answer;
        printf("Enter your answer choice: ");
        scanf(" %c", &answer);
        if (answer == 'a' && strcmp(elements[question_number].name, elements[question_numbers[(question_number+1)%MAX_ELEMENTS]].name) == 0) {
            score++;
        } else if (answer == 'b' && strcmp(elements[question_number].name, elements[question_numbers[(question_number+2)%MAX_ELEMENTS]].name) == 0) {
            score++;
        } else if (answer == 'c' && strcmp(elements[question_number].name, elements[question_numbers[(question_number+3)%MAX_ELEMENTS]].name) == 0) {
            score++;
        } else if (answer == 'd' && strcmp(elements[question_number].name, elements[question_numbers[(question_number+4)%MAX_ELEMENTS]].name) == 0) {
            score++;
        }

        // Print the current score
        printf("Your current score is %d/%d.\n\n", score, i+1);
    }

    // Print the final score
    printf("Congratulations, you have completed the quiz!\n");
    printf("Your final score is %d/%d.\n", score, NUM_QUESTIONS);
}

// Main function
int main() {
    // Initialize the elements array
    initialize_elements();

    // Start the quiz
    start_quiz();

    return 0;
}