//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000

typedef struct {
    char word[50];
    int count;
} Word;

int main() {
    FILE *fp;
    char filename[100], tempWord[50], *token;
    Word wordList[MAX_WORDS];
    int i, j, index;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nLove Letters Word Count Tool\n");
    printf("------------------------------\n");

    i = 0;

    while (fgets(tempWord, sizeof(tempWord), fp) != NULL) {
        token = strtok(tempWord, " ,.-'\"!?:;(){}%$#@\\\/\\\\");

        while (token != NULL) {
            for (j = 0; wordList[j].word[0] != '\0'; j++) {
                if (strcmp(wordList[j].word, token) == 0) {
                    wordList[j].count++;
                    index = j;
                    break;
                }
            }

            if (wordList[j].word[0] == '\0') {
                strcpy(wordList[i++].word, token);
                wordList[i - 1].count = 1;
            }
        }

        token = NULL;
    }

    printf("\nWord\t\tCount\n");
    printf("--------------------\n");

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(wordList[i].word, "\0") != 0) {
            printf("%s\t\t%d\n", wordList[i].word, wordList[i].count);
            if (strstr(wordList[i].word, "love") || strstr(wordList[i].word, "heart") ||
                strstr(wordList[i].word, "passion") || strstr(wordList[i].word, "romance")) {
                printf("This word is a sign of love!\n");
            }
        }
    }

    fclose(fp);

    return 0;
}