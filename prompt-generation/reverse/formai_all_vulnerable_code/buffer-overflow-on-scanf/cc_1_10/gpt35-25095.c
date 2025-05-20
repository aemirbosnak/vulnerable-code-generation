//FormAI DATASET v1.0 Category: Text Summarizer ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SENTENCES 100
#define MAX_TEXT_SIZE 10000

int count_sentences(char *text);
void summarize_text(char *text, int num_sentences);

int main()
{
    char text[MAX_TEXT_SIZE];
    int num_sentences;

    printf("Enter the post-apocalyptic text to be summarized:\n");
    fgets(text, MAX_TEXT_SIZE, stdin);

    printf("Enter the number of sentences the summary should contain:\n");
    scanf("%d", &num_sentences);

    int num_actual_sentences = count_sentences(text);
    if(num_actual_sentences < num_sentences)
    {
        printf("Error: The number of sentences in the text is less than the summary size!\n");
        exit(1);
    }

    summarize_text(text, num_sentences);

    return 0;
}

void summarize_text(char *text, int num_sentences)
{
    char *token = strtok(text, ".!?");
    char *sentences[MAX_SENTENCES];
    int i = 0;

    while(token != NULL)
    {
        sentences[i++] = token;
        token = strtok(NULL, ".!?");
    }

    int sentence_scores[i];

    for(int j=0; j<i; j++)
    {
        sentence_scores[j] = 0;

        for(int k=0; k<i; k++)
        {
            if(k == j) continue;

            char temp_sent[MAX_TEXT_SIZE];
            strcpy(temp_sent, sentences[k]);
            strcat(temp_sent, " ");
            strcat(temp_sent, sentences[j]);

            if(strstr(text, temp_sent) != NULL)
                sentence_scores[j]++;
        }
    }

    printf("Summary:\n");
    for(int j=0; j<num_sentences; j++)
    {
        int max_score_index = 0;
        int max_score = -1;

        for(int k=0; k<i; k++)
        {
            if(sentence_scores[k] > max_score)
            {
                max_score = sentence_scores[k];
                max_score_index = k;
            }
        }

        printf("%s", sentences[max_score_index]);

        for(int k=max_score_index; k<i-1; k++)
            sentences[k] = sentences[k+1];

        i--;
    }
}

int count_sentences(char *text)
{
    int num_sentences = 0;

    for(int i=0; i<strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
            num_sentences++;
    }

    return num_sentences;
}