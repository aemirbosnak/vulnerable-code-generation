//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

// function prototypes
void generateQuestion(int *atomicNumber, int *answer);
void checkAnswer(int *playerAnswer, int *correctAnswer, int *score);


int main(){
    // seed for random number generator
    srand(time(NULL));

    // variables
    int atomicNumber, answer, playerAnswer, score = 0, continuePlaying = TRUE;
    char playAgain;

    // Welcome message
    printf("Welcome to the Periodic Table Quiz!\n");

    while(continuePlaying){
        // generate question
        generateQuestion(&atomicNumber, &answer);

        // ask the question
        printf("What is the symbol for element with atomic number %d?\n", atomicNumber);

        // take input from user
        scanf("%d", &playerAnswer);

        // check the answer
        checkAnswer(&playerAnswer, &answer, &score);

        // ask user if they want to play again
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &playAgain);

        if(playAgain == 'n' || playAgain == 'N'){
            continuePlaying = FALSE;
        }

    }

    // print final score
    printf("Your final score is %d out of 10!\n", score);

    return 0;
}


// function to generate question
void generateQuestion(int *atomicNumber, int *answer){
    // generate random atomic number between 1 and 10
    *atomicNumber = rand() % 10 + 1;

    // set answer
    switch(*atomicNumber){
        case 1:
            printf("What is the symbol for Hydrogen?\n");
            *answer = 'H';
            break;
        case 2:
            printf("What is the symbol for Helium?\n");
            *answer = 'He';
            break;
        case 3:
            printf("What is the symbol for Lithium?\n");
            *answer = 'Li';
            break;
        case 4:
            printf("What is the symbol for Beryllium?\n");
            *answer = 'Be';
            break;
        case 5:
            printf("What is the symbol for Boron?\n");
            *answer = 'B';
            break;
        case 6:
            printf("What is the symbol for Carbon?\n");
            *answer = 'C';
            break;
        case 7:
            printf("What is the symbol for Nitrogen?\n");
            *answer = 'N';
            break;
        case 8:
            printf("What is the symbol for Oxygen?\n");
            *answer = 'O';
            break;
        case 9:
            printf("What is the symbol for Fluorine?\n");
            *answer = 'F';
            break;
        case 10:
            printf("What is the symbol for Neon?\n");
            *answer = 'Ne';
            break;
        default:
            printf("Error: Invalid atomic number generated.\n");
    }

}

// function to check answer and update score
void checkAnswer(int *playerAnswer, int *correctAnswer, int *score){
    if(*playerAnswer == *correctAnswer){
        // if answer is correct, increment score
        printf("Congratulations! Your answer is correct!\n");
        (*score)++;
    }
    else{
        // if answer is incorrect, display the correct answer
        printf("Sorry, your answer is incorrect. The correct answer is %c.\n", *correctAnswer);
    }
}