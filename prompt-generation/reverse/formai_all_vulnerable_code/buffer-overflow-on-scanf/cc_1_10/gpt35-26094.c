//FormAI DATASET v1.0 Category: Game ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int guess, answer, count = 0;
    char choice;

    srand(time(0));     // set seed for random number generator
    answer = rand() % 100 + 1;     // generate random number between 1 to 100
    
    // game instructions
    printf("Welcome to the Guessing Game!\n");
    printf("You have to guess a number between 1 to 100.\n");
    printf("You will be given 5 attempts to guess the correct number.\n\n");

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);

        if(guess < answer) {
            printf("The number is higher than %d.\n", guess);
        }
        else if(guess > answer) {
            printf("The number is lower than %d.\n", guess);
        }
        else {
            printf("Congratulations! You have guessed the correct number %d in %d attempts.\n", answer, count+1);

            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &choice);

            if(choice == 'y' || choice == 'Y'){
                // reset values
                answer = rand() % 100 + 1;
                count = 0;
                printf("\n\nNew game started!\n\n");
            }
            else {
                printf("\nThank you for playing.\n");
                break;
            }
        }

        count++;

        if(count == 5){
            printf("\nSorry, you have exceeded the maximum attempts.\n");
            printf("The correct number was %d.\n", answer);

            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &choice);

            if(choice == 'y' || choice == 'Y'){
                // reset values
                answer = rand() % 100 + 1;
                count = 0;
                printf("\n\nNew game started!\n\n");
            }
            else {
                printf("\nThank you for playing.\n");
                break;
            }
        }
    } while (1);

    return 0;
}