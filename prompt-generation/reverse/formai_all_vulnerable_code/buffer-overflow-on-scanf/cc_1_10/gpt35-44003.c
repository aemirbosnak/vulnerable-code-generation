//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Seed for random number generation

    //Arrays of random conspiracy theories
    char *conspiracy1[] = {"The moon landing was faked by the government.",
                           "The government is hiding evidence of alien life.",
                           "9/11 was an inside job.",
                           "The illuminati controls the world.",
                           "Chemtrails are being used to control the population."};
    char *conspiracy2[] = {"The government is using mind control through television and radio waves.",
                           "The CIA killed JFK.",
                           "Paul McCartney died and was replaced by a lookalike.",
                           "The earth is flat and the government is hiding it.",
                           "The government is using vaccines to control the population."};
    char *conspiracy3[] = {"The lizard people are secretly running the government.",
                           "The Bermuda Triangle is a gateway to an alternate dimension.",
                           "The apocalypse is coming but the government is keeping it a secret.",
                           "The ancient Egyptians had access to advanced technology.",
                           "The pyramids were not built by humans."};

    printf("Welcome to the Random Conspiracy Theory Generator\n\n");

    while(1)
    {
        //Generate random numbers to select a conspiracy theory from each array
        int rand1 = rand() % 5;
        int rand2 = rand() % 5;
        int rand3 = rand() % 5;

        //Print out the conspiracy theory
        printf("Conspiracy Theory: %s %s %s\n", conspiracy1[rand1], conspiracy2[rand2], conspiracy3[rand3]);

        //Ask user if they want to generate another conspiracy theory
        printf("\nWould you like to generate another conspiracy theory? (Y/N) ");
        char input;
        scanf(" %c", &input);

        //End program if user chooses N or n, otherwise continue generating theories
        if(input == 'N' || input == 'n')
        {
            break;
        }
    }

    printf("\nThank you for using the Random Conspiracy Theory Generator!\n");

    return 0;
}