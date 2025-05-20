//FormAI DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>
#include <string.h>

// function to remove punctuations from a given string
void removePunctuations(char* string)
{
    int i, j = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (isalpha(string[i]) || string[i] == ' ')
            string[j++] = tolower(string[i]);
    }
    string[j] = '\0';
}

// function to calculate the frequency of each word in a string
void calculateFrequency(char* string)
{
    char words[100][100], temp[100];
    int frequency[100], i, j, k = 0, count;

    // split the given string into words and store them in the words array
    for (i = 0; string[i] != '\0'; i++)
    {
        count = 0;
        while (string[i] != ' ' && string[i] != '\0')
        {
            temp[count++] = string[i];
            i++;
        }
        temp[count] = '\0';
        strcpy(words[k], temp);
        k++;
    }

    // calculate the frequency of each word and store it in the frequency array
    for (i = 0; i < k; i++)
    {
        frequency[i] = 1;
        for (j = i + 1; j < k; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                frequency[i]++;
                strcpy(words[j], "");
            }
        }
    }

    // print the top 5 most frequent words
    printf("The top 5 most frequent words in the given text are:\n");
    for (i = 0; i < 5; i++)
    {
        int max = 0, index;
        for (j = 0; j < k; j++)
        {
            if (frequency[j] > max)
            {
                max = frequency[j];
                index = j;
            }
        }
        if (max > 0)
            printf("%s - %d\n", words[index], max);
        frequency[index] = 0;
    }
}

int main()
{
    char input[1000];
    printf("Enter the text that you want to summarize:\n");
    fgets(input, 1000, stdin);

    // remove punctuations and convert to lower case
    removePunctuations(input);

    // calculate frequency of each word and print top 5 most frequent words
    calculateFrequency(input);

    return 0;
}