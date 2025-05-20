//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void read_words_file(char *filename, WordCount words[]) {
    FILE *file;
    char line[MAX_WORD_LEN];
    char *word;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            if (strlen(word) > 0 && strlen(word) <= MAX_WORD_LEN) {
                words[atoi(word)].count++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);
}

int is_spam(char *email, WordCount words[]) {
    char *word;
    int i, count = 0;

    for (i = 0; i < strlen(email); i++) {
        if (isalpha(email[i])) {
            word = &email[i];
            while (isalpha(word[0])) {
                word[strcspn(word, " ")] = '\0';
                if (strlen(word) > 0 && strlen(word) <= MAX_WORD_LEN) {
                    count += words[atoi(word)].count;
                }
                word++;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <words_file> <email>\n", argv[0]);
        exit(1);
    }

    WordCount words[MAX_WORDS];
    read_words_file(argv[1], words);

    char *email = argv[2];
    int spam_count = is_spam(email, words);

    if (spam_count > 0) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}