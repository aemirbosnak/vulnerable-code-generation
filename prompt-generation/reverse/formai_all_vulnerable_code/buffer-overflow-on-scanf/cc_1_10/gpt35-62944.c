//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0)); //seeding random number generator with time function

    char elements[118][3] = {
        "H","He","Li","Be","B","C","N","O","F","Ne",
        "Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
        "Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn",
        "Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr",
        "Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn",
        "Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd",
        "Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb",
        "Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg",
        "Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th",
        "Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm",
        "Md","No","Lr"
    }; //114 unique elements

    int questions = 10; //number of questions in quiz
    int score = 0; //initial score
    char answer[3]; //user's input for answer
    int used[118] = {0}; //array to keep track of used elements

    printf("Welcome to the C Periodic Table Quiz!\n\n");

    for(int i=0; i<questions; i++){
        int q_element = rand()%118; //generate random number between 0 and 117
        while(used[q_element] == 1){ //checking if element has already been used
            q_element = rand()%118;
        }
        used[q_element] = 1; //marking element as used
        printf("What is the symbol for element number %d?\n", q_element+1);
        scanf("%s", answer);
        if(strcmp(answer, elements[q_element]) == 0){ //checking user's answer
            printf("Correct!\n\n");
            score++;
        }
        else{
            printf("Sorry, the correct answer is %s.\n\n", elements[q_element]);
        }
    }

    printf("You scored %d out of %d.\n", score, questions);

    return 0;
}