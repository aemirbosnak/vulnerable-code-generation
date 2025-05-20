//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number within a range
int generateRandomNumber(int min, int max)
{
    srand(time(NULL)); // set seed for random number generator
    return (rand() % (max - min + 1)) + min; // generate random number within the given range
}

int main()
{
    // Initializing and populating the Periodic Table
    char periodic_table[118][3] = {{"H"},{"He"},{"Li"},{"Be"},{"B"},{"C"},{"N"},{"O"},{"F"},{"Ne"},
                                   {"Na"},{"Mg"},{"Al"},{"Si"},{"P"},{"S"},{"Cl"},{"Ar"},{"K"},{"Ca"},
                                   {"Sc"},{"Ti"},{"V"},{"Cr"},{"Mn"},{"Fe"},{"Co"},{"Ni"},{"Cu"},{"Zn"},
                                   {"Ga"},{"Ge"},{"As"},{"Se"},{"Br"},{"Kr"},{"Rb"},{"Sr"},{"Y"},{"Zr"},
                                   {"Nb"},{"Mo"},{"Tc"},{"Ru"},{"Rh"},{"Pd"},{"Ag"},{"Cd"},{"In"},{"Sn"},
                                   {"Sb"},{"Te"},{"I"},{"Xe"},{"Cs"},{"Ba"},{"La"},{"Ce"},{"Pr"},{"Nd"},
                                   {"Pm"},{"Sm"},{"Eu"},{"Gd"},{"Tb"},{"Dy"},{"Ho"},{"Er"},{"Tm"},{"Yb"},
                                   {"Lu"},{"Hf"},{"Ta"},{"W"},{"Re"},{"Os"},{"Ir"},{"Pt"},{"Au"},{"Hg"},
                                   {"Tl"},{"Pb"},{"Bi"},{"Po"},{"At"},{"Rn"},{"Fr"},{"Ra"},{"Ac"},{"Th"},
                                   {"Pa"},{"U"},{"Np"},{"Pu"},{"Am"},{"Cm"},{"Bk"},{"Cf"},{"Es"},{"Fm"},
                                   {"Md"},{"No"},{"Lr"},{"Rf"},{"Db"},{"Sg"},{"Bh"},{"Hs"},{"Mt"},{"Ds"},
                                   {"Rg"},{"Cn"},{"Nh"},{"Fl"},{"Mc"},{"Lv"},{"Ts"},{"Og"}};
    int num_questions = 5; // setting number of questions in the quiz
    int score = 0; // initializing the score of the quiz

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions. Good luck!\n", num_questions);

    // loop to ask quiz questions
    for(int i=0; i<num_questions; i++)
    {
        int question_num = i+1;
        printf("\nQuestion %d: What is the symbol for element number %d?\n", question_num, i+1);
        char correct_answer[3] = {0}; // initializing correct answer string
        char user_answer[3] = {0}; // initializing user answer string
        sprintf(correct_answer, "%s", periodic_table[i]); // setting the correct answer
        scanf("%s", user_answer); // getting user input

        // check if the user's answer is correct
        if(strcmp(correct_answer, user_answer) == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %s.\n", correct_answer);
        }
    }

    // display quiz results
    printf("\nQuiz complete! You scored %d out of %d.\n", score, num_questions);

    return 0;
}