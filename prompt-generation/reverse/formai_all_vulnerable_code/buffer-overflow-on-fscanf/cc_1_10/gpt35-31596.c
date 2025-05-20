//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100        // Maximum length of a translated word
#define MAX_DICT_WORDS 1000     // Maximum number of words in the alien dictionary
#define UNKNOWN_WORD "???"      // Translation of unknown or unregistered words

char alien_dict[MAX_DICT_WORDS][MAX_WORD_LEN + 1];  // The alien dictionary
int num_words_in_dict = 0;                          // Number of words in the alien dictionary

void load_alien_dict(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "*** Error: Couldn't open alien dictionary file '%s'\n", filename);
        return;
    }
    while (fgets(alien_dict[num_words_in_dict], MAX_WORD_LEN + 1, fp)) {
        alien_dict[num_words_in_dict][strlen(alien_dict[num_words_in_dict]) - 1] = '\0'; // remove newline
        num_words_in_dict++;
        if (num_words_in_dict == MAX_DICT_WORDS) break; // dictionary is full, stop reading
    }
    printf("Alien dictionary loaded from '%s' with %d words.\n", filename, num_words_in_dict);
    fclose(fp);
}

const char* translate_word(const char* alien_word) {
    for (int i = 0; i < num_words_in_dict; i++) {
        if (strcmp(alien_dict[i], alien_word) == 0) {
            return alien_dict[i] + strlen(alien_word) + 1; // skip the alien word and the separator
        }
    }
    return UNKNOWN_WORD; // not found in dictionary
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s alien_dict_file alien_text_file\n", argv[0]);
        return 1;
    }
    load_alien_dict(argv[1]);
    FILE* fp = fopen(argv[2], "r");
    if (!fp) {
        fprintf(stderr, "*** Error: Couldn't open alien text file '%s'\n", argv[2]);
        return 1;
    }
    char alien_word[MAX_WORD_LEN + 1];
    while (fscanf(fp, "%s", alien_word) == 1) {
        printf("%s ", translate_word(alien_word));
    }
    printf("\n");
    fclose(fp);
    return 0;
}