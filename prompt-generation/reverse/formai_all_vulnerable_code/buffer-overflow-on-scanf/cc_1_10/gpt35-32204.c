//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>

int main() {
    // Set up the periodic table array
    char periodic_table[118][3] = {"H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne",
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
                                   "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    // Set up the questions and answer key arrays
    char questions[10][30] = {"What element has the symbol Ag?", "What element has the symbol Na?",
                              "What element has the symbol Br?", "What element has the symbol S?",
                              "What element has the symbol Ne?", "What element has the symbol Fe?",
                              "What element has the symbol Cu?", "What element has the symbol Sn?",
                              "What element has the symbol Ca?", "What element has the symbol He?"};
    char answer_key[10] = {'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

    // Set up counters for correct and incorrect answers
    int correct = 0;
    int incorrect = 0;

    // Print welcome message and start quiz loop
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given 10 questions. Enter the letter of the answer choice.\n\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i+1, questions[i]);
        printf("   A. %s    B. %s\n", periodic_table[i*10+47], periodic_table[i*10+10]);
        printf("   C. %s    D. %s\n\n", periodic_table[i*10+78], periodic_table[i*10+16]);
        char user_answer;
        printf("Enter your answer: ");
        scanf(" %c", &user_answer);  // Note the space before %c to ignore leading whitespace
        if (user_answer == answer_key[i]) {
            printf("Correct!\n\n");
            correct++;
        } else {
            printf("Incorrect! The correct answer is %c. \n\n", answer_key[i]);
            incorrect++;
        }
    }

    // Print final results
    printf("Quiz complete! You got %d correct and %d incorrect.\n", correct, incorrect);

    return 0;
}