//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pause(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

int main()
{
    int choice, level = 1, health = 100;
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n");
    
    do
    {
        printf("\nYou are now on level %d.\n", level);
        printf("Your health is %d.\n", health);
        printf("Choose your next move:\n");
        printf("1. Go forward\n");
        printf("2. Turn back\n");
        printf("3. Rest and recover\n");
        printf("4. Quit game\n");
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("You venture deeper into the haunted house...\n");
                pause(1000);
                
                if(rand() % 2 == 0)
                {
                    printf("You encounter a spooky ghost!\n");
                    pause(1000);
                    printf("You lose 20 health.\n");
                    health -= 20;
                    
                    if(health <= 0)
                    {
                        printf("Game over. You died.\n");
                        return 0;
                    }
                }
                else
                {
                    printf("You move forward safely.\n");
                    pause(1000);
                    
                    if(rand() % 2 == 0)
                    {
                        printf("You find a potion!\n");
                        pause(1000);
                        printf("You gain 20 health.\n");
                        health += 20;
                    }
                }
                
                level++;
                break;
                
            case 2:
                printf("You turn back and exit the haunted house.\n");
                level--;
                
                if(level == 0)
                {
                    printf("Thanks for playing!\n");
                    return 0;
                }
                
                break;
                
            case 3:
                printf("You rest and recover some health.\n");
                pause(1000);
                printf("You gain 10 health.\n");
                health += 10;
                
                if(health > 100)
                    health = 100;
                
                break;
                
            case 4:
                printf("Thanks for playing!\n");
                return 0;
                
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        
    } while(level <= 5);
    
    printf("Congratulations, you made it out of the haunted house alive!\n");
    
    return 0;
}