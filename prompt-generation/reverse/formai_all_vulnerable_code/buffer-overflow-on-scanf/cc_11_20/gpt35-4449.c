//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[50];
    int age, score = 0;
    char choice;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s!\n", name);

    printf("How old are you?\n");
    scanf("%d", &age);
    if (age < 18)
    {
        printf("Sorry, but you must be atleast 18 years old to play this game!\n");
        return 0;
    }

    printf("Good luck on your adventure, %s!\n", name);

    printf("You find yourself in a dark cavern. You need to find your way out!\n");
    printf("You have three paths ahead of you: A, B, C\n");

    while (1)
    {
        printf("Which path do you choose? (A, B, or C)\n");
        scanf(" %c", &choice);

        if (choice == 'A')
        {
            printf("You chose path A.\n");
            printf("You encounter a dragon! What do you do?\n");
            printf("A) Fight the dragon\n");
            printf("B) Run away\n");
            scanf(" %c", &choice);

            if (choice == 'A')
            {
                printf("You fight the dragon, but unfortunately you are not skilled enough to win. You died.\n");
                printf("GAME OVER\n");
                break;
            }
            else if (choice == 'B')
            {
                printf("You run away from the dragon and find a key.\n");
                printf("You use the key to unlock a door and find a treasure chest. You gain 5 points!\n");
                score += 5;
            }
            else
            {
                printf("Invalid choice. Please choose either A or B.\n");
            }
        }
        else if (choice == 'B')
        {
            printf("You chose path B.\n");
            printf("You find an abandoned mine. You hear something in the distance.\n");
            printf("A) Investigate\n");
            printf("B) Leave the mine\n");
            scanf(" %c", &choice);

            if (choice == 'A')
            {
                printf("You investigate and find a rare gem. You gain 2 points!\n");
                score += 2;
            }
            else if (choice == 'B')
            {
                printf("You leave the mine and find a map. You gain 3 points!\n");
                score += 3;
            }
            else
            {
                printf("Invalid choice. Please choose either A or B.\n");
            }
        }
        else if (choice == 'C')
        {
            printf("You chose path C.\n");
            printf("You see a river. You need to cross it to continue.\n");
            printf("A) Swim across\n");
            printf("B) Build a raft\n");
            scanf(" %c", &choice);

            if (choice == 'A')
            {
                printf("You swim across the river and reach the other side safely. You gain 1 point!\n");
                score += 1;
            }
            else if (choice == 'B')
            {
                printf("You build a raft and successfully cross the river. You gain 2 points!\n");
                score += 2;
            }
            else
            {
                printf("Invalid choice. Please choose either A or B.\n");
            }
        }
        else
        {
            printf("Invalid choice. Please choose either A, B or C.\n");
        }

        printf("Your current score is: %d\n", score);
        printf("Do you want to continue playing? (Y/N)\n");
        scanf(" %c", &choice);

        if (choice == 'N')
        {
            printf("Thanks for playing, %s! Your final score is: %d\n", name, score);
            break;
        }
    }

    return 0;
}