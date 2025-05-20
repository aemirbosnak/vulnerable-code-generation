//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Welcome message
    printf("Welcome to PARANOIA - The Text-Based Adventure Game!\n");
    printf("You are an agent, always on high alert. Don't trust anyone!\n");

    // Player's name input
    char name[20];
    printf("What's your name, Agent?\n");
    scanf("%s", name);

    // Begin game
    printf("\n%s, you are on a mission to retrieve a top-secret file from a mysterious organization.\n", name);
    printf("You are in a dark alley, and there are two doors in front of you. Which one will you choose? (1 or 2)\n");

    // Player chooses door 1 or door 2
    int door_choice;
    scanf("%d", &door_choice);

    if (door_choice == 1)
    {
        printf("\nYou entered a room with a single window on the far wall. The curtains are drawn, blocking all light.\n");
        printf("What will you do?\n");
        printf("1. Open the curtains\n");
        printf("2. Ignore the window and search the room\n");

        // Player chooses to open the curtains or ignore them
        int window_choice;
        scanf("%d", &window_choice);

        if (window_choice == 1)
        {
            printf("\nYou opened the curtains, and your eyes were immediately drawn to a figure on the rooftop across the street.\n");
            printf("You couldn't make out any details, but it felt like they were watching you.\n");
            printf("What now?\n");
            printf("1. Investigate the rooftop\n");
            printf("2. Ignore the figure and continue searching the room\n");

            // Player chooses to investigate the rooftop or ignore it 
            int rooftop_choice;
            scanf("%d", &rooftop_choice);

            if (rooftop_choice == 1)
            {
                printf("\nYou climbed over to the rooftop and found nothing. As you returned to the room, you noticed a piece of paper under the door.\n");
                printf("It reads: 'Don't trust anyone, not even yourself.'\n");
                printf("What now?\n");
                printf("1. Keep searching for the file\n");
                printf("2. Leave the building\n");

                // Player chooses to keep searching or leave the building
                int building_choice;
                scanf("%d", &building_choice);

                if (building_choice == 1)
                {
                    printf("\nYou search the room and find the file hidden inside a book on the bookshelf. As you retrieve the file, you hear footsteps approaching the door.\n");
                    printf("What now?\n");
                    printf("1. Hide\n");
                    printf("2. Confront the intruder\n");

                    // Player chooses to hide or confront the intruder
                    int intruder_choice;
                    scanf("%d", &intruder_choice);

                    if (intruder_choice == 1)
                    {
                        printf("\nYou hid behind the couch, and a man dressed in black entered the room. He searched the room and left without finding anything. You wait a few moments and then leave the building.\n");
                        printf("Congratulations, %s! You successfully completed your mission!\n", name);
                    }
                    else if (intruder_choice == 2)
                    {
                        printf("\nYou confronted the intruder, but he attacked you before you could say anything.\n");
                        printf("Game over, %s. PARANOIA got the better of you.", name);
                    }
                    else 
                    {
                        printf("\nInvalid choice. Try again.\n");
                    }
                }
                else if (building_choice == 2)
                {
                    printf("\nYou left the building and noticed a shadowy figure following you. You quickened your pace and eventually lost them.\n");
                    printf("What now?\n");
                    printf("1. Continue the mission\n");
                    printf("2. Return to HQ and report what you found\n");

                    // Player chooses to continue or return to HQ
                    int mission_choice;
                    scanf("%d", &mission_choice);

                    if (mission_choice == 1)
                    {
                        printf("\nYou continue on the mission and succeed. Congratulations, %s!\n", name);
                    }
                    else if (mission_choice == 2)
                    {
                        printf("\nAs you reported what you found, you noticed that your colleagues were giving you strange looks.\n");
                        printf("You realize that they knew more than they let on, and you found yourself constantly looking over your shoulder.\n");
                        printf("Game over, %s. PARANOIA won.", name);
                    }
                    else
                    {
                        printf("\nInvalid choice. Try again.\n");
                    }
                }
                else 
                {
                    printf("\nInvalid choice. Try again.\n");
                }
            }
            else if (rooftop_choice == 2)
            {
                printf("\nAs you search the room, you start to feel like someone is watching you. You leave, quickly realizing you hadn't found the file.\n");
                printf("What now?\n");
                printf("1. Go back to the alley\n");
                printf("2. Look for another entrance to the building\n");

                // Player chooses to go back to the alley or look for another entrance
                int entrance_choice;
                scanf("%d", &entrance_choice);

                if (entrance_choice == 1)
                {
                    printf("\nAs you exit the building, you see a man in black standing at the end of the alley. You quickly turn around and find another way out.\n");
                    printf("What now?\n");
                    printf("1. Attempt to find the file through another method\n");
                    printf("2. Go back to HQ and report that the mission was a failure\n");

                    // Player chooses to attempt to find the file or report a failure
                    int failure_choice;
                    scanf("%d", &failure_choice);

                    if (failure_choice == 1)
                    {
                        printf("\nYou attempt to find the file through other means, but it's too late. The organization has already moved it.\n");
                        printf("What's your next move?\n");
                        printf("1. Search for more information on the organization\n");
                        printf("2. Return to HQ and hope for another mission\n");

                        // Player chooses to search for information or return to HQ
                        int information_choice;
                        scanf("%d", &information_choice);

                        if (information_choice == 1)
                        {
                            printf("\nYou start an investigation on the organization and eventually find the file. Congratulations on completing the mission, %s!\n", name);
                        }
                        else if (information_choice == 2)
                        {
                            printf("\nAs you return to HQ, you start to notice that your colleagues are giving you strange looks.\n");
                            printf("You realize that they knew more than they let on, and you found yourself constantly looking over your shoulder.\n");
                            printf("Game over, %s. PARANOIA won.", name);
                        }
                        else
                        {
                            printf("\nInvalid choice. Try again.\n");
                        }
                    }
                    else if (failure_choice == 2)
                    {
                        printf("\nAs you return to HQ and report the failure, you notice that your colleagues are giving you strange looks.\n");
                        printf("You realize that they knew more than they let on, and you found yourself constantly looking over your shoulder.\n");
                        printf("Game over, %s. PARANOIA won.", name);
                    }
                    else 
                    {
                        printf("\nInvalid choice. Try again.\n");
                    }
                }
                else if (entrance_choice == 2)
                {
                    printf("\nAs you search for another entrance, you notice that you're being followed by a man in black.\n");
                    printf("What now?\n");
                    printf("1. Confront him\n");
                    printf("2. Lose him\n");

                    // Player chooses to confront or lose the man in black
                    int man_choice;
                    scanf("%d", &man_choice);

                    if (man_choice == 1)
                    {
                        printf("\nYou confront the man and take him down. After searching him, you find a piece of paper that reads: 'The organization knows everything.'\n");
                        printf("You realize that you've been compromised and quickly flee the area.\n");
                        printf("Game over, %s. PARANOIA won.", name);
                    }
                    else if (man_choice == 2)
                    {
                        printf("\nYou manage to lose the man in black, but the organization has already moved the file.\n");
                        printf("What's your next move?\n");
                        printf("1. Search for more information on the organization\n");
                        printf("2. Return to HQ and hope for another mission\n");

                        // Player chooses to search for information or return to HQ
                        int information_choice;
                        scanf("%d", &information_choice);

                        if (information_choice == 1)
                        {
                            printf("\nYou start an investigation on the organization and eventually find the file. Congratulations on completing the mission, %s!\n", name);
                        }
                        else if (information_choice == 2)
                        {
                            printf("\nAs you return to HQ, you start to notice that your colleagues are giving you strange looks.\n");
                            printf("You realize that they knew more than they let on, and you found yourself constantly looking over your shoulder.\n");
                            printf("Game over, %s. PARANOIA won.", name);
                        }
                        else
                        {
                            printf("\nInvalid choice. Try again.\n");
                        }
                    }
                    else 
                    {
                        printf("\nInvalid choice. Try again.\n");
                    }
                }
                else 
                {
                    printf("\nInvalid choice. Try again.\n");
                }
            }
            else 
            {
                printf("\nInvalid choice. Try again.\n");
            }
        }
        else if (window_choice == 2)
        {
            printf("\nYou start searching the room and find the file hidden inside a book on the bookshelf. As you retrieve the file, you hear footsteps approaching the door.\n");
            printf("What now?\n");
            printf("1. Hide\n");
            printf("2. Confront the intruder\n");

            // Player chooses to hide or confront the intruder
            int intruder_choice;
            scanf("%d", &intruder_choice);

            if (intruder_choice == 1)
            {
                printf("\nYou hid behind the couch, and a man dressed in black entered the room. He searched the room and left without finding anything. You wait a few moments and then leave the building.\n");
                printf("Congratulations, %s! You successfully completed your mission!\n", name);
            }
            else if (intruder_choice == 2)
            {
                printf("\nYou confronted the intruder, but he attacked you before you could say anything.\n");
                printf("Game over, %s. PARANOIA got the better of you.", name);
            }
            else 
            {
                printf("\nInvalid choice. Try again.\n");
            }
        }
        else 
        {
            printf("\nInvalid choice. Try again.\n");
        }
    }
    else if (door_choice == 2)
    {
        printf("\nYou entered a room filled with people in suits, huddled around a table.\n");
        printf("What will you do?\n");
        printf("1. Walk up to the table and demand the file\n");
        printf("2. Listen in on their conversation\n");

        // Player chooses to demand the file or listen to the conversation
        int conversation_choice;
        scanf("%d", &conversation_choice);

        if (conversation_choice == 1)
        {
            printf("\nYou walk up to the table and demand the file. The people in suits look at you in shock, and one of them presses a button on the table.\n");
            printf("Suddenly, the floor beneath you opens, and you fall into a dark pit.\n");
            printf("Game over, %s. PARANOIA wins.", name);
        }
        else if (conversation_choice == 2)
        {
            printf("\nYou listen in on their conversation and hear them talking about the file. They mention that it's hidden somewhere inside the building.\n");
            printf("What now?\n");
            printf("1. Find the file\n");
            printf("2. Leave the building\n");

            // Player chooses to find the file or leave the building
            int building_choice;
            scanf("%d", &building_choice);

            if (building_choice == 1)
            {
                printf("\nYou search the building and eventually find the file. Congratulations, %s!\n", name);
            }
            else if (building_choice == 2)
            {
                printf("\nAs you leave the building, you notice that a black car is following you. You quicken your pace and eventually lose them.\n");
                printf("What's your next move?\n");
                printf("1. Return to HQ and report what you found\n");
                printf("2. Keep searching for more information on the organization\n");

                // Player chooses to report what they found or keep searching
                int information_choice;
                scanf("%d", &information_choice);

                if (information_choice == 1)
                {
                    printf("\nAs you report what you found, you notice that your colleagues are giving you strange looks.\n");
                    printf("You realize that they knew more than they let on, and you found yourself constantly looking over your shoulder.\n");
                    printf("Game over, %s. PARANOIA won.", name);
                }
                else if (information_choice == 2)
                {
                    printf("\nYou start an investigation on the organization and eventually uncover a plot to overthrow the government.\n");
                    printf("Congratulations, %s! You have just saved the nation from disaster!\n", name);
                }
                else
                {
                    printf("\nInvalid choice. Try again.\n");
                }
            }
            else
            {
                printf("\nInvalid choice. Try again.\n");
            }
        }
        else 
        {
            printf("\nInvalid choice. Try again.\n");
        }
    }
    else 
    {
        printf("\nInvalid choice. Try again.\n");
    }

    return 0;
}