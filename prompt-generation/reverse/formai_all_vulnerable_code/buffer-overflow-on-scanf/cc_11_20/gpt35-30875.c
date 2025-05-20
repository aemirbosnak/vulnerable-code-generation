//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of an old, decrepit mansion.\n");
    printf("As you step through the entrance, the door slams shut behind you.\n");
    printf("You are now trapped inside the Haunted House...\n\n");
    
    int room = 1; // Start in room 1
    int has_key = 0; // Player does not have key
    
    while(room != 0) // Loop until player exits
    {
        printf("You are in room %d\n", room);
        
        switch(room)
        {
            case 1: // Foyer
                printf("You see a dusty coat rack and an old umbrella.\n");
                printf("You notice a key on the floor.\n");
                printf("What would you like to do?\n");
                printf("1: Pick up the key\n");
                printf("2: Leave it and move to the next room\n");
                int choice;
                scanf("%d", &choice);
                
                if(choice == 1)
                {
                    printf("You pick up the key.\n");
                    has_key = 1;
                }
                
                printf("\n");
                room = 2;
                break;
                
            case 2: // Kitchen
                printf("You are in a large kitchen.\n");
                printf("You hear a loud thud coming from the pantry.\n");
                
                if(has_key == 1)
                {
                    printf("You use the key to unlock the pantry door.\n");
                    printf("Inside, you find a glowing red gem.\n");
                    printf("What would you like to do?\n");
                    printf("1: Take the gem\n");
                    printf("2: Leave it and move to the next room\n");
                    scanf("%d", &choice);
                    
                    if(choice == 1)
                    {
                        printf("You take the gem and feel a strange power surge through you.\n");
                    }
                }
                else
                {
                    printf("You try to open the pantry door, but it is locked.\n");
                }
                
                printf("\n");
                room = 3;
                break;
                
            case 3: // Living room
                printf("You enter a dimly lit living room.\n");
                printf("There is a creepy clown doll sitting on the sofa.\n");
                printf("What would you like to do?\n");
                printf("1: Approach the clown doll\n");
                printf("2: Ignore it and move to the next room\n");
                scanf("%d", &choice);
                
                if(choice == 1)
                {
                    printf("As you approach the doll, its eyes begin to glow red.\n");
                    printf("You hear a cackling laugh and suddenly the doll lunges at you!\n");
                    printf("You stumble backwards and fall through a secret door behind the sofa.\n");
                    room = 4;
                }
                else
                {
                    printf("You move on to the next room.\n");
                    printf("\n");
                    room = 5;
                }
                break;
                
            case 4: // Secret room
                printf("You stand up and dust yourself off.\n");
                printf("You appear to be in a secret room.\n");
                printf("There is a book on a pedestal in the center of the room.\n");
                printf("What would you like to do?\n");
                printf("1: Approach the book\n");
                printf("2: Leave the room\n");
                scanf("%d", &choice);
                
                if(choice == 1)
                {
                    printf("You open the book and read the ancient text.\n");
                    printf("Suddenly, a bright light envelops you and you feel yourself being transported...\n");
                    room = 0;
                }
                else
                {
                    printf("You leave the room and continue exploring.\n");
                    printf("\n");
                    room = 5;
                }
                break;
                
            case 5: // Bedroom
                printf("You enter a dusty bedroom.\n");
                printf("There is a large queen-sized bed in the center of the room.\n");
                printf("What would you like to do?\n");
                printf("1: Approach the bed\n");
                printf("2: Look under the bed\n");
                scanf("%d", &choice);
                
                if(choice == 1)
                {
                    printf("As you approach the bed, you feel a cold breeze behind you.\n");
                    printf("You turn around and see a ghostly figure standing behind you!\n");
                    printf("You try to run, but the ghostly figure blocks the door.\n");
                    printf("You are trapped!\n");
                    room = 0;
                }
                else
                {
                    printf("You look under the bed and find a small box.\n");
                    printf("Do you want to open the box?\n");
                    printf("1: Yes\n");
                    printf("2: No\n");
                    scanf("%d", &choice);
                    
                    if(choice == 1)
                    {
                        printf("You open the box and find a piece of paper.\n");
                        printf("It reads, 'The key to your escape is hidden in the foyer.'\n");
                    }
                    
                    printf("\n");
                    room = 6;
                }
                break;
                
            case 6: // Attic
                printf("You climb a creaky ladder up to the dark attic.\n");
                printf("There is a locked chest in the corner of the room.\n");
                printf("What would you like to do?\n");
                printf("1: Break open the chest\n");
                printf("2: Use the key you found in the foyer to open the chest\n");
                printf("3: Leave the chest and move on\n");
                scanf("%d", &choice);
                
                if(choice == 1)
                {
                    printf("You try to smash the chest open, but hurt your hand in the process.\n");
                    printf("You realize that brute force won't work.\n");
                }
                else if(choice == 2)
                {
                    if(has_key == 1)
                    {
                        printf("You use the key to open the chest and find a map.\n");
                        printf("The map shows the way to the hidden exit.\n");
                    }
                    else
                    {
                        printf("You try to use the key to open the chest, but you don't have a key!\n");
                    }
                }
                
                printf("\n");
                room = 0; // Exit the game
                break;
                
            default:
                printf("You seem to be lost... you wander for what seems like hours...\n");
                printf("Suddenly, a bright light envelops you and you feel yourself being transported...\n");
                room = 0;
                break;
        }
    }
    
    printf("You have escaped the Haunted House! Congratulations!\n");
    printf("Thanks for playing!\n");
    
    return 0;
}