//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 100

char dict[MAX_WORDS][MAX_SENTENCE_LENGTH];
int numWords;
char input[MAX_SENTENCE_LENGTH];
char output[MAX_SENTENCE_LENGTH];

void loadDict() {
    FILE* fp;
    char word[MAX_SENTENCE_LENGTH];
    int i = 0;
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(dict[i], word);
        i++;
    }
    numWords = i;
    fclose(fp);
}

void generateSentence() {
    int i, j;
    char* word;
    for (i = 0; i < MAX_SENTENCE_LENGTH; i++) {
        if (i == 0) {
            word = dict[rand() % numWords];
            strcpy(output, word);
        } else {
            word = dict[rand() % numWords];
            strcat(output, " ");
            strcat(output, word);
        }
    }
    output[MAX_SENTENCE_LENGTH - 1] = '\0';
    printf("%s\n", output);
}

int main() {
    loadDict();
    srand(time(NULL));
    printf("Enter the number of sentences to generate: ");
    scanf("%d", &numWords);
    for (int i = 0; i < numWords; i++) {
        generateSentence();
    }
    return 0;
}