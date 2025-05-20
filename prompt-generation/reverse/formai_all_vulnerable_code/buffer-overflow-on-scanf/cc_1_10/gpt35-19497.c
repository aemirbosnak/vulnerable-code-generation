//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int room = 1, choice;
    char answer;

    printf("\nWelcome to the Cyberpunk Haunted House Simulator!\n\n");

    do
    {
        printf("You are standing in room %d\n", room);
        printf("Choose the door you want to go through (1, 2, or 3): ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("You enter a room filled with ghostly apparitions. You try to run, but you trip over a chair and fall.\n");
            printf("The ghosts close in around you, and you feel their icy cold breath on your neck...\n");
            printf("GAME OVER\n\n");
            break;
        }
        else if (choice == 2)
        {
            printf("You enter a room filled with neon lights and loud music. You see a group of people dancing, and they invite you to join them.\n");
            printf("You hesitate at first, but then decide to have some fun.\n");
            printf("One of the dancers hands you a pill, telling you it will make you feel better. Do you take it? (y/n): ");
            scanf(" %c", &answer);

            if (answer == 'y')
            {
                printf("You take the pill and start to feel a strange sensation in your body. You try to run, but your legs give out.\n");
                printf("The dancers start to laugh as they morph into demonic figures. You black out...\n");
                printf("GAME OVER\n\n");
                break;
            }
            else
            {
                printf("You decline the offer and continue to dance. You have a great time, and when you leave the room, you feel energized.\n");
                room++;
            }
        }
        else if (choice == 3)
        {
            printf("You enter a dark room with a single chair in the middle of the room.\n");
            printf("You approach the chair and sit down. Suddenly, the room lights up with neon colors.\n");
            printf("A voice speaks to you, offering you power beyond your wildest dreams. Do you accept? (y/n): ");
            scanf(" %c", &answer);

            if (answer == 'y')
            {
                printf("You accept the offer and feel a surge of energy. The room disappears, and you find yourself in the streets of the cyberpunk city.\n");
                printf("You have gained incredible power, but at what cost?\n");
                printf("CONGRATULATIONS, YOU WIN!\n\n");
                break;
            }
            else
            {
                printf("You decline the offer and leave the room. As you walk away, you hear the voice laughing.\n");
                room++;
            }
        }
        else
        {
            printf("Invalid choice, try again.\n");
        }
    } while (room <= 3);

    return 0;
}