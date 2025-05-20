//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>

#define NUM_ELEMENTS 100

typedef struct {
    char symbol[4];
    int atomic_number;
    int mass_number;
    int valence_electrons;
    bool is_metal;
    bool is_nonmetal;
} Element;

Element elements[NUM_ELEMENTS] = {
    { "He", 2, 4, 2, true, false },
    { "Li", 3, 7, 1, true, false },
    { "Be", 4, 9, 2, true, false },
    { "B", 5, 11, 3, true, false },
    { "C", 6, 12, 4, true, false },
    { "N", 7, 14, 5, true, false },
    { "O", 8, 16, 6, true, false },
    { "F", 9, 19, 7, true, false },
    { "Ne", 10, 20, 8, true, false },
    { "Na", 11, 23, 1, true, false },
    { "Mg", 12, 24, 2, true, false },
    { "Al", 13, 27, 3, true, false },
    { "Si", 14, 28, 4, true, false },
    { "P", 15, 31, 5, true, false },
    { "S", 16, 32, 6, true, false },
    { "Cl", 17, 35, 7, true, false },
    { "Ar", 18, 40, 8, true, false },
    { "K", 19, 39, 1, true, false },
    { "Ca", 20, 40, 2, true, false },
    { "Sc", 21, 45, 3, true, false },
    { "Ti", 22, 48, 4, true, false },
    { "V", 23, 51, 5, true, false },
    { "Cr", 24, 52, 6, true, false },
    { "Mn", 25, 55, 7, true, false },
    { "Fe", 26, 56, 8, true, false },
    { "Co", 27, 58, 9, true, false },
    { "Ni", 28, 58, 10, true, false },
    { "Cu", 29, 63, 11, true, false },
    { "Zn", 30, 65, 12, true, false },
    { "Ga", 31, 69, 13, true, false },
    { "Ge", 32, 72, 14, true, false },
    { "As", 33, 74, 15, true, false },
    { "Se", 34, 78, 16, true, false },
    { "Br", 35, 79, 17, true, false },
    { "Kr", 36, 83, 18, true, false },
    { "Rb", 37, 85, 19, true, false },
    { "Sr", 38, 88, 20, true, false },
    { "Y", 39, 90, 21, true, false },
    { "Zr", 40, 92, 22, true, false },
    { "Nb", 41, 93, 23, true, false },
    { "Mo", 42, 96, 24, true, false },
    { "Tc", 43, 98, 25, true, false },
    { "Ru", 44, 101, 26, true, false },
    { "Rh", 45, 102, 27, true, false },
    { "Pd", 46, 106, 28, true, false },
    { "Ag", 47, 107, 29, true, false },
    { "Cd", 48, 112, 30, true, false },
    { "In", 49, 115, 31, true, false },
    { "Sn", 50, 118, 32, true, false },
    { "Sb", 51, 121, 33, true, false },
    { "Te", 52, 128, 34, true, false },
    { "I", 53, 126, 35, true, false },
    { "Xe", 54, 131, 36, true, false },
    { "Cs", 55, 137, 37, true, false },
    { "Ba", 56, 137, 38, true, false },
    { "La", 57, 138, 39, true, false },
    { "Ce", 58, 140, 40, true, false },
    { "Pr", 59, 141, 41, true, false },
    { "Nd", 60, 144, 42, true, false },
    { "Pm", 61, 146, 43, true, false },
    { "Sm", 62, 150, 44, true, false },
    { "Eu", 63, 151, 45, true, false },
    { "Gd", 64, 157, 46, true, false },
    { "Tb", 65, 158, 47, true, false },
    { "Dy", 66, 162, 48, true, false },
    { "Ho", 67, 164, 49, true, false },
    { "Er", 68, 167, 50, true, false },
    { "Tm", 69, 169, 51, true, false },
    { "Yb", 70, 173, 52, true, false },
    { "Lu", 71, 175, 53, true, false },
    { "Hf", 72, 178, 54, true, false },
    { "Ta", 73, 180, 55, true, false },
    { "W", 74, 184, 56, true, false },
    { "Re", 75, 186, 57, true, false },
    { "Os", 76, 190, 58, true, false },
    { "Ir", 77, 192, 59, true, false },
    { "Pt", 78, 195, 60, true, false },
    { "Au", 79, 197, 61, true, false },
    { "Hg", 80, 200, 62, true, false },
    { "Tl", 81, 204, 63, true, false },
    { "Pb", 82, 207, 64, true, false },
    { "Bi", 83, 209, 65, true, false },
    { "Po", 84, 209, 66, true, false },
    { "At", 85, 210, 67, true, false },
    { "Rn", 86, 222, 68, true, false },
    { "Fr", 87, 223, 69, true, false },
    { "Ra", 88, 225, 70, true, false },
    { "Ac", 89, 227, 71, true, false },
    { "Th", 90, 232, 72, true, false },
    { "Pa", 91, 231, 73, true, false },
    { "U", 92, 238, 74, true, false },
    { "Np", 93, 237, 75, true, false },
    { "Pu", 94, 244, 76, true, false },
    { "Am", 95, 243, 77, true, false },
    { "Cm", 96, 247, 78, true, false },
    { "Bk", 97, 247, 79, true, false },
    { "Cf", 98, 251, 80, true, false },
    { "Es", 99, 252, 81, true, false },
    { "Fm", 100, 257, 82, true, false }
};

bool is_metal(Element e) {
    return e.is_metal;
}

bool is_nonmetal(Element e) {
    return e.is_nonmetal;
}

int main() {
    int num_elements;
    printf("How many elements would you like to quiz on?\n");
    scanf("%d", &num_elements);
    
    if (num_elements > NUM_ELEMENTS) {
        printf("Too many elements!\n");
        return 1;
    }
    
    int num_correct = 0;
    int num_incorrect = 0;
    
    printf("Quiz: Which element is a metal?\n");
    for (int i = 0; i < num_elements; i++) {
        Element e = elements[i];
        printf("%s\n", e.symbol);
        if (is_metal(e)) {
            printf("%s is a metal.\n", e.symbol);
            num_correct++;
        } else {
            printf("%s is not a metal.\n", e.symbol);
            num_incorrect++;
        }
    }
    
    printf("Quiz: Which element is a nonmetal?\n");
    for (int i = 0; i < num_elements; i++) {
        Element e = elements[i];
        printf("%s\n", e.symbol);
        if (is_nonmetal(e)) {
            printf("%s is a nonmetal.\n", e.symbol);
            num_correct++;
        } else {
            printf("%s is not a nonmetal.\n", e.symbol);
            num_incorrect++;
        }
    }
    
    printf("You got %d correct and %d incorrect.\n", num_correct, num_incorrect);
    
    return 0;
}