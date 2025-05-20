//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

typedef struct {
    char english[50];
    char cat[50];
} word;

void loadWords(word words[]);
int searchWord(word words[], int n, char* word);
void translateSentence(char sentence[], word words[], int n);

int main() {
    word words[MAX_WORDS];
    loadWords(words);

    char sentence[1000];
    printf("Enter a sentence to translate: ");
    scanf("%s", sentence);

    translateSentence(sentence, words, 10);

    return 0;
}

void loadWords(word words[]) {
    FILE* file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
    }

    fclose(file);
}

int searchWord(word words[], int n, char* word) {
    for (int i = 0; i < n; i++) {
        if (strcmp(word, words[i].english) == 0) {
            return i;
        }
    }

    return -1;
}

void translateSentence(char sentence[], word words[], int n) {
    char* token = strtok(sentence, " ");

    while (token!= NULL) {
        int index = searchWord(words, n, token);

        if (index!= -1) {
            printf("%s ", words[index].cat);
        } else {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}