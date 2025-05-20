//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

//struct to store words and their frequency
typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFrequency;

//function to compare two strings (case insensitive)
int compareStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minLen = (len1 < len2)? len1 : len2;

    for (int i = 0; i < minLen; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return 0;
        }
    }

    return 1;
}

//function to read words from a file and store them in an array
int readWordsFromFile(char* filename, char words[MAX_WORDS][MAX_WORD_LEN]) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    int wordCount = 0;
    char word[MAX_WORD_LEN];

    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[wordCount], word);
        wordCount++;
    }

    fclose(fp);
    return wordCount;
}

//function to count the frequency of each word in an array
void countWordFrequency(char words[MAX_WORDS][MAX_WORD_LEN], int wordCount, WordFrequency freq[MAX_WORDS]) {
    for (int i = 0; i < wordCount; i++) {
        freq[i].word[0] = '\0';
        freq[i].frequency = 0;
    }

    for (int i = 0; i < wordCount; i++) {
        int j;
        for (j = 0; j < wordCount; j++) {
            if (compareStrings(words[i], words[j])) {
                break;
            }
        }

        if (j == wordCount) {
            strcpy(freq[wordCount - 1].word, words[i]);
            freq[wordCount - 1].frequency++;
        } else {
            freq[j].frequency++;
        }
    }
}

//function to print the top n most frequent words
void printTopWords(WordFrequency freq[MAX_WORDS], int n) {
    printf("Top %d most frequent words:\n", n);

    for (int i = 0; i < n && i < MAX_WORDS; i++) {
        if (freq[i].frequency > 0) {
            printf("%s: %d\n", freq[i].word, freq[i].frequency);
        }
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LEN];
    WordFrequency freq[MAX_WORDS];

    int wordCount = readWordsFromFile("words.txt", words);
    countWordFrequency(words, wordCount, freq);

    int n;
    printf("Enter the number of top words to print: ");
    scanf("%d", &n);

    printTopWords(freq, n);

    return 0;
}