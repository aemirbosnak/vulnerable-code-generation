//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10

typedef struct {
    int atomic_number;
    char name[20];
} Element;

Element periodic_table[MAX_ELEMENTS] = {
    {1, "Hydrogen"},
    {2, "Helium"},
    {3, "Lithium"},
    {4, "Beryllium"},
    {5, "Boron"},
    {6, "Carbon"},
    {7, "Nitrogen"},
    {8, "Oxygen"},
    {9, "Fluorine"},
    {10, "Neon"}
};

void display_instructions() {
    printf("\nWelcome to the Periodic Table Quiz!\n");
    printf("Guess the element by its atomic number.\n");
    printf("Type 'exit' to quit the quiz at any time.\n");
}

void start_quiz() {
    char answer[20];
    int score = 0;
    int guessed_count = 0;

    printf("\nLet's start the quiz!\n");
    
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("\nWhat is the name of the element with atomic number %d? ", 
               periodic_table[i].atomic_number);
        printf("(Your Answer): ");
        scanf("%s", answer);
        
        // Allow the user to exit the quiz
        if (strcmp(answer, "exit") == 0) {
            printf("\nYou scored %d out of %d!\n", score, guessed_count);
            return;
        }

        guessed_count++;

        // Check if the answer is correct
        if (strcasecmp(answer, periodic_table[i].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", periodic_table[i].name);
        }
    }

    printf("\nQuiz Over! You scored %d out of %d!\n", score, MAX_ELEMENTS);
}

int main() {
    display_instructions();
    start_quiz();
    return 0;
}