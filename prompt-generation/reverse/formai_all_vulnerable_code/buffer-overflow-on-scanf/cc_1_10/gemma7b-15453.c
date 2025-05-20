//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GORE 10

void play_haunted_house(void)
{
    int room_num, choice, gore = 0, is_dead = 0;
    char name[20];

    printf("Welcome to the Haunted Castle of Grimsborough!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("You have entered the cursed halls of Grimsborough. Choose a room: \n");
    printf("1. The Bloodstained Hall\n");
    printf("2. The Haunted Dining Hall\n");
    printf("3. The Twisted Tower\n");

    scanf("%d", &room_num);

    switch (room_num)
    {
        case 1:
            printf("You have entered the Bloodstained Hall. It is filled with the blood of innocent souls. Prepare for a gruesome encounter.\n");
            gore++;
            break;
        case 2:
            printf("You have entered the Haunted Dining Hall. The smell of decay and despair fills the air. Be cautious of the ghostly figures that roam its halls.\n");
            gore++;
            break;
        case 3:
            printf("You have entered the Twisted Tower. It is a labyrinth of horrors and madness. Prepare for a fight against the forces of evil.\n");
            gore++;
            break;
    }

    if (gore >= MAX_GORE)
    {
        printf("You have succumbed to the horrors of Grimsborough Castle. Game Over.\n");
        is_dead = 1;
    }

    if (is_dead == 0)
    {
        printf("You have survived the haunted halls of Grimsborough. Congratulations!\n");
    }

    return;
}

int main()
{
    play_haunted_house();

    return 0;
}