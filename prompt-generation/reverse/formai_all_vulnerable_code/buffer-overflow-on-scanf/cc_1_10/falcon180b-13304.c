//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int player_health = 100;
    int enemy_health = 50;
    int choice;
    int damage;

    printf("Welcome to the Sherlock Holmes Space Adventure!\n");
    printf("You are on a mission to defeat the evil space villain, Moriarty.\n");
    printf("You have %d health points and Moriarty has %d health points.\n", player_health, enemy_health);
    printf("Choose your attack:\n");
    printf("1. Laser gun\n");
    printf("2. Plasma sword\n");
    printf("3. Ion cannon\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            damage = rand() % 10 + 1;
            printf("You fired your laser gun and dealt %d damage to Moriarty!\n", damage);
            enemy_health -= damage;
            break;
        case 2:
            damage = rand() % 20 + 1;
            printf("You sliced Moriarty with your plasma sword and dealt %d damage!\n", damage);
            enemy_health -= damage;
            break;
        case 3:
            damage = rand() % 30 + 1;
            printf("You blasted Moriarty with your ion cannon and dealt %d damage!\n", damage);
            enemy_health -= damage;
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    if(enemy_health <= 0)
    {
        printf("Congratulations! You have defeated Moriarty and saved the galaxy!\n");
    }
    else
    {
        printf("Moriarty retaliates and deals %d damage to you!\n", rand() % 10 + 1);
        player_health -= rand() % 10 + 1;
    }

    if(player_health <= 0)
    {
        printf("Game over. You have been defeated by Moriarty.\n");
        exit(1);
    }

    return 0;
}