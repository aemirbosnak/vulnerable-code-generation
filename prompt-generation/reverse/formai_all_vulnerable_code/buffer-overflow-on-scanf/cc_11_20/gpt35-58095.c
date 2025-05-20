//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to generate a random integer within a given range
int randInRange(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main()
{
    char playerName[20];
    int roomNum = 1;
    bool hasKey = false;
    bool hasFlashlight = false;
    bool isAlive = true;

    srand(time(NULL)); // seed random number generator

    printf("Welcome to Romeo and Juliet's Haunted House Simulator!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);

    printf("\n%s, you find yourself standing in front of a spooky old house.\n", playerName);
    printf("You have heard rumors that this house is haunted by the ghosts of Romeo and Juliet,\n");
    printf("who died tragically in a lovers' suicide in this very house.\n");
    printf("Do you dare to enter the haunted house and solve its mysteries?\n\n");

    while (isAlive && roomNum <= 5)
    {
        switch (roomNum)
        {
        case 1: // foyer
            printf("You enter the foyer of the haunted house.\n");
            printf("There are two doors in front of you, one to the left and one to the right.\n");
            printf("Which door do you choose? (1 for left, 2 for right): ");
            int doorChoice;
            scanf("%d", &doorChoice);

            if (doorChoice == 1)
            {
                printf("You enter the left door and find a grand piano.\n");
                printf("As you gaze upon the piano, you hear faint music start to play.\n");
                printf("The music gets louder and louder, until it's almost deafening.\n");
                printf("Suddenly, you feel a cold hand on your shoulder.\n");
                printf("You turn around quickly, but there is no one there.\n");
                printf("Feeling spooked, you quickly exit the room.\n\n");
            }
            else if (doorChoice == 2)
            {
                printf("You enter the right door and find a dusty old bookshelf.\n");
                printf("As you browse through the books, you come across a key.\n");
                printf("Do you take the key? (1 for yes, 2 for no): ");
                int keyChoice;
                scanf("%d", &keyChoice);

                if (keyChoice == 1)
                {
                    printf("You take the key and continue exploring the haunted house.\n\n");
                    hasKey = true;
                }
                else
                {
                    printf("You leave the key behind and continue exploring the haunted house.\n\n");
                }
            }

            roomNum++;
            break;

        case 2: // living room
            printf("You enter the living room of the haunted house.\n");
            printf("There is a fireplace in the center of the room.\n");
            printf("You notice a strange symbol etched into the mantel of the fireplace.\n");
            printf("Do you investigate the symbol? (1 for yes, 2 for no): ");
            int symbolChoice;
            scanf("%d", &symbolChoice);

            if (symbolChoice == 1)
            {
                printf("You investigate the symbol and find a secret compartment in the fireplace.\n");
                printf("Inside the compartment, you find a flashlight.\n");
                printf("Do you take the flashlight? (1 for yes, 2 for no): ");
                int flashlightChoice;
                scanf("%d", &flashlightChoice);

                if (flashlightChoice == 1)
                {
                    printf("You take the flashlight and continue exploring the haunted house.\n\n");
                    hasFlashlight = true;
                }
                else
                {
                    printf("You leave the flashlight behind and continue exploring the haunted house.\n\n");
                }
            }
            else
            {
                printf("You decide not to investigate the symbol and continue exploring the haunted house.\n\n");
            }

            roomNum++;
            break;

        case 3: // kitchen
            printf("You enter the kitchen of the haunted house.\n");
            printf("There is a table set for two in the center of the room.\n");
            printf("As you walk past the table, you hear faint whispers.\n");
            printf("You turn around quickly, but there is no one there.\n");
            printf("Feeling uneasy, you quickly exit the room.\n\n");

            roomNum++;
            break;

        case 4: // bedroom
            printf("You enter the bedroom of the haunted house.\n");
            printf("There is a large four-poster bed in the center of the room.\n");
            printf("As you approach the bed, you hear the sound of someone crying.\n");
            printf("You look under the bed and find a ghostly figure of Romeo and Juliet.\n");
            printf("They ask you to solve a riddle in order to unlock the secret passage to escape the haunted house.\n");

            int riddleNum = randInRange(1, 3);

            switch (riddleNum)
            {
            case 1:
                printf("Romeo and Juliet's riddle: What starts with an E, ends with an E, but contains only one letter?\n");
                printf("Your answer: ");
                char answer1[20];
                scanf("%s", answer1);

                if (strcmp(answer1, "envelope") == 0)
                {
                    printf("Romeo and Juliet's ghostly figure nods their approval and the secret passage opens.\n");
                    printf("You successfully escape the haunted house!\n\n");
                    isAlive = false;
                }
                else
                {
                    printf("Romeo and Juliet's ghostly figure shakes their head and the riddle resets.\n\n");
                }

                break;

            case 2:
                printf("Romeo and Juliet's riddle: What has a head and a tail, but no body?\n");
                printf("Your answer: ");
                char answer2[20];
                scanf("%s", answer2);

                if (strcmp(answer2, "coin") == 0)
                {
                    printf("Romeo and Juliet's ghostly figure nods their approval and the secret passage opens.\n");
                    printf("You successfully escape the haunted house!\n\n");
                    isAlive = false;
                }
                else
                {
                    printf("Romeo and Juliet's ghostly figure shakes their head and the riddle resets.\n\n");
                }

                break;

            case 3:
                printf("Romeo and Juliet's riddle: I am not alive, but I grow; I don't have lungs, but I need air; I don't have a mouth, but water kills me. What am I?\n");
                printf("Your answer: ");
                char answer3[20];
                scanf("%s", answer3);

                if (strcmp(answer3, "fire") == 0)
                {
                    printf("Romeo and Juliet's ghostly figure nods their approval and the secret passage opens.\n");
                    printf("You successfully escape the haunted house!\n\n");
                    isAlive = false;
                }
                else
                {
                    printf("Romeo and Juliet's ghostly figure shakes their head and the riddle resets.\n\n");
                }

                break;
            }

            roomNum++;
            break;

        case 5: // secret passage
            if (hasKey && hasFlashlight)
            {
                printf("You use the key to unlock the secret passage and enter.\n");
                printf("You use the flashlight to light your way through the dark passage.\n");
                printf("You eventually find your way back outside the haunted house.\n");
                printf("You turn around to look at the haunted house, but it has vanished without a trace.\n");
                printf("You breathe a sigh of relief and head home.\n");
            }
            else if (hasKey)
            {
                printf("You use the key to unlock the secret passage and enter.\n");
                printf("Unfortunately, you don't have a flashlight to light your way, and the passage is too dark to navigate.\n");
                printf("Feeling lost and afraid, you scream out for help, but no one answers.\n");
                printf("You wander aimlessly through the dark passage, eventually succumbing to the ghosts' malevolent intentions.\n");
                printf("You died in the haunted house.\n");
                isAlive = false;
            }
            else
            {
                printf("You try to enter the secret passage, but it is locked.\n");
                printf("Feeling defeated, you turn around to exit the haunted house.\n");
                printf("As you walk towards the exit, you hear the sound of a hauntingly beautiful voice singing a love ballad.\n");
                printf("You turn around to investigate, but you are suddenly overwhelmed with a feeling of despair.\n");
                printf("You died in the haunted house.\n");
                isAlive = false;
            }

            roomNum++;
            break;
        }
    }

    printf("Thanks for playing Romeo and Juliet's Haunted House Simulator, %s!\n", playerName);

    return 0;
}