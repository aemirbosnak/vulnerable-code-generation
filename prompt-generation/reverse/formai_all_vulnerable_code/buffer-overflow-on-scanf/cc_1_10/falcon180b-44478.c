//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char words[MAX_WORDS][MAX_WORD_LEN];
int numWords = 0;

void addWord(char* word) {
    if (numWords >= MAX_WORDS) {
        printf("Error: Too many words\n");
        return;
    }
    strcpy(words[numWords], word);
    numWords++;
}

int main() {
    char filename[100];
    FILE* file;
    char line[1000];
    char* word;
    int i, j;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        i = 0;
        while ((word = strtok(line, ",.?!;:\"'"))!= NULL) {
            if (strlen(word) > 0) {
                addWord(word);
            }
            i++;
            if (i >= MAX_WORDS) {
                printf("Error: Too many words in line\n");
                break;
            }
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], countWord(words[i]));
    }

    return 0;
}

int countWord(char* word) {
    int count = 0;
    char* p;

    for (p = strtok(word, ",.?!;:\"'"); p!= NULL; p = strtok(NULL, ",.?!;:\"'")) {
        count++;
    }

    return count;
}