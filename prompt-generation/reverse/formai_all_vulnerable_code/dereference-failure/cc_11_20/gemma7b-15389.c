//Gemma-7B DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // The case of the stolen diamond
    char *suspect_names[] = {"Mr. A", "Mrs. B", "Mr. C", "Mrs. D", "Mr. E"};
    int num_suspects = 5;

    // Create a list of potential clues
    char **clues = (char **)malloc(num_suspects * 20);
    for (int i = 0; i < num_suspects; i++)
    {
        clues[i] = (char *)malloc(20);
    }

    // Gather clues from the scene
    clues[0] = "The diamond was last seen in Mr. A's possession.";
    clues[1] = "Mrs. B was seen carrying a suspicious bag on the night of the theft.";
    clues[2] = "Mr. C has a history of pawnbrokering stolen goods.";
    clues[3] = "Mrs. D is known to have a keen eye for valuable jewels.";
    clues[4] = "Mr. E was seen lurking around the diamond vault on the night of the theft.";

    // Analyze the clues
    int suspects_with_clues = 0;
    for (int i = 0; i < num_suspects; i++)
    {
        if (strstr(clues[i], "diamond") || strstr(clues[i], "suspicious") || strstr(clues[i], "valuable") || strstr(clues[i], "stolen"))
        {
            suspects_with_clues++;
        }
    }

    // Identify the culprit
    char *culprit = NULL;
    if (suspects_with_clues == 1)
    {
        for (int i = 0; i < num_suspects; i++)
        {
            if (strstr(clues[i], "diamond") || strstr(clues[i], "suspicious") || strstr(clues[i], "valuable") || strstr(clues[i], "stolen"))
            {
                culprit = suspect_names[i];
            }
        }
    }

    // Print the results
    if (culprit)
    {
        printf("The culprit is: %s", culprit);
    }
    else
    {
        printf("The case remains unsolved.");
    }

    return 0;
}