//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function declarations
void printIntro();
void startGame();
void forest();
void swamp();
void dungeon();
void finalBoss();

int main()
{
    //call the printIntro function to print the game intro
    printIntro();
    
    //call the startGame function to begin the game
    startGame();
    
    return 0;
}

void printIntro()
{
    printf("Welcome to the Adventure Game!\n\n");
    printf("You are about to embark on a thrilling journey that will take you through dangerous forests, treacherous swamps, and dark dungeons.\n");
    printf("Your goal is to defeat the final boss and save the kingdom from his evil clutches.\n\n");
    printf("Get ready to face your fears and make some tough choices...\n\n");
}

void startGame()
{
    char name[20];
    
    //ask the player for their name
    printf("What is your name, adventurer?\n");
    scanf("%s", name);
    printf("\nWelcome, %s! Let's begin...\n\n", name);
    
    //call the forest function to start the game
    forest();
}

void forest()
{
    int choice;
    
    printf("You find yourself in a dense forest.\n");
    printf("The air is thick with the sounds of rustling leaves and chirping birds.\n");
    printf("You see a path leading deeper into the forest, and a small river off to your left.\n");
    printf("What do you do?\n");
    printf("1. Follow the path\n");
    printf("2. Follow the river\n");
    printf("3. Go back\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("You follow the path deeper into the forest.\n");
            printf("The trees get thicker and the light gets dimmer.\n");
            printf("You hear strange noises ahead.\n");
            printf("What do you do?\n");
            printf("1. Investigate the noises\n");
            printf("2. Turn back\n");
            scanf("%d", &choice);
            
            if(choice == 1)
            {
                printf("You cautiously approach the source of the noises.\n");
                printf("Suddenly, a giant spider jumps out at you!\n");
                printf("You draw your sword and prepare for battle.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the dungeon function to continue the game
                dungeon();
            }
            else
            {
                printf("You decide to turn back and explore a different part of the forest.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the swamp function to continue the game
                swamp();
            }
            break;
            
        case 2:
            printf("You follow the river, enjoying the peaceful sound of the water.\n");
            printf("Suddenly, you hear a loud roar!\n");
            printf("You peek around a tree and see a huge bear.\n");
            printf("What do you do?\n");
            printf("1. Try to sneak past the bear\n");
            printf("2. Fight the bear\n");
            scanf("%d", &choice);
            
            if(choice == 1)
            {
                printf("You try to sneak past the bear, but he catches your scent and charges at you!\n");
                printf("You draw your sword and prepare for battle.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the dungeon function to continue the game
                dungeon();
            }
            else
            {
                printf("You draw your sword and run at the bear, ready to fight.\n");
                printf("The bear is no match for your strength and you defeat him easily.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the dungeon function to continue the game
                dungeon();
            }
            break;
            
        case 3:
            printf("You decide to turn back and explore a different part of the forest.\n");
            printf("Press any key to continue...\n");
            getchar();
            getchar();
            
            //call the swamp function to continue the game
            swamp();
            break;
            
        default:
            printf("Invalid choice. Please try again.\n");
            printf("Press any key to continue...\n");
            getchar();
            getchar();
            
            //call the forest function to continue the game
            forest();
            break;
    }
}

void swamp()
{
    int choice;
    
    printf("You enter a dense swamp.\n");
    printf("The air is thick with the smell of rotting vegetation.\n");
    printf("You see a path leading deeper into the swamp, and a small boat off to your right.\n");
    printf("What do you do?\n");
    printf("1. Follow the path\n");
    printf("2. Take the boat\n");
    printf("3. Go back\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("You follow the path deeper into the swamp.\n");
            printf("The ground becomes mushy and your feet sink in with each step.\n");
            printf("You hear strange noises ahead.\n");
            printf("What do you do?\n");
            printf("1. Investigate the noises\n");
            printf("2. Turn back\n");
            scanf("%d", &choice);
            
            if(choice == 1)
            {
                printf("You cautiously approach the source of the noises.\n");
                printf("Suddenly, a giant alligator jumps out at you!\n");
                printf("You draw your sword and prepare for battle.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the dungeon function to continue the game
                dungeon();
            }
            else
            {
                printf("You decide to turn back and explore a different part of the swamp.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the forest function to continue the game
                forest();
            }
            break;
            
        case 2:
            printf("You take the boat, paddling through the murky water.\n");
            printf("Suddenly, you hear a loud hissing sound!\n");
            printf("You look around and see a giant snake coiled up in a nearby tree.\n");
            printf("What do you do?\n");
            printf("1. Shoot the snake with an arrow\n");
            printf("2. Row away as fast as possible\n");
            scanf("%d", &choice);
            
            if(choice == 1)
            {
                printf("You shoot the snake with an arrow, but it dodges and charges at you!\n");
                printf("You draw your sword and prepare for battle.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the dungeon function to continue the game
                dungeon();
            }
            else
            {
                printf("You row away as fast as possible, narrowly avoiding the snake's attack.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the dungeon function to continue the game
                dungeon();
            }
            break;
            
        case 3:
            printf("You decide to turn back and explore a different part of the swamp.\n");
            printf("Press any key to continue...\n");
            getchar();
            getchar();
            
            //call the forest function to continue the game
            forest();
            break;
            
        default:
            printf("Invalid choice. Please try again.\n");
            printf("Press any key to continue...\n");
            getchar();
            getchar();
            
            //call the swamp function to continue the game
            swamp();
            break;
    }
}

void dungeon()
{
    int choice;
    
    printf("You enter a dark dungeon.\n");
    printf("The air is cold and musty.\n");
    printf("You see a hallway leading deeper into the dungeon, and a staircase going up.\n");
    printf("What do you do?\n");
    printf("1. Follow the hallway\n");
    printf("2. Go up the staircase\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("You follow the hallway deeper into the dungeon.\n");
            printf("You hear strange noises ahead.\n");
            printf("What do you do?\n");
            printf("1. Investigate the noises\n");
            printf("2. Turn back\n");
            scanf("%d", &choice);
            
            if(choice == 1)
            {
                printf("You cautiously approach the source of the noises.\n");
                printf("Suddenly, a group of goblins ambushes you!\n");
                printf("You draw your sword and prepare for battle.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the finalBoss function to continue the game
                finalBoss();
            }
            else
            {
                printf("You decide to turn back and explore a different part of the dungeon.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the swamp function to continue the game
                swamp();
            }
            break;
            
        case 2:
            printf("You go up the staircase and find yourself in a large chamber.\n");
            printf("There is a treasure chest in the center of the room.\n");
            printf("What do you do?\n");
            printf("1. Open the treasure chest\n");
            printf("2. Leave the treasure chest alone\n");
            scanf("%d", &choice);
            
            if(choice == 1)
            {
                printf("You open the treasure chest and find a rare magic amulet!\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the finalBoss function to continue the game
                finalBoss();
            }
            else
            {
                printf("You decide to leave the treasure chest alone and explore a different part of the dungeon.\n");
                printf("Press any key to continue...\n");
                getchar();
                getchar();
                
                //call the finalBoss function to continue the game
                finalBoss();
            }
            break;
            
        default:
            printf("Invalid choice. Please try again.\n");
            printf("Press any key to continue...\n");
            getchar();
            getchar();
            
            //call the dungeon function to continue the game
            dungeon();
            break;
    }
}

void finalBoss()
{
    int choice;
    
    printf("You find yourself face to face with the final boss.\n");
    printf("The evil sorcerer, Zoltar, raises his staff and charges at you!\n");
    printf("What do you do?\n");
    printf("1. Fight Zoltar with your sword\n");
    printf("2. Use the magic amulet to defeat Zoltar\n");
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        printf("You charge at Zoltar with your sword, but he deflects your blows with magic spells.\n");
        printf("You are no match for his dark powers and he defeats you easily.\n");
        printf("Game Over.\n");
    }
    else
    {
        printf("You use the magic amulet to channel powerful magic spells at Zoltar.\n");
        printf("Zoltar is overwhelmed by your powers and falls to the ground defeated.\n");
        printf("Congratulations! You have saved the kingdom from his evil clutches.\n");
        printf("Press any key to exit the game...\n");
        getchar();
        getchar();
        
        //exit the game with no errors
        exit(0);
    }
}