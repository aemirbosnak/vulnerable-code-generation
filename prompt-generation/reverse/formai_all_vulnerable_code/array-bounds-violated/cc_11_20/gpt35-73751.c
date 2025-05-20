//FormAI DATASET v1.0 Category: Data mining ; Style: unmistakable
#include<stdio.h>   // Standard Input/Output Header File
#include<stdlib.h>  // Standard Library Header File
 
#define max(x,y) ((x)>(y)?(x):(y))   // Define a function to find maximum of two numbers
 
int main()
{
    int n, m, i, j;   // Declare variables to store size of dataset
    printf("Enter the size of the dataset (n,m): ");
    scanf("%d%d", &n, &m);
 
    int data[n][m];   // Declare a two dimensional array to store the dataset
    printf("\nEnter the dataset:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d", &data[i][j]);   // Take input for the dataset
        }
    }
 
    int freq[m];  // Declare an array to store the frequency of each attribute
    for(i=0; i<m; i++)
    {
        freq[i] = 0;     // Initialize the frequency array to zero
    }
 
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(data[j][i] == 1)   // If the attribute is present in a record, increase its frequency count
            {
                freq[i]++;
            }
        }
    }
 
    int strongest = 0, count = 0;  // Declare variables to store the strongest attribute and its count
    for(i=0; i<m; i++)
    {
        if(freq[i] > (n/2))    // If the attribute has frequency greater than half the number of records, it is the strongest
        {
            count++;
            strongest = i;
        }
    }
 
    if(count == 1)   // If there is only one strongest attribute, print its index
    {
        printf("\nThe strongest attribute is %d\n", strongest);
    }
    else    // If there are more than one strongest attributes, select the one with maximum frequency and print its index
    {
        int max_freq = freq[strongest], max_index = strongest;
        for(i=0; i<m; i++)
        {
            if(freq[i] > max_freq)
            {
                max_freq = freq[i];
                max_index = i;
            }
        }
     
        printf("\nThe strongest attribute is %d\n", max_index);
    }
 
    return 0;   // End of the program
}