//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
// C Text Summarizer Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Structure to store information about a sentence
typedef struct {
    char sentence[MAX_LENGTH];
    int length;
} Sentence;

// Function to read a sentence from the user
Sentence read_sentence() {
    Sentence sentence;
    printf("Enter a sentence: ");
    fgets(sentence.sentence, MAX_LENGTH, stdin);
    sentence.length = strlen(sentence.sentence);
    return sentence;
}

// Function to check if a sentence is a duplicate
int is_duplicate(Sentence sentence, Sentence* sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        if (strcmp(sentence.sentence, sentences[i].sentence) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to summarize a set of sentences
void summarize(Sentence* sentences, int num_sentences) {
    int num_unique_sentences = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (!is_duplicate(sentences[i], sentences, num_sentences)) {
            num_unique_sentences++;
        }
    }
    Sentence* unique_sentences = (Sentence*)malloc(num_unique_sentences * sizeof(Sentence));
    int j = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (!is_duplicate(sentences[i], sentences, num_sentences)) {
            unique_sentences[j] = sentences[i];
            j++;
        }
    }
    for (int i = 0; i < num_unique_sentences; i++) {
        printf("%s\n", unique_sentences[i].sentence);
    }
    free(unique_sentences);
}

// Main function
int main() {
    int num_sentences;
    printf("Enter the number of sentences: ");
    scanf("%d", &num_sentences);
    Sentence* sentences = (Sentence*)malloc(num_sentences * sizeof(Sentence));
    for (int i = 0; i < num_sentences; i++) {
        sentences[i] = read_sentence();
    }
    summarize(sentences, num_sentences);
    free(sentences);
    return 0;
}