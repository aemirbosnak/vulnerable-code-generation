//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include<stdio.h>

#define MAX_ELEMENTS 118

int main()
{
    char elements[MAX_ELEMENTS][3] = {
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
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };
    
    char symbol[3];
    int atomic_number;
    int correct_answers = 0;

    printf("\n\t\tPeriodic Table Quiz\n");
    printf("=========================================================\n");
    printf("Enter 'Q' to quit.\n");
    
    while (1) {
        // pick a random element
        int random_index = rand() % MAX_ELEMENTS;
        strcpy(symbol, elements[random_index]);
        atomic_number = random_index + 1; // atomic number starts from 1
        
        // ask the question
        printf("\nWhat is the symbol for element with atomic number %d?\n", atomic_number);
        scanf("%s", symbol);
        
        if (strcmp(symbol, "Q") == 0) {
            break;
        }
        
        if (strcmp(symbol, elements[random_index]) == 0) {
            // correct answer
            printf("Correct! %s is the symbol for element with atomic number %d.\n", symbol, atomic_number);
            correct_answers++;
        } else {
            // incorrect answer
            printf("Incorrect. The correct symbol for element with atomic number %d is %s.\n", atomic_number, elements[random_index]);
        }
    }
    
    // quiz summary
    printf("\nQuiz Complete! You got %d out of %d questions correct.\n", correct_answers, MAX_ELEMENTS);
    
    return 0;
}