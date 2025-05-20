//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototypes
void start_game();
void intro();
void room_one();
void room_two();
void room_three();
void room_four();
void finish_game();
void game_over();
void try_again();

// global variables
char player_name[20];
int player_health = 100;
int enemy_health = 100;
int enemy_choice;

int main()
{
    start_game();

    return 0;
}

void start_game()
{
    system("clear");

    printf("\n ##### WELCOME TO THE ADVENTURE GAME #####\n\n");
    printf("Enter your name: ");
    scanf("%s", player_name);

    intro();
}

void intro()
{
    system("clear");

    printf("\n Welcome, %s, to the world of adventure!\n\n", player_name);
    printf("You find yourself in a dark room with four doors.\n");
    printf("Each door leads to a different adventure and a different challenge.\n");
    printf("Choose your door wisely, %s.\n\n", player_name);

    printf("Press enter to continue...\n");
    getchar();

    room_one();
}

void room_one()
{
    system("clear");

    printf("\n You have chosen door number one...\n");
    printf("You enter a room filled with treasure!\n");
    printf("But be careful, there is an enemy guarding it.\n");

    while (player_health > 0 && enemy_health > 0)
    {
        printf("\n Your health: %d\n", player_health);
        printf(" Enemy health: %d\n\n", enemy_health);
        printf(" What will you do?\n");
        printf(" 1. Attack\n");
        printf(" 2. Defend\n");
        printf(" 3. Escape\n");

        printf("\n Enter your choice: ");
        scanf("%d", &enemy_choice);

        if (enemy_choice == 1)
        {
            srand(time(NULL));
            int damage = rand() % 10 + 1;
            enemy_health -= damage;

            printf("\n You attack the enemy and deal %d damage!\n", damage);

            damage = rand() % 10 + 1;
            player_health -= damage;

            printf(" The enemy attacks you and deals %d damage!\n", damage);
        }
        else if (enemy_choice == 2)
        {
            int block = rand() % 2;

            if (block)
            {
                printf("\n You block the enemy's attack!\n");
            }
            else
            {
                int damage = rand() % 10 + 1;
                player_health -= damage;

                printf("\n You fail to block the enemy's attack and take %d damage!\n", damage);
            }
        }
        else if (enemy_choice == 3)
        {
            printf("\n You try to escape...\n");

            srand(time(NULL));
            int escape = rand() % 2;

            if (escape)
            {
                printf(" You successfully escape!\n");
                room_two();
            }
            else
            {
                printf(" The enemy catches you as you try to escape!\n");

                int damage = rand() % 10 + 1;
                player_health -= damage;

                printf(" The enemy deals %d damage!\n", damage);
            }
        }
    }

    if (player_health <= 0)
    {
        game_over();
    }
    else if (enemy_health <= 0)
    {
        printf("\n Congratulations, %s, you defeated the enemy and gained the treasure!\n", player_name);
        room_two();
    }
}

void room_two()
{
    system("clear");

    printf("\n You have chosen door number two...\n");
    printf("You enter a room with a riddle.\n");

    char answer[20];

    printf("\n What has a head and a tail but no body?\n");
    printf(" Enter your answer: ");
    scanf("%s", answer);

    if (!strcmp(answer, "coin"))
    {
        printf("\n Congratulations, %s, you solved the riddle!\n", player_name);
        printf(" You are awarded with the key to the next room!\n");

        printf("\n Press enter to continue...\n");
        getchar();

        room_three();
    }
    else
    {
        printf("\n Sorry, %s, that is incorrect.\n", player_name);
        printf(" Try again...\n\n");

        printf(" Press enter to continue...\n");
        getchar();

        room_two();
    }
}

void room_three()
{
    system("clear");

    printf("\n You have chosen door number three...\n");
    printf("You enter a room with a maze.\n");

    srand(time(NULL));
    int rand_num = rand() % 4 + 1;

    printf("\n Choose a path:\n");
    printf(" 1. Left\n");
    printf(" 2. Right\n");
    printf(" 3. Straight\n");

    int choice;

    printf("\n Enter your choice: ");
    scanf("%d", &choice);

    if (choice == rand_num)
    {
        printf("\n Congratulations, %s, you solved the maze!\n", player_name);
        printf(" You are awarded with the key to the next room!\n");

        printf("\n Press enter to continue...\n");
        getchar();

        room_four();
    }
    else
    {
        printf("\n Sorry, %s, you chose the wrong path.\n", player_name);
        printf(" You must try again...\n\n");

        printf(" Press enter to continue...\n");
        getchar();

        room_three();
    }
}

void room_four()
{
    system("clear");

    printf("\n You have chosen door number four...\n");
    printf("You enter a room with a final boss.\n");
    printf("Defeat the boss to complete the game!\n");

    while (player_health > 0 && enemy_health > 0)
    {
        printf("\n Your health: %d\n", player_health);
        printf(" Enemy health: %d\n\n", enemy_health);
        printf(" What will you do?\n");
        printf(" 1. Attack\n");
        printf(" 2. Defend\n");
        printf(" 3. Escape\n");

        printf("\n Enter your choice: ");
        scanf("%d", &enemy_choice);

        if (enemy_choice == 1)
        {
            srand(time(NULL));
            int damage = rand() % 10 + 1;
            enemy_health -= damage;

            printf("\n You attack the boss and deal %d damage!\n", damage);

            damage = rand() % 10 + 1;
            player_health -= damage;

            printf(" The boss attacks you and deals %d damage!\n", damage);
        }
        else if (enemy_choice == 2)
        {
            int block = rand() % 2;

            if (block)
            {
                printf("\n You block the boss's attack!\n");
            }
            else
            {
                int damage = rand() % 10 + 1;
                player_health -= damage;

                printf("\n You fail to block the boss's attack and take %d damage!\n", damage);
            }
        }
        else if (enemy_choice == 3)
        {
            printf("\n You try to escape...\n");

            printf(" Sorry, %s, there is no escape from the boss!\n", player_name);

            int damage = rand() % 10 + 1;
            player_health -= damage;

            printf(" The boss deals %d damage!\n", damage);
        }
    }

    if (player_health <= 0)
    {
        game_over();
    }
    else if (enemy_health <= 0)
    {
        printf("\n Congratulations, %s, you defeated the final boss and completed the game!\n", player_name);
        finish_game();
    }
}

void finish_game()
{
    printf("\n Thank you, %s, for playing the adventure game!\n", player_name);
    printf(" Your hero's journey has ended.\n\n");
}

void game_over()
{
    system("clear");

    printf("\n ##### GAME OVER #####\n\n");
    printf(" Oh no, %s, your adventure has come to a sad end...\n", player_name);
    printf(" Would you like to try again?\n");

    try_again();
}

void try_again()
{
    char choice[10];

    printf("\n Enter 'yes' or 'no': ");
    scanf("%s", choice);

    if (!strcmp(choice, "yes"))
    {
        player_health = 100;
        enemy_health = 100;

        start_game();
    }
    else if (!strcmp(choice, "no"))
    {
        printf("\n Thank you for playing the adventure game!\n\n");
        exit(0);
    }
    else
    {
        printf("\n Sorry, %s, that is an invalid choice.\n", player_name);
        printf(" Try again...\n");

        try_again();
    }
}