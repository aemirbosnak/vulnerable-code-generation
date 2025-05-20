//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int num_words;
} Sentence;

int compare_words(const void* a, const void* b) {
    const Word* word1 = a;
    const Word* word2 = b;

    if (word1->length > word2->length) {
        return -1;
    } else if (word1->length < word2->length) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input_sentence[MAX_WORD_LENGTH * 100];
    int input_sentence_length;
    Sentence sentence;

    printf("Enter a sentence: ");
    scanf("%s", input_sentence);
    input_sentence_length = strlen(input_sentence);

    int num_words = 0;
    char* current_word = input_sentence;
    char* end_of_word = NULL;

    while (num_words < MAX_WORDS && *current_word!= '\0') {
        end_of_word = strpbrk(current_word, ",.?!;:");
        if (end_of_word == NULL) {
            end_of_word = current_word + strlen(current_word);
        }

        int word_length = end_of_word - current_word;
        if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
            strncpy(sentence.words[num_words].word, current_word, word_length);
            sentence.words[num_words].word[word_length] = '\0';
            sentence.words[num_words].length = word_length;
            num_words++;
        }

        current_word = end_of_word + 1;
    }

    qsort(sentence.words, num_words, sizeof(Word), compare_words);

    printf("Sorted sentence: ");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", sentence.words[i].word);
    }
    printf("\n");

    return 0;
}