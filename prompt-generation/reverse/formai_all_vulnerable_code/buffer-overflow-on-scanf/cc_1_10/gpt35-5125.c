//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_distance(char input1[], char input2[]); // function to calculate Levenshtein Distance

int main()
{
    printf("**********RETRO-STYLE LEVENSHTEIN DISTANCE CALCULATOR**********\n\n");
    printf("Enter two words to calculate the Levenshtein Distance between them:\n");

    char input1[20], input2[20]; // initializing variable to store user inputs
    scanf("%s", input1);
    scanf("%s", input2);

    int distance = calculate_distance(input1, input2); // calling the function to calculate Levenshtein Distance

    printf("\nThe Levenshtein Distance between %s and %s is %d.\n", input1, input2, distance);

    return 0;
}

int calculate_distance(char input1[], char input2[])
{
    int len1 = strlen(input1);
    int len2 = strlen(input2);

    int arr[len1+1][len2+1]; // initializing array to store distances
   
    for(int i=0; i<=len1; i++) //populating the first row of the array
    {
        arr[i][0] = i;
    }

    for(int j=0; j<=len2; j++) //populating the first column of the array
    {
        arr[0][j] = j;
    }

    for(int i=1; i<=len1; i++) //populating rest of the array
    {
        for(int j=1; j<=len2; j++)
        {
            int cost = (input1[i-1] == input2[j-1]) ? 0 : 1;
            arr[i][j] = fmin(fmin(arr[i-1][j]+1, arr[i][j-1]+1), arr[i-1][j-1]+cost);
        }
    }

    return arr[len1][len2];
}