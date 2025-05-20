//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 1000
#define WORD_LENGTH 50

// Struct for storing word and its frequency
typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void extract_words(char *text, Word words[MAX_WORDS]) {
    int index = 0;
    char current_word[WORD_LENGTH];
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            current_word[index++] = tolower(text[i]);
            if (index >= WORD_LENGTH) {
                words[index - WORD_LENGTH].count += 1;
                strncpy(words[index - WORD_LENGTH].word, current_word, WORD_LENGTH);
                index = 0;
            }
        }
    }
    words[index].count += 1;
    strncpy(words[index].word, current_word, WORD_LENGTH);
}

int main() {
    char text[1000] = "Two households, both alike in dignity, In fair Verona, where we lay our scene, From ancient grudge break to new mutiny, Where civil blood makes civil hands unclean. From forth the fatal loins of these two foes A pair of star-cross'd lovers take their life; Whose misadventured piteous overthrows Do with their death bury their parents' strife.";
    Word words[MAX_WORDS];

    extract_words(text, words);

    printf("Love's lamentation is cruel and bitter,\n");
    printf("Summon'd is this sorrowful fruition;\n");

    int most_common_index = 0;
    int max_count = 0;

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > max_count) {
            most_common_index = i;
            max_count = words[i].count;
        }
    }

    printf("'%s' is the most frequent word found,\n", words[most_common_index].word);
    printf("With count %d, a testament to the text.\n", words[most_common_index].count);

    int min_count = max_count;
    int num_summary_words = 0;

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count < min_count) {
            printf("'%s' is a summary word, with count %d,\n", words[i].word, words[i].count);
            num_summary_words++;
            if (num_summary_words == 5)
                break;
        }
    }

    printf("Five such words form our text's essence,\n");
    printf("A condensed reflection of this verse.\n");

    return 0;
}