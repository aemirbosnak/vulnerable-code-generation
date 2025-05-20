//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandom(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// Function to print random fortune messages
void printFortune(){

    int randomNum = generateRandom(0, 8);

    switch(randomNum){
        case 0:
            printf("You will find what you are looking for in an unexpected place.\n");
            break;
        case 1:
            printf("Good news is coming your way, be ready for it.\n");
            break;
        case 2:
            printf("You will have a major life change in the near future.\n");
            break;
        case 3:
            printf("You will have great success in your career.\n");
            break;
        case 4:
            printf("Your love life will soon improve.\n");
            break;
        case 5:
            printf("You will soon go on a journey to a far-off land.\n");
            break;
        case 6:
            printf("You will be the recipient of a large sum of money.\n");
            break;
        case 7:
            printf("Your health will improve in the upcoming days.\n");
            break;
        case 8:
            printf("You will make a new friend that will be important to you.\n");
            break;
    }
}

int main(){

    // Seed the random number generator with time
    srand(time(0));

    printf("Welcome to Automated Fortune Teller! \n\n");

    char userInput;

    // loop through until user enter 'n' or 'N'
    do{
        printf("Do you want to know your fortune? (Y/N): ");
        scanf(" %c", &userInput);

        if(userInput == 'Y' || userInput == 'y'){

            printf("\n");
            printf("*****************************************\n");
            printFortune();
            printf("*****************************************\n\n");

        }else if (userInput != 'N' && userInput != 'n'){

            printf("Invalid input, please try again.\n\n");

        }

    } while(userInput != 'N' && userInput != 'n');

    printf("Thank you for using Automated Fortune Teller! Have a great day!\n");

    return 0;
}