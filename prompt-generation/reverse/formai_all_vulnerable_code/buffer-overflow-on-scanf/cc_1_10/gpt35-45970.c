//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void intro();
void forest(int *health, int *points, int *arrows);
void cave(int *health, int *points, int *arrows);
void monster(int *health, int *points, int *arrows);
void endgame(int *points);

int main()
{
    int health = 100, points = 0, arrows = 5; //player's initial stats
    intro(); //display the game intro
    forest(&health, &points, &arrows); //start the game in the forest
    endgame(&points); //display endgame results
    return 0;
}

void intro()
{
    printf("Welcome to The Adventure Game! In this game, you will navigate through a forest and a cave, facing various challenges along the way. You will need to make smart choices and be strategic in order to prevail. Good luck!\n\n");
}

void forest(int *health, int *points, int *arrows)
{
    char choice;
    printf("You find yourself in a dense forest. You can go 'left', 'right', or 'forward'. Which direction do you choose?\n");
    scanf(" %c", &choice);
    if(choice == 'l' || choice == 'L')
    {
        printf("You encounter a group of hostile tribal hunters. You have two options; 'run' or 'fight'. What do you do?\n");
        scanf(" %c", &choice);
        if(choice == 'r' || choice == 'R')
        {
            printf("You manage to run away and lose the tribal hunters.\n\n");
            forest(health, points, arrows); //recursive call to forest function
        }
        else if(choice == 'f' || choice == 'F')
        {
            monster(health, points ,arrows); //go to monster function
        }
        else
        {
            printf("Invalid choice! Try again.\n\n");
            forest(health, points, arrows); //recursive call to forest function
        }
    }
    else if(choice == 'r' || choice == 'R')
    {
        printf("You find a hidden treasure! You gain 5 points. You can go 'left', 'right', or 'forward'. Which direction do you choose?");
        *points += 5; //adds 5 points to the player's score
        scanf(" %c", &choice);
        if(choice == 'l' || choice == 'L' || choice == 'r' || choice == 'R' || choice == 'f' || choice == 'F')
        {
            printf("You continue on your journey.\n\n");
            forest(health, points, arrows); //recursive call to forest function
        }
        else
        {
            printf("Invalid choice! Try again.\n\n");
            forest(health, points, arrows); //recursive call to forest function
        }
    }
    else if(choice == 'f' || choice == 'F')
    {
        printf("You come across a river. You can 'swim' across or 'look' for a bridge. What do you want to do?");
        scanf(" %c", &choice);
        if(choice == 's' || choice == 'S')
        {
            *health -= 10; //subtracts 10 health from the player's stats
            printf("You struggle to swim across the river and lose 10 health.\n\n");
            forest(health, points, arrows); //recursive call to forest function
        }
        else if(choice == 'l' || choice == 'L' || choice == 'r' || choice == 'R')
        {
            printf("You continue on your journey.\n\n");
            forest(health, points, arrows); //recursive call to forest function
        }
        else
        {
            printf("Invalid choice! Try again.\n\n");
            forest(health, points, arrows); //recursive call to forest function
        }
    }
    else
    {
        printf("Invalid choice! Try again.\n\n");
        forest(health, points, arrows); //recursive call to forest function
    }
}

void cave(int *health, int *points, int *arrows)
{
    char choice;
    printf("You enter a dark and creepy cave. You can go 'left', 'right', or 'forward'. Which direction do you choose?\n");
    scanf(" %c", &choice);
    if(choice == 'l' || choice == 'L')
    {
        *arrows += 1; //gives the player one additional arrow
        printf("You find an old bow and arrow! You now have %d arrows. You can go 'left', 'right', or 'forward'. Which direction do you choose?", *arrows);
        scanf(" %c", &choice);
        if(choice == 'l' || choice == 'L' || choice == 'r' || choice == 'R' || choice == 'f' || choice == 'F')
        {
            printf("You continue on your journey.\n\n");
            cave(health, points, arrows); //recursive call to cave function
        }
        else
        {
            printf("Invalid choice! Try again.\n\n");
            cave(health, points, arrows); //recursive call to cave function
        }
    }
    else if(choice == 'r' || choice == 'R')
    {
        monster(health, points, arrows); //go to monster function
    }
    else if(choice == 'f' || choice == 'F')
    {
        printf("You stumble upon a hidden room filled with treasures! You gain 10 points and 3 arrows. You can 'take' the treasure or 'leave' it. What do you do?");
        scanf(" %c", &choice);
        if(choice == 't' || choice == 'T')
        {
            *points += 10; //adds 10 points to the player's score
            *arrows +=3; //gives the player three additional arrows
            printf("You take the treasure and continue on your journey.\n\n");
            cave(health, points, arrows); //recursive call to cave function
        }
        else if(choice == 'l' || choice == 'L')
        {
            printf("You continue on your journey.\n\n");
            cave(health, points, arrows); //recursive call to cave function
        }
        else
        {
            printf("Invalid choice! Try again.\n\n");
            cave(health, points, arrows); //recursive call to cave function
        }
    }
    else
    {
        printf("Invalid choice! Try again.\n\n");
        cave(health, points, arrows); //recursive call to cave function
    }
}

void monster(int *health, int *points, int *arrows)
{
    char choice;
    printf("You encounter a fierce monster!\n\nYou have three options; 'attack', 'defend', or 'run'. What do you do?\n");
    scanf(" %c", &choice);
    if(choice == 'r' || choice == 'R')
    {
        printf("You try to run away, but the monster catches you and you lose 20 health.\n\n");
        *health -= 20; //subtracts 20 health from the player's stats
        if(*health > 0)
        {
            forest(health, points, arrows); //recursive call to forest function
        }
        else
        {
            endgame(points); //go to endgame function
        }
    }
    else if(choice == 'a' || choice == 'A')
    {
        if(*arrows > 0)
        {
            printf("You use one of your arrows and manage to kill the monster!\n\n");
            *arrows -= 1; //subtracts one arrow from the player's stats
            (*points)++; //adds one point to the player's score
        }
        else
        {
            printf("You don't have any arrows left and the monster defeats you. You lose 30 health.\n\n");
            *health -= 30; //subtracts 30 health from the player's stats
        }
        if(*health > 0)
        {
            cave(health, points, arrows); //recursive call to cave function
        }
        else
        {
            endgame(points); //go to endgame function
        }
    }
    else if(choice == 'd' || choice == 'D')
    {
        printf("You defend yourself against the monster and manage to escape unscathed.\n\n");
        forest(health, points, arrows); //recursive call to forest function
    }
    else
    {
        printf("Invalid choice! Try again.\n\n");
        monster(health, points, arrows); //recursive call to monster function
    }
}

void endgame(int *points)
{
    if(*points >= 10)
    {
        printf("Congratulations! You have successfully completed The Adventure Game with %d points!\n\n", *points);
    }
    else
    {
        printf("Game Over. Better luck next time!\n\n");
    }
}