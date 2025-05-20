//FormAI DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function declaration
void textSummarize(char* document, int num_sentences);

// main function
int main()
{
    // input document
    char document[1000];
    printf("Enter the document to summarize:\n");
    fgets(document, 1000, stdin);

    // input number of sentences to summarize
    int num_sentences;
    printf("Enter the number of sentences to summarize:\n");
    scanf("%d", &num_sentences);

    // summarize the document
    textSummarize(document, num_sentences);
    return 0;
}

// function definition
void textSummarize(char* document, int num_sentences)
{
    // array to store all the sentences
    char sentences[100][100];
    int sentence_count = 0;

    // split the document into sentences and store in array
    char *sentence = strtok(document, ".");
    while (sentence != NULL && sentence_count < 100)
    {
        strncpy(sentences[sentence_count], sentence, 100);
        sentence_count++;
        sentence = strtok(NULL, ".");
    }

    // calculate score for each sentence
    int score[100] = {0};
    for (int i = 0; i < sentence_count; i++)
    {
        // split the sentence into words
        char *word = strtok(sentences[i], " ");
        while (word != NULL)
        {
            // check if the word is relevant
            if (strcmp(word, "is") == 0 || strcmp(word, "the") == 0 || strcmp(word, "a") == 0 || strcmp(word, "an") == 0 || strcmp(word, "of") == 0 || strcmp(word, "and") == 0 || strcmp(word, "in") == 0)
            {
                score[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // print the summary
    printf("Summary:\n");
    for (int i = 0; i < num_sentences; i++)
    {
        int max_index = 0;
        int max_score = score[0];
        for (int j = 1; j < sentence_count; j++)
        {
            if (score[j] > max_score)
            {
                max_index = j;
                max_score = score[j];
            }
        }
        printf("%s.", sentences[max_index]);
        score[max_index] = -1;
    }
}