//Gemma-7B DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Scene: The Mysterious Laboratory

    // Characters:
    // - Sherlock Holmes: A master detective with a sharp mind and keen observation skills.
    // - Dr. John Watson: Sherlock's loyal companion and sidekick.
    // - Professor Moriarty: A cunning criminal mastermind.

    // Setting: The laboratory is filled with clues and evidence.

    // The mystery: A priceless diamond has been stolen from the laboratory.

    // Step 1: Inspect the laboratory.

    printf("You have entered the mysterious laboratory. The air is thick with the scent of chemicals and mystery. What do you see?");

    // Gather evidence from the laboratory.
    char evidence[200];
    scanf("%s", evidence);

    // Step 2: Analyze the evidence.

    printf("You have carefully analyzed the evidence. What is your deduction?");

    // Make a deduction based on the evidence.
    char deduction[200];
    scanf("%s", deduction);

    // Step 3: Confront the suspect.

    printf("You have confronted the suspect, Professor Moriarty. What do you say to him?");

    // Accuse the suspect.
    char accusation[200];
    scanf("%s", accusation);

    // Did you solve the mystery?

    if (strcmp(deduction, "Professor Moriarty stole the diamond") == 0)
    {
        printf("Congratulations, Sherlock Holmes! You have solved the mystery!");
    }
    else
    {
        printf("Alas, my dear Watson, the mystery remains unsolved. The diamond is still at large.");
    }

    return 0;
}