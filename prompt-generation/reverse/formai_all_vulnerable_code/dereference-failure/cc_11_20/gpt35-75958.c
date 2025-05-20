//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200

int main() {
    char input_text[10000], sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentence_count=0, i, j, k, word_count, total_words=0, freq[MAX_SENTENCES], max_freq_index;
    float scores[MAX_SENTENCES];

    // Input text
    printf("Welcome to our text summarizer program.\nPlease input your text:\n");
    fgets(input_text, 10000, stdin);

    // Split text into sentences
    for (i=0, j=0; i<strlen(input_text); i++) {
        if (input_text[i] == '.' || input_text[i] == '!' || input_text[i] == '?') {
            sentence_count++;
            j=0;
        } else {
            sentences[sentence_count][j++] = input_text[i];
        }
    }

    // Remove leading and trailing whitespace from sentences
    for (i=0; i<=sentence_count; i++) {
        char *s = sentences[i];
        while (isspace(*s)) s++;
        j = strlen(s)-1;
        while (isspace(s[j])) j--;
        s[j+1] = '\0';
        strcpy(sentences[i], s);
    }

    // Calculate word count and word frequency for each sentence
    for (i=0; i<=sentence_count; i++) {
        word_count = 0;
        for (j=0; j<strlen(sentences[i]); j++) {
            if (isspace(sentences[i][j])) {
                word_count++;
            }
        }
        freq[i] = word_count;
        total_words += word_count;
    }

    // Calculate score for each sentence
    for (i=0; i<=sentence_count; i++) {
        scores[i] = (float)freq[i] / (float)total_words;
    }

    // Print summary by selecting highest scoring sentences
    printf("Here's a summary of your text:\n");
    for (i=0; i<3; i++) { // Print top 3 sentences
        max_freq_index = 0;
        for (j=0; j<=sentence_count; j++) {
            if (scores[j] > scores[max_freq_index]) {
                max_freq_index = j;
            }
        }
        printf("%s\n", sentences[max_freq_index]);
        scores[max_freq_index] = -1; // Mark sentence as printed
    }

    return 0;
}