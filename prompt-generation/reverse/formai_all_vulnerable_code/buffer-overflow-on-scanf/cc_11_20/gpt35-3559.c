//FormAI DATASET v1.0 Category: Computer Biology ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a structure representing a DNA sequence
typedef struct DNA
{
    char name[20];
    char sequence[100];
} DNA;


int main()
{
    // Create an array of 3 DNA sequences
    DNA sequences[3];

    // Read in the name and sequence for each DNA sequence
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("Enter the name for sequence %d: ", i+1);
        scanf("%s", sequences[i].name);

        printf("Enter the DNA sequence for %s: ", sequences[i].name);
        scanf("%s", sequences[i].sequence);
    }

    // Print out the input sequences
    printf("\n\nInput Sequences:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s: %s\n", sequences[i].name, sequences[i].sequence);
    }

    // Reverse Complement each DNA sequence
    for (i = 0; i < 3; i++)
    {
        // First reverse the sequence
        int j;
        int len = strlen(sequences[i].sequence);
        char reverseSequence[100];

        for (j = 0; j < len; j++)
        {
            reverseSequence[j] = sequences[i].sequence[len-j-1];
        }
        reverseSequence[len] = '\0';

        // Then complement the sequence
        char complementSequence[100];

        for (j = 0; j < len; j++)
        {
            if (reverseSequence[j] == 'A')
            {
                complementSequence[j] = 'T';
            }
            else if (reverseSequence[j] == 'T')
            {
                complementSequence[j] = 'A';
            }
            else if (reverseSequence[j] == 'C')
            {
                complementSequence[j] = 'G';
            }
            else if (reverseSequence[j] == 'G')
            {
                complementSequence[j] = 'C';
            }
        }
        complementSequence[len] = '\0';

        // Update the DNA sequence with the reverse complement
        strcpy(sequences[i].sequence, complementSequence);
    }

    // Print out the Reverse Complement Sequences
    printf("\n\nReverse Complement Sequences:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s: %s\n", sequences[i].name, sequences[i].sequence);
    }

    return 0;
}