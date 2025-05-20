//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <string.h>

//function to display the periodic table
void display_table(){
    printf("\n");
    printf("================================ PERIODIC TABLE ==================================\n");
    printf("===================================================================================\n");
    printf("||  H |                                                                 |  He ||\n");
    printf("||  1 |                                                                 |  2  ||\n");
    printf("||----+-----                                                             +-----||\n");
    printf("||Li  |  Be |                                                             |  B  ||\n");
    printf("|| 3  |  4  |                                                             |  5  ||\n");
    printf("||----+---- |                                                            |-----||\n");
    printf("||  C |  N  |                                                             |  O  ||\n");
    printf("|| 6  |  7  |                                                             |  8  ||\n");
    printf("||----+---- |----+---+---+---+------+------+------+------+------+-----+-----||\n");
    printf("||  F | Ne | Na | Mg | Al | Si | P  |  S | Cl | Ar | K  | Ca | Sc | Ti | V  ||\n");
    printf("|| 9  | 10 |  11|  12|  13|  14| 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 ||\n");
    printf("||----+----|----+---+---+---+------+------+------+------+------+-----+-----||\n");
    printf("|| Cr| Mn | Fe | Co | Ni | Cu | Zn | Ga | Ge | As | Se | Br | Kr | Rb | Sr ||\n");
    printf("|| 24| 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 ||\n");
    printf("||----+----|----+---+---+---+------+------+------+------+------+-----+-----||\n");
    printf("|| Y |  Zr| Nb | Mo|  Tc| Ru | Rh | Pd | Ag | Cd | In | Sn | Sb | Te |  I   ||\n");
    printf("|| 39|  40| 41 | 42|  43| 44 | 45 | 46 | 47 | 48 | 49 | 50 | 51 | 52 | 53 ||\n");
    printf("||----+----|----+---+---+---+------+------+------+------+------+-----+-----||\n");
    printf("|| Xe| Cs | Ba | La| Ce | Pr | Nd | Pm | Sm | Eu | Gd | Tb | Dy | Ho | Er ||\n");
    printf("|| 54| 55 | 56 | 57| 58 | 59 | 60 | 61 | 62 | 63 | 64 | 65 | 66 | 67 | 68 ||\n");
    printf("||----+----|----+---+---+---+------+------+------+------+------+-----+-----||\n");
    printf("|| Tm| Yb | Lu | Hf| Ta | W  | Re | Os | Ir | Pt | Au | Hg | Tl | Pb | Bi ||\n");
    printf("|| 69| 70 | 71 | 72| 73 | 74 | 75 | 76 | 77 | 78 | 79 | 80 | 81 | 82 | 83 ||\n");
    printf("||----+----|----+---+---+---+------+------+------+------+------+-----+-----||\n");
    printf("|| Po| At | Rn | Fr| Ra | Ac | Th | Pa | U  | Np | Pu | Am | Cm | Bk | Cf ||\n");
    printf("|| 84| 85 | 86 | 87| 88 | 89 | 90 | 91 | 92 | 93 | 94 | 95 | 96 | 97 | 98 ||\n");
    printf("||----+----|----+---+---+---+------+------+------+------+------+-----+-----||\n");
    printf("|| Es| Fm | Md | No| Lr |                                                                ||\n");
    printf("|| 99|100|101|102|103|                                                                ||\n");
    printf("===================================================================================\n");
    printf("\n");
}

int main()
{
    //call function to display periodic table
    display_table();

    //array of questions
    char *questions[] = {"What is the symbol for sodium?", "How many electrons are in a neutral oxygen atom?",
                        "What is the atomic number of neon?", "What is the melting point of gold?",
                        "What is the heaviest element on the periodic table?",
                        "What is the chemical formula for table salt?"};

    //array of answers
    char *answers[] = {"Na", "8", "10", "1,064°C", "Oganesson", "NaCl"};

    //variable to keep track of score
    int score = 0;

    //loop through all the questions and accept user input
    for(int i = 0; i < 6; i++){
        printf("Question %d: %s\n", i+1, questions[i]);
        char user_answer[10];
        printf("Enter your answer: ");
        scanf("%s", user_answer);

        //check if user answer matches actual answer
        if(strcmp(user_answer, answers[i])==0){
            printf("Correct answer!\n");
            score++;
        }
        else{
            printf("Incorrect answer! The correct answer was %s.\n", answers[i]);
        }
    }

    //display final score
    printf("\nYour score is %d out of 6.\n", score);

    return 0;
}