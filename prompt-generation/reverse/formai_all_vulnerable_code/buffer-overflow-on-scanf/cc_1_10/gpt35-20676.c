//FormAI DATASET v1.0 Category: Dice Roller ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int choice, dice1, dice2, total;
    int i;

    srand(time(NULL));

    printf("************************\n");
    printf("** HAPPY DICE ROLLER **\n");
    printf("************************\n");

    do{
        printf("\n\n***MENU***\n");
        printf("1.Roll Dice\n");
        printf("2.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nRolling the dice...\n");
                printf("The dice have been rolled:\n");

                dice1 = rand() % 6 + 1;
                dice2 = rand() % 6 + 1;

                printf("Dice 1: %d\n", dice1);
                printf("Dice 2: %d\n", dice2);

                total = dice1 + dice2;

                printf("Total: %d\n", total);

                if(total == 7 || total == 11){
                    printf("\nYOU WIN! Congratulations :)\n");
                }else if(total == 2 || total == 3 || total == 12){
                    printf("\nYOU LOSE! Oh no :(\n");
                }else{
                    printf("Keep playing!\n");
                }

                break;
            case 2:
                printf("\nThanks for playing! Bye :) \n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }

    }while(choice != 2);

    return 0;
}