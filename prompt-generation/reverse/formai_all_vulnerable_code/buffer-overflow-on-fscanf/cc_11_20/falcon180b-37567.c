//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word {
    char *word;
    int count;
};

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    if (argc!= 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fscanf(file, "%s", line)!= EOF) {
        words[num_words].word = strdup(line);
        words[num_words].count = 0;
        num_words++;
    }

    fclose(file);

    file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening text file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                j = 0;
                while (words[j].word!= NULL && strcmp(line + i, words[j].word)!= 0) {
                    j++;
                }
                if (words[j].word!= NULL) {
                    words[j].count++;
                }
            }
            i++;
        }
    }

    fclose(file);

    printf("Spelling errors:\n");
    for (i = 0; i < num_words; i++) {
        if (words[i].count == 0) {
            printf("%s\n", words[i].word);
        }
    }

    for (i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return 0;
}