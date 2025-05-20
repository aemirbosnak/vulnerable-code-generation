//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdnoreturn.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <errno.h>
#include <assert.h>

#define MAX_WORDS 2000
#define MAX_WORD_LENGTH 20

char* words[MAX_WORDS];
int numWords = 0;

void readWords(FILE* file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words!\n");
            exit(1);
        }
        words[numWords++] = strdup(word);
    }
}

int main() {
    FILE* file;
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }
    readWords(file);
    fclose(file);

    int i, j;
    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    printf("Sorted words:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}