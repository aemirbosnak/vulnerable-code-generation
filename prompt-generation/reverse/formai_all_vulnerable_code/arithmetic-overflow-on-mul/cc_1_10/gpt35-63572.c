//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));
    int choice, chance = 5, clear = 0, money = 0;
    int balance = 1000, bet = 0;
    
    printf("Welcome to the Statistical Adventure Game!\n");
    printf("You have a starting balance of $1000. Good luck!\n\n");
    
    while(clear == 0){
    
        printf("What would you like to do?\n");
        printf("1. Play a game of chance.\n");
        printf("2. Check your balance.\n");
        printf("3. Quit.\n");
        scanf("%d", &choice);
        
        switch(choice){
            
            case 1:
                printf("How much would you like to bet?\n");
                scanf("%d", &bet);
                if(bet > balance){
                    printf("You do not have enough balance to make this bet.\n");
                    break;
                }
                printf("You have chosen to bet $%d.\n", bet);
                printf("You have %d chances to win the game.\n", chance);
                while(chance > 0){
                    printf("Guess a number between 1 and 10.\n");
                    int guess = rand()%10;
                    int answer;
                    scanf("%d", &answer);
                    if(answer == guess){
                        money = bet*2;
                        printf("You have won $%d!\n", money);
                        balance += money;
                        chance = 5;
                        break;
                    }
                    else{
                        printf("Sorry, that is not correct. You have %d chances left.\n", chance-1);
                        chance--;
                    }
                }
                if(chance == 0){
                    printf("You have lost the game. Try again next time.\n");
                    balance -= bet;
                    chance = 5;
                    break;
                }
                break;
            
            case 2:
                printf("Your current balance is $%d.\n", balance);
                break;
            
            case 3:
                printf("Thank you for playing the Statistical Adventure Game.\n");
                printf("Your final balance is $%d. Come back soon!\n", balance);
                clear = 1;
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        if(balance == 0){
            printf("You have run out of money. Game over.\n");
            clear = 1;
        }
    }

    return 0;
}