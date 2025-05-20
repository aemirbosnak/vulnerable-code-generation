//Falcon-180B DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int num_words;

void load_words(void) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int i;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    while (fscanf(file, "%s", line)!= EOF) {
        word = strdup(line);
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
        words[num_words++] = word;
    }

    fclose(file);
}

void generate_sentence(int length) {
    int i;
    char sentence[MAX_WORD_LENGTH * length];

    for (i = 0; i < length; i++) {
        int word_index = rand() % num_words;
        strcat(sentence, words[word_index]);
        if (i < length - 1) {
            strcat(sentence, " ");
        }
    }

    printf("%s\n", sentence);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    load_words();
    int length = rand() % 20 + 5;
    generate_sentence(length);
    return 0;
}