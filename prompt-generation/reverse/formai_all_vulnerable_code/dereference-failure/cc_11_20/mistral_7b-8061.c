//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_SIZE 50

typedef struct {
    char word[WORD_SIZE];
    int count;
} Word;

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[1024];
    Word words[MAX_WORDS];
    int num_words = 0;
    char search_word[WORD_SIZE];
    int i;

    if (argc != 3) {
        printf("Usage: %s <word> <file>\n", argv[0]);
        return 1;
    }

    strcpy(search_word, argv[1]);

    file = fopen(argv[2], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *token = strtok(buffer, " \t\n\r.,;:!?");

        if (token == NULL) {
            continue;
        }

        for (i = 0; i < num_words; i++) {
            if (strcasecmp(words[i].word, token) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Too many words in file\n");
                fclose(file);
                return 1;
            }

            strcpy(words[num_words].word, token);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(file);

    printf("Word '%s' occurs %d times in the file.\n", search_word, words[0].count);

    for (i = 1; i < num_words; i++) {
        if (strcasecmp(words[i].word, search_word) == 0) {
            printf("Your search word also occurs %d times as '%s'\n", words[i].count, words[i].word);
            break;
        }
    }

    return 0;
}