//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

typedef struct {
    char *word;
    int count;
} word_count;

typedef struct {
    word_count *words;
    int num_words;
} sentence;

int compare_word_counts(const void *a, const void *b) {
    return ((word_count *)a)->count - ((word_count *)b)->count;
}

int main() {
    // Read the input text from stdin
    char text[100000];
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Error reading input text\n");
        return 1;
    }

    // Tokenize the text into sentences
    char *sentences[MAX_SENTENCES];
    int num_sentences = 0;
    char *sentence_start = text;
    while (*sentence_start != '\0') {
        // Find the end of the sentence
        char *sentence_end = strchr(sentence_start, '.');
        if (sentence_end == NULL) {
            sentence_end = strchr(sentence_start, '?');
        }
        if (sentence_end == NULL) {
            sentence_end = strchr(sentence_start, '!');
        }
        if (sentence_end == NULL) {
            break;
        }

        // Copy the sentence into the array
        sentences[num_sentences] = malloc(sentence_end - sentence_start + 1);
        strncpy(sentences[num_sentences], sentence_start, sentence_end - sentence_start);
        sentences[num_sentences][sentence_end - sentence_start] = '\0';
        num_sentences++;

        // Advance to the next sentence
        sentence_start = sentence_end + 1;
    }

    // Tokenize each sentence into words
    sentence sentences_with_words[MAX_SENTENCES];
    for (int i = 0; i < num_sentences; i++) {
        char *words[MAX_WORDS];
        int num_words = 0;
        char *word_start = sentences[i];
        while (*word_start != '\0') {
            // Skip whitespace
            while (isspace(*word_start)) {
                word_start++;
            }

            // Find the end of the word
            char *word_end = strchr(word_start, ' ');
            if (word_end == NULL) {
                word_end = strchr(word_start, '.');
            }
            if (word_end == NULL) {
                word_end = strchr(word_start, '?');
            }
            if (word_end == NULL) {
                word_end = strchr(word_start, '!');
            }
            if (word_end == NULL) {
                break;
            }

            // Copy the word into the array
            words[num_words] = malloc(word_end - word_start + 1);
            strncpy(words[num_words], word_start, word_end - word_start);
            words[num_words][word_end - word_start] = '\0';
            num_words++;

            // Advance to the next word
            word_start = word_end + 1;
        }

        // Create a sentence struct with the words
        sentences_with_words[i].words = malloc(sizeof(word_count) * num_words);
        sentences_with_words[i].num_words = num_words;
        for (int j = 0; j < num_words; j++) {
            sentences_with_words[i].words[j].word = words[j];
            sentences_with_words[i].words[j].count = 1;
        }
    }

    // Count the number of occurrences of each word in each sentence
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < sentences_with_words[i].num_words; j++) {
            for (int k = j + 1; k < sentences_with_words[i].num_words; k++) {
                if (strcmp(sentences_with_words[i].words[j].word, sentences_with_words[i].words[k].word) == 0) {
                    sentences_with_words[i].words[j].count++;
                    sentences_with_words[i].words[k].count--;
                }
            }
        }
    }

    // Sort the words in each sentence by their frequency
    for (int i = 0; i < num_sentences; i++) {
        qsort(sentences_with_words[i].words, sentences_with_words[i].num_words, sizeof(word_count), compare_word_counts);
    }

    // Print the top 10 words in each sentence
    for (int i = 0; i < num_sentences; i++) {
        printf("Sentence %d:\n", i + 1);
        for (int j = 0; j < 10 && j < sentences_with_words[i].num_words; j++) {
            printf("\t%s: %d\n", sentences_with_words[i].words[j].word, sentences_with_words[i].words[j].count);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < sentences_with_words[i].num_words; j++) {
            free(sentences_with_words[i].words[j].word);
        }
        free(sentences_with_words[i].words);
        free(sentences[i]);
    }

    return 0;
}