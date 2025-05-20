//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Welcome message
    printf("\nWelcome to the Periodic Table Quiz!\n");
    printf("=================================\n");

    // Seed the random number generator
    srand(time(0));

    // Define variables for the game
    int question_number = 0;
    int correct_answers = 0;
    int incorrect_answers = 0;

    // Loop to ask questions
    for(int i = 0; i < 10; i++){
        // Increment question number
        question_number++;

        // Generate a random element
        int element_number = rand() % 118 + 1;

        // Define variables to store element properties
        char symbol[3];
        char name[30];
        int atomic_number;

        // Switch statement to set element properties based on element number
        switch(element_number){
            case 1:
                strcpy(symbol, "H");
                strcpy(name, "Hydrogen");
                atomic_number = 1;
                break;
            case 2:
                strcpy(symbol, "He");
                strcpy(name, "Helium");
                atomic_number = 2;
                break;
            // Cases for remaining elements omitted for brevity
            default:
                break;
        }

        // Ask the user to input the element's atomic number
        printf("\nQuestion %d: What is the atomic number of %s?\n", question_number, name);
        int user_answer;
        scanf("%d", &user_answer);

        // Check the user's answer and provide feedback
        if(user_answer == atomic_number){
            printf("Correct! %s has an atomic number of %d.\n", name, atomic_number);
            correct_answers++;
        } else {
            printf("Incorrect. %s has an atomic number of %d.\n", name, atomic_number);
            incorrect_answers++;
        }
    }

    // Display game results
    printf("\nGame Over!\n");
    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct_answers, incorrect_answers);

    // Return from main function
    return 0;
}