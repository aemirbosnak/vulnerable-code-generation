//FormAI DATASET v1.0 Category: Game ; Style: visionary
#include<stdio.h> //header file for standard input/output
#include<stdlib.h> //header file for standard library
#include<time.h> //header file for time-related functions

int main(){
    int option, guessNumber, randomNumber, attempt=0; //declaring variables
    
    srand(time(0)); //seeding random number generator with current time
    
    printf("Welcome to the Guessing Game!\n\n");
    printf("You have to guess a randomly generated number between 1 and 100 in minimum number of attempts.\n\n");

    do{
        printf("Choose the difficulty level:\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("4. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option){ //switch case for different levels
            case 1:
                printf("Easy level selected. You have 10 attempts.\n");
                randomNumber = rand() % 10 + 1; //generating random number between 1 and 10
                break;
            case 2:
                printf("Medium level selected. You have 7 attempts.\n");
                randomNumber = rand() % 50 + 1; //generating random number between 1 and 50
                break;
            case 3:
                printf("Hard level selected. You have 5 attempts.\n");
                randomNumber = rand() % 100 + 1; //generating random number between 1 and 100
                break;
            case 4:
                printf("Thank you for playing!\n");
                exit(0); //exiting program
                break;
            default:
                printf("Invalid option selected! Please try again.\n\n");
                continue;
        }

        while(attempt<10 && attempt<7 && attempt<5){ //loop for maximum attempts
            printf("\nEnter your guess (between 1 and 100): ");
            scanf("%d", &guessNumber);
            attempt++; //incrementing attempt

            if(guessNumber==randomNumber){
                printf("Congratulations! You have guessed the number in %d attempts\n\n", attempt);
                break; //breaking out of loop
            }else if(guessNumber<randomNumber){
                printf("Your guess is too low. Please try again.\n");
            }else{
                printf("Your guess is too high. Please try again.\n");
            }
        }

        if(attempt==10 || attempt==7 || attempt==5){
            printf("\nGame over! You have exhausted all attempts. The number was %d\n\n", randomNumber);
        }

        attempt = 0; //resetting attempt
    }while(1);

    return 0;
}