//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SUMMARY_LEN 100

int main()
{
    char article[5000], summary[MAX_SUMMARY_LEN], temp[MAX_SUMMARY_LEN];
    int i, j, k, article_len, summary_len, num_sentences;

    // Get input article text from the user
    printf("Enter the article:\n");
    fgets(article, 5000, stdin);
    article_len = strlen(article);

    // Determine the number of sentences in the article
    num_sentences = 0;
    for(i=0; i<article_len; i++){
        if(article[i] == '.' || article[i] == '?' || article[i] == '!')
            num_sentences++;
    }

    // Split the article into individual sentences
    char *sentences[num_sentences];
    sentences[0] = strtok(article, ".?!");
    for(i=1; i<num_sentences; i++){
        sentences[i] = strtok(NULL, ".?!");
    }

    // Get the most important sentences from the article
    summary[0] = '\0';
    summary_len = 0;
    for(i=0; i<num_sentences; i++)
    {
        // Check if the sentence contains any important words
        char *important_words[] = {"important", "significant", "crucial", "essential", "vital", "key", "critical", "fundamental"};
        int num_important_words = sizeof(important_words)/sizeof(important_words[0]);

        int contains_important_word = 0;
        for(j=0; j<num_important_words; j++){
            if(strstr(sentences[i], important_words[j]) != NULL){
                contains_important_word = 1;
                break;
            }
        }

        // If the sentence contains an important word, add it to the summary
        if(contains_important_word)
        {
            article_len = strlen(sentences[i]);
            for(k=0; k<article_len; k++)
            {
                if(summary_len >= MAX_SUMMARY_LEN-1)
                    break;

                summary[summary_len] = sentences[i][k];
                summary_len++;
            }
            summary[summary_len] = '.';
            summary_len++;
            summary[summary_len] = ' ';
            summary_len++;
            summary[summary_len] = '\0';
        }
    }

    // Print the summary
    printf("\n\nSummary:\n%s\n", summary);

    return 0;
}