//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    int choice=0,health=100,attack=10,gold=0;
    char name[20];
    printf("Welcome to the Dungeon Adventure Game\n");
    printf("Please enter your name: ");
    scanf("%s",name);

    printf("Hello %s! you are now on the journey for the lost treasure\n",name);
    printf("You have %d health and your attack power is %d\n",health,attack);

    while(choice!=3)
    {
        printf("\nPlease choose an option below\n");
        printf("1. Enter the dungeon\n2. Visit the shop\n3. Quit the game\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int enemy_health=50,enemy_attack=8;
                printf("\nYou enter the dungeon and encounter an enemy!\n");
                printf("Enemy health: %d\n",enemy_health);

                while(enemy_health>0)
                {
                    printf("Choose your move\n1. Attack\n2. Heal\n");
                    int move;
                    scanf("%d",&move);

                    if(move==1)
                    {
                        printf("You attack and deal %d damage to the enemy\n",attack);
                        enemy_health-=attack;
                        printf("Enemy health now: %d\n",enemy_health);

                        if(enemy_health>0)
                        {
                            printf("Enemy attacks and deals %d damage to you\n",enemy_attack);
                            health-=enemy_attack;
                            printf("Your health now: %d\n",health);
                            if(health<=0)
                            {
                                printf("Game over. You died in the dungeon. Better luck next time.\n");
                                exit(0);
                            }
                        }
                        else
                        {
                            printf("You have defeated the enemy!\n");
                            gold+=50;
                            printf("You have gained 50 gold\n");
                            break;
                        }
                    }
                    else if(move==2)
                    {
                        if(gold>=20)
                        {
                            printf("You heal yourself and gain 20 health\n");
                            health+=20;
                            printf("Your health now: %d\n",health);
                            gold-=20;
                            printf("Gold now: %d\n",gold);
                        }
                        else
                        {
                            printf("You don't have enough gold to heal\n");
                        }
                    }
                    else
                    {
                        printf("Invalid move. Please choose 1 or 2\n");
                    }
                }
                break;
            }
            case 2:
            {
                printf("\nWelcome to the shop! What would you like to buy?\n");
                printf("Gold: %d\n1. Increase health by 20 (costs 30 gold)\n2. Increase attack by 5 (costs 40 gold)\n3. Leave shop\n");
                int shop_choice;
                scanf("%d",&shop_choice);

                if(shop_choice==1)
                {
                    if(gold>=30)
                    {
                        printf("You have bought the health upgrade\n");
                        health+=20;
                        printf("Your health now: %d\n",health);
                        gold-=30;
                        printf("Gold now: %d\n",gold);
                    }
                    else
                    {
                        printf("You don't have enough gold to buy this item\n");
                    }
                }
                else if(shop_choice==2)
                {
                    if(gold>=40)
                    {
                        printf("You have bought the attack upgrade\n");
                        attack+=5;
                        printf("Your attack now: %d\n",attack);
                        gold-=40;
                        printf("Gold now: %d\n",gold);
                    }
                    else
                    {
                        printf("You don't have enough gold to buy this item\n");
                    }
                }
                else if(shop_choice==3)
                {
                    printf("Thanks for visiting the shop, come again!\n");
                }
                else
                {
                    printf("Invalid choice, please try again\n");
                }
                break;
            }
            case 3:
            {
                printf("Thanks for playing! Goodbye\n");
                break;
            }
            default:
            {
                printf("Invalid choice, please try again\n");
                break;
            }
        }
    }

    return 0;
}