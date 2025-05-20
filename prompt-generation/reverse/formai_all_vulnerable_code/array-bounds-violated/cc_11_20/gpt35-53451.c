//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_WORDS 1000

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    char text[10000];
    int count_map[MAX_WORDS], unique_words = 0, total_words = 0;
    char word[MAX_WORD_LENGTH];

    printf("Enter text to analyze:\n");
    fgets(text, 10000, stdin);

    int len = strlen(text);
    if(text[len - 1] == '\n') text[len - 1] = 0;

    for(int i = 0; i < len; ++i) {
        char letter = tolower(text[i]);
        if(letter >= 'a' && letter <= 'z') {
            word[strlen(word)] = letter;
        } else if(strlen(word)) {
            ++total_words;
            int found = 0;
            for(int j = 0; j < unique_words; ++j) {
                if(!strcmp(word, text + count_map[j])) {
                    ++count_map[j + MAX_WORD_LENGTH];
                    found = 1;
                    break;
                }
            }

            if(!found) {
                ++unique_words;
                count_map[unique_words - 1 + MAX_WORD_LENGTH] = total_words - 1;
                count_map[unique_words - 1] = 1;
                strcpy(text + count_map[unique_words - 1 + MAX_WORD_LENGTH], word);
            }
            word[0] = 0;
        }
    }

    if(strlen(word)) {
        ++total_words;
        int found = 0;
        for(int j = 0; j < unique_words; ++j) {
            if(!strcmp(word, text + count_map[j])) {
                ++count_map[j + MAX_WORD_LENGTH];
                found = 1;
                break;
            }
        }

        if(!found) {
            ++unique_words;
            count_map[unique_words - 1 + MAX_WORD_LENGTH] = total_words - 1;
            count_map[unique_words - 1] = 1;
            strcpy(text + count_map[unique_words - 1 + MAX_WORD_LENGTH], word);
        }
    }

    printf("Total words: %d\n", total_words);
    printf("Unique words: %d\n", unique_words);
    printf("Word frequency:\n");
    int max_frequency = 1, min_frequency = MAX_WORDS;

    for(int i = 0; i < unique_words; ++i) {
        int count = count_map[i + MAX_WORD_LENGTH];
        if(count > max_frequency) max_frequency = count;
        if(count < min_frequency) min_frequency = count;
    }

    int range = max_frequency - min_frequency;
    int buckets[10], div = range / 10;

    memset(buckets, 0, sizeof(buckets));

    for(int i = 0; i < unique_words; ++i) {
        int count = count_map[i + MAX_WORD_LENGTH];
        ++buckets[((count - min_frequency) / div)];
    }

    for(int i = 0; i < 10; ++i) {
        printf("%2d%% -%2d%% |", i * 10, i * 10 + 9);
        for(int j = 0; j < range / 10; ++j) {
            if(j < buckets[i] * 50 / unique_words) {
                printf("=");
            } else {
                printf(" ");
            }
        }
        printf("| %d\n", buckets[i]);
    }

    printf("------------------------------------\n");
    qsort(count_map, unique_words, sizeof(int) * 2, compare);
    for(int i = 0; i < unique_words; ++i) {
        printf("%-20s | %d\n", text + count_map[i + MAX_WORD_LENGTH], count_map[i]);
    }

    return 0;
}