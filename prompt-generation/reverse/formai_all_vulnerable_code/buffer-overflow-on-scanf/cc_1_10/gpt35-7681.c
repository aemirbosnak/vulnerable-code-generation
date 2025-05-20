//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between min and max (inclusive) */
int generate_random_number(int min, int max) {
    srand((unsigned) time(NULL));   // initialize the random number generator
    return rand() % (max - min + 1) + min;
}

int main() {
    char periodic_table[7][18] = {  // 2D array to store the periodic table
        {"H   He"}, {"Li  Be  B   C   N   O   F   Ne"},
        {"Na  Mg  Al  Si  P   S   Cl  Ar"}, 
        {"K   Ca  Sc  Ti  V   Cr  Mn  Fe  Co  Ni  Cu  Zn  Ga  Ge  As  Se  Br  Kr"},
        {"Rb  Sr  Y   Zr  Nb  Mo  Tc  Ru  Rh  Pd  Ag  Cd  In  Sn  Sb  Te  I   Xe"}, 
        {"Cs  Ba  La  Ce  Pr  Nd  Pm  Sm  Eu  Gd  Tb  Dy  Ho  Er  Tm  Yb  Lu  Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg  Tl  Pb  Bi  Po  At  Rn"}
    };
    char symbol[50], answer[50];    // arrays to store the user's input and the quiz answer
    int random_row, num_of_elements, score = 0, i, j;  // variables to store the randomly generated row number, number of elements in that row, user's score, and loop counters
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please enter the number of elements you want to be quizzed on (1-118): ");
    scanf("%d", &num_of_elements);
    if (num_of_elements < 1 || num_of_elements > 118) {
        printf("Invalid input. Please enter a number between 1 and 118.\n");
        return 1;
    }
    
    for (i = 1; i <= num_of_elements; i++) {
        random_row = generate_random_number(0, 6);
        num_of_elements = 0;
        for (j = 0; j < 18; j += 3) {
            if (periodic_table[random_row][j] == '\0') {
                break;
            }
            num_of_elements++;
        }
        printf("\nElement %d:\n", i);
        printf("What is the symbol of %s? ", periodic_table[random_row]);
        scanf("%s", symbol);
        for (j = 0; j < num_of_elements; j++) {
            if (periodic_table[random_row][3*j] == symbol[0]
                && periodic_table[random_row][3*j+1] == symbol[1]) {
                score++;
                printf("Correct!\n");
                break;
            }
        }
        if (j == num_of_elements) {
            printf("Incorrect. The answer was %c%c. \n", periodic_table[random_row][0], periodic_table[random_row][1]);
        }
        printf("Your current score is %d/%d.\n", score, i);   
    }
    
    printf("\nCongratulations! You finished the quiz with a score of %d/%d.\n", score, num_of_elements);
    
    return 0;
}