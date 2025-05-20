//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    Word *words;
    int num_words;
} Sentence;

// Function to split a sentence into words
void split_sentence(char sentence[], Sentence *result) {
    char *token = strtok(sentence, " ");
    int i = 0;
    while (token!= NULL) {
        strncpy(result->words[i].word, token, MAX_WORD_LENGTH);
        result->words[i].length = strlen(token);
        i++;
        token = strtok(NULL, " ");
    }
    result->num_words = i;
}

// Function to print a sentence
void print_sentence(Sentence sentence) {
    for (int i = 0; i < sentence.num_words; i++) {
        printf("%s ", sentence.words[i].word);
    }
    printf("\n");
}

// Function to align a sentence
void align_sentence(Sentence sentence, int max_width) {
    int i, j, k;
    for (i = 0; i < sentence.num_words; i++) {
        for (j = 0; j < sentence.words[i].length; j++) {
            printf(" ");
        }
        for (j = 0; j < sentence.words[i].length; j++) {
            printf("%c", sentence.words[i].word[j]);
        }
        for (k = j; k < max_width; k++) {
            printf(" ");
        }
        printf("\n");
    }
}

// Function to find the longest common suffix of a sentence
int find_longest_common_suffix(Sentence sentence) {
    int suffix_length = 0;
    while (suffix_length < sentence.num_words &&
           strcmp(sentence.words[0].word, sentence.words[sentence.num_words - 1].word) == 0) {
        suffix_length++;
    }
    return suffix_length;
}

// Function to align a sentence greedily
void align_sentence_greedily(Sentence sentence, int max_width) {
    int i, j, k, suffix_length;
    suffix_length = find_longest_common_suffix(sentence);
    for (i = 0; i < sentence.num_words; i++) {
        for (j = 0; j < sentence.words[i].length; j++) {
            printf(" ");
        }
        for (j = 0; j < sentence.words[i].length; j++) {
            printf("%c", sentence.words[i].word[j]);
        }
        for (k = j; k < max_width - suffix_length; k++) {
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    char sentence[] = "The quick brown fox jumps over the lazy dog";
    Sentence result;
    split_sentence(sentence, &result);
    int max_width = 50;
    align_sentence(result, max_width);
    printf("\n");
    align_sentence_greedily(result, max_width);
    return 0;
}