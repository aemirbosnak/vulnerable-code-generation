//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 100

void summarize(char text[], int num_sentences);

int main() {
    char text[10000];
    int num_sentences;
    
    printf("Enter the text to summarize:\n");
    fgets(text, 10000, stdin);
    
    printf("Enter the number of sentences for the summary:\n");
    scanf("%d", &num_sentences);
    
    summarize(text, num_sentences);
    
    return 0;
}

void summarize(char text[], int num_sentences) {
    char sentences[MAX_SENTENCES][1000];
    char words[MAX_SENTENCES][MAX_WORDS][50];
    int sentence_count = 0;
    int word_count[MAX_SENTENCES] = {0};
    
    // Split text into sentences
    char* token = strtok(text, ".!?");
    while (token != NULL && sentence_count < MAX_SENTENCES) {
        strcpy(sentences[sentence_count], token);
        sentence_count++;
        token = strtok(NULL, ".!?");
    }
    
    // Split sentences into words
    for (int i = 0; i < sentence_count; i++) {
        char* word = strtok(sentences[i], " \n\t");
        while (word != NULL) {
            // Remove punctuation and convert to lowercase
            for (int j = 0; j < strlen(word); j++) {
                if (ispunct(word[j])) {
                    memmove(&word[j], &word[j+1], strlen(word)-j);
                    j--;
                } else {
                    word[j] = tolower(word[j]);
                }
            }
            strcpy(words[i][word_count[i]], word);
            word_count[i]++;
            word = strtok(NULL, " \n\t");
        }
    }
    
    // Calculate word frequency for each sentence
    int freq[MAX_SENTENCES][MAX_WORDS] = {0};
    for (int i = 0; i < sentence_count; i++) {
        for (int j = 0; j < word_count[i]; j++) {
            char* word = words[i][j];
            for (int k = 0; k < sentence_count; k++) {
                if (k == i) {
                    continue;
                }
                for (int l = 0; l < word_count[k]; l++) {
                    if (strcmp(words[k][l], word) == 0) {
                        freq[i][j]++;
                    }
                }
            }
        }
    }
    
    // Calculate sentence importance
    int importance[MAX_SENTENCES] = {0};
    for (int i = 0; i < sentence_count; i++) {
        for (int j = 0; j < word_count[i]; j++) {
            importance[i] += freq[i][j];
        }
    }
    
    // Print summary
    for (int i = 0; i < num_sentences; i++) {
        int max = 0;
        int max_index = 0;
        for (int j = 0; j < sentence_count; j++) {
            if (importance[j] > max) {
                max = importance[j];
                max_index = j;
            }
        }
        printf("%s.\n", sentences[max_index]);
        importance[max_index] = 0;
    }
}