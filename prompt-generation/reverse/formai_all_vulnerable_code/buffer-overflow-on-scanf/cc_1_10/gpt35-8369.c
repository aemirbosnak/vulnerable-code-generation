//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the periodic table with element symbols
    char* elements[] = {
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg",
        "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V",
        "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se",
        "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh",
        "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba",
        "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho",
        "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt",
        "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac",
        "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg",
        "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };
    int size = sizeof(elements) / sizeof(elements[0]);
    
    printf("*** Welcome to the Periodic Table Quiz! ***\n");
    printf("You will be given the number of an element, and you must enter its symbol.\n");
    printf("Enter 'quit' to exit the program at any time.\n\n");

    // Set seed for random number generator
    srand(time(NULL));

    // Start the quiz loop
    char input[10];
    int score = 0;
    while (1) {
        // Generate a random atomic number for an element
        int atomic_number = rand() % size + 1;
        char* symbol = elements[atomic_number - 1];

        // Prompt user for the symbol of the element with the given atomic number
        printf("What is the symbol for element with atomic number %d? ", atomic_number);

        // Get user input
        scanf("%s", input);

        // Convert input to uppercase
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                input[i] -= 32;
            }
        }

        // Check if user wants to quit
        if (strcmp(input, "QUIT") == 0) {
            break;
        }

        // Check if user input is correct
        if (strcmp(input, symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The symbol for element %d is %s.\n", atomic_number, symbol);
        }

        // Print current score
        printf("Your score is %d.\n", score);
        printf("\n");
    }

    // End of quiz
    printf("Thanks for playing! Your final score is %d.\n", score);

    return 0;
}