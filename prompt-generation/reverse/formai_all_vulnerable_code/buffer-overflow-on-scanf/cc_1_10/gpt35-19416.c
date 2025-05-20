//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char elements[118][3] = {
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", 
        "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", 
        "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", 
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", 
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", 
        "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", 
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", 
        "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", 
        "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", 
        "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int atomic_numbers[118] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
        91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
        101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
        111, 112, 113, 114, 115, 116, 117, 118};
    int num_elements = 118;
    srand(time(0)); // Seed the random number generator with the current time.
    
    // Print welcome message
    printf("************************************************************\n");
    printf("*                Welcome to the Periodic Table Quiz         *\n");
    printf("*                --------------------------------         *\n");
    printf("*   You will be shown an element and its atomic number.    *\n");
    printf("*     Your task is to enter the element's symbol.          *\n");
    printf("*                                                          *\n");
    printf("*     Press any key to start the quiz...                    *\n");
    printf("************************************************************\n");
    getchar(); // Wait for user to press a key.
    
    // Variables to keep track of quiz results.
    int num_correct = 0;
    int num_attempts = 0;
    
    while (1) {
        // Pick a random element from the list.
        int index = rand() % num_elements;
        int atomic_number = atomic_numbers[index];
        char symbol[3];
        
        // Get user input.
        printf("\nWhat is the symbol for element %d?\n", atomic_number);
        scanf("%s", symbol);
        
        // Check if user answer is correct.
        if (strcmp(elements[index], symbol) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", elements[index]);
        }
        num_attempts++;
        
        // Ask user if they want to continue or quit.
        char choice;
        printf("\nDo you want to continue? (Y/N)");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }
    
    // Print quiz results.
    printf("\n\n************************************************************\n");
    printf("*                         Quiz Results                      *\n");
    printf("*                                                          *\n");
    printf("*    Number of Correct Answers: %d / %d                  *\n", num_correct, num_attempts);
    printf("*                                                          *\n");
    printf("************************************************************\n");
    
    return 0;
}