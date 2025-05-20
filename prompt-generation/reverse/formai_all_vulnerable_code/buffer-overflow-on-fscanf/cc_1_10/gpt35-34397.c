//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

int word_count = 0;
int freq_count = 0;

char* words[MAX_WORDS];
int freq[MAX_WORDS];

void read_words(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if(file == NULL) {
        printf("Error reading file!\n");
        exit(1);
    }

    char* word = (char*) malloc(sizeof(char) * MAX_WORD_LENGTH);
    while(fscanf(file, " %s", word) != EOF) {
        int word_exists = 0;
        for(int i = 0; i < word_count; i++) {
            if(strcmp(word, words[i]) == 0) {
                freq[i] += 1;
                freq_count += 1;
                word_exists = 1;
                break;
            }
        }

        if(!word_exists) {
            words[word_count] = word;
            freq[word_count] += 1;
            freq_count += 1;
            word_count += 1;
        }

        word = (char*) malloc(sizeof(char) * MAX_WORD_LENGTH);
    }

    fclose(file);
}

void print_frequencies() {
    printf("Word\tFrequency\n");
    for(int i = 0; i < word_count; i++) {
        printf("%s:\t%d\n", words[i], freq[i]);
    }

    printf("\nTotal Words: %d\n", freq_count);
}

int main() {
    char* file_name = "example.txt";
    read_words(file_name);
    print_frequencies();

    return 0;
}