//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char play_again = 'y';
    
    srand(time(NULL)); // Seed the random number generator
    
    while (play_again == 'y')
    {
        printf("Welcome to the Haunted House Simulator!\n\n");
        
        printf("You find yourself at the front door of the haunted house. Do you dare to enter? (y/n): ");
        char enter_house;
        scanf(" %c", &enter_house);
        
        if (enter_house == 'y')
        {
            printf("You've entered the house, and the door has slammed shut behind you.\n\n");
            
            printf("You're in the foyer of the house. You see a staircase leading up to the second floor,\n");
            printf("and a hallway leading to what appears to be a dining room.\n");
            
            printf("Where would you like to go? (stairs/hallway): ");
            char first_choice[10];
            scanf(" %s", first_choice);
            
            if (strcmp(first_choice, "stairs") == 0)
            {
                printf("You climb the stairs to the second floor.\n\n");
                
                int random_room = rand() % 3; // Generate a random room number
                
                switch (random_room)
                {
                    case 0:
                        printf("You find yourself in a dusty old bedroom.\n");
                        printf("There's a creaky old dresser in the corner, and a bed with tattered sheets.\n");
                        break;
                        
                    case 1:
                        printf("You find yourself in a bathroom with peeling wallpaper and a broken mirror.\n");
                        printf("You hear a faint dripping sound coming from the bathtub.\n");
                        break;
                        
                    case 2:
                        printf("You find yourself in a children's playroom.\n");
                        printf("There's an old rocking horse in the corner, and a toy chest that appears to be moving slightly.\n");
                        break;
                }
            }
            else if (strcmp(first_choice, "hallway") == 0)
            {
                printf("You enter the dining room.\n\n");
                
                printf("In the center of the room, there's a large chandelier made of jagged bones.\n");
                printf("There are dusty old place settings on the table, as if dinner was interrupted.\n");
                
                printf("As you walk around the table, you hear a faint whispering sound coming from a nearby door.\n");
                printf("Do you investigate the sound? (y/n): ");
                char investigate_sound;
                scanf(" %c", &investigate_sound);
                
                if (investigate_sound == 'y')
                {
                    printf("You enter the room where the sound was coming from, and find a dusty old library.\n");
                    printf("The books on the shelves appear to be ancient tomes of forbidden knowledge.\n");
                    printf("As you're looking around, you hear a loud banging on the door behind you.\n");
                }
                else
                {
                    printf("You decide not to investigate the sound, and make your way back to the foyer.\n\n");
                }
            }
        }
        else
        {
            printf("You chicken out and run away from the house.\n\n");
        }
        
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);
    }
    
    printf("Thanks for playing! Don't get too scared...\n");
    
    return 0;
}