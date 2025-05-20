//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

void toLowerCase(char* str) {
    int i = 0;
    while(str[i] != '\0') {
        if(isupper(str[i])) {
            str[i] += 32;
        }
        i++;
    }
}

int hashFunction(char* str) {
    int hash = 0;
    int i = 0;
    while(str[i] != '\0') {
        hash += (int)str[i];
        i++;
    }
    return hash % MAX_WORDS;
}

int main() {
    Word table[MAX_WORDS];
    char fileName[100];
    FILE* fp;
    char str[MAX_WORD_LEN];
    char* token;
    int i, pos;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while(fgets(str, sizeof(str), fp) != NULL) {
        toLowerCase(str);
        token = strtok(str, " ,.\t\n\r\f\v");
        while(token != NULL) {
            pos = hashFunction(token);
            strcpy(table[pos].word, token);
            table[pos].count++;
            token = strtok(NULL, " ,.\t\n\r\f\v");
        }
    }

    fclose(fp);

    printf("\nWord Frequency Table:\n");
    for(i = 0; i < MAX_WORDS; i++) {
        if(table[i].count > 0) {
            printf("%s : %d\n", table[i].word, table[i].count);
        }
    }

    return 0;
}