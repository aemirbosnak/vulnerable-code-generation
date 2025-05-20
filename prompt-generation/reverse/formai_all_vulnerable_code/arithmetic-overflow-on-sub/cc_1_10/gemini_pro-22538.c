//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the structure of an element
typedef struct element {
    int atomic_number;
    char *name;
    char *symbol;
    double atomic_mass;
    int group;
    int period;
} element;

// Define an array of elements
element elements[NUM_ELEMENTS];

// Initialize the array of elements
void initialize_elements() {
    // Open the file containing the periodic table data
    FILE *fp = fopen("periodic_table.csv", "r");
    if (fp == NULL) {
        perror("Error opening periodic_table.csv");
        exit(EXIT_FAILURE);
    }

    // Read the data from the file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the data
        int atomic_number;
        char *name;
        char *symbol;
        double atomic_mass;
        int group;
        int period;
        sscanf(line, "%d,%[^,],%[^,],%lf,%d,%d", &atomic_number, name, symbol, &atomic_mass, &group, &period);

        // Store the data in the array of elements
        elements[atomic_number - 1].atomic_number = atomic_number;
        elements[atomic_number - 1].name = name;
        elements[atomic_number - 1].symbol = symbol;
        elements[atomic_number - 1].atomic_mass = atomic_mass;
        elements[atomic_number - 1].group = group;
        elements[atomic_number - 1].period = period;
    }

    // Close the file
    fclose(fp);
}

// Print the periodic table
void print_periodic_table() {
    // Print the header
    printf("%-3s %-20s %-2s %-8s %-6s %-6s\n", "No.", "Name", "Symbol", "Atomic Mass", "Group", "Period");

    // Print the elements
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%-3d %-20s %-2s %-8.3f %-6d %-6d\n", elements[i].atomic_number, elements[i].name, elements[i].symbol, elements[i].atomic_mass, elements[i].group, elements[i].period);
    }
}

// Play the periodic table quiz
void play_periodic_table_quiz() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 118
    int random_number = rand() % NUM_ELEMENTS + 1;

    // Get the element from the array of elements
    element element = elements[random_number - 1];

    // Ask the user to guess the element
    char guess[100];
    printf("Guess the element with atomic number %d: ", element.atomic_number);
    scanf("%s", guess);

    // Check if the guess is correct
    if (strcmp(guess, element.name) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %s.\n", element.name);
    }
}

// Main function
int main() {
    // Initialize the array of elements
    initialize_elements();

    // Print the periodic table
    print_periodic_table();

    // Play the periodic table quiz
    play_periodic_table_quiz();

    return 0;
}