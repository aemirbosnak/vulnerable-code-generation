//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random conspiracy theories
void generate_conspiracy_theories()
{
    // Array of conspiracy theories
    char theories[7][100] = {
        "The moon landing was staged by the government",
        "The government is controlling the weather",
        "The earth is flat",
        "9/11 was an inside job",
        "The world is run by a secret society",
        "The Illuminati controls the entertainment industry",
        "The government is hiding the existence of aliens"
    };
    
    // Get current time for seed
    srand(time(0));
    
    // Generate random index
    int index = rand() % 7;
    
    // Print random conspiracy theory
    printf("Did you hear about this? %s\n", theories[index]);
}

int main()
{
    // Welcome message
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press enter to generate a conspiracy theory, or enter 'Q' to quit.\n");
    
    // Loop until Q is entered
    while(1)
    {
        // Get input from user
        char input;
        scanf("%c", &input);
        
        if(input == '\n')
        {
            generate_conspiracy_theories();
        }
        else if(input == 'Q' || input == 'q')
        {
            printf("Exiting program...\n");
            break;
        }
    }
    
    return 0;
}