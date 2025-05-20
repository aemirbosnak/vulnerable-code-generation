//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

void delay(int seconds) //Custom delay function
{   
    float start_time=(float)clock()/(float)CLOCKS_PER_SEC;
    while(((float)clock()/(float)CLOCKS_PER_SEC)-start_time<=seconds);
}

void clear_screen() //Custom function to clear screen
{
    if (system("CLS")) system("clear");
}

int main()
{
    char name[50];
    char choice;
    int health = 100;
    int gold = 0;
    int level = 1;
    int enemy, enemy_health, enemy_attack, enemy_defense;
    srand(time(0));

    printf("What is your name, adventurer?\n");
    scanf("%s", name);
    printf("Welcome, %s! You are starting your adventure in a small village.\n", name);
    delay(2);
    clear_screen();
    printf("You are walking down the dirt road in the village when you see a sign that reads 'WANTED: Goblin slayer'.\n");
    printf("The reward is 50 gold coins, do you wish to accept [y/n]?\n");
    scanf(" %c", &choice);
    if (tolower(choice) == 'y')
    {
        printf("You decide to accept the job and head to the goblin cave, located outside of the village.\n");
        delay(2);
        clear_screen();
        printf("As you enter the cave, a goblin jumps out from behind a rock and attacks you!\n");
        enemy = 0;
        enemy_health = 50;
        enemy_attack = 10;
        enemy_defense = 5;
        delay(2);
        while (health > 0 && enemy_health > 0)
        {
            printf("Your health: %d\n", health);
            printf("Enemy health: %d\n", enemy_health);
            printf("What will you do? [a]ttack [d]efend\n");
            scanf(" %c", &choice);
            if (tolower(choice) == 'a')
            {
                printf("You attack the goblin!\n");
                int damage = rand() % 10 + 10 - enemy_defense;
                printf("You deal %d damage!\n", damage);
                enemy_health -= damage;
                delay(2);
                if (enemy_health > 0)
                {
                    printf("The goblin attacks you!\n");
                    int enemy_damage = rand() % enemy_attack + 5;
                    printf("The goblin deals %d damage!\n", enemy_damage);
                    health -= enemy_damage;
                    delay(2);                    
                }
            }
            else if (tolower(choice) == 'd')
            {
                printf("You defend yourself!\n");
                enemy_attack /= 2;
                delay(2);
            }
            else
            {
                printf("Invalid choice!\n");
                delay(1);
            }
            clear_screen();
        }
        if (health <= 0)
        {
            printf("You were defeated by the goblin!\n");
            delay(2);
            return 0;
        }
        printf("You defeated the goblin and earned 50 gold coins!\n");
        gold += 50;
        delay(2);
        clear_screen();
    }
    printf("You continue on your journey and come across a bridge with a troll blocking the way.\n");
    printf("The troll demands 100 gold coins to cross the bridge, do you wish to pay [p] or fight [f]?\n");
    scanf(" %c", &choice);
    if (tolower(choice) == 'p')
    {
        if (gold >= 100)
        {
            printf("You pay the troll and cross the bridge.\n");
            gold -= 100;
            delay(2);
            clear_screen();
        }
        else
        {
            printf("You don't have enough gold to pay the troll!\n");
            delay(2);
            return 0;
        }
    }
    else if (tolower(choice) == 'f')
    {
        printf("You decide to fight the troll!\n");
        enemy = 1;
        enemy_health = 100;
        enemy_attack = 20;
        enemy_defense = 10;
        delay(2);
        while (health > 0 && enemy_health > 0)
        {
            printf("Your health: %d\n", health);
            printf("Enemy health: %d\n", enemy_health);
            printf("What will you do? [a]ttack [d]efend\n");
            scanf(" %c", &choice);
            if (tolower(choice) == 'a')
            {
                printf("You attack the troll!\n");
                int damage = rand() % 10 + 15 - enemy_defense;
                printf("You deal %d damage!\n", damage);
                enemy_health -= damage;
                delay(2);
                if (enemy_health > 0)
                {
                    printf("The troll attacks you!\n");
                    int enemy_damage = rand() % enemy_attack + 5;
                    printf("The troll deals %d damage!\n", enemy_damage);
                    health -= enemy_damage;
                    delay(2);                    
                }
            }
            else if (tolower(choice) == 'd')
            {
                printf("You defend yourself!\n");
                enemy_attack /= 2;
                delay(2);
            }
            else
            {
                printf("Invalid choice!\n");
                delay(1);
            }
            clear_screen();
        }
        if (health <= 0)
        {
            printf("You were defeated by the troll!\n");
            delay(2);
            return 0;
        }
        printf("You defeated the troll!\n");
        gold += 100;
        delay(2);
        clear_screen();
    }
    printf("You continue on your journey and come across a tower in the distance.\n");
    printf("Do you wish to enter the tower [y/n]?\n");
    scanf(" %c", &choice);
    if (tolower(choice) == 'y')
    {
        printf("You enter the tower and start climbing the stairs.\n");
        delay(2);
        clear_screen();
        printf("As you reach the top, you see a dragon guarding a treasure chest!\n");
        printf("You must defeat the dragon to claim the treasure!\n");
        enemy = 2;
        enemy_health = 150;
        enemy_attack = 30;
        enemy_defense = 15;
        delay(2);
        while (health > 0 && enemy_health > 0)
        {
            printf("Your health: %d\n", health);
            printf("Enemy health: %d\n", enemy_health);
            printf("What will you do? [a]ttack [d]efend\n");
            scanf(" %c", &choice);
            if (tolower(choice) == 'a')
            {
                printf("You attack the dragon!\n");
                int damage = rand() % 10 + 20 - enemy_defense;
                printf("You deal %d damage!\n", damage);
                enemy_health -= damage;
                delay(2);
                if (enemy_health > 0)
                {
                    printf("The dragon attacks you!\n");
                    int enemy_damage = rand() % enemy_attack + 10;
                    printf("The dragon deals %d damage!\n", enemy_damage);
                    health -= enemy_damage;
                    delay(2);                    
                }
            }
            else if (tolower(choice) == 'd')
            {
                printf("You defend yourself!\n");
                enemy_attack /= 2;
                delay(2);
            }
            else
            {
                printf("Invalid choice!\n");
                delay(1);
            }
            clear_screen();
        }
        if (health <= 0)
        {
            printf("You were defeated by the dragon!\n");
            delay(2);
            return 0;
        }
        printf("You defeated the dragon and claimed the treasure!\n");
        gold += 500;
        delay(2);
        clear_screen();
    }    
    printf("Congratulations, %s! You have completed your adventure!\n", name);
    printf("Final stats: Health: %d Gold: %d Level: %d\n", health, gold, level);
    return 0;
}