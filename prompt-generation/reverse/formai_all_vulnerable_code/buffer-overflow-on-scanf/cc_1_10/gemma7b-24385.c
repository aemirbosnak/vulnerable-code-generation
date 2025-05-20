//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost Ghost;
struct Ghost {
    char name[20];
    int room_num;
    int health;
    int attack_power;
};

Ghost ghouls[MAX_GHOULS] = {
    {"Mr. Freddy", 1, 100, 20},
    {"Miss Emily", 2, 80, 15},
    {"The Phantom", 3, 60, 10},
    {"The Blood Countess", 4, 40, 5},
    {"The Babbling Ghost", 5, 20, 2}
};

void start_haunted_house(void)
{
    int i, j, choice, rand_num, attack_power, health;
    char name[20];

    system("clear");

    printf("Welcome to the Haunted House of Doom!\n");
    printf("------------------------\n");

    // Get the player's name
    printf("What is your name? ");
    scanf("%s", name);

    // Create a loop to simulate the haunted house
    for (i = 0; i < MAX_GHOULS; i++)
    {
        // Get a random number between 1 and 5
        rand_num = rand() % 5 + 1;

        // Check if the ghoul is in the room
        if (ghouls[i].room_num == rand_num)
        {
            // Attack the player
            attack_power = ghouls[i].attack_power;
            health = ghouls[i].health;

            printf("Suddenly, %s appears! Prepare for battle!\n", ghouls[i].name);

            // Fight the ghoul
            printf("Enter 1 to attack, 2 to defend: ");
            scanf("%d", &choice);

            // Check if the player won or lost
            if (choice == 1)
            {
                if (attack_power - health > 0)
                {
                    printf("You have defeated %s!\n", ghouls[i].name);
                }
                else
                {
                    printf("You have slain %s!\n", ghouls[i].name);
                }
            }
            else
            {
                printf("You have been defeated by %s!\n", ghouls[i].name);
            }
        }
    }

    // End the game
    printf("Thank you for playing the Haunted House of Doom! Goodbye!\n");
}

int main()
{
    start_haunted_house();

    return 0;
}