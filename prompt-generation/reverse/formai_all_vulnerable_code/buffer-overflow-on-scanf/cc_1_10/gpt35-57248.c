//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char symbol[118][3] = { // Symbol array with 118 elements
        "H ","He","Li","Be","B ","C ","N ","O ","F ","Ne",
        "Na","Mg","Al","Si","P ","S ","Cl","Ar","K ","Ca",
        "Sc","Ti","V ","Cr","Mn","Fe","Co","Ni","Cu","Zn",
        "Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y ","Zr",
        "Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn",
        "Sb","Te","I ","Xe","Cs","Ba","La","Ce","Pr","Nd",
        "Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb",
        "Lu","Hf","Ta","W ","Re","Os","Ir","Pt","Au","Hg",
        "Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th",
        "Pa","U ","Np","Pu","Am","Cm","Bk","Cf","Es","Fm",
        "Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds",
        "Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"
    };
    int atomicNumber[118] = { // Atomic number array with 118 elements
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 
        91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 
        101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 
        111, 112, 113, 114, 115, 116, 117, 118
    };

    int score = 0; // Player's score
    int count = 0; // Number of questions asked
    int answered[118] = {0}; // Array to keep track of answered questions
    srand(time(0)); // Seed the random number generator with current time

    printf("\nWelcome to the Happy Periodic Table Quiz!\n");
    printf("Answer 10 questions correctly and you can win a prize!!!\n\n");

    while(count < 10) {
        int q = rand() % 118; // Generate random number between 0 and 117
        
        if(answered[q] == 0) { // If question has not been answered yet
            printf("Question %d.\n", count + 1);
            printf("What is the symbol for element with atomic number %d?\n", atomicNumber[q]);
            printf("Your answer: ");
            
            char answer[3]; // Player's answer
            scanf("%s", answer);
            
            if(answer[0] == symbol[q][0] && answer[1] == symbol[q][1]) { // If answer is correct
                printf("Correct!!!\n\n");
                score++;
                answered[q] = 1;
                count++;
            } else { // If answer is incorrect
                printf("Incorrect. The correct answer is %s.\n\n", symbol[q]);
            }
        }
    }

    printf("\nYou answered 10 questions correctly!\n");
    printf("Your score: %d\n", score);

    if(score == 10) { // If player wins prize
        printf("Congratulations!!! You won the grand prize!!!\n");
    } else { // If player does not win prize
        printf("Better luck next time!\n");
    }

    return 0;
}