//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

// Function to remove punctuation from a sentence
void remove_punctuation(char* sentence) {
    int i = 0, j = 0;
    while (sentence[i]!= '\0') {
        if (!ispunct(sentence[i])) {
            sentence[j++] = sentence[i];
        }
        i++;
    }
    sentence[j] = '\0';
}

// Function to split a paragraph into sentences
void split_paragraph(char* paragraph, char* sentences[]) {
    int num_sentences = 0;
    char* sentence = strtok(paragraph, ".");
    while (sentence!= NULL) {
        remove_punctuation(sentence);
        strcpy(sentences[num_sentences], sentence);
        num_sentences++;
        sentence = strtok(NULL, ".");
    }
}

// Function to generate a summary of a paragraph
void generate_summary(char* sentences[], int num_sentences, int max_summary_length, char* summary) {
    int i = 0, j = 0;
    while (i < num_sentences && j < max_summary_length) {
        strcat(summary, sentences[i]);
        strcat(summary, " ");
        i++;
        j++;
    }
    if (j < max_summary_length) {
        strcat(summary, "...");
    }
    summary[strcspn(summary, "\n")] = '\0';
}

int main() {
    char paragraph[MAX_SENTENCE_LENGTH];
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    char summary[MAX_SENTENCE_LENGTH];

    // Get paragraph from user
    printf("Enter a paragraph: ");
    fgets(paragraph, MAX_SENTENCE_LENGTH, stdin);

    // Split paragraph into sentences
    int num_sentences = 0;
    split_paragraph(paragraph, sentences);

    // Get desired summary length from user
    int max_summary_length;
    printf("Enter maximum summary length: ");
    scanf("%d", &max_summary_length);

    // Generate summary
    generate_summary(sentences, num_sentences, max_summary_length, summary);

    // Print summary
    printf("Summary: %s\n", summary);

    return 0;
}