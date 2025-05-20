//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
// A tragic tale of word frequency counting in the city of Verona

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int main(){
    FILE *fp;
    char filename[20];
    char word[MAX_WORD_LENGTH];
    char *words[MAX_NUM_WORDS];
    int freq[MAX_NUM_WORDS], i, j, count, total_words;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // initialize counters
    total_words = 0;
    for(i = 0; i < MAX_NUM_WORDS; i++) {
        freq[i] = 0;
    }

    // read in words and count
    while(fscanf(fp, "%s", word) != EOF) {
        // remove punctuation marks at the start or end of words
        if(word[0] == '.' || word[0] == ',' || word[0] == ':' || word[0] == ';' || word[0] == '!' || word[0] == '?') {
            memmove(word, word+1, strlen(word));
        }
        if(word[strlen(word)-1] == '.' || word[strlen(word)-1] == ',' || word[strlen(word)-1] == ':' || word[strlen(word)-1] == ';' || word[strlen(word)-1] == '!' || word[strlen(word)-1] == '?') {
            word[strlen(word)-1] = '\0';
        }
        // convert to lowercase
        for(i = 0; i < strlen(word); i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                word[i] += 'a' - 'A';
            }
        }
        // check if word already exists in array
        count = 0;
        for(i = 0; i < total_words; i++) {
            if(strcmp(words[i], word) == 0) {
                count = freq[i] + 1;
                freq[i] = count;
                break;
            }
        }
        if(count == 0) {
            freq[total_words] = 1;
            words[total_words] = strdup(word);
            total_words++;
        }
    }

    // print out results
    printf("Total Words: %d\n", total_words);
    printf("Word\tFrequency\n");
    for(i = 0; i < total_words; i++) {
        printf("%s\t%d\n", words[i], freq[i]);
    }

    // free memory
    for(i = 0; i < total_words; i++) {
        free(words[i]);
    }

    return 0;
}