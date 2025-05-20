//Falcon-180B DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void generateRandomString(char* str, int len) {
    const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<len; i++) {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    str[len] = '\0';
}

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    srand(time(NULL));
    char inputStr[MAX_WORD_LEN];
    printf("Enter a string: ");
    scanf("%s", inputStr);
    int wordCount = 0;
    char words[MAX_WORDS][MAX_WORD_LEN];
    char* token = strtok(inputStr, ",.?!;:");
    while(token!= NULL) {
        if(wordCount >= MAX_WORDS) {
            printf("Maximum number of words exceeded.\n");
            break;
        }
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, ",.?!;:");
    }
    qsort(words, wordCount, sizeof(char*), compareWords);
    printf("Sorted words:\n");
    for(int i=0; i<wordCount; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}