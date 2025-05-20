//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include<stdio.h>
#include<string.h>

int main()
{
    printf("Welcome to the Text Summarizer program!\n");
    printf("Enter the text you want to summarize:\n");

    char text[1000];
    fgets(text, 1000, stdin);

    printf("Processing your text...\n");

    // Counting the number of sentences in the paragraph
    int sentence_count = 0;
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_count++;
        }
    }

    // Creating an array of all sentences in the paragraph
    char sentences[sentence_count][1000];
    int j = 0;
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences[j][0] = text[i];
            sentences[j][1] = '\n';
            sentences[j][2] = '\0';
            j++;
        }
        else
        {
            sentences[j][strlen(sentences[j])] = text[i];
        }
    }

    // Counting the number of words in each sentence
    int word_count[sentence_count];
    for(int i = 0; i < sentence_count; i++)
    {
        int count = 0;
        for(int j = 0; sentences[i][j] != '\0'; j++)
        {
            if(sentences[i][j] == ' ')
            {
                count++;
            }
        }
        word_count[i] = count + 1;
    }

    // Finding the sentence with the least number of words
    int min_index = 0;
    for(int i = 0; i < sentence_count; i++)
    {
        if(word_count[i] < word_count[min_index])
        {
            min_index = i;
        }
    }

    // Printing the Summary
    printf("\nSummary:\n");
    for(int i = min_index; i < sentence_count; i++)
    {
        printf("%s", sentences[i]);
    }

    return 0;
}