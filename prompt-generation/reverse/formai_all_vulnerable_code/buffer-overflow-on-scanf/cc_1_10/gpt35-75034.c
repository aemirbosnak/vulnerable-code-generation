//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function checks if the element symbol entered by the user is correct
int checkAnswer(char element[3], char correctSymbol[3]){
    if(strcmp(element, correctSymbol) == 0){
        printf("Congratulations! You have solved this mystery...\n");
        return 1;
    }
    else {
        printf("Unfortunately, that is not the correct answer. Try again!\n");
        return 0;
    }
}

// This function will display the question and take the user's answer as input
int askQuestion(char *question, char *correctSymbol){
    char userAnswer[3];
    printf("%s?: ", question);
    scanf("%s", userAnswer);
    return checkAnswer(userAnswer, correctSymbol);
}

int main()
{
    printf("Welcome to the C Periodic Table Quiz, my dear Watson...\n");

    int score = 0;
    score += askQuestion("What is the symbol for Hydrogen", "H");
    score += askQuestion("What is the symbol for Carbon", "C");
    score += askQuestion("What is the symbol for Oxygen", "O");
    score += askQuestion("What is the symbol for Sodium", "Na");
    score += askQuestion("What is the symbol for Iron", "Fe");
    score += askQuestion("What is the symbol for Calcium", "Ca");
    score += askQuestion("What is the symbol for Gold", "Au");
    score += askQuestion("What is the symbol for Mercury", "Hg");
    score += askQuestion("What is the symbol for Lead", "Pb");
    score += askQuestion("What is the symbol for Uranium", "U");

    if(score >= 8){
        printf("\nWell done! You have solved the mystery and earned the title of a chemistry expert!\n");
    } else if(score >= 5){
        printf("\nNot bad, but you still have room for improvement...\n");
    } else {
        printf("\nOh dear, it seems like you need to brush up on your chemistry knowledge...\n");
    }

    return 0;
}