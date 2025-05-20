//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 118 // number of elements in the periodic table
#define MAX_NAME_LENGTH 20 // maximum number of characters in an element name
#define MAX_SYMBOL_LENGTH 3 // maximum number of characters in an element symbol

// structure for each element in the periodic table
typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    float atomic_weight;
} element_t;

// function to get a random number between min and max (inclusive)
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// function to shuffle an array of integers using the Fisher-Yates shuffle algorithm
void shuffle_array(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = get_random_number(0, i);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// function to initialize a quiz with random element order and score of 0
void initialize_quiz(int *element_order, int num_questions) {
    // initialize element order with numbers from 1 to NUM_ELEMENTS
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element_order[i] = i + 1;
    }
    
    // shuffle the first num_questions elements
    shuffle_array(element_order, num_questions);
}

// function to display the element name and symbol along with a prompt to enter the atomic number
void display_question(element_t element, int question_number, int num_questions) {
    printf("Question %d of %d:\n", question_number, num_questions);
    printf("What is the atomic number of the element whose name is %s and symbol is %s?\n", element.name, element.symbol);
}

// function to grade the user's response to a question
void grade_response(int user_response, int correct_response, int *score) {
    if (user_response == correct_response) {
        printf("Correct!\n");
        (*score)++;
    } else {
        printf("Incorrect. The correct answer was %d.\n", correct_response);
    }
}

// function to play the quiz with num_questions questions
void play_quiz(element_t *periodic_table, int num_questions) {
    int element_order[NUM_ELEMENTS];
    int score = 0;
    
    initialize_quiz(element_order, num_questions);
    
    for (int i = 0; i < num_questions; i++) {
        element_t current_element = periodic_table[element_order[i] - 1];
        display_question(current_element, i + 1, num_questions);
        
        int user_response;
        scanf("%d", &user_response);
        
        grade_response(user_response, current_element.atomic_number, &score);
    }
    
    printf("Quiz complete! Your score is %d out of %d.\n", score, num_questions);
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    // initialize the periodic table with data for all elements
    element_t periodic_table[NUM_ELEMENTS] = {
        {"Hydrogen", "H", 1, 1.008},
        {"Helium", "He", 2, 4.003},
        {"Lithium", "Li", 3, 6.941},
        {"Beryllium", "Be", 4, 9.012},
        {"Boron", "B", 5, 10.81},
        {"Carbon", "C", 6, 12.01},
        {"Nitrogen", "N", 7, 14.01},
        {"Oxygen", "O", 8, 16.00},
        // more elements here...
    };
    
    // prompt the user for the number of questions they want to answer
    int num_questions;
    printf("How many questions would you like to answer? (up to %d)\n", NUM_ELEMENTS);
    scanf("%d", &num_questions);
    
    // play the quiz using the specified number of questions
    play_quiz(periodic_table, num_questions);
    
    return 0;
}