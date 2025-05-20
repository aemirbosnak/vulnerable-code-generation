//FormAI DATASET v1.0 Category: Text Summarizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_SUMMARY_LENGTH 10000
#define MAX_KEYWORDS 10
#define MINIMUM_OCCURRENCE 2

// Function to tokenize a string
void tokenize(char* sentence, char tokens[][MAX_SENTENCE_LENGTH]) {
    int i = 0;
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, " ");
    }
}

// Function to compare two strings while ignoring case
int strcasecmp(const char* s1, const char* s2) {
    const char* p1 = s1;
    const char* p2 = s2;
    int result;
    if (p1 == p2)
        return 0;
    while ((result = tolower(*p1) - tolower(*p2++)) == 0)
        if (*p1++ == 0)
            break;
    return result;
}

// Function to get the frequency of a keyword in a sentence
int keyword_frequency(char* sentence, char* keyword) {
    char tokens[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    tokenize(sentence, tokens);
    int i, frequency = 0;
    for (i = 0; i < MAX_SENTENCES && strlen(tokens[i]) > 0; i++) {
        if (strcasecmp(tokens[i], keyword) == 0) {
            frequency++;
        }
    }
    return frequency;
}

int main() {
    char text[MAX_SUMMARY_LENGTH];
    printf("Enter the text:\n");
    fgets(text, MAX_SUMMARY_LENGTH, stdin);

    // Remove newline character from the end of text
    text[strlen(text) - 1] = '\0';

    // Tokenize the text into individual sentences
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    char delimiters[] = ".!?";
    char* sentence = strtok(text, delimiters);
    int i = 0;
    while (sentence != NULL) {
        strcpy(sentences[i], sentence);
        i++;
        sentence = strtok(NULL, delimiters);
    }

    // Get the keywords from the user
    char keywords[MAX_KEYWORDS][MAX_SENTENCE_LENGTH];
    printf("Enter the keywords(separated by spaces):\n");
    fgets(keywords[0], MAX_SENTENCE_LENGTH, stdin);
    keywords[0][strlen(keywords[0]) - 1] = '\0';
    char* token = strtok(keywords[0], " ");
    i = 0;
    while (token != NULL) {
        strcpy(keywords[i], token);
        i++;
        token = strtok(NULL, " ");
    }

    // Get the frequency count of each keyword in each sentence
    int sentence_frequencies[MAX_SENTENCES] = { 0 };
    for (i = 0; i < MAX_SENTENCES && strlen(sentences[i]) > 0; i++) {
        int j, sum = 0;
        for (j = 0; j < MAX_KEYWORDS; j++) {
            sum += keyword_frequency(sentences[i], keywords[j]);
        }
        sentence_frequencies[i] = sum;
    }

    // Find the sentences with the highest frequency count
    int k = 0;
    char summary[MAX_SUMMARY_LENGTH] = "";
    for (i = 0; i < MAX_SENTENCES && k < 5 && strlen(sentences[i]) > 0; i++) {
        if (sentence_frequencies[i] >= MINIMUM_OCCURRENCE) {
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
            k++;
        }
    }
    printf("Summary:\n%s\n", summary);
    return 0;
}