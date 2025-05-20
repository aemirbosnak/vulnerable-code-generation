//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} Word;

typedef struct {
    char sentence[MAX_WORD_LEN];
    int freq;
} Sentence;

void print_word_freq(Word* words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].freq);
    }
}

void print_sentence_freq(Sentence* sentences, int num_sentences) {
    int i;
    for (i = 0; i < num_sentences; i++) {
        printf("%s: %d\n", sentences[i].sentence, sentences[i].freq);
    }
}

int main() {
    char text[MAX_SENTENCES][MAX_WORD_LEN];
    int num_sentences = 0;
    int num_words = 0;
    int i, j;

    // Read text from stdin
    while (scanf("%s", text[num_sentences]) != EOF) {
        num_sentences++;
    }

    // Initialize word and sentence arrays
    Word words[MAX_SENTENCES];
    Sentence sentences[MAX_SENTENCES];

    // Count word frequencies
    for (i = 0; i < num_sentences; i++) {
        char* word = strtok(text[i], " ");
        while (word != NULL) {
            int found = 0;
            for (j = 0; j < num_words; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    words[j].freq++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(words[num_words].word, word);
                words[num_words].freq = 1;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Count sentence frequencies
    for (i = 0; i < num_sentences; i++) {
        int found = 0;
        for (j = 0; j < num_sentences; j++) {
            if (strcmp(text[i], sentences[j].sentence) == 0) {
                sentences[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(sentences[num_sentences].sentence, text[i]);
            sentences[num_sentences].freq = 1;
            num_sentences++;
        }
    }

    // Print word frequencies
    print_word_freq(words, num_words);

    // Print sentence frequencies
    print_sentence_freq(sentences, num_sentences);

    return 0;
}