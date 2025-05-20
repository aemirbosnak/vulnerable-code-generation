//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 5

int main()
{
    int i, j, k, p, q, r, playerHP, enemyHP, enemyAtk, choice;
    int playerAtk = 10, playerDef = 5, playerGold = 0, playerXP = 0;
    int roomChoice = 0, itemChoice = 0, bossChoice = 0;
    char playerName[20], c;

    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("Enter your name: ");
    scanf("%19s", playerName);

    printf("\nHello, %s! You have stumbled upon a haunted house. ", playerName);
    printf("Your goal is to make it out alive and with as much treasure and experience as possible.\n");

    printf("\nYou start with %d HP, %d attack, and %d defense.\n", playerHP = 100, playerAtk, playerDef);

    for(i=1; i<=MAX; i++)
    {
        printf("\n==========ROOM %d==========\n", i);

        roomChoice = rand() % 3;

        switch(roomChoice)
        {
            case 0:
                printf("You enter a room and find a chest. Open it?\n1. Yes\n2. No\n");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("You open the chest and find ");
                    itemChoice = rand() % 3;

                    switch(itemChoice)
                    {
                        case 0:
                            printf("10 gold!\n");
                            playerGold += 10;
                            break;
                        
                        case 1:
                            printf("a potion that will restore 20 HP!\n");
                            playerHP += 20;
                            break;
                        
                        case 2:
                            printf("a sword that increases your attack by 5!\n");
                            playerAtk += 5;
                            break;
                    }
                }
                else
                {
                    printf("You decide not to open the chest and move on.\n");
                }
                break;

            case 1:
                printf("You enter a room and are confronted by an enemy. Prepare for battle!\n");

                enemyHP = 50;
                enemyAtk = 8;

                while(playerHP > 0 && enemyHP > 0)
                {
                    printf("\nYour HP: %d\nEnemy HP: %d\n", playerHP, enemyHP);
                    printf("1. Attack\n2. Defend\n");
                    scanf("%d", &choice);

                    switch(choice)
                    {
                        case 1:
                            printf("You attack the enemy for %d damage!\n", playerAtk);
                            enemyHP -= playerAtk;
                            break;
                        
                        case 2:
                            printf("You defend against the enemy's attack and take 2 less damage!\n");
                            playerHP -= enemyAtk - playerDef + 2;
                            break;
                    }

                    if(enemyHP <= 0)
                    {
                        printf("\nYou have defeated the enemy!\n");
                        playerGold += 10;
                        playerXP += 5;
                        break;
                    }

                    printf("\nThe enemy attacks you for %d damage!\n", enemyAtk);
                    playerHP -= enemyAtk - playerDef;

                    if(playerHP <= 0)
                    {
                        printf("\nYou have been defeated by the enemy!\n");
                        break;
                    }
                }
                break;

            case 2:
                printf("You enter a room and encounter the boss of the haunted house. ");
                printf("Prepare for the final battle!\n");

                bossChoice = rand() % 3;

                switch(bossChoice)
                {
                    case 0:
                        printf("You are facing a giant spider!\n");
                        enemyHP = 100;
                        enemyAtk = 12;
                        break;
                    
                    case 1:
                        printf("You are facing a ghost!\n");
                        enemyHP = 120;
                        enemyAtk = 10;
                        break;
                    
                    case 2:
                        printf("You are facing a demon!\n");
                        enemyHP = 150;
                        enemyAtk = 15;
                        break;
                }

                while(playerHP > 0 && enemyHP > 0)
                {
                    printf("\nYour HP: %d\nEnemy HP: %d\n", playerHP, enemyHP);
                    printf("1. Attack\n2. Defend\n");
                    scanf("%d", &choice);

                    switch(choice)
                    {
                        case 1:
                            printf("You attack the boss for %d damage!\n", playerAtk);
                            enemyHP -= playerAtk;
                            break;
                        
                        case 2:
                            printf("You defend against the boss's attack and take 2 less damage!\n");
                            playerHP -= enemyAtk - playerDef + 2;
                            break;
                    }

                    if(enemyHP <= 0)
                    {
                        printf("\nYou have defeated the boss! Congratulations, %s!\n", playerName);
                        playerGold += 50;
                        playerXP += 20;
                        break;
                    }

                    printf("\nThe boss attacks you for %d damage!\n", enemyAtk);
                    playerHP -= enemyAtk - playerDef;

                    if(playerHP <= 0)
                    {
                        printf("\nYou have been defeated by the boss. Better luck next time!\n");
                        break;
                    }
                }
                break;
        }
    }

    printf("\n\n==========GAME OVER==========\n");
    printf("\n%s's final stats:\nHP: %d\nAttack: %d\nDefense: %d\nGold: %d\nExperience: %d\n",
        playerName, playerHP, playerAtk, playerDef, playerGold, playerXP);

    return 0;
}