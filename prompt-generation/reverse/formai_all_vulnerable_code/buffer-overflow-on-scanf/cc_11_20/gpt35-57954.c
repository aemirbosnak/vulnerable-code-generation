//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int MAX_QUESTIONS = 10; // maximum number of questions in the quiz
    const int MAX_OPTIONS = 4; // maximum number of options for each question 
    const char ELEMENTS[118][3] = {"H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne", "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca", 
                                  "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr", 
                                  "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", 
                                  "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg", 
                                  "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", 
                                  "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"}; // array of all the elements along with their symbols
    
    char name[50]; // to store name of the participant
    int score = 0; // initial score of the participant
    int i, j, k, randomNum, answer, isDuplicate; // loop variables and other variables
    int indices[MAX_QUESTIONS]; // array to store the indices of randomly selected elements for each question
    int options[MAX_OPTIONS]; // array to store the options for each question
    srand(time(0)); // set seed for random number generator
    
    // welcome message and getting the name of the participant
    printf("Hello! Welcome to the C Periodic Table Quiz.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! Let's get started with the quiz.\n\n", name);
    
    // loop through each question
    for (i = 0; i < MAX_QUESTIONS; i++) {
        // select a random element and its index for the question
        do {
            isDuplicate = 0; // flag to check if the index has already been used in this quiz
            randomNum = rand() % 118; // generate a random number between 0 and 117
            for (j = 0; j < i; j++) {
                if (indices[j] == randomNum) { // if the index has already been used, set isDuplicate flag to 1 and break the loop
                    isDuplicate = 1;
                    break;
                }
            }
        } while (isDuplicate == 1); // loop until a new index is selected
        
        indices[i] = randomNum; // store the selected index to the indices array
        
        printf("Question %d: What is the symbol for element with atomic number %d?\n", i+1, randomNum+1);
        
        // set the correct answer option
        answer = rand() % MAX_OPTIONS;
        options[answer] = randomNum;
        
        // generate other options randomly
        for (j = 0, k = 0; j < MAX_OPTIONS; j++) {
            if (j == answer) continue;
            do {
                isDuplicate = 0; // flag to check if the option has already been used
                randomNum = rand() % 118;
                for (k = 0; k < MAX_OPTIONS; k++) {
                    if (options[k] == randomNum) { // if the option has already been used, set isDuplicate flag to 1 and break the loop
                        isDuplicate = 1;
                        break;
                    }
                }
            } while (isDuplicate == 1); // loop until a new option is generated
            options[j] = randomNum;
        }
        
        // print the options for the question
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, ELEMENTS[options[j]]);
        }
        
        // get the participant's answer
        printf("Your answer: ");
        scanf("%d", &answer);
        
        // check if the answer is correct and update the score
        if (options[answer-1] == indices[i]) {
            score++;
            printf("Correct! %s is the symbol for element with atomic number %d.\n", ELEMENTS[indices[i]], indices[i]+1);
        } else {
            printf("Incorrect. The correct answer is %s.\n", ELEMENTS[indices[i]]);
        }
        
        // print current score
        printf("Your current score is %d/%d.\n\n", score, i+1);
    }
    
    // print final score and goodbye message
    printf("Congratulations %s! You have completed the quiz.\n", name);
    printf("Your final score is %d/%d.\n", score, MAX_QUESTIONS);
    printf("Thank you for playing the C Periodic Table Quiz.\n");
    return 0;
}