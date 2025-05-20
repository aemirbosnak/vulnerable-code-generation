//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    // game instructions
    printf("Statistic Adventure - Instructions:\n");
    printf("You will be on a journey to discover a hidden treasure. During the journey, you will encounter various obstacles and enemies.");
    printf("You have a total of 100 health points and 50 stamina points.\n");
    printf("Do your best to navigate through the adventure and reach the treasure.\n");
    printf("Press Enter to Begin.\n");
    getchar();

    // game variables
    int health_points = 100;
    int stamina_points = 50;
    int steps_taken = 0;
    int total_enemies_defeated = 0;
    int total_obstacles_encountered = 0;
    int total_treasure_found = 0;

    // game loop
    while(health_points > 0 && stamina_points > 0)
    {
        // present player options
        printf("\nEnter a choice:\n");
        printf("1. Walk forward\n");
        printf("2. Rest and regain stamina\n");
        printf("3. Quit game\n");

        // get user's choice
        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            // option 1: walking forward
            case 1:
                {
                    printf("\nYou take a step forward.\n");

                    // generate a random event
                    srand(time(0));
                    int event = rand() % 3;

                    switch(event)
                    {
                        // enemy encounter
                        case 0:
                            {
                                int enemy_health = rand() % 100;
                                printf("\nYou have encountered an enemy with %d health points.\n", enemy_health);

                                // fight the enemy
                                while(health_points > 0 && enemy_health > 0)
                                {
                                    srand(time(0));
                                    int player_attack = rand() % 50;
                                    int enemy_attack = rand() % 50;

                                    printf("\nYou attack the enemy and inflict %d damage.\n", player_attack);
                                    enemy_health -= player_attack;

                                    printf("The enemy attacks you and inflicts %d damage.\n", enemy_attack);
                                    health_points -= enemy_attack;
                                }

                                // check if the player won or lost the fight
                                if(enemy_health <= 0)
                                {
                                    printf("\nYou have defeated the enemy!\n");
                                    total_enemies_defeated++;
                                }

                                if(health_points <= 0)
                                {
                                    printf("\nYou have been defeated by the enemy. Game Over.\n");
                                    break;
                                }

                                // update statistics and continue game loop
                                steps_taken++;
                                stamina_points -= 5;
                                break;
                            }

                        // obstacle encounter
                        case 1:
                            {
                                printf("\nYou have encountered an obstacle. Beware!\n");
                                total_obstacles_encountered++;

                                // check if stamina points are sufficient to overcome the obstacle
                                if(stamina_points >= 25)
                                {
                                    printf("You have enough stamina points to overcome the obstacle.\n");
                                    stamina_points -= 25;
                                }
                                else
                                {
                                    printf("You do not have enough stamina points to overcome the obstacle. You lose 10 health points.\n");
                                    health_points -= 10;
                                }

                                // update statistics and continue game loop
                                steps_taken++;
                                stamina_points -= 5;
                                break;
                            }

                        // treasure encounter
                        case 2:
                            {
                                printf("\nYou have found a treasure. Congratulations!\n");
                                total_treasure_found++;

                                // update statistics and continue game loop
                                steps_taken++;
                                stamina_points -= 5;
                                break;
                            }
                    }

                    // display updated game status
                    printf("\nStatistics:\n");
                    printf("- Health Points: %d\n", health_points);
                    printf("- Stamina Points: %d\n", stamina_points);
                    printf("- Steps Taken: %d\n", steps_taken);
                    printf("- Total Enemies Defeated: %d\n", total_enemies_defeated);
                    printf("- Total Obstacles Encountered: %d\n", total_obstacles_encountered);
                    printf("- Total Treasure Found: %d\n", total_treasure_found);
                    break;
                }

            // option 2: resting and restoring stamina
            case 2:
                {
                    printf("\nYou rest and regain stamina.\n");
                    stamina_points = 50;

                    // update statistics and continue game loop
                    steps_taken++;
                    break;
                }

            // option 3: quitting game
            case 3:
                {
                    printf("\nAre you sure you want to quit the game? Y/N\n");
                    char confirm;
                    scanf(" %c", &confirm);

                    // if user confirms, end game
                    if(confirm == 'y' || confirm == 'Y')
                    {
                        printf("\nThanks for playing! Goodbye!\n");
                        return 0;
                    }

                    // if user cancels, continue game loop
                    else if(confirm == 'n' || confirm == 'N')
                    {
                        break;
                    }

                    // if user inputs invalid option, display error message and continue game loop
                    else
                    {
                        printf("\nInvalid Option. Please try again.\n");
                        break;
                    }
                }

            // if user inputs invalid option, display error message and continue game loop
            default:
                {
                    printf("\nInvalid Option. Please try again.\n");
                    break;
                }
        }
    }

    // if user runs out of health or stamina points, end game
    if(health_points <= 0 || stamina_points <= 0)
    {
        printf("\nYou have run out of health or stamina points. Game Over.\n");
    }

    return 0;
}