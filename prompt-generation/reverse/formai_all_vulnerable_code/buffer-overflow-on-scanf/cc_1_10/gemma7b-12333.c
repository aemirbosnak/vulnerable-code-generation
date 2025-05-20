//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    int choice, score = 0, lives = 3;
    char name[20];

    printf("Hello, and welcome to the Amazing Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    // Loop until the player wins or loses
    while (lives > 0)
    {
        // Display the available options
        printf("What would you like to do? (1) Attack, (2) Defend, (3) Use Item\n");

        // Get the player's choice
        scanf("%d", &choice);

        // Check if the player's choice is valid
        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Implement the game logic based on the player's choice
        switch (choice)
        {
            case 1:
                printf("You attacked the enemy. You gained 5 points.\n");
                score += 5;
                break;
            case 2:
                printf("You defended against the enemy. You avoided damage.\n");
                break;
            case 3:
                printf("You used an item to gain strength. You have 2 extra lives.\n");
                lives++;
                break;
        }

        // Check if the player has won or lost
        if (score >= 100)
        {
            printf("Congratulations, %s! You have won the game!\n", name);
            break;
        }
        else if (lives == 0)
        {
            printf("Sorry, %s. You have lost the game.\n", name);
            break;
        }
    }

    // Print the final score
    printf("Your final score is: %d\n", score);
}

int main()
{
    play_game();

    return 0;
}