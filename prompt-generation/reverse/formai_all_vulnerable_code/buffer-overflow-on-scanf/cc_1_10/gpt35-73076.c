//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_QUESTIONS 10 

int main() {

    //Seed random number generator
    srand(time(NULL));
    
    //Initialize variables
    char elements[] = {'H','He','Li','Be','B','C','N','O','F','Ne',
                       'Na','Mg','Al','Si','P','S','Cl','Ar',
                       'K','Ca','Sc','Ti','V','Cr','Mn','Fe','Co','Ni','Cu','Zn','Ga','Ge','As',
                       'Se','Br','Kr','Rb','Sr','Y','Zr','Nb','Mo','Tc','Ru','Rh','Pd','Ag','Cd',
                       'In','Sn','Sb','Te','I','Xe'};
    char symbols[]  = {'Hy','He','Li','Be','B','C','N','O','F','Ne','Na',
                       'Mg','Al','Si','P','S','Cl','Ar','K','Ca','Sc','Ti','V','Cr','Mn','Fe',
                       'Co','Ni','Cu','Zn','Ga','Ge','As','Se','Br','Kr','Rb','Sr','Y',
                       'Zr','Nb','Mo','Tc','Ru','Rh','Pd','Ag','Cd','In',' Sn','Sb','Te','I','Xe'};
    int correctAnswers = 0;
    int questionNumber = 0;
    char answer;
    
    //Loop through questions
    while(questionNumber < MAX_QUESTIONS) {
        
        //Select random element
        int randomIndex = rand() % 54;
        char element = elements[randomIndex];
        char symbol = symbols[randomIndex];
        
        //Print question
        printf("What is the symbol for %s?\n", element);
        
        //Read answer
        scanf(" %c", &answer);
        
        //Check answer
        if(answer == symbol) {
            printf("Correct!\n");
            correctAnswers++;
        }
        else {
            printf("Incorrect. The correct answer was %c.\n", symbol);
        }
        
        //Increment question number
        questionNumber++;
    }
    
    //Print final score
    printf("Quiz complete. You got %d out of %d questions correct.\n", correctAnswers, MAX_QUESTIONS);
    
    return 0;
}