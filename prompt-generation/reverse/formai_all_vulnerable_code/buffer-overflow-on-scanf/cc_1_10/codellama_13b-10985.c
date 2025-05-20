//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: genius
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <math.h>
    #include <ctype.h>

    #define MAX_STRING_LENGTH 256
    #define MAX_WORDS 1000
    #define MAX_PHRASES 100
    #define MAX_SPAM_THRESHOLD 0.9

    typedef struct {
        char* word;
        int frequency;
    } Word;

    typedef struct {
        char* phrase;
        int frequency;
    } Phrase;

    int compare_words(const void* a, const void* b) {
        return (*(Word*)b).frequency - (*(Word*)a).frequency;
    }

    int compare_phrases(const void* a, const void* b) {
        return (*(Phrase*)b).frequency - (*(Phrase*)a).frequency;
    }

    void add_word(Word* words, char* word, int* word_count) {
        for (int i = 0; i < *word_count; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                return;
            }
        }
        words[*word_count].word = word;
        words[*word_count].frequency = 1;
        (*word_count)++;
    }

    void add_phrase(Phrase* phrases, char* phrase, int* phrase_count) {
        for (int i = 0; i < *phrase_count; i++) {
            if (strcmp(phrases[i].phrase, phrase) == 0) {
                phrases[i].frequency++;
                return;
            }
        }
        phrases[*phrase_count].phrase = phrase;
        phrases[*phrase_count].frequency = 1;
        (*phrase_count)++;
    }

    void sort_words(Word* words, int word_count) {
        qsort(words, word_count, sizeof(Word), compare_words);
    }

    void sort_phrases(Phrase* phrases, int phrase_count) {
        qsort(phrases, phrase_count, sizeof(Phrase), compare_phrases);
    }

    int is_spam(Word* words, int word_count, Phrase* phrases, int phrase_count, double spam_threshold) {
        int spam_words = 0;
        int spam_phrases = 0;
        for (int i = 0; i < word_count; i++) {
            if (words[i].frequency > spam_threshold) {
                spam_words++;
            }
        }
        for (int i = 0; i < phrase_count; i++) {
            if (phrases[i].frequency > spam_threshold) {
                spam_phrases++;
            }
        }
        return (spam_words + spam_phrases) > (word_count + phrase_count) * spam_threshold;
    }

    int main() {
        char input[MAX_STRING_LENGTH];
        Word words[MAX_WORDS];
        Phrase phrases[MAX_PHRASES];
        int word_count = 0;
        int phrase_count = 0;
        double spam_threshold = 0.7;
        while (1) {
            printf("Enter a sentence: ");
            scanf("%s", input);
            if (strcmp(input, "exit") == 0) {
                break;
            }
            char* token = strtok(input, " ");
            while (token != NULL) {
                add_word(words, token, &word_count);
                token = strtok(NULL, " ");
            }
            token = strtok(input, " ");
            while (token != NULL) {
                add_phrase(phrases, token, &phrase_count);
                token = strtok(NULL, " ");
            }
        }
        sort_words(words, word_count);
        sort_phrases(phrases, phrase_count);
        if (is_spam(words, word_count, phrases, phrase_count, spam_threshold)) {
            printf("This is spam.\n");
        } else {
            printf("This is not spam.\n");
        }
        return 0;
    }