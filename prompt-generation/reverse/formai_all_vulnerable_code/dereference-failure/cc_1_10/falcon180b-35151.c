//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to count the number of words in a string
int count_words(char* str) {
    char* word = strtok(str, ",.?!;:");
    int count = 0;
    while (word!= NULL) {
        count++;
        word = strtok(NULL, ",.?!;:");
    }
    return count;
}

// Function to print the most common words in a string
void print_common_words(char* str, int num_words) {
    int word_counts[MAX_WORD_LENGTH] = {0};
    char* words[MAX_WORD_LENGTH];
    int num_unique_words = 0;
    char* word = strtok(str, ",.?!;:");
    while (word!= NULL) {
        if (num_unique_words >= MAX_WORD_LENGTH) {
            break;
        }
        if (strlen(word) > MAX_WORD_LENGTH) {
            word = strtok(NULL, ",.?!;:");
            continue;
        }
        if (isalpha(word[0])) {
            for (int i = 0; i < num_unique_words; i++) {
                if (strcmp(word, words[i]) == 0) {
                    word_counts[i]++;
                    break;
                }
            }
        } else {
            continue;
        }
        strcpy(words[num_unique_words], word);
        word_counts[num_unique_words]++;
        num_unique_words++;
        word = strtok(NULL, ",.?!;:");
    }
    for (int i = 0; i < num_unique_words; i++) {
        printf("%s: %d\n", words[i], word_counts[i]);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    char* str = argv[1];
    int num_words = count_words(str);
    printf("Number of words: %d\n", num_words);
    print_common_words(str, num_words);
    return 0;
}