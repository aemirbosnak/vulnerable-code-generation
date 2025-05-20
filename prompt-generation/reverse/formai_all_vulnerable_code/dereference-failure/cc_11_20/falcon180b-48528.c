//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

struct word_count {
    char word[WORD_LENGTH];
    int count;
};

int main() {
    FILE* input_file;
    char line[1000];
    char word[WORD_LENGTH];
    int word_count = 0;
    struct word_count* word_table = malloc(MAX_WORDS * sizeof(struct word_count));

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        int i, j;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                j = 0;
                while (isalpha(line[i]) && j < WORD_LENGTH) {
                    word[j] = tolower(line[i]);
                    i++;
                    j++;
                }
                word[j] = '\0';
                for (int k = 0; k < word_count; k++) {
                    if (!strcmp(word_table[k].word, word)) {
                        word_table[k].count++;
                        break;
                    }
                }
                if (word_count == MAX_WORDS) {
                    printf("Error: Maximum number of unique words reached.\n");
                    exit(1);
                }
                strcpy(word_table[word_count].word, word);
                word_table[word_count].count = 1;
                word_count++;
            }
        }
    }

    fclose(input_file);

    printf("Word\tFrequency\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\t%d\n", word_table[i].word, word_table[i].count);
    }

    free(word_table);
    return 0;
}