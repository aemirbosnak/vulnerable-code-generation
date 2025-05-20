//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20

int player_health = 100;
int player_gold = 10;

void wait_for_enter()
{
    fflush(stdin);
    printf("\nPress Enter to continue...");
    while(getchar() != '\n');
}

void clear_screen()
{
    system("cls || clear");
}

//function to get user's name
void get_player_name(char *name)
{
    printf("Welcome stranger! What is your name?\n");
    scanf("%s", name);
}

//function to randomly generate a number between min and max (inclusive)
int random_number(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

//function to handle user's choice to go left or right
void handle_direction_choice(char direction, int *enemy_health_ptr)
{
    int random_damage = random_number(5, 15);
    int random_gold = random_number(5, 20);
    switch(direction)
    {
        case 'L':
            printf("You chose to go left.\n");
            printf("You encounter a goblin!\n");
            do
            {
                printf("What will you do?\n");
                printf("A - Attack the goblin\n");
                printf("R - Run away\n");
                char choice;
                scanf(" %c", &choice);
                switch(choice)
                {
                    case 'A':
                        printf("You attack the goblin and deal %d damage.\n", random_damage);
                        *enemy_health_ptr -= random_damage;
                        if(*enemy_health_ptr <= 0)
                        {
                            printf("You defeat the goblin and find %d gold!\n", random_gold);
                            player_gold += random_gold;
                            wait_for_enter();
                            return;
                        }
                        printf("The goblin attacks you and deals %d damage.\n", random_damage);
                        player_health -= random_damage;
                        if(player_health <= 0)
                        {
                            printf("You have been defeated by the goblin.\n");
                            exit(1);
                        }
                        break;
                    case 'R':
                        printf("You run away from the goblin.\n");
                        wait_for_enter();
                        return;
                    default:
                        printf("Invalid choice.\n");
                }
            } while(1);
        case 'R':
            printf("You chose to go right.\n");
            printf("You find a treasure chest containing %d gold!\n", random_gold);
            player_gold += random_gold;
            wait_for_enter();
            return;
        default:
            printf("Invalid choice.\n");
    }
}

int main()
{
    char player_name[MAX_NAME_LENGTH];
    get_player_name(player_name);
    printf("Welcome %s to the medieval land of CodeQuest!\n", player_name);
    wait_for_enter();
    clear_screen();

    printf("You are currently standing at a crossroad.\n");
    while(1)
    {
        printf("Which direction do you want to go?\n");
        printf("L - Left\n");
        printf("R - Right\n");
        char choice;
        scanf(" %c", &choice);
        handle_direction_choice(choice, &player_health);
    }
    return 0;
}