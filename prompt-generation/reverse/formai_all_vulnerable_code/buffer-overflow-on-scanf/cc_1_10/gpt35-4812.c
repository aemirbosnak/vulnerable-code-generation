//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    int numSegments, segLength, seqLength;
    char *sequence;
    
    // Prompt user for input
    printf("Enter the number of segments: ");
    scanf("%d", &numSegments);
    printf("Enter length of each segment: ");
    scanf("%d", &segLength);
    
    // Calculate sequence length
    seqLength = numSegments * segLength;
    
    // Allocate memory for sequence
    sequence = (char*)calloc(seqLength, sizeof(char));
    
    // Generate random sequence
    int i, j;
    for(i=0; i<numSegments; i++)
    {
        for(j=0; j<segLength; j++)
        {
            int randNum = rand() % 4;
            switch(randNum)
            {
                case 0:
                    sequence[i*segLength + j] = 'A';
                    break;
                case 1:
                    sequence[i*segLength + j] = 'C';
                    break;
                case 2:
                    sequence[i*segLength + j] = 'G';
                    break;
                case 3:
                    sequence[i*segLength + j] = 'T';
                    break;
            }
        }
    }
    
    // Output sequence
    printf("Generated sequence: %s\n", sequence);
    
    // Free memory
    free(sequence);

    // End program
    return 0;
}