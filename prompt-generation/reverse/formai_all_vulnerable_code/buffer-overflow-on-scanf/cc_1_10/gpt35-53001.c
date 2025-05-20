//FormAI DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <string.h>

// function to count number of words in a string
int wordCount(char *str) {
    int count = 0;
    char prev = ' ';
    for(int i=0; i<strlen(str); i++) {
        if(prev == ' ' && str[i] != ' ') {
            count++;
        }
        prev = str[i];
    }
    return count;
}

// function to count number of occurrences of a word in a string
int wordOccurrence(char *str, char *word) {
    int count = 0;
    char *ptr = strstr(str, word);
    while(ptr != NULL) {
        count++;
        ptr = strstr(ptr + strlen(word), word);
    }
    return count;
}

// function to summarize a given text string
char* summarizeText(char *text, int summaryLength) {
    char *summary = malloc(summaryLength * sizeof(char));
    char *word = strtok(text, " ");
    int count = 0;
    while(word != NULL && count < summaryLength) {
        strcat(summary, word);
        strcat(summary, " ");
        word = strtok(NULL, " ");
        count++;
    }
    return summary;
}

int main() {
    char text[1000], word[50];
    printf("Enter the text to summarize: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the word to count occurrences for: ");
    scanf("%s", word);

    int totalWords = wordCount(text);
    int wordCount = wordOccurrence(text, word);
    float occurrencePercentage = (float) wordCount / (float) totalWords * 100.0;
    printf("\nTotal Words: %d", totalWords);
    printf("\nOccurrence of '%s': %d", word, wordCount);
    printf("\nOccurrence Percentage: %2.2f%%", occurrencePercentage);

    printf("\nEnter the summary length: ");
    int summaryLength;
    scanf("%d", &summaryLength);
    char *summary = summarizeText(text, summaryLength);
    printf("\nSummary: %s", summary);

    free(summary);
    return 0;
}