//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_health = 100, enemy_health = 100, player_attack = 0, enemy_attack = 0, choice;
    char play_again;

    printf("Welcome to the year 2050, where humans and robots coexist.\n");
    printf("You are a human warrior fighting against a robot enemy.\n");
    printf("Your mission is to defeat the enemy by reducing its health to zero.\n");
    printf("Are you ready? (y/n): ");
    scanf("%c", &play_again);

    while (play_again == 'y' || play_again == 'Y')
    {
        system("clear");
        printf("Round %d\n", rand() % 10 + 1);
        printf("Your health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);

        srand(time(NULL));
        player_attack = rand() % 10 + 1;
        enemy_attack = rand() % 10 + 1;

        printf("You attacked with %d damage!\n", player_attack);
        printf("Enemy attacked with %d damage!\n", enemy_attack);

        if (player_attack > enemy_attack)
        {
            enemy_health -= player_attack;
        }
        else if (enemy_attack > player_attack)
        {
            player_health -= enemy_attack;
        }
        else
        {
            printf("It's a tie!\n");
        }

        if (player_health <= 0)
        {
            printf("You lost. Game over.\n");
            break;
        }
        else if (enemy_health <= 0)
        {
            printf("You won! Congratulations!\n");
            break;
        }

        printf("Do you want to continue? (y/n): ");
        scanf("%c", &play_again);
    }

    return 0;
}