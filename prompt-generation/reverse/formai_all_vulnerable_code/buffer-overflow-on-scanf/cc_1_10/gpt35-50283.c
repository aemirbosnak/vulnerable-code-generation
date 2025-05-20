//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 5

// Struct to store element information
typedef struct element {
    char symbol[3];
    int atomic_num;
    char name[25];
} Element;

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Create array of elements in periodic table
    Element periodic_table[NUM_ELEMENTS] = {
        {"H", 1, "Hydrogen"},
        {"He", 2, "Helium"},
        {"Li", 3, "Lithium"},
        // ...
        {"Og", 118, "Oganesson"}
    };
    
    // Ask questions
    int correct = 0;
    int question_num = 1;
    while (question_num <= NUM_QUESTIONS) {
        // Pick a random element
        int index = rand() % NUM_ELEMENTS;
        Element element = periodic_table[index];
        
        // Ask the question
        printf("Question %d: What is the atomic number of %s?\n", question_num, element.name);
        
        // Get user's answer
        int user_answer;
        scanf("%d", &user_answer);
        
        // Check if user's answer is correct
        if (user_answer == element.atomic_num) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", element.atomic_num);
        }
        
        // Move on to next question
        question_num++;
    }
    
    // Print final score
    printf("You got %d out of %d questions correct!\n", correct, NUM_QUESTIONS);
    
    return 0;
}