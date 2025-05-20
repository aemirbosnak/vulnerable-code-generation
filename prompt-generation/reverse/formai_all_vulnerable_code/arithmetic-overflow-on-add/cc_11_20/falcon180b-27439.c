//Falcon-180B DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char **argv) {
    FILE *input_file;
    char input_buffer[1024];
    char *word_start, *word_end;
    int word_length;
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(input_buffer, sizeof(input_buffer), input_file)!= NULL) {
        word_start = input_buffer;
        while ((word_end = strpbrk(word_start, " \t\r\n\f\v"))!= NULL) {
            word_length = word_end - word_start;
            if (word_length > MAX_WORD_LENGTH) {
                word_length = MAX_WORD_LENGTH;
            }
            for (i = 0; i < MAX_WORDS && word_counts[i].count > 0; i++) {
                if (strncasecmp(word_start, word_counts[i].word, word_length) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                for (i = 0; i < MAX_WORDS && word_counts[i].count == 0; i++) {
                    strncpy(word_counts[i].word, word_start, word_length);
                    word_counts[i].count = 1;
                    num_words++;
                    break;
                }
            }
            word_start = word_end + 1;
        }
    }

    fclose(input_file);

    printf("Total number of words: %d\n", num_words);

    for (i = 0; i < MAX_WORDS && word_counts[i].count > 0; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}