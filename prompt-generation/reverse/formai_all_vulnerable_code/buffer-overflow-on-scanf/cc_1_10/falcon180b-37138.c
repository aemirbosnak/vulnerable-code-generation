//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define NUM_BUCKETS 26

// Function to count the frequency of each character in a string
void countFrequency(char *str, int freq[NUM_BUCKETS])
{
    int i, j;

    for (i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            j = tolower(str[i]) - 'a';
            freq[j]++;
        }
    }
}

// Function to perform bucket sort
void bucketSort(char *str)
{
    int i, j, k, freq[NUM_BUCKETS] = {0};
    char bucket[NUM_BUCKETS][MAX_STRING_LENGTH];

    // Count the frequency of each character in the string
    countFrequency(str, freq);

    // Place each character in its corresponding bucket
    for (i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            j = tolower(str[i]) - 'a';
            strcat(bucket[j], &str[i]);
        }
    }

    // Concatenate the sorted buckets to form the sorted string
    for (i = 0; i < NUM_BUCKETS; i++)
    {
        if (bucket[i][0]!= '\0')
        {
            strcat(str, bucket[i]);
            strcat(str, " ");
        }
    }
}

// Function to remove leading and trailing spaces from a string
void trim(char *str)
{
    int i, j;

    for (i = 0; i < strlen(str); i++)
    {
        if (!isspace(str[i]))
        {
            for (j = i; j < strlen(str); j++)
            {
                str[j] = str[j + 1];
            }
            str[strlen(str) - 1] = '\0';
            break;
        }
    }

    for (i = strlen(str) - 1; i >= 0; i--)
    {
        if (!isspace(str[i]))
        {
            str[i + 1] = '\0';
            break;
        }
    }
}

// Main function
int main()
{
    char input[MAX_STRING_LENGTH];

    printf("Enter a string: ");
    scanf("%s", input);

    trim(input);
    bucketSort(input);

    printf("Sorted string: %s\n", input);

    return 0;
}