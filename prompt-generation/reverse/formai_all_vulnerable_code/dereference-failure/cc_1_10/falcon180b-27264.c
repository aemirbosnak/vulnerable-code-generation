//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 20
#define SMOOTHING_FACTOR 0.001

// Function to read words from a file and store them in an array
void readWords(char *filename, char *words[]) {
    FILE *fp;
    char ch, word[MAX_WORD_LENGTH];
    int i = 0;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            word[0] = tolower(ch);
            int j = 1;
            while(isalpha(ch = fgetc(fp))) {
                if(j >= MAX_WORD_LENGTH) {
                    printf("Error: Word too long\n");
                    exit(1);
                }
                word[j++] = tolower(ch);
            }
            word[j] = '\0';
            strcpy(words[i++], word);
        }
    }
    fclose(fp);
}

// Function to classify a sentence based on the frequency of words
void classify(char *sentence, char *words[], int wordCounts[], int numWords) {
    int i, j, maxCount = 0;
    for(i = 0; i < numWords; i++) {
        if(strstr(sentence, words[i])!= NULL) {
            wordCounts[i]++;
        }
    }
    for(i = 0; i < numWords; i++) {
        if(wordCounts[i] > maxCount) {
            maxCount = wordCounts[i];
        }
    }
    for(i = 0; i < numWords; i++) {
        if(wordCounts[i] == maxCount) {
            printf("%s\n", words[i]);
        }
    }
}

int main() {
    char *filename;
    char *words[MAX_WORDS];
    int wordCounts[MAX_WORDS] = {0};
    int numWords = 0;
    printf("Enter the name of the file containing words: ");
    scanf("%s", filename);
    readWords(filename, words);
    numWords = strlen(words);

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to classify: ");
    scanf("%s", sentence);

    classify(sentence, words, wordCounts, numWords);

    return 0;
}