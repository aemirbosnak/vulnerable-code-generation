//FormAI DATASET v1.0 Category: Computer Biology ; Style: creative
#include <stdio.h>

// Function to calculate the hamming distance between two strings
int hammingDistance(char* str1, char* str2)
{
    int distance = 0;
    for(int i=0; str1[i] && str2[i]; i++)
    {
        if (str1[i] != str2[i])
        {
            distance++;
        }
    }
    return distance;
}

// Function to convert a DNA sequence to RNA 
char* dnaToRna(char* dnaSequence)
{
    int i=0;
    while(dnaSequence[i])
    {
        if(dnaSequence[i] == 'T')
            dnaSequence[i] = 'U';
        i++;
    }
    return dnaSequence;
}

int main()
{
    // Input DNA sequence
    char dnaSequence[100];
    printf("Enter a DNA sequence: ");
    scanf("%s", dnaSequence);
    
    // Convert to RNA
    char* rnaSequence = dnaToRna(dnaSequence);
    
    // Input a reference RNA sequence
    char referenceRnaSequence[100];
    printf("Enter a reference RNA sequence: ");
    scanf("%s", referenceRnaSequence);
    
    // Calculate hamming distance between DNA sequence and reference RNA sequence
    int distance = hammingDistance(rnaSequence, referenceRnaSequence);
    
    // Output the result
    printf("The hamming distance between DNA sequence and reference RNA sequence is: %d", distance);
    
    return 0;
}