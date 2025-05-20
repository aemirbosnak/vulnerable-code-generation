//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

// Function to compare strings (case insensitive)
int compare_strings(const void *a, const void *b) {
    return strcasecmp(*(char **)a, *(char **)b);
}

// Function to split a string into words
void split_string(char *line, char **words) {
    char *word = strtok(line, ",.?!;:");
    int i = 0;

    while (word!= NULL) {
        if (i >= MAX_WORDS - 1) {
            break;
        }
        words[i] = word;
        i++;
        word = strtok(NULL, ",.?!;:");
    }

    words[i] = NULL;
}

// Function to print the frequency of each word
void print_word_frequency(char **words, int *freq) {
    qsort(words, MAX_WORDS, sizeof(char *), compare_strings);

    for (int i = 0; i < MAX_WORDS && words[i]!= NULL; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }
}

// Main function
int main() {
    FILE *file;
    char line[MAX_WORD_LEN];
    char **words = malloc(MAX_WORDS * sizeof(char *));
    int freq[MAX_WORDS] = {0};

    if ((file = fopen("post_apocalyptic_story.txt", "r")) == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        split_string(line, words);

        for (int i = 0; i < MAX_WORDS && words[i]!= NULL; i++) {
            freq[i]++;
        }
    }

    print_word_frequency(words, freq);

    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }
    free(words);

    fclose(file);

    return 0;
}