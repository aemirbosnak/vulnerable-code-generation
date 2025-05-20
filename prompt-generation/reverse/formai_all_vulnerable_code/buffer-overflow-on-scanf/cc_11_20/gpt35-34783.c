//FormAI DATASET v1.0 Category: Computer Biology ; Style: creative
#include <stdio.h>

int main()
{
    //Welcome message
    printf("Welcome to the Genetic Analyzer\n");

    //Ask user for DNA sequence
    printf("Please enter the DNA sequence: ");
    char dna[500];
    scanf("%s", dna);

    //Count nucleotides
    int a_count = 0, t_count = 0, c_count = 0, g_count = 0;
    int i;
    for (i = 0; dna[i] != '\0'; i++)
    {
        if (dna[i] == 'A' || dna[i] == 'a')
            a_count++;
        else if (dna[i] == 'T' || dna[i] == 't')
            t_count++;
        else if (dna[i] == 'C' || dna[i] == 'c')
            c_count++;
        else if (dna[i] == 'G' || dna[i] == 'g')
            g_count++;
    }

    //Display nucleotide counts
    printf("\nNucleotide counts:\n");
    printf("A: %d\n", a_count);
    printf("T: %d\n", t_count);
    printf("C: %d\n", c_count);
    printf("G: %d\n", g_count);

    //Calculate GC content
    float gc_content = ((float)c_count + g_count) / (a_count + t_count + c_count + g_count) * 100;

    //Display GC content
    printf("\nGC content: %.2f%%\n", gc_content);

    //Determine if DNA sequence is protein coding or not
    int codon_count = 0;
    int j;
    for (j = 0; dna[j + 2] != '\0'; j += 3)
    {
        if ((dna[j] == 'A' && dna[j + 1] == 'T' && dna[j + 2] == 'G') ||
            (dna[j] == 'G' && dna[j + 1] == 'T' && dna[j + 2] == 'C'))
        {
            codon_count++;
        }
    }

    //Display protein coding status
    if (codon_count >= 5)
    {
        printf("\nThis DNA sequence is likely to be protein coding.\n");
    }
    else
    {
        printf("\nThis DNA sequence is unlikely to be protein coding.\n");
    }

    //Exit message
    printf("\nThank you for using the Genetic Analyzer!\n");

    return 0;
}