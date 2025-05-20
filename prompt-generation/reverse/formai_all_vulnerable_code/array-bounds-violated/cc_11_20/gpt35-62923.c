//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

int main()
{
    char text[MAX_SENTENCE_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];
    int sentence_count = 0;
    int index = 0;
    int i, j, k;

    // Read the input text
    printf("Enter the text to summarize: \n");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    // Count number of sentences
    for(i = 0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }

    // Create an array of sentence indices
    int sentence_indices[sentence_count];
    for(j = 0; j < strlen(text); j++)
    {
        if(text[j] == '.' || text[j] == '!' || text[j] == '?')
        {
            sentence_indices[index] = j;
            index++;
        }
    }

    // Calculate the score of each sentence and determine top sentences
    int scores[sentence_count];
    for(k = 0; k < sentence_count; k++)
    {
        scores[k] = rand()%100; // Replace with your scoring function
    }

    int top_sentence_indices[MAX_SUMMARY_LENGTH];
    for(i = 0; i < MAX_SUMMARY_LENGTH; i++)
    {
        int top_score = -1;
        int top_index = -1;
        for(j = 0; j < sentence_count; j++)
        {
            if(scores[j] > top_score)
            {
                top_score = scores[j];
                top_index = j;
            }
        }

        top_sentence_indices[i] = top_index;
        scores[top_index] = -1;
    }

    // Concatenate top sentences to create summary
    int start_index = 0;
    for(i = 0; i < MAX_SUMMARY_LENGTH; i++)
    {
        int end_index = sentence_indices[top_sentence_indices[i]];

        strncpy(summary + start_index, text + start_index, end_index - start_index + 1);

        start_index = end_index + 1;
    }

    printf("\nSummary:\n%s\n", summary);

    return 0;
}