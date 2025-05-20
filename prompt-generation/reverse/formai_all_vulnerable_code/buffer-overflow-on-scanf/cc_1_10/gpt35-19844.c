//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// A structure to store word and its count in a file
typedef struct WordFreq {
    char* word;
    int count;
} WordFreq;

// A function to compare two WordFreq structures for sorting 
int compare(const void* a, const void* b) {
    WordFreq* wf1 = (WordFreq*) a;
    WordFreq* wf2 = (WordFreq*) b;
    return wf2->count - wf1->count;
}

// A function to add a word to WordFreq structure array
void addWord(WordFreq* wf, char* word) {
    int i;
    // Convert the word to lowercase
    for(i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    // Check if the word already exists in the array
    for(i = 0; wf[i].word; i++) {
        if(strcmp(wf[i].word, word) == 0) {          
            wf[i].count++;
            free(word);
            return;
        }
    }
    // Add the new word to the array if it doesn't exist
    wf[i].word = word;
    wf[i].count = 1;
    wf[i+1].word = NULL;
}

// A function to read a file and count the number of occurrences of each word
WordFreq* count(FILE* fp) {
    char c, *word = NULL;
    int i = 0, size = 0;
    WordFreq* wf = (WordFreq*) calloc(1, sizeof(WordFreq));
    while((c = fgetc(fp)) != EOF) {
        if(isalpha(c)) {
            size++;
            word = (char*) realloc(word, size*sizeof(char));
            word[i++] = c;
        }
        else if(word) {
            word = (char*) realloc(word, (size+1)*sizeof(char));
            word[size++] = '\0';
            addWord(wf, word);
            word = NULL;
            i = 0;
            size = 0;
        }
    }
    // Free the memory allocated for the last word
    free(word);
    // Sort the array in descending order of word count
    qsort(wf, sizeof(wf)/sizeof(WordFreq), sizeof(WordFreq), compare);
    return wf;
}

int main(void) {
    FILE* fp;
    WordFreq* wf;
    char filename[20];
    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: File could not be opened!\n");
        return 1;
    }
    wf = count(fp);
    int i;
    printf("Word\t\tCount\n");
    for(i = 0; wf[i].word; i++) {
        printf("%-16s%d\n", wf[i].word, wf[i].count);
    }
    // Free the memory allocated to the WordFreq array
    free(wf);
    fclose(fp);
    return 0;
}