//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    char name[20], choice;
    int health = 100, ammo = 6, food = 5;
    int day = 1, score = 0;
    
    printf("*** Welcome to Wilderness Adventure! ***\n");
    printf("What is your name, adventurer? ");
    scanf("%s", name);
    
    printf("\nHello, %s! You are on a survival adventure in the wilderness.\n", name);
    printf("You have limited supplies and must make wise decisions to stay alive.\n");
    printf("Good luck on your journey!\n\n");
    
    do{
        printf("Day %d\n", day);
        printf("Health: %d\tAmmo: %d\tFood: %d\n", health, ammo, food);
        printf("What do you want to do? (H)unt, (F)ind food, or (R)elax? ");
        scanf(" %c", &choice);
        choice = toupper(choice);
        
        switch(choice){
            case 'H':
                printf("\nYou decide to go hunting for food.\n");
                if(ammo > 0){
                    health -= 10;
                    ammo--;
                    int success = rand() % 2;
                    if(success){
                        printf("You successfully hunt a deer and gain 20 food points.\n");
                        food += 20;
                    }
                    else{
                        printf("You fail to catch any game. Better luck next time.\n");
                    }
                }
                else{
                    printf("You have no ammo to hunt with. Try finding food instead.\n");
                }
                break;
                
            case 'F':
                printf("\nYou decide to search for food.\n");
                health -= 5;
                int success = rand() % 2;
                if(success){
                    printf("You find a berry bush and gain 10 food points.\n");
                    food += 10;
                }
                else{
                    printf("You scavenge but find no food. Better luck tomorrow.\n");
                }
                break;
            
            case 'R':
                printf("\nYou decide to rest and relax.\n");
                health += 10;
                food--;
                printf("You eat one of your remaining food rations and regain some health.\n");
                break;
                
            default:
                printf("\nInvalid choice. Try again.\n");
        }
        
        if(food <= 0){
            printf("\nYou have run out of food and cannot survive any longer. Game over.\n");
            break;
        }
        
        if(health <= 0){
            printf("\nYou have died from starvation or wounds. Game over.\n");
            break;
        }
        
        printf("\nEnd of day %d. You survived another day!\n", day);
        score++;
        day++;
        
        if(day > 5){
            printf("\nYou have survived for 5 days. Congratulations, %s! You win!\n", name);
            break;
        }
        
    }while(1);
    
    printf("\nFinal score: %d\n", score * 10);
    return 0;
}