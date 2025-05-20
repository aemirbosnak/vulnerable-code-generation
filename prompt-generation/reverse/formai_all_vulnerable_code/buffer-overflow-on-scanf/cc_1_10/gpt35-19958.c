//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    char answer;
    
    // seed the random number generator with the current time
    srand(time(NULL));
    
    // array of elements
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
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };
    
    // array of element symbols used
    char symbols[118][3] = {
        "H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne",
        "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca",
        "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr",
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
        "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
        "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg",
        "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
        "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };
    
    // welcome message
    printf("Welcome to the apocalyptic Periodic Table Quiz!\n");
    printf("Try to correctly guess the symbols for each element.\n");
    printf("You have 10 chances to get as many correct answers as possible.\n\n");
    
    // loop through 10 questions
    for (int i = 0; i < 10; i++) {
        int random_num = rand() % 118;
        
        printf("Question %d\n", i+1);
        printf("What is the symbol for element %s?\n", elements[random_num]);
        scanf(" %c", &answer); // space before %c ignores whitespace
        
        if (answer == symbols[random_num][0]) {
            printf("Correct! The symbol for element %s is %s.\n", elements[random_num], symbols[random_num]);
            score++;
        } else {
            printf("Incorrect! The symbol for element %s is %s.\n", elements[random_num], symbols[random_num]);
        }
        
        printf("Your score is: %d\n\n", score);
    }
    
    // final score
    printf("Thanks for playing!\n");
    printf("Your final score is: %d/10\n", score);
    
    return 0;
}