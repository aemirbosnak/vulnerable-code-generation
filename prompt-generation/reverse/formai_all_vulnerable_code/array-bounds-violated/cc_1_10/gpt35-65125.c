//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 100

// Function to count the frequency of each word in a given string
void countFrequency(char *str)
{
    int i, j, k;
    char word[MAX_LENGTH], temp[MAX_LENGTH];
    int freq[MAX_LENGTH], idx;

    // Split the string into words and count the frequency
    k = 0;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ')
        {
            word[k] = '\0';
            for(j = 0; j < strlen(word); j++)
            {
                if(word[j] >= 'A' && word[j] <= 'Z')
                    word[j] += 32;
            }

            // Check if the word is already counted
            idx = -1;
            for(j = 0; j < k; j++)
            {
                if(strcmp(word, temp[j]) == 0)
                {
                    idx = j;
                    break;
                }
            }

            if(idx != -1)
            {
                freq[idx]++;
            }
            else
            {
                strcpy(temp[k], word);
                freq[k] = 1;
                k++;
            }

            // Reset the word array
            for(j = 0; j < MAX_LENGTH; j++)
            {
                word[j] = '\0';
            }
            k = 0;
        }
        else
        {
            word[k++] = str[i];
        }
    }

    // Print the result
    printf("\nWord\t\tFrequency\n");
    for(i = 0; i < k; i++)
    {
        printf("%s\t\t%d\n", temp[i], freq[i]);
    }
}

// Main function
int main()
{
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) - 1] = '\0';

    countFrequency(str);

    return 0;
}