//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int travel(char, int);
void battle(int, int);
void shop(int*);
void print_status(char, int, int, int, int);

// Main function
int main()
{
    char planet = 'A';
    int health = 100;
    int credits = 1000;
    int fuel = 5;
    int energy = 5;
    int choice;
    
    printf("Welcome to Procedural Space Adventure!\n");
    
    do
    {
        printf("You are currently on planet %c\n", planet);
        printf("What would you like to do?\n");
        printf("1. Travel\n2. Battle\n3. Visit Shop\n4. Check Status\n5. Quit\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                fuel--;
                if(fuel < 0)
                {
                    printf("You do not have enough fuel to travel!\n");
                    fuel = 0;
                }
                else
                {
                    printf("Where would you like to travel?\n");
                    printf("A. Planet B\nB. Planet C\nC. Planet D\n");
                    getchar();
                    planet = getchar();
                    credits += travel(planet, fuel);
                }
                break;
            case 2:
                energy--;
                if(energy < 0)
                {
                    printf("You do not have enough energy to battle!\n");
                    energy = 0;
                }
                else
                {
                    battle(health, energy);
                }
                break;
            case 3:
                shop(&credits);
                break;
            case 4:
                print_status(planet, health, credits, fuel, energy);
                break;
            case 5:
                printf("Thanks for playing Procedural Space Adventure!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
        
    } while(choice != 5);
    
    return 0;
}

// Function definitions

int travel(char planet, int fuel)
{
    int credits = 0;
    
    switch(planet)
    {
        case 'A':
            credits += 500;
            break;
        case 'B':
            credits += 1000;
            break;
        case 'C':
            credits += 1500;
            break;
        case 'D':
            credits += 2000;
            break;
        default:
            printf("Invalid planet choice. Try again.\n");
            break;
    }
    
    if(fuel == 0)
    {
        printf("You have run out of fuel! You are now stranded on planet %c.\n", planet);
    }
    else if(fuel < 3)
    {
        printf("Low on fuel! Better refuel soon.\n");
    }
    
    return credits;
}

void battle(int health, int energy)
{
    int enemy_health = 100;
    int damage;
    
    while(enemy_health > 0 && health > 0)
    {
        printf("You have %d health and %d energy.\n", health, energy);
        printf("The enemy has %d health.\n", enemy_health);
        printf("What would you like to do?\n");
        printf("1. Attack\n2. Defend\n");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                damage = rand() % 51 + 50;
                printf("You attacked for %d damage!\n", damage);
                enemy_health -= damage;
                break;
            case 2:
                damage = rand() % 11 + 10;
                printf("You defended and took %d damage.\n", damage);
                health -= damage;
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        
        if(enemy_health <= 0)
        {
            printf("You won the battle!\n");
            health += 20;
            energy += 10;
        }
        else
        {
            damage = rand() % 21 + 30;
            printf("The enemy attacked for %d damage.\n", damage);
            health -= damage;
            energy += 5;
        }
        
        if(health <= 0)
        {
            printf("You lost the battle and died.\n");
            exit(0);
        }
    }
}

void shop(int* credits)
{
    printf("Welcome to the shop! What would you like to buy?\n");
    printf("1. Fuel (200 credits)\n2. Health Pack (100 credits)\n3. Energy Drink (50 credits)\n4. Exit Shop\n");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            *credits -= 200;
            printf("Thanks for your purchase! You now have 5 units of fuel.\n");
            break;
        case 2:
            *credits -= 100;
            printf("Thanks for your purchase! Your health has been restored.\n");
            break;
        case 3:
            *credits -= 50;
            printf("Thanks for your purchase! You now have 5 units of energy.\n");
            break;
        case 4:
            printf("Thanks for visiting the shop!\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}

void print_status(char planet, int health, int credits, int fuel, int energy)
{
    printf("Planet: %c\n", planet);
    printf("Health: %d\n", health);
    printf("Credits: %d\n", credits);
    printf("Fuel: %d\n", fuel);
    printf("Energy: %d\n", energy);
}