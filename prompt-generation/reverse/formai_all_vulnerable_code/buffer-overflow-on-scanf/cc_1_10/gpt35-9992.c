//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); // initialize random seed
    
    int n,k,r,j,i; // declare required variables
    char *seq; // declare character pointer for sequence
    
    printf("Enter the length of the genome:");
    scanf("%d",&n); // take input for length of genome
    
    seq = malloc(n * sizeof(char)); // allocate memory for sequence
    
    if(seq == NULL) // check if allocation was successful
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    
    printf("\nEnter the number of genomes to be generated:");
    scanf("%d",&k); // take input for number of genomes to be generated
    
    printf("\nGenerating %d genomes...",k);

    for(i=1; i<=k; i++) // loop for generating k genomes
    {
        printf("\n\nGenome %d:",i);
        
        for(j=0; j<n; j++) // loop for generating n length of genome
        {
            r = rand() % 4; // generate random integer between 0 to 3
            
            switch(r) // assign character according to random number
            {
                case 0:
                    seq[j] = 'A';
                    break;
                case 1:
                    seq[j] = 'C';
                    break;
                case 2:
                    seq[j] = 'G';
                    break;
                case 3:
                    seq[j] = 'T';
                    break;
            }
            
            printf("%c",seq[j]); // print the current character generated         
        }       
    }
    
    free(seq); // free memory allocated for sequence
    printf("\n");
    return 0;
}