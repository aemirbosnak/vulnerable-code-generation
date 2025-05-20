//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up random seed
    srand(time(NULL));

    // Variables for player position and score
    int player_pos = 10;
    int score = 0;

    // Variables for room states
    int room1_state = 0;
    int room2_state = 0;
    int room3_state = 0;
    int room4_state = 0;
    int room5_state = 0;

    // Game loop
    while(1)
    {
        // Print current room layout
        printf("\n");
        printf("Score: %d\n", score);
        printf("----------\n");
        printf("|  %d  |  \n", room1_state);
        printf("|     |  \n");
        printf("----------\n");
        printf("|  %d  |  \n", room2_state);
        printf("|     |  \n");
        printf("----------\n");
        printf("|  %d  |  \n", room3_state);
        printf("|     |  \n");
        printf("----------\n");
        printf("|  %d  |  \n", room4_state);
        printf("|     |  \n");
        printf("----------\n");
        printf("|  %d  |  \n", room5_state);
        printf("| P:%d |  \n", player_pos);
        printf("----------\n");

        // Check if player has won or lost
        if(score == 5)
        {
            printf("\nYou win!\n");
            break;
        }
        if(room1_state == 1 && room2_state == 1 && room3_state == 1 && room4_state == 1 && room5_state == 1)
        {
            printf("\nThe haunted house has claimed another victim!\n");
            break;
        }

        // Prompt player for action
        printf("\nWhat do you want to do?\n");
        printf("1. Move left\n");
        printf("2. Move right\n");
        printf("3. Interact with room\n");
        printf("4. Quit game\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        // Process player action
        switch(choice)
        {
            case 1:
                if(player_pos > 1)
                {
                    player_pos--;
                }
                break;

            case 2:
                if(player_pos < 5)
                {
                    player_pos++;
                }
                break;

            case 3:
                switch(player_pos)
                {
                    case 1:
                        if(room1_state == 0)
                        {
                            printf("\nYou enter the room and find a flashlight.\n");
                            room1_state = 1;
                            score++;
                        }
                        else
                        {
                            printf("\nThis room is empty.\n");
                        }
                        break;

                    case 2:
                        if(room2_state == 0)
                        {
                            printf("\nYou enter the room and find a first-aid kit.\n");
                            room2_state = 1;
                            score++;
                        }
                        else
                        {
                            printf("\nThis room is empty.\n");
                        }
                        break;

                    case 3:
                        if(room3_state == 0)
                        {
                            int monster = rand() % 2;
                            if(monster == 0)
                            {
                                printf("\nYou enter the room and are attacked by a zombie!\n");
                                room3_state = 1;
                            }
                            else
                            {
                                printf("\nYou enter the room and find a key.\n");
                                room3_state = 2;
                            }
                        }
                        else if(room3_state == 1)
                        {
                            printf("\nThe zombie is still in this room. You need to kill it before you can search it.\n");
                        }
                        else
                        {
                            printf("\nThis room is empty.\n");
                        }
                        break;

                    case 4:
                        if(room4_state == 0)
                        {
                            printf("\nYou enter the room and find a gun.\n");
                            room4_state = 1;
                            score++;
                        }
                        else
                        {
                            printf("\nThis room is empty.\n");
                        }
                        break;

                    case 5:
                        if(room5_state == 0)
                        {
                            printf("\nYou enter the final room and find the last piece of the key.\n");
                            room5_state = 1;
                            score++;
                        }
                        else
                        {
                            printf("\nThis room is empty.\n");
                        }
                        break;

                    default:
                        printf("\nInvalid choice.\n");
                        break;
                }
                break;

            case 4:
                printf("\nQuitting game.\n");
                return 0;

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}