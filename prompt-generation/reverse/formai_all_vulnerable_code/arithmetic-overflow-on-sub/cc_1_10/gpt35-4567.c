//FormAI DATASET v1.0 Category: Text Summarizer ; Style: retro
/* Retro Style Text Summarizer */
/* Written by Chatbot 9000 */

#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 5000
#define MAX_SUMMARY_LENGTH 1000

void summarize(char *text, char *summary);

int main()
{
    char text[MAX_TEXT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];

    printf("Welcome to the Retro Style Text Summarizer!\n\n");
    printf("Enter the text you would like to summarize (up to %d characters):\n", MAX_TEXT_LENGTH);
    fgets(text, MAX_TEXT_LENGTH, stdin);

    summarize(text, summary);

    printf("\n\nHere is your summary:\n\n%s\n\nThank you for using the Retro Style Text Summarizer!\n", summary);

    return 0;
}

void summarize(char *text, char *summary)
{
    // initialize variables
    int i, j, k;
    int text_length = strlen(text);
    int summary_length = 0;
    int sentence_count = 0;
    int word_count = 0;
    int sentence_start = 0;
    int sentence_lengths[MAX_TEXT_LENGTH] = {0};
    int word_lengths[MAX_TEXT_LENGTH] = {0};
    char sentence[MAX_TEXT_LENGTH] = {0};
    char word[MAX_TEXT_LENGTH] = {0};
    char summary_sentence[MAX_SUMMARY_LENGTH] = {0};

    // loop through the text to count sentences and words
    for (i = 0; i <= text_length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_lengths[sentence_count] = i - sentence_start + 1;
            sentence_count++;
            sentence_start = i + 1;
        }
        else if (text[i] == ' ' || text[i] == '\n' || text[i] == '\0')
        {
            word_lengths[word_count] = i - k;
            k = i + 1;
            word_count++;
        }
    }

    // loop through sentences and copy the ones with the most words into the summary
    for (i = 0; i < sentence_count; i++)
    {
        memset(sentence, 0, MAX_TEXT_LENGTH);
        strncpy(sentence, &text[summary_length], sentence_lengths[i]);
        summary_length += sentence_lengths[i];

        sentence_start = 0;

        // loop through words in sentence to count them
        for (j = 0; j <= sentence_lengths[i]; j++)
        {
            if (sentence[j] == ' ' || sentence[j] == '.' || sentence[j] == '?' || sentence[j] == '!')
            {
                memset(word, 0, MAX_TEXT_LENGTH);
                strncpy(word, &sentence[sentence_start], j - sentence_start + 1);
                sentence_start = j + 1;

                // if word count is less than 10, add it to the summary
                if (word_count <= 10)
                {
                    strcat(summary_sentence, word);
                }
            }
        }

        // add the summary sentence to the summary
        strcat(summary, summary_sentence);
        memset(summary_sentence, 0, MAX_SUMMARY_LENGTH);
    }
}