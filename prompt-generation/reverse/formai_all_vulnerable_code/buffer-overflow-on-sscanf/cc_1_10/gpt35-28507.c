//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118

// Define the structure of a chemical element
typedef struct {
    char symbol[3]; // Element symbol (e.g. "H", "He")
    char name[20]; // Element name (e.g. "Hydrogen", "Helium")
    int atomic_number; // Atomic number of the element
    int group_number; // Group number of the element
} Element;

// Function to generate a random number within a range
int generate_random_number(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main() {
    srand(time(NULL)); // Initialize the random number generator

    Element periodic_table[MAX_ELEMENTS]; // Array to store the periodic table
    int num_elements = 0; // Number of elements in the periodic table

    // Read the periodic table data from a file
    FILE *fp = fopen("periodic_table.txt", "r");
    if (fp != NULL) {
        // Read each line of the file
        char line[50];
        while (fgets(line, sizeof(line), fp) != NULL) {
            // Split the line into its components
            char symbol[3];
            char name[20];
            int atomic_number;
            int group_number;
            sscanf(line, "%s %s %d %d", symbol, name, &atomic_number, &group_number);

            // Create a new element and add it to the periodic table array
            Element element;
            strcpy(element.symbol, symbol);
            strcpy(element.name, name);
            element.atomic_number = atomic_number;
            element.group_number = group_number;
            periodic_table[num_elements] = element;
            num_elements++;
        }
        fclose(fp);
    } else {
        printf("Error: Could not open file.\n");
        return -1;
    }

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Type the atomic number of the element corresponding to each symbol.\n");
    printf("Type 'quit' to exit.\n\n");

    int num_correct = 0; // Number of correct answers
    int num_questions = 0; // Number of questions asked

    while(1) {
        // Generate a random element from the periodic table
        int index = generate_random_number(0, num_elements - 1);
        Element element = periodic_table[index];

        // Ask the user for the atomic number of the element
        printf("%s: ", element.symbol);
        char input[10];
        fgets(input, sizeof(input), stdin);

        // Check if the user wants to quit
        if (strncmp(input, "quit", 4) == 0) {
            break;
        }

        // Parse the user's input
        int guess = atoi(input);

        // Check if the guess is correct
        if (guess == element.atomic_number) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The atomic number of %s is %d.\n", element.name, element.atomic_number);
        }

        num_questions++; // Increment the number of questions asked
    }

    // Calculate and print the user's score
    float score = (float)num_correct / num_questions * 100;
    printf("\nYou answered %d out of %d questions correctly.\n", num_correct, num_questions);
    printf("Your score: %.2f%%\n", score);

    return 0;
}