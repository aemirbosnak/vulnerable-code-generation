//FormAI DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>
#include <string.h>
//Define constant variables
#define MAX_SENTENCES 100
#define MAX_LENGTH 1000
//Function prototype for the text summarization function
void summarizeText(char *inputText, char *summaryText);

int main()
{
    char inputText[MAX_LENGTH], summaryText[MAX_LENGTH];
    printf("Welcome to Text Summarizer!\n");
    printf("Please enter your text:\n");
    scanf("%[^\n]s", inputText);
    summarizeText(inputText, summaryText);
    printf("\nSummary:\n%s\n", summaryText);
    return 0;
}

void summarizeText(char *inputText, char *summaryText)
{
    //Split text into sentences delimited by "."
    char *sentence = strtok(inputText, ".");
    char sentences[MAX_SENTENCES][MAX_LENGTH];
    int numSentences = 0;
    while (sentence != NULL) {
        strcpy(sentences[numSentences], sentence);
        numSentences++;
        sentence = strtok(NULL, ".");
    }
    //Calculate the score of each sentence based on the number of non-stopwords
    int sentenceScores[MAX_SENTENCES];
    char *stopwords[] = {"a", "an", "the", "and", "or", "but", "on", "in", "with", "at", "by", "for"};
    for (int i = 0; i < numSentences; i++) {
        sentenceScores[i] = 0;
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            int isStopword = 0;
            for (int j = 0; j < sizeof(stopwords)/sizeof(stopwords[0]); j++) {
                if (strcmp(stopwords[j], word) == 0) {
                    isStopword = 1;
                    break;
                }
            }
            if (!isStopword) {
                sentenceScores[i]++;
            }
            word = strtok(NULL, " ");
        }
    }
    //Sort the sentences in descending order of score
    int sortedScoreIndices[numSentences];
    for (int i = 0; i < numSentences; i++) {
        sortedScoreIndices[i] = i;
    }
    for (int i = 0; i < numSentences - 1; i++) {
        for (int j = i + 1; j < numSentences; j++) {
            if (sentenceScores[sortedScoreIndices[j]] > sentenceScores[sortedScoreIndices[i]]) {
                int temp = sortedScoreIndices[i];
                sortedScoreIndices[i] = sortedScoreIndices[j];
                sortedScoreIndices[j] = temp;
            }
        }
    }
    //Concatenate the top 3 sentences to form the summary
    strcpy(summaryText, "");
    for (int i = 0; i < 3; i++) {
        strcat(summaryText, sentences[sortedScoreIndices[i]]);
    }
}