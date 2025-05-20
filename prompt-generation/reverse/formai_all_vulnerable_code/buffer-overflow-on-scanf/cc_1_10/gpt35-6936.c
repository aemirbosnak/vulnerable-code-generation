//FormAI DATASET v1.0 Category: Dice Roller ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int dice, i;
    char choice;

    srand(time(NULL));

    do {
        printf("Welcome to the Dice Roller! \nChoose a type of die to roll \n1. 4-sided die \n2. 6-sided die \n3. 8-sided die \n4. 10-sided die \n5. 12-sided die \n6. 20-sided die \n");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                dice = (rand() % 4) + 1;
                printf("You rolled a %d-sided die and got a %d \n", 4, dice);
                break;
            case '2':
                dice = (rand() % 6) + 1;
                printf("You rolled a %d-sided die and got a %d \n", 6, dice);
                break;
            case '3':
                dice = (rand() % 8) + 1;
                printf("You rolled an %d-sided die and got a %d \n", 8, dice);
                break;
            case '4':
                dice = (rand() % 10) + 1;
                printf("You rolled a %d-sided die and got a %d \n", 10, dice);
                break;
            case '5':
                dice = (rand() % 12) + 1;
                printf("You rolled a %d-sided die and got a %d \n", 12, dice);
                break;
            case '6':
                dice = (rand() % 20) + 1;
                printf("You rolled a %d-sided die and got a %d \n", 20, dice);
                break;
            default:
                printf("Invalid choice! Please choose a number from 1 to 6 \n");
        }

        printf("Do you want to roll another die? (y/n) \n");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("Thanks for using the Dice Roller! \n");

    return 0;
}