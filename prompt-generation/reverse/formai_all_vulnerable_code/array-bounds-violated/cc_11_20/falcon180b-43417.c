//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    struct word_count words[MAX_WORDS];
    int num_words = 0;

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isspace(line[i])) {
                if (i > 0 &&!isspace(line[i-1])) {
                    words[num_words].word[words[num_words].count] = '\0';
                    words[num_words].count++;
                    num_words++;
                }
                i++;
            } else {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached\n");
                    fclose(file);
                    return 1;
                }
                if (words[num_words].count >= MAX_WORD_LENGTH) {
                    printf("Error: Maximum word length reached\n");
                    fclose(file);
                    return 1;
                }
                words[num_words].word[words[num_words].count++] = tolower(line[i]);
            }
            i++;
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}