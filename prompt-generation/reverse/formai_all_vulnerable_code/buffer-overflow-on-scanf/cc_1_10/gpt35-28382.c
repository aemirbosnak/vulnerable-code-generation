//FormAI DATASET v1.0 Category: Computer Biology ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

/*
* This program demonstrates how to use recursion to find the reverse 
* complement of a DNA sequence.
*/
 
void reverse_complement(char []);
 
int main()
{
    char sequence[30];
    printf("Enter a DNA sequence of up to 30 base pairs:\n");
    scanf("%s", sequence);
    reverse_complement(sequence);
    printf("The reverse complement is: %s\n", sequence);
    return 0;
}
 
void reverse_complement(char sequence[])
{
    int i, j;
    char temp;
    j = strlen(sequence) - 1;
    for (i = 0; i < j; i++, j--) {
        temp = sequence[i];
        sequence[i] = sequence[j];
        sequence[j] = temp;
    }
    for (i = 0; i < strlen(sequence); i++) {
        switch (sequence[i]) {
            case 'A':
                sequence[i] = 'T';
                break;
            case 'T':
                sequence[i] = 'A';
                break;
            case 'G':
                sequence[i] = 'C';
                break;
            case 'C':
                sequence[i] = 'G';
                break;
            default:
                // Invalid base pair
                printf("Invalid base pair.\n");
                exit(1);
        }
    }
}