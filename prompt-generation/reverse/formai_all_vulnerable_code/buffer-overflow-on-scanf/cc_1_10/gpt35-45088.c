//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000
#define MAX_SENTENCES 50
#define MAX_SUMMARY 5
#define MIN_SENTENCE_LENGTH 10
#define MIN_KEYWORD_LENGTH 4

char* split_sentences(char* input_text)
{
    char sentence_delimiters[] = ".?!";
    char* sentence = strtok(input_text, sentence_delimiters);
    int sentence_count = 0;
    while (sentence != NULL)
    {
        sentence_count++;
        sentence = strtok(NULL, sentence_delimiters);
    }
    char* sentences[sentence_count];
    sentence = strtok(input_text, sentence_delimiters);
    int index = 0;
    while (sentence != NULL)
    {
        sentences[index] = sentence;
        sentence = strtok(NULL, sentence_delimiters);
        index++;
    }
    return sentences;
}

int check_keywords(char* sentence, char* keywords[])
{
    for (int i = 0; i < MAX_SUMMARY; i++)
    {
        char* keyword = keywords[i];
        if (strstr(sentence, keyword) != NULL)
        {
            return 1;
        }
    }
    return 0;
}

char* summarize_text(char* input_text, char* keywords[])
{
    char* sentences = split_sentences(input_text);
    char* summary[MAX_SUMMARY];
    int summary_count = 0;
    for (int i = 0; i < MAX_SENTENCES; i++)
    {
        char* sentence = sentences[i];
        if (strlen(sentence) >= MIN_SENTENCE_LENGTH)
        {
            if (check_keywords(sentence, keywords))
            {
                summary[summary_count] = sentence;
                summary_count++;
                if (summary_count == MAX_SUMMARY)
                {
                    break;
                }
            }
        }
    }
    char* summary_text = (char*)malloc(sizeof(char) * MAX_SUMMARY * MIN_SENTENCE_LENGTH);
    for (int i = 0; i < MAX_SUMMARY; i++)
    {
        strcat(summary_text, summary[i]);
        strcat(summary_text, " ");
    }
    return summary_text;
}

int main()
{
    printf("Enter the text you want to summarize:\n");
    char* input_text = (char*)malloc(sizeof(char) * MAX_INPUT);
    fgets(input_text, MAX_INPUT, stdin);
    printf("Enter the keywords to look for:\n");
    char* keywords[MAX_SUMMARY];
    for (int i = 0; i < MAX_SUMMARY; i++)
    {
        keywords[i] = (char*)malloc(sizeof(char) * MIN_KEYWORD_LENGTH);
        scanf("%s", keywords[i]);
    }
    char* summary = summarize_text(input_text, keywords);
    printf("Summary:\n%s", summary);
    return 0;
}