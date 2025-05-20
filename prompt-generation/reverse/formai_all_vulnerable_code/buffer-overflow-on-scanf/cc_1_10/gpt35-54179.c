//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printConspiracyTheory(void)
{
    // Generate random conspiracy theory
    int randomNum = rand() % 10;

    switch (randomNum)
    {
        case 0:
            printf("Did you know that all of our technology is actually developed by aliens in secret labs? It's true!\n");
            break;
        case 1:
            printf("Have you ever noticed that the government puts chemicals in our water that turn the frogs gay? It's part of their plan to control us!\n");
            break;
        case 2:
            printf("The world is flat! It's all a conspiracy by the government and NASA to keep us from discovering the truth!\n");
            break;
        case 3:
            printf("The moon landing was faked. It was all a big Hollywood production, and the government was in on it!\n");
            break;
        case 4:
            printf("Did you know that the Illuminati control everything? They're pulling the strings behind the scenes, controlling all aspects of our lives!\n");
            break;
        case 5:
            printf("Alien abductions are real! The government has been covering it up for years, and conducting experiments on the abductees.\n");
            break;
        case 6:
            printf("The New World Order is coming! The government is working with a shadowy cabal to set up a one-world government and enslave us all!\n");
            break;
        case 7:
            printf("9/11 was an inside job! The government orchestrated the whole thing to justify invading other countries and tightening their grip on power.\n");
            break;
        case 8:
            printf("The US government has been hiding evidence of extraterrestrial life for decades. They don't want the public to know what they've discovered!\n");
            break;
        case 9:
            printf("The JFK assassination was a conspiracy! Lee Harvey Oswald was just a fall guy. The real killers were never caught.\n");
            break;
        default:
            break;
    }
}

int main()
{
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Conspiracy Theory Generator!\n");

    while (1) // Repeat until user decides to quit
    {
        int input;
        printf("Press 1 to generate a new conspiracy theory, or 2 to quit: ");
        scanf("%d", &input);

        if (input == 1)
        {
            printConspiracyTheory();
        }
        else if (input == 2)
        {
            printf("Thanks for using the Conspiracy Theory Generator. Stay safe out there!\n");
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}