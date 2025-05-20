//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Define the number of questions
    int num_questions = 10;

    // Define the elements and their properties
    const char* elements[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon"};
    const int num_elements = sizeof(elements) / sizeof(elements[0]);
    int correct_answers = 0;

    // Ask the user for their name
    printf("What is your name? ");
    char name[50];
    scanf("%s", name);

    // Print a personalized greeting
    printf("Welcome to the Periodic Table Quiz, %s!\n", name);

    // Ask the user for the difficulty level
    int difficulty;
    printf("Choose a difficulty level (1-3): ");
    scanf("%d", &difficulty);

    // Shuffle the elements based on the difficulty level
    for (int i = 0; i < num_questions; i++) {
        int rand_index = rand() % num_elements;
        char* temp = elements[rand_index];
        elements[rand_index] = elements[i];
        elements[i] = temp;
    }

    // Ask the user the questions
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: What element has the symbol '%s'?\n", i+1, elements[i]);
        char answer[50];
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, elements[i]) == 0) {
            correct_answers++;
        }
    }

    // Print the results
    printf("\nYou got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}