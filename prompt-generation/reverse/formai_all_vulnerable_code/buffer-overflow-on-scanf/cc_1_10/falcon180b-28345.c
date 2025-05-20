//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void load_words() {
    FILE *fp;
    char word[MAX_WORD_LENGTH];

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    num_words = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[num_words++], word);
    }

    fclose(fp);
}

void generate_test(int num_sentences) {
    int i, j;
    char *sentence;

    srand(time(NULL));

    for (i = 0; i < num_sentences; i++) {
        sentence = malloc(MAX_WORD_LENGTH * 10);
        strcpy(sentence, "");

        for (j = 0; j < rand() % 10 + 5; j++) {
            int k = rand() % num_words;
            strcat(sentence, words[k]);
            strcat(sentence, " ");
        }

        printf("%s\n", sentence);
        free(sentence);
    }
}

int main() {
    int num_sentences;

    printf("Enter the number of sentences to generate: ");
    scanf("%d", &num_sentences);

    load_words();
    generate_test(num_sentences);

    return 0;
}