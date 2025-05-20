//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int fuel = 1000; 
    int distance = 0;
    int health = 100;
    int enemyHealth = 100;
    int laser = 10;
    int enemyLaser = 5;
    int choice;
    
    srand(time(NULL));
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You wake up on your spaceship ready for a new mission.\n");
    printf("Your goal is to explore the Galaxy and collect valuable resources.\n\n");
    
    while(health > 0 && fuel > 0)
    {
        printf("Choose your next move: \n");
        printf("1. Travel to a new planet\n");
        printf("2. Explore the planet\n");
        printf("3. Attack enemy ship\n");
        printf("4. Refuel your spaceship\n");
        printf("5. Check status\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("You are travelling to a new planet...\n");
                distance += rand() % 150 + 50;
                fuel -= distance / 10;
                printf("You travelled %d km and have %d fuel remaining\n", distance, fuel);
                break;
                
            case 2:
                printf("You are exploring the planet...\n");
                printf("You found a rare resource and gained 100 points!\n");
                break;
                
            case 3:
                printf("You encounter an enemy ship!\n");
                while(health > 0 && enemyHealth > 0)
                {
                    printf("Choose your next move: \n");
                    printf("1. Attack enemy with laser\n");
                    printf("2. Dodge enemy laser\n");
                    scanf("%d", &choice);
                    
                    switch(choice)
                    {
                        case 1:
                            printf("You attacked the enemy ship with the laser!\n");
                            enemyHealth -= laser;
                            printf("Enemy Health: %d\n", enemyHealth);
                            break;
                            
                        case 2:
                            printf("You dodged the enemy laser!\n");
                            break;
                            
                        default:
                            printf("Invalid choice! Try again\n");
                            break;
                    }
                    
                    if(enemyHealth <= 0)
                    {
                        printf("You destroyed the enemy ship and gained 50 fuel!\n");
                        fuel += 50;
                        break;
                    }
                    printf("The enemy ship fires its laser at you!\n");
                    printf("You lost %d health.\n", enemyLaser);
                    health -= enemyLaser;
                    if(health <= 0)
                    {
                        printf("Your spaceship was destroyed. Game over!\n");
                        return 0;
                    }
                }
                break;
                
            case 4:
                printf("You refuel your spaceship\n");
                fuel += 500;
                printf("Fuel: %d\n", fuel);
                break;
                
            case 5:
                printf("Your status is:\n");
                printf("Health: %d\n", health);
                printf("Fuel: %d\n", fuel);
                printf("Distance travelled: %d km\n", distance);
                break;
                
            default:
                printf("Invalid choice! Try again\n");
                break;
        }
    }
    
    if(fuel <= 0)
    {
        printf("You ran out of fuel and stranded in the middle of space. Game over!\n");
    }
    
    return 0;
}