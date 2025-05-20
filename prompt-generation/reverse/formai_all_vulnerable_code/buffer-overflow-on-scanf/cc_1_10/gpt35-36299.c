//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char conspiracy[8][50] = {"The moon landing was faked",
                              "The government is controlling the weather",
                              "The Illuminati controls everything",
                              "Chemtrails are poisoning us all",
                              "The Mandela Effect proves alternate realities",
                              "Area 51 is hiding alien technology",
                              "Fluoride in the water is mind control",
                              "The world is ruled by lizard people"};
                              
    char explanation[8][200] = {"The shadow of the flag isn't right in the moon landing photo",
                                "The government has admitted to cloud seeding for weather control",
                                "Celebrities and politicians are all part of the Illuminati",
                                "Chemicals in airplane exhaust can cause health problems",
                                "Different memories of events are proof of a parallel universe",
                                "There are many conspiracy theories surrounding what is really hidden at Area 51",
                                "Fluoride has been shown to lower IQ and cause other negative effects",
                                "Some people believe that a race of shape-shifting lizards rule the world in secret"};
                                  
    srand(time(NULL));
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    printf("The conspiracy theory for today is: \n\n");
    printf("%s\n\n", conspiracy[rand() % 8]);
    printf("Explanation: \n\n");
    printf("%s\n\n", explanation[rand() % 8]);
    
    printf("Do you believe in this conspiracy theory? (y/n) ");
    char answer;
    scanf("%c", &answer);
    
    if (answer == 'y')
    {
        printf("\nWelcome to the club! You are now a believer in this theory.\n");
    }
    else if (answer == 'n')
    {
        printf("\nDon't worry, not everyone is ready to accept the truth.\n");
    }
    else
    {
        printf("\nSorry, that's not a valid answer.\n");
    }
    
    return 0;
}