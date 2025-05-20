//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for generating random numbers

int main()
{
    char elements[118][3] = {"H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne", "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca", "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    char symbols[118][3] = {"H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne", "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca", "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int atomic_numbers[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118};
    char categories[118][15] = {"Nonmetal", "Noble gas", "Alkali metal", "Alkaline earth metal", "Metalloid", "Nonmetal", "Nonmetal", "Nonmetal", "Halogen", "Noble gas", "Alkali metal", "Alkaline earth metal", "Metal", "Metalloid", "Nonmetal", "Nonmetal", "Nonmetal", "Noble gas", "Alkali metal", "Alkaline earth metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Post-transition metal", "Metalloid", "Nonmetal", "Nonmetal", "Halogen", "Noble gas", "Alkali metal", "Alkaline earth metal", "Lanthanide", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Post-transition metal", "Post-transition metal", "Metalloid", "Nonmetal", "Halogen", "Noble gas", "Alkali metal", "Alkaline earth metal", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Transition metal", "Post-transition metal", "Metalloid", "Post-transition metal", "Post-transition metal", "Metalloid", "Halogen", "Noble gas", "Alkali metal", "Alkaline earth metal", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide", "Transactinide"};
    int num_questions = 10; // number of questions in the quiz
    int correct_answers = 0; // number of correct answers
    int user_answer; // user's input
    int question_number; // random number used to select a question
    int i, j;
    srand(time(NULL)); // seed the random number generator
 
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n\n", num_questions);
    
    // loop through questions
    for(i = 1; i <= num_questions; i++)
    {
        // randomly select a question
        question_number = rand() % 118;
        printf("Question #%d: What is the symbol for element number %d?\n", i, atomic_numbers[question_number]);
        printf("1. %s     2. %s     3. %s     4. %s\n", symbols[rand() % 118], symbols[rand() % 118], symbols[rand() % 118], symbols[question_number]);
        printf("Enter your answer (1-4): ");
        scanf("%d", &user_answer);
        if(user_answer == 4)
        {
            printf("Correct!\n\n");
            correct_answers++;
        }
        else
        {
            printf("Incorrect. The correct answer is %s.\n\n", symbols[question_number]);
        }
    }
    
    // display results
    printf("Results: You answered %d out of %d questions correctly.\n", correct_answers, num_questions);
    printf("Here is a list of the categories for each element:\n\n");
    for(j = 0; j < 118; j++)
    {
        printf("%2d. %-2s: %s\n", atomic_numbers[j], elements[j], categories[j]);
    }
    
    return 0;
}