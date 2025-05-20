//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_WORD_LENGTH 20

    struct Word {
        char word[MAX_WORD_LENGTH];
        int count;
    };

    struct WordList {
        struct Word *words;
        int num_words;
    };

    int is_word_correct(const char *word) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            return 0;
        }

        char *dict_file = "/usr/share/dict/words";
        FILE *fp = fopen(dict_file, "r");
        if (!fp) {
            perror("fopen");
            return -1;
        }

        char word_buf[MAX_WORD_LENGTH];
        while (fscanf(fp, "%s", word_buf) == 1) {
            if (strcmp(word_buf, word) == 0) {
                fclose(fp);
                return 1;
            }
        }

        fclose(fp);
        return 0;
    }

    int main(int argc, char **argv) {
        if (argc < 2) {
            printf("Usage: %s <word>\n", argv[0]);
            return 1;
        }

        char *word = argv[1];
        if (is_word_correct(word)) {
            printf("%s is a correct word.\n", word);
        } else {
            printf("%s is not a correct word.\n", word);
        }

        return 0;
    }