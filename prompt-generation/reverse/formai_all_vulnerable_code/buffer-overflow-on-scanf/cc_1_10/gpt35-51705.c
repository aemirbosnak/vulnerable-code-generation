//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold element information
typedef struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
    double atomic_mass;
} Element;

int main() {
    // Define array to hold elements
    Element elements[] = {
        {"H", "Hydrogen", 1, 1.008},
        {"He", "Helium", 2, 4.003},
        {"Li", "Lithium", 3, 6.941},
        {"Be", "Beryllium", 4, 9.012},
        {"B", "Boron", 5, 10.81},
        {"C", "Carbon", 6, 12.01},
        // add the other elements here...
    };

    // Get the number of elements in the array
    int num_elements = sizeof(elements) / sizeof(elements[0]);

    // Print header
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("There are %d elements to guess.\n\n", num_elements);

    // Loop through the elements
    for (int i = 0; i < num_elements; i++) {
        // Print the symbol and prompt for guess
        printf("What is the element with the symbol %s? ", elements[i].symbol);

        // Read in the user's guess
        char guess[20];
        scanf("%s", guess);

        // Compare the user's guess to the actual symbol
        if (strcmp(guess, elements[i].symbol) == 0) {
            printf("Correct!\n\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", elements[i].symbol);
        }
    }

    // Print end of game message
    printf("End of game. Thanks for playing!\n");

    return 0;
}