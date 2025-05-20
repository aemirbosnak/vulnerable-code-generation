//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max
int get_random(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}

int main()
{
    int num_rooms = 5;
    int current_room = 1;
    int ghost_room = get_random(1, num_rooms);
    int player_choices[num_rooms];
    
    printf("Welcome to the Haunted House Simulator!\n");
    
    while (current_room <= num_rooms)
    {
        // print current room and ghost status
        printf("You are in room %d.\n", current_room);
        if (current_room == ghost_room)
            printf("There is a ghost in this room!\n");
        
        // prompt player for their choice
        int choice;
        printf("What is your choice for this room? (0 = leave, 1 = stay)\n");
        scanf("%d", &choice);
        
        // store player's choice in array
        player_choices[current_room-1] = choice;
        
        // check if player has encountered the ghost
        if (current_room == ghost_room && choice == 1)
        {
            printf("Oh no! You encountered the ghost! Game over.\n");
            exit(0);
        }
        
        // move to the next room if player chooses to leave
        if (choice == 0)
        {
            current_room++;
        }
    }
    
    // calculate and display player's score
    int score = 0;
    for (int i = 0; i < num_rooms; i++)
    {
        score += player_choices[i];
    }
    printf("Congratulations, you made it through the haunted house with a score of %d!\n", score);
    
    return 0;
}