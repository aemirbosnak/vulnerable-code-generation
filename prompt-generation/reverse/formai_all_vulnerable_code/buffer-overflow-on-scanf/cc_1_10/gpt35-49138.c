//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char element[3];
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Guess the symbol of the given element. Enter 'quit' to exit.\n");

    //list of elements to be guessed
    char elements[][15] = {
        "Hydrogen", "Carbon", "Oxygen", "Nitrogen", "Sodium", 
        "Chlorine", "Magnesium", "Iron", "Gold", "Zinc", 
        "Neon", "Helium", "Lithium", "Silver", "Copper"
    };

    //list of symbols of the elements
    char symbols[][3] = {
        "H", "C", "O", "N", "Na", 
        "Cl", "Mg", "Fe", "Au", "Zn", 
        "Ne", "He", "Li", "Ag", "Cu"
    };

    //loop through all the elements
    for(int i=0; i<15; i++){
        printf("%d. %s: ", i+1, elements[i]);
        scanf("%s", element);

        //convert the input element to uppercase
        for(int j=0; element[j]; j++){
            element[j] = toupper(element[j]);
        }

        //check if user wants to exit
        if(strcmp(element, "QUIT")==0){
            printf("Exiting the Quiz...\n");
            break;
        }

        //check if user guessed the correct symbol
        if(strcmp(element, symbols[i])==0){
            printf("Correct!\n");
            score++;
        }
        else{
            printf("Incorrect. The symbol of %s is %s.\n", elements[i], symbols[i]);
        }
    }

    printf("Your final score is %d out of 15. Thanks for playing!\n", score);

    return 0;
}