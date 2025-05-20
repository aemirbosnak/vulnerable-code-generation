//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char cat_word[MAX_WORD_LEN];
    int count;
} WordFrequency;

int compare_word_frequency(const void *a, const void *b) {
    WordFrequency *frequency_a = (WordFrequency*)a;
    WordFrequency *frequency_b = (WordFrequency*)b;

    if (frequency_a->count > frequency_b->count) {
        return -1;
    } else if (frequency_a->count < frequency_b->count) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LEN];
    WordFrequency word_frequency_table[10000];
    int num_words = 0;
    int i, j;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file '%s'\n", argv[1]);
        exit(1);
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file '%s'\n", argv[2]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, input_file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int word_len = strlen(word);
            if (word_len > MAX_WORD_LEN) {
                printf("Warning: word '%s' is too long (max %d characters)\n", word, MAX_WORD_LEN);
            } else {
                for (i = 0; i < num_words; i++) {
                    if (strcmp(word_frequency_table[i].word, word) == 0) {
                        word_frequency_table[i].count++;
                        break;
                    }
                }
                if (i == num_words) {
                    strcpy(word_frequency_table[num_words].word, word);
                    strcpy(word_frequency_table[num_words].cat_word, word);
                    word_frequency_table[num_words].count = 1;
                    num_words++;
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(word_frequency_table, num_words, sizeof(WordFrequency), compare_word_frequency);

    fprintf(output_file, "Word\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\t%d\n", word_frequency_table[i].word, word_frequency_table[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}