//FormAI DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1, player2, roll, turn = 1, total1 = 0, total2 = 0;
    char choice;
    srand(time(0)); //seed random number generator with current time
  
    printf("Welcome to the C Table Game!\n");
    printf("Player 1, roll the dice by pressing 'r'\n");
  
    while(1){
        //Player 1 turn
        if(turn % 2 == 1){
            scanf(" %c", &choice);
            if(choice == 'r'){
                roll = rand() % 6 + 1; // generate random number between 1 and 6
                printf("Player 1 rolled a %d\n", roll);
                total1 += roll;
                printf("Player 1's total score is %d\n\n", total1);
                if(total1 >= 50){
                    printf("Congratulations! Player 1 Wins!"); //Player 1 wins when score reaches 50 or more
                    break;
                }
                printf("Player 2, press 'r' to roll the dice\n");
            }
            else{
                printf("Invalid input! Press 'r' to roll the dice\n");
            }
        }
        //Player 2 turn
        else{
            scanf(" %c", &choice);
            if(choice == 'r'){
                roll = rand() % 6 + 1;
                printf("Player 2 rolled a %d\n", roll);
                total2 += roll;
                printf("Player 2's total score is %d\n\n", total2);
                if(total2 >= 50){
                    printf("Congratulations! Player 2 Wins!"); //Player 2 wins when score reaches 50 or more
                    break;
                }
                printf("Player 1, press 'r' to roll the dice\n");
            }
            else{
                printf("Invalid input! Press 'r' to roll the dice\n");
            }
        }
        turn++;
    }
  
    return 0;
}