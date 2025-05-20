//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int count = 0;
    int guess, num;
    char choice;

    printf("-------------------------------------------\n");
    printf("          THE GUESSING GAME\n");
    printf("-------------------------------------------\n");
    printf("\n");

    srand(time(NULL)); // randomly seeds the generator
    num = rand() % 50 + 1; // picks random number between 1-50

    printf("Guess a number between 1 and 50: ");
    scanf("%d", &guess);
    count++;

    // while loop that runs until user guesses correct number
    while(guess != num){
        if(guess < num){
            printf("Too low! Try a higher number: ");
            scanf("%d", &guess);
            count++;
        }
        else{
            printf("Too high! Try a lower number: ");
            scanf("%d", &guess);
            count++;
        }
    }

    printf("\n");
    printf("Congratulations! You guessed the number %d in %d tries.\n", num, count);
    printf("\n");
    printf("Do you want to play again? (Y/N)\n");
    scanf(" %c", &choice);

    // while loop that runs until user decides to stop playing
    while (choice == 'Y' || choice == 'y'){
        srand(time(NULL)); // randomly seeds the generator
        num = rand() % 50 + 1; // picks random number between 1-50
        count = 0;

        printf("\n");
        printf("Guess a number between 1 and 50: ");
        scanf("%d", &guess);
        count++;

        // while loop that runs until user guesses correct number
        while(guess != num){
            if(guess < num){
                printf("Too low! Try a higher number: ");
                scanf("%d", &guess);
                count++;
            }
            else{
                printf("Too high! Try a lower number: ");
                scanf("%d", &guess);
                count++;
            }
        }

        printf("\n");
        printf("Congratulations! You guessed the number %d in %d tries.\n", num, count);
        printf("\n");
        printf("Do you want to play again? (Y/N)\n");
        scanf(" %c", &choice);
    }

    printf("\n");
    printf("Thanks for playing! Goodbye.\n");

    return 0;
}