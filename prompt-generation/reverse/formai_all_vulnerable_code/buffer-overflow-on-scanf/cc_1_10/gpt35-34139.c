//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    int has_key = 0;

    printf("Welcome to the Haunted House Simulator\n\n");

    printf("You have entered the front door of the haunted house.\n");
    printf("You can proceed to the left door to enter the living room, or the right door to enter the kitchen.\n");
    printf("Which door do you choose? (1 for left, 2 for right):\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("As you enter the living room, you hear some strange noises. Suddenly, a ghost appears and says, 'To pass this room, you must guess a number between 1 and 10.'\n");
        printf("What number do you choose?\n");
        scanf("%d", &choice);
        
        // Generate a random number between 1-10 to compare with the user input
        srand(time(NULL)); 
        int random_num = rand() % 10 + 1; 

        if (choice == random_num)
        {
            printf("Congratulations, you passed the living room!\n");
            has_key = 1;
        }
        else
        {
            printf("Sorry, the correct number was %d. You cannot proceed.\n", random_num);
        }
    }
    else if (choice == 2)
    {
        printf("As you enter the kitchen, you notice a cabinet. Do you want to open it? (1 for yes, 2 for no):\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Inside the cabinet, you find a key!\n");
            has_key = 1;
        }
        else
        {
            printf("You decide not to open the cabinet.\n");
        }
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
    }

    if (has_key == 1)
    {
        printf("You have obtained the key and can proceed to the next room.\n");
        printf("You can either go upstairs or downstairs. Which do you choose? (1 for upstairs, 2 for downstairs):\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("As you climb the stairs, you hear creaking sounds. Suddenly, a chandelier falls from the ceiling!\n");
            printf("You narrowly dodge it and continue walking. You reach the top of the stairs and see two doors.\n");
            printf("The left door leads to the master bedroom, and the right door leads to the guest bedroom.\n");
            printf("Which door do you choose? (1 for left, 2 for right):\n");
            scanf("%d", &choice);

            if (choice == 1)
            {
                printf("As you enter the master bedroom, you see a figure standing in the corner of the room.\n");
                printf("It turns around and you see that it is a zombie! You quickly use the key to unlock the window and escape.\n");
                printf("Congratulations, you escaped the haunted house!\n");
            }
            else if (choice == 2)
            {
                printf("As you enter the guest bedroom, the door slams shut behind you.\n");
                printf("You try to open it, but it's locked. Suddenly, you hear a voice whispering, 'You will never leave this place.'\n");
                printf("You are trapped and cannot escape. Game over.\n");
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
            }
        }
        else if (choice == 2)
        {
            printf("As you descend the stairs, you see a figure standing in the hallway.\n");
            printf("It turns around and you see that it is a ghost! It disappears and the hallway turns pitch black.\n");
            printf("You try to feel your way around, but you cannot find the light switch. You are lost and cannot escape. Game over.\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }
    else
    {
        printf("You do not have the key to proceed. Game over.\n");
    }

    return 0;
}