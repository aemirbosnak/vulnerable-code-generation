//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int main()
{
    int choice, rand_num;
    char name[20];
    
    printf("Welcome adventurer! What is your name?\n");
    scanf("%s", name);
    printf("Hello %s, are you ready to embark on a journey?\n", name);
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        printf("Excellent! Let's get started.\n");
        delay(2);
        printf("You find yourself in a dark and spooky forest. You hear strange noises all around you.\n");
        delay(3);
        printf("1. Look for a path out of the forest\n");
        printf("2. Stay put and hope for the best\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("You stumble upon an old map that shows a path leading out of the forest.\n");
            delay(3);
            printf("You follow the path and eventually reach a clearing with three doors.\n");
            printf("Above each door is a symbol - a heart, a skull, and a crown.\n");
            printf("1. Enter the door with the heart symbol\n");
            printf("2. Enter the door with the skull symbol\n");
            printf("3. Enter the door with the crown symbol\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            
            srand(time(0));
            rand_num = rand() % 3 + 1; //generate a random number between 1 and 3
            
            if(choice == rand_num)
            {
                printf("Congratulations! You have found the treasure and won the game!\n");
            }
            else
            {
                printf("Oh no! You opened the wrong door and fell into a pit trap. You lose.\n");
            }
        }
        else
        {
            printf("You wait for what seems like hours, but nothing happens.\n");
            delay(3);
            printf("Eventually you realize that you are stuck in the forest forever.\n");
            printf("Game Over.\n");
        }
    }
    else
    {
        printf("That's too bad. Maybe another time. Goodbye!\n");
    }
    
    return 0;
}