//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

typedef struct {
    char *word;
    int count;
} Word;

typedef struct {
    char *sentence;
    int score;
} Sentence;

int compare_words(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int compare_sentences(const void *a, const void *b) {
    return ((Sentence *)b)->score - ((Sentence *)a)->score;
}

double calc_sentence_score(char *sentence, Word *words, int num_words) {
    char *word;
    int count;
    double score = 0.0;

    word = strtok(sentence, " ");
    while (word != NULL) {
        count = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                count = words[i].count;
                break;
            }
        }
        score += log(1 + count);
        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    char *text;
    char *words[MAX_WORDS];
    char *sentences[MAX_SENTENCES];
    Word word_list[MAX_WORDS];
    Sentence sentence_list[MAX_SENTENCES];
    int num_words = 0;
    int num_sentences = 0;
    int num_unique_words = 0;
    int max_sentence_length = 0;

    // Read the text from the standard input
    text = malloc(1000000);
    scanf("%[^\n]", text);

    // Tokenize the text into words
    char *word = strtok(text, " ");
    while (word != NULL) {
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }

    // Sort the words in alphabetical order
    qsort(words, num_words, sizeof(char *), compare_words);

    // Count the occurrences of each word
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], words[i + 1]) != 0) {
            word_list[num_unique_words].word = words[i];
            word_list[num_unique_words].count = 1;
            num_unique_words++;
        } else {
            word_list[num_unique_words - 1].count++;
        }
    }

    // Tokenize the text into sentences
    char *sentence = strtok(text, ".");
    while (sentence != NULL) {
        sentences[num_sentences] = sentence;
        num_sentences++;
        sentence = strtok(NULL, ".");
    }

    // Calculate the score of each sentence
    for (int i = 0; i < num_sentences; i++) {
        sentence_list[i].sentence = sentences[i];
        sentence_list[i].score = calc_sentence_score(sentences[i], word_list, num_unique_words);
    }

    // Sort the sentences in descending order of score
    qsort(sentence_list, num_sentences, sizeof(Sentence), compare_sentences);

    // Print the top-scoring sentence
    printf("%s\n", sentence_list[0].sentence);

    // Free the allocated memory
    free(text);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }

    return 0;
}