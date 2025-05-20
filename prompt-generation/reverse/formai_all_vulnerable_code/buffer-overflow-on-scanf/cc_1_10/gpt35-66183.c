//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_SIZE 50

struct wordCount {
    char word[MAX_WORD_SIZE];
    int count;
};

/* Function prototypes */
void readWords(char words[][MAX_WORD_SIZE], int *size);
void countWords(char words[][MAX_WORD_SIZE], int size, struct wordCount table[], int *tableSize);
void sortTable(struct wordCount table[], int size);
void printTable(struct wordCount table[], int size);

/* Main function */
int main() {
    char words[MAX_WORDS][MAX_WORD_SIZE];
    int size = 0;
    struct wordCount table[MAX_WORDS];
    int tableSize = 0;

    printf("Enter some text (ctrl+d to terminate):\n");
    readWords(words, &size);

    countWords(words, size, table, &tableSize);

    sortTable(table, tableSize);

    printTable(table, tableSize);

    return 0;
}

/* Function to read words from user input */
void readWords(char words[][MAX_WORD_SIZE], int *size) {
    char word[MAX_WORD_SIZE];
    while(scanf("%s", word) != EOF) {
        if(*size == MAX_WORDS) {
            printf("Too many words, terminating input.\n");
            return;
        }
        if(strlen(word) < MAX_WORD_SIZE) {
            strcpy(words[*size], word);
            (*size)++;
        }
        else {
            printf("Word too long (%s), skipping it.\n", word);
        }
    }
}

/* Function to count the frequency of each word */
void countWords(char words[][MAX_WORD_SIZE], int size, struct wordCount table[], int *tableSize) {
    int i, j;
    for(i = 0; i < size; i++) {
        /* Convert word to lowercase */
        for(j = 0; j < strlen(words[i]); j++) {
            words[i][j] = tolower(words[i][j]);
        }

        /* Check if word already exists in table */
        for(j = 0; j < (*tableSize); j++) {
            if(strcmp(words[i], table[j].word) == 0) {
                table[j].count++;
                break;
            }
        }

        /* If word doesn't exist in table, add it */
        if(j == (*tableSize)) {
            strcpy(table[*tableSize].word, words[i]);
            table[*tableSize].count = 1;
            (*tableSize)++;
        }
    }
}

/* Function to sort the word frequency table */
void sortTable(struct wordCount table[], int size) {
    int i, j;
    struct wordCount temp;

    for(i = 0; i < size - 1; i++) {
        for(j = i + 1; j < size; j++) {
            if(table[i].count < table[j].count) {
                temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }
}

/* Function to print the word frequency table */
void printTable(struct wordCount table[], int size) {
    int i;
    printf("\nWord frequency table:\n");
    printf("----------------------\n");
    for(i = 0; i < size; i++) {
        printf("%s: %d\n", table[i].word, table[i].count);
    }
}