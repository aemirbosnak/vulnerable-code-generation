//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define WORD_LEN 20

struct word {
    char word[WORD_LEN];
    int count;
};

struct word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        struct word* entry = &dictionary[num_words];
        strcpy(entry->word, word);
        entry->count = 0;
        num_words++;
    }

    fclose(fp);
}

int compare(const void* a, const void* b) {
    const struct word* wa = a;
    const struct word* wb = b;
    return strcmp(wa->word, wb->word);
}

void suggest(const char* word) {
    char* buf = malloc(WORD_LEN * 10);
    if (buf == NULL) {
        printf("Error: out of memory.\n");
        exit(1);
    }

    int len = strlen(word);
    if (len > WORD_LEN) {
        printf("Error: word too long.\n");
        exit(1);
    }

    strcpy(buf, word);
    strcat(buf, " ");

    qsort(dictionary, num_words, sizeof(struct word), compare);

    for (int i = 0; i < num_words; i++) {
        if (strncmp(dictionary[i].word, buf, WORD_LEN) == 0) {
            printf("%s\n", dictionary[i].word);
        }
    }

    free(buf);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s dictionary.txt [word]\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);

    if (argc == 3) {
        suggest(argv[2]);
    } else {
        char word[WORD_LEN];
        while (fgets(word, WORD_LEN, stdin)!= NULL) {
            word[strcspn(word, "\n")] = '\0';
            suggest(word);
        }
    }

    return 0;
}