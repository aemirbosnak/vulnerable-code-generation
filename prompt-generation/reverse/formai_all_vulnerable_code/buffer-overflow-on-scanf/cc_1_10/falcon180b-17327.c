//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 32
#define MAX_SENTENCES 1000
#define SENTENCE_LEN 1024

int main() {
    FILE *fp;
    char filename[MAX_WORD_LEN];
    char sentence[SENTENCE_LEN];
    int word_count = 0;
    int sentence_count = 0;
    int char_count = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(sentence, SENTENCE_LEN, fp)!= NULL) {
        sentence_count++;
        char_count += strlen(sentence);

        char *token = strtok(sentence, ",.?!;:");

        while (token!= NULL) {
            word_count++;
            char_count += strlen(token);

            if (strlen(token) > MAX_WORD_LEN) {
                printf("Warning: Word '%s' is too long.\n", token);
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    printf("Total words: %d\n", word_count);
    printf("Total sentences: %d\n", sentence_count);
    printf("Total characters: %d\n", char_count);

    fclose(fp);

    return 0;
}