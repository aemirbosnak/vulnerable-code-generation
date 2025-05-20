//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, ans, choice, score = 0;
    int max = 118, min = 1;
    srand(time(NULL)); // seed for random number generator
    for(i=1; i<=5; i++) // loop for each question
    {
        printf("\nQuestion %d:\n", i);
        int atomic_num = rand() % (max - min + 1) + min; // generate a random atomic number
        printf("What is the symbol of element with atomic number %d ?\n", atomic_num);
        
        // array of element symbols
        char* elements[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg",
                            "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr",
                            "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
                            "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd",
                            "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La",
                            "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er",
                            "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
                            "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
                            "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
                            "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn",
                            "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
        
        // print options for the question
        printf("1. %s\n2. %s\n3. %s\n4. %s\n", elements[atomic_num-1], elements[atomic_num], elements[atomic_num+1], elements[atomic_num+2]);
        printf("Enter your answer (1-4): ");
        scanf("%d", &choice);
        
        // check if answer is correct and update score
        if(choice == 1 && atomic_num!=1)
        {
            ans = atomic_num-1;
        }
        else if(choice == 2)
        {
            ans = atomic_num;
        }
        else if(choice == 3 && atomic_num!=max)
        {
            ans = atomic_num+1;
        }
        else if(choice == 4 && atomic_num<max-1)
        {
            ans = atomic_num+2;
        }
        else
        {
            ans = 0;
        }
        
        // print correct answer and update score
        if(ans!=0 && ans==atomic_num)
        {
            printf("\nCorrect!\n");
            score++;
        }
        else
        {
            printf("\nIncorrect. The correct answer is %s\n", elements[atomic_num-1]);
        }
    }
    printf("\nQuiz ended. Your score is %d out of 5.\n", score);
    return 0;
}