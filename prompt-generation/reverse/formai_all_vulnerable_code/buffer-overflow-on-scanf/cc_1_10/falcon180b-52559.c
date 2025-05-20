//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function Prototypes
void init();
void play();
void end();

int main()
{
    init();
    play();
    end();

    return 0;
}

void init()
{
    srand(time(NULL)); //Seed the random number generator
    printf("Welcome to the Space Adventure!\n");
    printf("Press any key to begin...\n");
    getchar();
}

void play()
{
    int choice;
    int health = 100; //Player's health
    int score = 0; //Player's score
    int level = 1; //Current level of the game

    while(health > 0) //Loop until player runs out of health
    {
        printf("You are on level %d\n", level);
        printf("Your health is %d\n", health);
        printf("Your score is %d\n", score);

        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //Attack
                printf("You attacked and gained 10 points!\n");
                score += 10;
                break;
            case 2: //Defend
                printf("You defended and lost 5 health points.\n");
                health -= 5;
                break;
            case 3: //Heal
                printf("You healed and gained 20 health points!\n");
                health += 20;
                break;
            case 4: //Quit
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if(health <= 0) //Player has run out of health
        {
            printf("Game Over! Your final score is %d.\n", score);
            break;
        }

        if(score >= level * 100) //Player has reached the required score for the level
        {
            level++; //Increase the level
            printf("Congratulations! You have advanced to level %d!\n", level);
        }
    }
}

void end()
{
    printf("Thanks for playing! Press any key to exit...\n");
    getchar();
}