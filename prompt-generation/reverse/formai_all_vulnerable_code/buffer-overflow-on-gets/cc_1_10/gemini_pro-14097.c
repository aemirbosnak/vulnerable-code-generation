//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to store a sentence and its score
typedef struct Sentence {
    char *sentence;
    int score;
} Sentence;

// Custom comparator function for qsort
int compareSentences(const void *a, const void *b) {
    const Sentence *s1 = (const Sentence *)a;
    const Sentence *s2 = (const Sentence *)b;
    return s2->score - s1->score;
}

// Function to calculate the score of a sentence
int calculateScore(char *sentence) {
    int score = 0;
    int length = strlen(sentence);

    // Iterate over the sentence and count the number of words and punctuation marks
    for (int i = 0; i < length; i++) {
        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '!' || sentence[i] == '?') {
            score++;
        }
    }

    // Return the score
    return score;
}

// Function to summarize a text
char *summarizeText(char *text, int numSentences) {
    // Split the text into sentences
    char *sentences[100];
    int numWords = 0;
    char *token = strtok(text, ".");
    while (token != NULL) {
        sentences[numWords++] = token;
        token = strtok(NULL, ".");
    }

    // Calculate the score of each sentence
    Sentence sentencesWithScores[numWords];
    for (int i = 0; i < numWords; i++) {
        sentencesWithScores[i].sentence = sentences[i];
        sentencesWithScores[i].score = calculateScore(sentences[i]);
    }

    // Sort the sentences by score in descending order
    qsort(sentencesWithScores, numWords, sizeof(Sentence), compareSentences);

    // Create the summary by concatenating the top-scoring sentences
    char *summary = malloc(1000);
    strcpy(summary, "");
    for (int i = 0; i < numSentences; i++) {
        strcat(summary, sentencesWithScores[i].sentence);
        strcat(summary, ". ");
    }

    // Return the summary
    return summary;
}

// Main function
int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text to be summarized: ");
    gets(text);

    // Get the number of sentences to include in the summary
    int numSentences;
    printf("Enter the number of sentences to include in the summary: ");
    scanf("%d", &numSentences);

    // Summarize the text
    char *summary = summarizeText(text, numSentences);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free(summary);

    return 0;
}