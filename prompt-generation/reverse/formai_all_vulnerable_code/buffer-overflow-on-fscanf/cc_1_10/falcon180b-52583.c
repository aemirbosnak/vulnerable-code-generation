//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char* word;
    int count;
} WordFrequency;

void generate_conspiracy_theory(char* theory, int length) {
    srand(time(NULL));
    char* words[MAX_WORDS];
    int num_words = 0;

    FILE* fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening words file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", words[num_words])!= EOF) {
        num_words++;
        if (num_words == MAX_WORDS) {
            break;
        }
    }

    fclose(fp);

    for (int i = 0; i < length; i++) {
        int index = rand() % num_words;
        strcat(theory, words[index]);
        strcat(theory, " ");
    }

    theory[length - 1] = '\0';
}

int main() {
    char theory[MAX_WORD_LENGTH * 10]; // Allow for up to 10 words of length 20
    int length = rand() % 10 + 5; // Random length between 5 and 14 words

    generate_conspiracy_theory(theory, length);

    printf("New conspiracy theory: %s\n", theory);

    return 0;
}