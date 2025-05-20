//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Define global constants for the maximum number of elements and their symbols
#define MAX_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3

// Define a struct to represent an element with its symbol, name, and atomic number
struct Element {
    char symbol[MAX_SYMBOL_LENGTH];
    char name[25];
    int atomic_number;
};

// Define a function to create and return a new element struct given its symbol, name, and atomic number
struct Element create_element(char symbol[MAX_SYMBOL_LENGTH], char name[25], int atomic_number) {
    struct Element element;
    strcpy(element.symbol, symbol);
    strcpy(element.name, name);
    element.atomic_number = atomic_number;
    return element;
}

int main() {
    // Initialize an array to store all the element structs
    struct Element elements[MAX_ELEMENTS] = {
        create_element("H", "Hydrogen", 1),
        create_element("He", "Helium", 2),
        create_element("Li", "Lithium", 3),
        create_element("Be", "Beryllium", 4),
        create_element("B", "Boron", 5),
        create_element("C", "Carbon", 6),
        create_element("N", "Nitrogen", 7),
        create_element("O", "Oxygen", 8),
        create_element("F", "Fluorine", 9),
        create_element("Ne", "Neon", 10),
        // Add the rest of the elements here
    };

    // Initialize a counter for the number of correct answers
    int num_correct = 0;

    // Initialize a counter for the number of questions asked
    int num_questions = 0;

    // Loop through 10 randomly chosen elements and ask the user for their symbol
    for (int i = 0; i < 10; i++) {
        // Generate a random number between 0 and MAX_ELEMENTS - 1
        int random_index = rand() % MAX_ELEMENTS;

        // Get the element struct at the randomly chosen index
        struct Element element = elements[random_index];

        // Print the question and prompt the user for a response
        printf("What is the symbol for %s (atomic number %d)?\n", element.name, element.atomic_number);
        char answer[MAX_SYMBOL_LENGTH];
        scanf("%s", answer);

        // Compare the user's response to the correct answer
        if (strcmp(answer, element.symbol) == 0) {
            // If the user's response is correct, increment the num_correct counter
            printf("Correct!\n");
            num_correct++;
        } else {
            // If the user's response is incorrect, reveal the correct answer
            printf("Incorrect. The correct symbol is %s.\n", element.symbol);
        }

        // Increment the num_questions counter
        num_questions++;
    }

    // Calculate the percentage of correct answers and print the result
    float percentage_correct = (float) num_correct / num_questions * 100;
    printf("You got %d out of %d questions correct (%.0f%%).\n", num_correct, num_questions, percentage_correct);

    return 0;
}