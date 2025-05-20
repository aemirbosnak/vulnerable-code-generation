//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main(){

    char* element_symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl",
                               "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", 
                               "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In",
                               "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb",
                               "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl",
                               "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk",
                               "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn",
                               "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    int element_atomic_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
                                    25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
                                    47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
                                    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
                                    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
                                    111, 112, 113, 114, 115, 116, 117, 118};

    printf("Welcome to the Cryptic Periodic Table Quiz!\n");
    printf("Your mission, should you choose to accept it, is to answer all the questions correctly.\n");
    printf("You have three chances before the program self-destructs. Good luck!\n");

    int score = 0;
    int chances = 3;

    while(chances > 0){

        int i = rand() % 118;
        char* symbol = element_symbols[i];
        int atomic_number = element_atomic_numbers[i];

        printf("\nWhat element has the symbol \"%c%c\" and atomic number %d?\n", symbol[0], symbol[1], atomic_number);

        char answer[3];
        scanf("%s", answer);

        if(answer[0] == symbol[0] && answer[1] == symbol[1] && answer[2] == '\0'){
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
            chances--;
        }
    }

    printf("\nMission failed. The program has self-destructed.\n");
    printf("Your score: %d\n", score);

    return 0;
}