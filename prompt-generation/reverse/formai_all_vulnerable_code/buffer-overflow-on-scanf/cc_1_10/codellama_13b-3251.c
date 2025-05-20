//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: random
// Periodic Table Quiz
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Struct to represent an element
typedef struct {
    char name[50];
    char symbol[10];
    int number;
    char category[50];
    char phase[50];
} Element;

// Function to generate a random element
Element generate_element() {
    Element element;
    strcpy(element.name, "Hydrogen");
    strcpy(element.symbol, "H");
    element.number = 1;
    strcpy(element.category, "Alkali metal");
    strcpy(element.phase, "Gas");
    return element;
}

// Function to display the element
void display_element(Element element) {
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic number: %d\n", element.number);
    printf("Category: %s\n", element.category);
    printf("Phase: %s\n", element.phase);
}

// Function to check the answer
int check_answer(Element element, char *input) {
    if (strcmp(input, element.symbol) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate a random element
    Element element = generate_element();

    // Display the element
    display_element(element);

    // Get the answer
    char input[50];
    printf("What is the symbol of the element? ");
    scanf("%s", input);

    // Check the answer
    if (check_answer(element, input)) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    return 0;
}