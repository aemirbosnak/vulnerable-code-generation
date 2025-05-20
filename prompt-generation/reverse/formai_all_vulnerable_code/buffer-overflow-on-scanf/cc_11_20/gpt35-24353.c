//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL)); 
    int flashlight = rand() % 2; 

    char name[20]; 
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\nWelcome, %s, to the Haunted House Simulator!\n", name);
    printf("You find yourself standing in front of an old, decrepit house. The windows are boarded up, and the doors creak ominously in the wind. Do you dare enter the house? (Y/N): ");
    
    char input[2];
    scanf("%s", input);

    if(input[0] == 'Y' || input[0] == 'y')
    {
        printf("\nYou cautiously make your way inside the house. The air is thick and musty, and you can hear strange whispers and creaks all around you.\n");
        printf("You notice a flashlight on the ground and pick it up. You turn it on to illuminate the darkness but the batteries are low!\n");
        if(flashlight == 0)
        {
            printf("The flashlight dies and you are plunged into complete darkness...\n");
            printf("GAME OVER.\n\n");
            return 0;
        }
        else
        {
            printf("The flashlight flickers to life, and you can see better now. You realize that this house is not what it seems, and you need to find your way out before it's too late.\n");
            printf("You hear a strange noise coming from upstairs. Do you investigate? (Y/N): ");
            
            char input2[2];
            scanf("%s", input2);

            if(input2[0] == 'Y' || input2[0] == 'y')
            {
                printf("\nYou slowly make your way up the stairs, the creaking wood echoing with every step. You come to a hallway, with doors on either side.\n");
                printf("Do you choose to investigate the left room? (Y/N): ");
                
                char input3[2];
                scanf("%s", input3);

                if(input3[0] == 'Y' || input3[0] == 'y')
                {
                    printf("\nYou open the door and see nothing but darkness. You cautiously step inside, and suddenly feel a cold breeze on the back of your neck.\n");
                    printf("You quickly turn around, but the door is gone, replaced by a solid wall. You're trapped!\n");
                    printf("GAME OVER.\n\n");
                    return 0;
                }
                else
                {
                    printf("\nYou cautiously open the door on the right and find a dusty old library. The books are all covered in cobwebs, and you can tell nobody has been here for years.\n");
                    printf("As you start to leave, you notice a book sticking out from the shelf. Do you investigate? (Y/N): ");
                    
                    char input4[2];
                    scanf("%s", input4);

                    if(input4[0] == 'Y' || input4[0] == 'y')
                    {
                        printf("\nYou pull the book out, and hear a loud click. Suddenly, the bookshelf swings open, revealing a secret room.\n");
                        printf("You cautiously step inside, and see a glowing object in front of you. As you approach, you realize that it's a mystical orb.\n");
                        printf("Do you take the orb with you? (Y/N): ");

                        char input5[2];
                        scanf("%s", input5);

                        if(input5[0] == 'Y' || input5[0] == 'y')
                        {
                            printf("\nYou take the orb with you, and suddenly feel a rush of energy. You can tell that the orb is powerful beyond your wildest dreams.\n");
                            printf("As you make your way out of the haunted house, you feel a sense of satisfaction. You have completed your mission, and have something to show for it.\n");
                            printf("CONGRATULATIONS, %s! YOU HAVE ESCAPED THE HAUNTED HOUSE!\n\n", name);
                            return 0;
                        }
                        else
                        {
                            printf("\nYou leave the orb behind, and make your way back to the entrance. As you exit the haunted house, you hear a voice whispering.. 'you almost had it.'\n");
                            printf("GAME OVER.\n\n");
                            return 0;
                        }
                    }
                    else
                    {
                        printf("\nYou decide not to investigate the book any further and leave the library. As you exit the haunted house, you feel like you've missed something important.\n");
                        printf("GAME OVER.\n\n");
                        return 0;
                    }
                }
            }
            else
            {
                printf("\nYou decide not to investigate the noise. As you exit the haunted house, you realize that you're being followed.\n");
                printf("Before you can turn around, you feel a cold hand on your shoulder. You turn around, but there's nobody there...\n");
                printf("GAME OVER.\n\n");
                return 0;
            }
        }
    }
    else
    {
        printf("\nYou decide not to enter the house. As you turn to leave, you realize that the door has been locked behind you.\n");
        printf("In a panic, you start to run, but each turn leads you deeper and deeper into the haunted house.\n");
        printf("GAME OVER.\n\n");
        return 0;
    }
}