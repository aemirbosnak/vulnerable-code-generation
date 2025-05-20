//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char elements[][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Ni", "Co", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int num_elements = 118;
    int num_questions, score, i, j, answer;
    char continue_quiz;

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("What is your name?\n");
    char name[20];
    scanf("%s", name);
    printf("Hi %s, let's get started!\n", name);

    do {
        printf("How many questions would you like to answer?\n");
        scanf("%d", &num_questions);

        score = 0;

        printf("Here we go!\n");

        srand(time(0)); //random number generator seed

        for (i = 0; i < num_questions; i++) {
            int valid_options[4] = {0}; //array to store which options are valid, in case of repeated options
            int correct_option = rand() % 4; //randomly choose which option is correct
            int atomic_num = rand() % num_elements; //randomly choose an element
            printf("%d. What is the symbol of the element with atomic number %d?\n", i+1, atomic_num+1);
            
            valid_options[correct_option] = 1;
            printf("%d. %s\n", correct_option+1, elements[atomic_num]);

            for (j = 0; j < 4; j++) {
                if (j != correct_option) {
                    int option = rand() % num_elements;
                    if (option == atomic_num || valid_options[0] == option || valid_options[1] == option || valid_options[2] == option) {
                        j--;
                        continue;
                    }
                    valid_options[j] = option;
                    printf("%d. %s\n", j+1, elements[option]);
                }
            }

            printf("Enter your answer (1-4): ");
            scanf("%d", &answer);

            if (answer == correct_option + 1) {
                printf("Correct!\n");
                score++;
            }
            else {
                printf("Incorrect. The correct answer is %d. %s\n", correct_option+1, elements[atomic_num]);
            }
        }

        printf("You answered %d out of %d questions correctly.\n", score, num_questions);

        printf("Would you like to play again? (y/n): ");
        scanf("%s", &continue_quiz);

    } while (continue_quiz == 'y');

    printf("Thanks for playing the C Periodic Table Quiz, %s!\n", name);

    return 0;
}