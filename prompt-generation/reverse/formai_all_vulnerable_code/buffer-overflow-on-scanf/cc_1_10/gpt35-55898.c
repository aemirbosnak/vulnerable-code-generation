//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));  //seed for random number generator
    int correctCount = 0, incorrectCount = 0;

    printf("Welcome to the Happy Periodic Table Quiz!\n");
    printf("Answer the following questions correctly to make the world a happier place!\n\n");

    //Array of elements and their symbols
    char* elements[] = {"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Fluorine","Neon",
    "Sodium","Magnesium","Aluminum","Silicon","Phosphorus","Sulfur","Chlorine","Argon","Potassium","Calcium"};
    char* symbols[] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca"};

    for(int i=1; i<=10; i++) {

        int randomIndex = rand() % 20;

        printf("Question %d: What is the symbol for %s?\n", i, elements[randomIndex]);
        char answer[3];  //array to hold user's answer
        scanf("%s", answer);

        //convert user's answer to uppercase for comparison
        for(int j=0; j<3; j++) {
            answer[j] = toupper(answer[j]);
        }

        if(strcmp(answer, symbols[randomIndex]) == 0) {  //compare user's answer to correct answer
            printf("Correct!\n\n");
            correctCount++;
        } else {
            printf("Incorrect.\n");
            printf("The symbol for %s is %s.\n\n", elements[randomIndex], symbols[randomIndex]);
            incorrectCount++;
        }

        //after 5 questions, ask if the user wants to continue or quit
        if(i == 5) {
            printf("You've answered %d questions correctly and %d questions incorrectly.\n", correctCount, incorrectCount);
            printf("Do you want to continue? (y/n)\n");
            char response;
            scanf(" %c", &response);  //inline whitespace ignores previous newline character
            if(response == 'n') {
                printf("Thanks for playing the Happy Periodic Table Quiz!\n");
                return 0;  //end program if user wants to quit
            }
        }
    }

    //final results after all 10 questions
    printf("You've answered %d questions correctly and %d questions incorrectly.\n", correctCount, incorrectCount);
    printf("Thanks for playing the Happy Periodic Table Quiz! Let's make the world a happier place!\n");

    return 0;  //end program
}