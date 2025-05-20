//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milli_seconds) 
{ 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

int main() 
{
    int input;
    char name[20];
    char pronoun[10];
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("What is your preferred pronoun (he, she, they)?\n");
    scanf("%s", pronoun);
    printf("\n");
    printf("Welcome, %s. You are the last survivor in a post-apocalyptic world, searching for shelter.\n", name);
    printf("You come across a seemingly abandoned house.\n");
    printf("As you approach the door, it creaks open on its own.\n");
    printf("Do you want to enter the house? Press 1 for yes or 2 for no.\n");
    scanf("%d", &input);
    printf("\n");
    
    if(input == 1)
    {
        printf("As you enter the house, you feel a chill down your spine.\n");
        printf("The door slams shut behind you. You are trapped.\n");
        printf("You look around and find yourself in a dimly lit hallway.\n");
        delay(2000);
        printf("Suddenly, you hear footsteps coming towards you.\n");
        printf("You turn to face the sound and see a ghostly figure.\n");
        printf("It whispers your name and beckons you to follow it.\n");
        printf("Do you want to follow the ghost? Press 1 for yes or 2 for no.\n");
        scanf("%d", &input);
        printf("\n");
        
        if(input == 1)
        {
            printf("You follow the ghost through a series of twisting corridors.\n");
            delay(2000);
            printf("The air grows colder and the walls appear to be closing in on you.\n");
            delay(2000);
            printf("Finally, you arrive at a grand staircase.\n");
            printf("The ghost floats up the stairs and disappears through a doorway.\n");
            delay(2000);
            printf("Do you want to go up the staircase? Press 1 for yes or 2 for no.\n");
            scanf("%d", &input);
            printf("\n");
            
            if(input == 1)
            {
                printf("You climb the staircase and find yourself in a large room.\n");
                printf("Cobwebs cover every surface and the room is filled with dust.\n");
                printf("You hear a noise coming from a nearby closet.\n");
                delay(2000);
                printf("Do you want to investigate? Press 1 for yes or 2 for no.\n");
                scanf("%d", &input);
                printf("\n");
                
                if(input == 1)
                {
                    printf("As you open the closet, you find a skeleton inside.\n");
                    printf("The skeleton animates and attacks you.\n");
                    delay(2000);
                    printf("You fight back to defend yourself.\n");
                    printf("A few minutes later, the skeleton explodes into dust.\n");
                    delay(2000);
                    printf("You notice a key on the ground where the skeleton was.\n");
                    printf("You pick it up and examine it.\n");
                    printf("It looks like it might fit in the locked door you saw earlier.\n");
                    delay(2000);
                    printf("You hear a noise coming from down the hallway.\n");
                    printf("Do you want to investigate? Press 1 for yes or 2 for no.\n");
                    scanf("%d", &input);
                    printf("\n");
                    
                    if(input == 1)
                    {
                        printf("You cautiously make your way down the hallway.\n");
                        delay(2000);
                        printf("You hear a growling sound and see a pair of glowing eyes.\n");
                        printf("A zombie attacks you.\n");
                        delay(2000);
                        printf("You manage to defeat the zombie but you are wounded.\n");
                        printf("You continue down the hallway and find the locked door.\n");
                        printf("You use the key to unlock it and enter the room.\n");
                        delay(2000);
                        printf("The room is empty except for a note on the desk.\n");
                        printf("The note reads \"Congratulations %s, you have survived the haunted house.\"\n", name);
                        printf("You smile with relief and head for the door.\n");
                        delay(2000);
                        printf("As you leave the house, you realize that you are no longer alone.\n");
                        printf("There are other survivors out there, and together, you might stand a chance.\n");
                        printf("You vow to keep searching for them, and for a new home.\n");
                        delay(2000);
                        printf("The end.\n");
                    }
                    else if(input == 2)
                    {
                        printf("You decide not to investigate and continue through the house.\n");
                        delay(2000);
                        printf("You hear a growling sound and see a pair of glowing eyes.\n");
                        printf("A zombie attacks you.\n");
                        delay(2000);
                        printf("You manage to defeat the zombie but you are wounded.\n");
                        printf("You continue through the house, hoping to find a way out.\n");
                        delay(2000);
                        printf("Unfortunately, you never make it out alive.\n");
                        printf("The end.\n");
                    }
                    else
                    {
                        printf("Invalid input. The game will now quit.\n");
                    }
                }
                else if(input == 2)
                {
                    printf("You decide not to investigate and continue through the house.\n");
                    delay(2000);
                    printf("You hear a growling sound and see a pair of glowing eyes.\n");
                    printf("A zombie attacks you.\n");
                    delay(2000);
                    printf("You manage to defeat the zombie but you are wounded.\n");
                    printf("You continue through the house, hoping to find a way out.\n");
                    delay(2000);
                    printf("Unfortunately, you never make it out alive.\n");
                    printf("The end.\n");
                }
                else
                {
                    printf("Invalid input. The game will now quit.\n");
                }
            }
            else if(input == 2)
            {
                printf("You decide not to go up the staircase and continue through the house.\n");
                delay(2000);
                printf("You hear a growling sound and see a pair of glowing eyes.\n");
                printf("A zombie attacks you.\n");
                delay(2000);
                printf("You manage to defeat the zombie but you are wounded.\n");
                printf("You continue through the house, hoping to find a way out.\n");
                delay(2000);
                printf("Unfortunately, you never make it out alive.\n");
                printf("The end.\n");
            }
            else
            {
                printf("Invalid input. The game will now quit.\n");
            }
        }
        else if(input == 2)
        {
            printf("You decide not to follow the ghost and continue through the house.\n");
            delay(2000);
            printf("You hear a growling sound and see a pair of glowing eyes.\n");
            printf("A zombie attacks you.\n");
            delay(2000);
            printf("You manage to defeat the zombie but you are wounded.\n");
            printf("You continue through the house, hoping to find a way out.\n");
            delay(2000);
            printf("Unfortunately, you never make it out alive.\n");
            printf("The end.\n");
        }
        else
        {
            printf("Invalid input. The game will now quit.\n");
        }
    }
    else if(input == 2)
    {
        printf("You decide not to enter the house and continue your search.\n");
        printf("You wander through the wasteland, hoping to find some sort of shelter.\n");
        delay(2000);
        printf("Unfortunately, you never find what you are looking for.\n");
        printf("The end.\n");
    }
    else
    {
        printf("Invalid input. The game will now quit.\n");
    }
    
    return 0;
}