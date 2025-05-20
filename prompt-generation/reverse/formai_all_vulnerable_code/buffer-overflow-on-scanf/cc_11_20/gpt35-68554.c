//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int elements[118] = {0}; // Array to keep track of answered questions
    int score = 0; // Initialize score
    char answer; // Initialize answer variable
    srand(time(0)); // Seed random number generator with current time

    printf("Welcome to the C Periodic Table Quiz! Let's test your knowledge.\n");
    printf("Answer the questions by entering the correct element symbol.\n");
    printf("Type \'q\' at any time to quit the quiz.\n");

    while(1){ // Loop until player quits
        int element = rand() % 118 + 1; // Generate random element number

        if(elements[element] == 1){ // Check if element has been asked before
            continue;
        }
        else{
            elements[element] = 1; // Mark element as asked
        }

        // Switch statement to ask questions
        switch(element){
            case 1:
                printf("What is the symbol for Hydrogen? ");
                scanf(" %c", &answer);
                if(answer == 'H'){
                    printf("Correct!\n");
                    score++;
                }
                else if(answer == 'q'){
                    printf("Goodbye! Your final score is %d.\n", score);
                    return 0;
                }
                else{
                    printf("Incorrect, the correct answer is H.\n");
                }
                break;
            case 2:
                printf("What is the symbol for Helium? ");
                scanf(" %c", &answer);
                if(answer == 'He'){
                    printf("Correct!\n");
                    score++;
                }
                else if(answer == 'q'){
                    printf("Goodbye! Your final score is %d.\n", score);
                    return 0;
                }
                else{
                    printf("Incorrect, the correct answer is He.\n");
                }
                break;
            case 3:
                printf("What is the symbol for Lithium? ");
                scanf(" %c", &answer);
                if(answer == 'Li'){
                    printf("Correct!\n");
                    score++;
                }
                else if(answer == 'q'){
                    printf("Goodbye! Your final score is %d.\n", score);
                    return 0;
                }
                else{
                    printf("Incorrect, the correct answer is Li.\n");
                }
                break;
            // Continue with all 118 elements
            default:
                break;
        }

        printf("Your score is %d.\n", score); // Display current score
        printf("Press enter to continue...");
        while(getchar() != '\n'); // Wait for player to press enter
        printf("\n");
    }
    return 0;
}