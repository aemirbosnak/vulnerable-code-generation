//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Sherlock Holmes's Deduction Game
    // A murder mystery in the grand estate of Downton Abbey

    // Declare variables
    int suspects[5] = {0, 0, 0, 0, 0};
    int evidence[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int suspects_visited = 0;
    int evidence_collected = 0;

    // Set up the suspects
    suspects[0] = "Mr. Herlock Holmes";
    suspects[1] = "Mr. Watson";
    suspects[2] = "Mr. Rochester";
    suspects[3] = "Mrs. Jennings";
    suspects[4] = "Mr. Bates";

    // Set up the evidence
    evidence[0] = "Bloody fingerprint";
    evidence[1] = "Broken vase";
    evidence[2] = "Empty poison bottle";
    evidence[3] = "Withered rose";
    evidence[4] = "Stained rope";
    evidence[5] = "Missing hat";
    evidence[6] = "Bloodstained carpet";
    evidence[7] = "Cigarette ash";
    evidence[8] = "Suspect's footprints";
    evidence[9] = "Trail of blood";

    // Begin the game loop
    while (!evidence_collected)
    {
        // Make a deduction
        printf("Please provide me with any evidence you have found: ");
        char evidence_found[20];
        scanf("%s", evidence_found);

        // Check if the evidence has already been collected
        for (int i = 0; i < evidence_collected; i++)
        {
            if (strcmp(evidence_found, evidence[i]) == 0)
            {
                printf("You have already collected that evidence.\n");
                break;
            }
        }

        // If the evidence has not been collected, add it to the evidence list
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(evidence_found, evidence[i]) == 0)
            {
                evidence_collected++;
                break;
            }
        }

        // If the evidence has been collected, print a clue
        if (evidence_collected == 10)
        {
            printf("Congratulations, Mr. Holmes! You have solved the case!\n");
            printf("The murderer is... %s\n", suspects[suspects_visited]);
        }
    }

    return 0;
}