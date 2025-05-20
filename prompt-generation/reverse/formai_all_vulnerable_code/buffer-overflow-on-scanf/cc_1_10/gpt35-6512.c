//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void intro();
void chapterOne();
void chapterTwo();
void chapterThree();
void gameOver();

// Main function
int main()
{
    intro();
    chapterOne();
    chapterTwo();
    chapterThree();
    gameOver();

    return 0;
}

// Function definitions
void intro()
{
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You wake up in a dark forest with no memory of how you got there.\n");
    printf("Your objective is to find your way out of the forest and discover what happened to you.\n");
}

void chapterOne()
{
    printf("As you begin to explore the forest, you come across a fork in the road.\n");
    printf("Do you choose path A or path B?\n");
    
    char path[10];
    scanf("%s", path);
    
    if (strcmp(path, "A") == 0)
    {
        printf("You continue down path A and come across a river.\n");
        printf("Do you attempt to cross the river (C) or follow it downstream (D)?\n");
        
        scanf("%s", path);
        
        if (strcmp(path, "C") == 0)
        {
            printf("You attempt to cross the river, but the strong current sweeps you away.\n");
            printf("GAME OVER");
            exit(0);
        }
        else if (strcmp(path, "D") == 0)
        {
            printf("You follow the river downstream and eventually come across a bridge.\n");
        }
        else
        {
            printf("Invalid input. Please enter C or D.\n");
            chapterOne();
        }
    }
    else if (strcmp(path, "B") == 0)
    {
        printf("You continue down path B and come across a clearing.\n");
        printf("Do you investigate the clearing (E) or continue down the path (F)?\n");
        
        scanf("%s", path);
        
        if (strcmp(path, "E") == 0)
        {
            printf("You investigate the clearing and find a chest buried under some leaves.\n");
            printf("Inside the chest, you find a map and a compass.\n");
        }
        else if (strcmp(path, "F") == 0)
        {
            printf("You continue down the path and come across a cliff.\n");
            printf("Do you attempt to climb down the cliff (G) or turn back (H)?\n");
            
            scanf("%s", path);
            
            if (strcmp(path, "G") == 0)
            {
                printf("You attempt to climb down the cliff, but lose your grip and fall to your death.\n");
                printf("GAME OVER");
                exit(0);
            }
            else if (strcmp(path, "H") == 0)
            {
                printf("You turn back and decide to investigate the clearing instead.\n");
                printf("You find a chest buried under some leaves.\n");
                printf("Inside the chest, you find a map and a compass.\n");
            }
            else
            {
                printf("Invalid input. Please enter G or H.\n");
                chapterOne();
            }
        }
        else
        {
            printf("Invalid input. Please enter E or F.\n");
            chapterOne();
        }
    }
    else
    {
        printf("Invalid input. Please enter A or B.\n");
        chapterOne();
    }
}

void chapterTwo()
{
    printf("After finding the map and compass, you use them to navigate your way through the forest.\n");
    printf("As you continue your journey, you hear a loud growling noise in the distance.\n");
    printf("Do you investigate the noise (I) or avoid it and continue on your way (J)?\n");
    
    char path[10];
    scanf("%s", path);
    
    if (strcmp(path, "I") == 0)
    {
        printf("You investigate the noise and come across a hungry bear.\n");
        printf("Do you run away (K) or attempt to fight the bear (L)?\n");
        
        scanf("%s", path);
        
        if (strcmp(path, "K") == 0)
        {
            printf("You try to run away, but the bear catches up to you and attacks.\n");
            printf("GAME OVER");
            exit(0);
        }
        else if (strcmp(path, "L") == 0)
        {
            printf("You attempt to fight the bear and manage to fend it off with a nearby branch.\n");
        }
        else
        {
            printf("Invalid input. Please enter K or L.\n");
            chapterTwo();
        }
    }
    else if (strcmp(path, "J") == 0)
    {
        printf("You avoid the noise and continue on your way, eventually coming across a small cottage.\n");
        printf("Do you investigate the cottage (M) or continue on your way (N)?\n");
        
        scanf("%s", path);
        
        if (strcmp(path, "M") == 0)
        {
            printf("You investigate the cottage and find an old woman inside.\n");
            printf("She offers you food and shelter for the night.\n");
        }
        else if (strcmp(path, "N") == 0)
        {
            printf("You decide to continue on your way and eventually come across a road.\n");
        }
        else
        {
            printf("Invalid input. Please enter M or N.\n");
            chapterTwo();
        }
    }
    else
    {
        printf("Invalid input. Please enter I or J.\n");
        chapterTwo();
    }
}

void chapterThree()
{
    printf("As you walk along the road, you suddenly remember who you are and how you ended up in the forest.\n");
    printf("You were on a plane headed to a business meeting when the plane crashed in the forest.\n");
    printf("With this realization, you now know where you need to go to be rescued.\n");
    printf("Do you go back through the forest to find the plane wreckage (O) or follow the road to civilization (P)?\n");
    
    char path[10];
    scanf("%s", path);
    
    if (strcmp(path, "O") == 0)
    {
        printf("You go back through the forest and eventually find the plane wreckage.\n");
        printf("You are able to contact rescue services and are rescued.\n");
        printf("Congratulations, you have won the game!");
    }
    else if (strcmp(path, "P") == 0)
    {
        printf("You follow the road and eventually come across a town.\n");
        printf("Do you go to the police station for help (Q) or seek help elsewhere (R)?\n");
        
        scanf("%s", path);
        
        if (strcmp(path, "Q") == 0)
        {
            printf("You go to the police station and are able to contact rescue services.\n");
            printf("You are rescued and taken to the hospital to recover.\n");
            printf("Congratulations, you have won the game!");
        }
        else if (strcmp(path, "R") == 0)
        {
            printf("You seek help elsewhere, but are unable to find anyone to help you.\n");
            printf("You end up getting lost and are never found.\n");
            printf("GAME OVER");
            exit(0);
        }
        else
        {
            printf("Invalid input. Please enter Q or R.\n");
            chapterThree();
        }
    }
    else
    {
        printf("Invalid input. Please enter O or P.\n");
        chapterThree();
    }
}

void gameOver()
{
    printf("\nThanks for playing the Text-Based Adventure Game!\n");
}