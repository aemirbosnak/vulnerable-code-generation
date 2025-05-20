//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int numSentences;
} Text;

int main() {
    Text text;
    int i, j;
    char input[MAX_SENTENCE_LENGTH];

    // Read the input text
    printf("Enter the input text: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);

    // Split the input text into sentences
    char *token = strtok(input, ".");
    int sentenceLength = 0;
    int numSentences = 0;
    while (token!= NULL) {
        if (sentenceLength + strlen(token) + 1 > MAX_SENTENCE_LENGTH) {
            printf("Error: sentence too long.\n");
            exit(1);
        }
        strcpy(text.sentences[numSentences].text, token);
        text.sentences[numSentences].length = strlen(token);
        sentenceLength += text.sentences[numSentences].length + 1; // +1 for space
        numSentences++;
        token = strtok(NULL, ".");
    }

    // Print the original text
    printf("Original Text:\n");
    for (i = 0; i < numSentences; i++) {
        printf("%s ", text.sentences[i].text);
    }
    printf("\n");

    // Summarize the text
    int summaryLength = 0;
    for (i = 0; i < numSentences; i++) {
        if (summaryLength + text.sentences[i].length + 1 > MAX_SENTENCE_LENGTH) {
            break;
        }
        strcpy(input, text.sentences[i].text);
        j = strlen(input);
        while (j > 0 && input[j-1] == '.' || input[j-1] == '?' || input[j-1] == '!') {
            input[j-1] = '\0';
            j--;
        }
        strcat(input, " ");
        strcat(input, text.sentences[i].text);
        summaryLength += strlen(input);
    }
    printf("Summary:\n");
    printf("%s", input);

    return 0;
}