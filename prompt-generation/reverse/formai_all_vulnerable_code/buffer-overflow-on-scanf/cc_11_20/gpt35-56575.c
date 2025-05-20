//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int usr_input, comp_num, score=0, count=0;
    char option;

    srand(time(NULL));

    while(1){
        printf("--------------------------------------------------------\n");
        printf("Welcome to the Number Guessing game!\n\n");

        printf("Choose your difficulty level:\n");
        printf("1. Easy (1-10)\n2. Medium (1-50)\n3. Hard (1-100)\n");

        scanf("%d", &usr_input);

        switch (usr_input){
            case 1:
                comp_num = rand() % 10 + 1;
                break;
            case 2:
                comp_num = rand() % 50 + 1;
                break;
            case 3:
                comp_num = rand() % 100 + 1;
                break;
            default:
                printf("Invalid input! Try again.\n");
                continue;
        }

        printf("Great! I have a number in mind. You have to guess it within 5 attempts.\n");

        while(count<5){
            printf("Enter your guess:\n");
            scanf("%d", &usr_input);

            if(usr_input > comp_num){
                printf("Your guess is too high. Try again.\n");
            }
            else if(usr_input < comp_num){
                printf("Your guess is too low. Try again.\n");
            }
            else{
                printf("Congratulations! You guessed the correct number in %d attempt(s).\n", count);
                score++;
                break;
            }

            count++;
        }

        if(count>=5){
            printf("Sorry, you couldn't guess the number. The number was %d.\n", comp_num);
        }

        count = 0;

        printf("Your score: %d.\n", score);
        printf("Do you want to play again? (y/n)\n");

        scanf("%s", &option);

        if(option == 'n' || option == 'N'){
            printf("Thank you for playing! Your final score is: %d.\n", score);
            break;
        }

        printf("\n");
    }

    return 0;
}