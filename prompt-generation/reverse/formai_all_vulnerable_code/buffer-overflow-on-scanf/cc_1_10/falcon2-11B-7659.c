//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Define the periodic table
    char periodicTable[110][2] = {
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
        "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
        "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te",
        "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm",
        "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
        "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr",
        "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og", "Un", "Lr",
        "Uub", "Uut", "Uuu"
    };

    // Define the quiz
    char* questions[10] = {
        "What is the symbol for Hydrogen?",
        "What is the symbol for Helium?",
        "What is the symbol for Lithium?",
        "What is the symbol for Beryllium?",
        "What is the symbol for Boron?",
        "What is the symbol for Carbon?",
        "What is the symbol for Nitrogen?",
        "What is the symbol for Oxygen?",
        "What is the symbol for Fluorine?",
        "What is the symbol for Neon?"
    };
    char* answers[10] = {
        "H",
        "He",
        "Li",
        "Be",
        "B",
        "C",
        "N",
        "O",
        "F",
        "Ne"
    };

    // Play the quiz
    int score = 0;
    for (int i = 0; i < 10; i++) {
        printf("%s. %s\n", questions[i], answers[i]);
        scanf("%s", periodicTable);
        if (strcmp(periodicTable, answers[i]) == 0) {
            score++;
        }
    }

    printf("You scored %d/%d.\n", score, 10);

    return 0;
}