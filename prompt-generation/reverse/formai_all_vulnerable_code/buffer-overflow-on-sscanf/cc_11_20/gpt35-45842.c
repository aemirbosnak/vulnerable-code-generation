//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 50

struct freq_counter {
    char word[MAX_WORD_LEN];
    int count;
};

int main(int argc, char const *argv[]) {
    char* file_name;
    char* stop_words_file_name;

    if (argc == 2) {
        file_name = argv[1];
        stop_words_file_name = "";
    } else if (argc == 3) {
        file_name = argv[1];
        stop_words_file_name = argv[2];
    } else {
        printf("usage: wordfreq <file_name> [<stop_words_file_name>]\n");
        exit(0);
    }

    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("error: could not open file %s\n", file_name);
        exit(1);
    }

    FILE *stop_words_file = fopen(stop_words_file_name, "r");

    char stop_words[26][MAX_WORD_LEN] = { {0} };
    int num_stop_words = 0;

    if (stop_words_file != NULL) {
        char line[MAX_WORD_LEN];

        while (fgets(line, sizeof(line), stop_words_file)) {
            sscanf(line, "%s", stop_words[num_stop_words++]);
        }

        fclose(stop_words_file);
    }

    char line[256];
    char *word;
    struct freq_counter word_freq[MAX_WORDS];
    int i, j, num_words = 0;

    for (i = 0; i < MAX_WORDS; i++) {
        word_freq[i].count = 0;
    }

    while (fgets(line, sizeof(line), file)) {
        word = strtok(line, " .\n\t\r");

        while (word != NULL) {
            int is_stop_word = 0;

            for (i = 0; i < num_stop_words; i++) {
                if (strcmp(stop_words[i], word) == 0) {
                    is_stop_word = 1;
                    break;
                }
            }

            if (!is_stop_word) {
                int word_found = 0;

                for (i = 0; i < num_words; i++) {
                    if (strcmp(word_freq[i].word, word) == 0) {
                        word_freq[i].count++;
                        word_found = 1;
                        break;
                    }
                }

                if (!word_found) {
                    if (strlen(word) <= MAX_WORD_LEN) {
                        strcpy(word_freq[num_words].word, word);
                        word_freq[num_words].count = 1;
                        num_words++;
                    }
                }
            }

            word = strtok(NULL, " .\n\t\r");
        }
    }

    fclose(file);

    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(word_freq[i].word, word_freq[j].word) > 0) {
                struct freq_counter tmp = word_freq[i];
                word_freq[i] = word_freq[j];
                word_freq[j] = tmp;
            }
        }
    }

    printf("Word frequency count...\n");

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_freq[i].word, word_freq[i].count);
    }

    return 0;
}